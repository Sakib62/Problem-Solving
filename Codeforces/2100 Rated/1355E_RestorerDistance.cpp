//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << '>' << #x << " : " << x << "\n";
#define all(c) c.begin(), c.end()
#define F first
#define S second

typedef unsigned long long ull;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        ll n, a, r, m;
        cin >> n >> a >> r >> m;
        vector < ll > lst;
        ll mx = -1;
        for(ll i = 0, x; i < n; i++) {
            cin >> x;
            lst.push_back(x);
            mx = max(mx, x);
        }
        //lambda function
        auto cost = [&](ll x) -> ll {
            ll tmp = 0, sub = 0, add = 0;
            for(auto i : lst) {
                if(i < x) add += (x - i);
                else sub += (i - x);
            }
            if(a + r > m) {
                tmp += min(add, sub) * m;
                if(add > sub) tmp += (add - sub) * a;
                else tmp += (sub - add) * r;
            }
            else {
                tmp = add * a + sub * r;
            }
            return tmp;
        };
        ll s = 0, e = mx, m1, m2;
        while(s < e) {
            m1 = s + (e - s) / 3;//ternary search, unimodal function
            m2 = e - (e - s) / 3;
            if(cost(m1) >= cost(m2)) s = m1 + 1;
            else e = m2 - 1;
        }
        cout << cost(s) << "\n";
    }
}