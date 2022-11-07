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
        int n;
        cin >> n;
        int a[n], ops = 0, todo = 0, gcd = 0;
        bool ok = false, ok2 = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2 != 0 && a[i] % 3 != 0) {
                ok = true;
                todo = a[i];//this one can't be affected
            }
            gcd = __gcd(gcd, a[i]);//in case all num are either div by 2 or 3 or both
        }
        if(ok) {//at least one num which can't be modified, others need to be same as this
            for(int i = 0; i < n; i++) {
                if(a[i] == todo) continue;
                if(a[i] < todo) {//already smaller
                    ok2 = true;
                    break;
                }
                else {
                    a[i] /= todo;
                    int cnt = 0;//if a[i] = todo+1,, then cnt=0, a[i]=1,,so cnt need to be >1
                    while(a[i] % 2 == 0) {a[i] /= 2; cnt++;}//can't remain other factor except 2 & 3
                    while(a[i] % 3 == 0) {a[i] /= 3; cnt++;}
                    if(!cnt || a[i] > 1) {ok2 = true; break;}
                    ops += cnt;
                }
            }
            if(ok2) cout << "-1\n";
            else cout << ops << "\n";
        }
        else  {
            for(int i = 0; i < n; i++) {
                if(a[i] == gcd) continue;
                int cnt = 0;
                a[i] /= gcd;//surely all num are greater than this gcd
                while(a[i] % 2 == 0) {a[i] /= 2; cnt++;}
                while(a[i] % 3 == 0) {a[i] /= 3; cnt++;}
                if(a[i] > 1) {ok2 = true; break;}//can't be any other factor except 2 & 3
                ops += cnt;
            }
            if(ok2) cout << "-1\n";
            else cout << ops << "\n";
        }
    }
}