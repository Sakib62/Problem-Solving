// Problem: Distinct Numbers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1621
// Time Limit: 1000 ms Memory Limit: 512 MB
// Parsed at: 2022-11-14 23:13:04

/*
    Bismillahir Rahmanir Rahim
    Author: Sakib62
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    //#endif
    ios::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
        	cin >> a[i];
        }
        sort(a, a + n);
        int cnt = 1;
        for(int i = 1; i < n; i++) {
        	if(a[i] != a[i-1]) cnt++;
        }
        cout << cnt << "\n";
    }
}