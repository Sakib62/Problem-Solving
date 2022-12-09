/**
 *       Author :   Sakib62
 *       Created:   Mon__17.Oct.2022__21:27:54
 *       File   :   C_Save_the_Magazines.cpp
**/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << ">" << #x << ": " << x << "\n"; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;

    cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a[n], ans=0, beg, end;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            if(s[i]=='1') {
                if(i==0) ans+=a[0];
                else {
                    if(s[i-1]=='1') ans+=a[i];//this one can't be shifted left anymore
                    else {
                        if(a[i-1]>=a[i]) {ans+=a[i-1]; s[i]='0';}//obvious
                        else if(a[i-1]<a[i]) {
                            if(i+1<n) {
                                if(s[i+1]=='0') ans+=a[i];//nothing right to be affected by this one
                                else {
                                    beg=a[i-1];//to compare with later
                                    int tmp=a[i], j=i+1;
                                    bool ok=false;
                                    while(j < n && s[j]=='1') {
                                        if(a[j]<beg) {ans+=(tmp+beg); s[j]='0';i=j;ok=true;break;}//beg index's 0 will be shifted here in j
                                        else tmp+=a[j];
                                        j++;
                                    }
                                    if(!ok) {
                                        ans+=tmp;
                                        i=j-1;
                                    }
                                }
                            }
                            else ans+=a[i];
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}