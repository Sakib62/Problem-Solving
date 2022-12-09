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
        	cin >> a[i];//desired apartment size
        }
        sort(a, a + n);
        for(int i = 0; i < m; i++) {
        	cin >> b[i];//actual apartment size
        }
        sort(b, b + m);
        //both array sorted
        int cnt = 0;
        for(int i = 0, j = 0; i < n && j < m; i++) {
        	if(a[i] + k >= b[j] && a[i] - k <= b[j]) { //ith applicant's desired size is fulfilled by jth apartment
        		cnt++;//hence, increment counter
        		j++;//move on to next apartment, outer loop will move on to next applicant
        	}
        	else if(b[j] > a[i] + k) continue;//j'th apartment is much bigger than i'th applicant's need. Hence, i++, moving on to see if i+1'th applicant's need match
        	else {//j'th apartment is much smaller than i'th applicant's need, so move on to next apartment, applicant remains same
        		while(j < m && b[j] < a[i] - k) {//as long as apartment size is smaller than i'th applicant's need
        			j++;
        		}//loop breaks, either no more apartment or found a match for i'th applicant
        		i--;//outer loop will increment thus skips the current matched applicant, so first decrement
        	}
        }
        cout << cnt << "\n";
    }
}