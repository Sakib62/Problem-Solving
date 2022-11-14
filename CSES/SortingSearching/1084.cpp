// Problem: Apartments
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1084
// Time Limit: 1000 ms Memory Limit: 512 MB
// Parsed at: 2022-11-14 23:41:44

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
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m];
        for(int i = 0; i < n; i++) {
        	cin >> a[i];
        }
        sort(a, a + n);
        for(int i = 0; i < m; i++) {
        	cin >> b[i];
        }
        sort(b, b + m);
        int cnt = 0;
        for(int i = 0, j = 0; i < n && j < m; i++) {
        	if(a[i] + k >= b[j] && a[i] - k <= b[j]) {
        		cnt++;
        		j++;
        	}
        	else if(b[j] > a[i] + k) continue;
        	else {
        		while(j < m && b[j] < a[i] - k) {
        			j++;
        		}
        		i--;
        	}
        }
        cout << cnt << "\n";
    }
}