// Problem: Complex Operations
// Contest: Toph
// URL: https://toph.co/p/complex-operations
// Time Limit: 1000 ms Memory Limit: 512 MB
// Parsed at: 2022-12-10 01:00:55

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
        int n, q;
        cin >> n >> q;
        long long a[n];
        for(int i = 0; i < n; i++) {
        	cin >> a[i];
        }
        sort(a, a + n);//need to apply binary search
        long long totalSub = 0;	
    	while(q--) {
    		int type;
    		cin >> type;
    		if(type == 1) {
    			long long sub;//can be upto 10^18
    			cin >> sub;
    			totalSub += sub;//as all elements will be modified, just keep track of total amount modified
    		}
    		else {
    			long long l, r, k;
    			cin >> l >> r >> k;
    			int startInd = lower_bound(a, a + n, l + totalSub) - a;//how many numbers are before l in modified array
    			int endInd = upper_bound(a, a + n, r + totalSub) - a;//how many numbers are before r+1 in modified array
    			if(endInd - startInd >= k) {//total elements in range inclusive
    				cout << a[startInd + k - 1] - totalSub << "\n";//startInd is 1st in range, so to find k-th add k-1. All elements have been subtracted by totalSub amount
    			}
    			else cout << "-1\n";//range size is less than k
    			
    			// int neededInd = startInd + k - 1;
				// if(neededInd > n-1 || a[neededInd] > r + totalSub) cout << "-1\n";
				// else cout << a[neededInd] - totalSub << "\n";
    		}
    	}
    }
}