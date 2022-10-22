/**
 *       Author :   Sakib62
 *       Created:   Fri__21.Oct.2022__15:25:06
 *       File   :   B_Death_s_Blessing.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;

    cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        int x, mx = 0;
        long long sum=0;
        for(int i = 0; i < n; i++) {
            cin >> x;
            sum += x; //must
        }
//first & last element has one neighbour. So, we iterate either from first or last
//Each step, array size shrinks, we want the element with largest spell to remain last
//so that its spell need not affect any other element
//if we iterate from one end and find the largest spell element, we start iterating from the opposite end.

//in a nutshell, it means that we add all spell except the largest.
        for(int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
            mx=max(mx, x);
        }
        cout << sum - mx << "\n";
    }
}