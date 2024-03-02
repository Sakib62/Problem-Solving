/**
 *       Author :   Sakib62
 *       File   :   C_K_th_Not_Divisible_by_n.cpp
**/
//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << ">" << #x << ": " << x << "\n"; 
#define all(c) c.begin(), c.end()
#define revall(c) c.rbegin(), c.rend()
#define F first
#define S second

typedef unsigned long long ull;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
/**
 The number of integers not divisible by n among numbers 1,2,…,x is x−⌊x/n⌋
, so you can do binary search to find suitable value of  x
 */
    cin >> testCase;
    for (int TC = 1; TC <= testCase; TC++) {
        ll n, k, low = 1, high = 1e18, ans = -1;
        cin >> n >> k;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if ((mid - mid / n) < k) {
                low = mid + 1;
            }
            else {
                ans = mid;//for n=3, k=8; mid=12 or mid=11
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}