/**
 *       Author :   Sakib62
 *       Created:   Sat__10.Dec.2022__19:18:24
 *       File   :   C_-_C.cpp
**/
//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;

    //cin >> testCase;
    while(testCase--) {
        long long n, x, k, ans = 0;
        cin >> n >> x >> k;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);//index not important in the problem
        for(int i = 0; i < n; i++) {

            long long init, upper, en, st;
            
            init = (1 + (a[i] / x)) * x;//closest(to a[i]) number that is divisible by x
            if(a[i] % x ==0) init = a[i];
            
            upper = x * ((init / x) + k-1);//from init to upper we get k numbers that are divisible by x
            
            en = lower_bound(a, a + n, upper + x) - a;//numbers less than upper + x
            st = lower_bound(a, a + n, upper) - a;//how many numbers are less than upper
            
            //lower range is below a[i], so a[i-1] less than a[i] should't be paired,
            if(k==0) st = lower_bound(a, a + n, a[i]) - a;// (2 5 0) -> (8 9),, ans should be 3 not 4, upper 10, lower 5, but lower should be a[i] to exclude a[i-1] < a[i]

            ans += (en - st);//this amount of number's index can be paired with i
        }
        cout << ans << "\n";
    }
}