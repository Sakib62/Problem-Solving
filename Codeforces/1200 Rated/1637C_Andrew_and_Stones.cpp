/*      BISMILLAHIR-RAHMANIR-RAHIM
        *******************************
        \                            ~~
         \                            ~~
          \     SAKIB-SUST-SWE'19      ~~
           \                            ~~
            \                            ~~
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        long long a[n];
        int one = 0, odd = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i > 0 && i < n - 1) { //no need to consider border elements. 
                if(a[i] % 2 == 0) {
                    ans += (a[i] / 2); //min step to remove this element, can use it to pile up border elements or make any odd element even
                }
                else {
                    odd++;
                    if(a[i] == 1) one++;//cannot divide this element
                    ans += ((a[i] + 1) / 2);//if this odd is made even with the help of other elements
                }
            }
        }

        if(one == n - 2 || (n == 3 && odd == 1)) {//corner case, if all middle element are 1 can't proceed. if single middle element is 1 can't proceed too.
            cout << "-1\n";
            continue;
        }
        cout << ans << "\n";
    }
    return 0;
}