#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int testCase = 1;
    cin >> testCase;
    while(testCase--) {

    	int n, m;
    	cin >> n >> m;
    	int a[n][m];
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			cin >> a[i][j];
    		}
    	}

    	int tot = 0, id1, id2;
    	bool end = false, cool = true;
//only 1 operation is allowed by swapping two columns
//so if 3 elements are not in correct place, impossible to sort whole row in non-decreasing order in 1 move.
    	for(int i = 0; i < n; i++) {

    		vector <int> hi;
    		for(int j = 0; j < m; j++) {
    			hi.push_back(a[i][j]);
    		}
    		sort(hi.begin(), hi.end());

    		tot = 0, id1 = -1, id2 = -1;
    		for(int j = 0; j < m; j++) {

    			if(a[i][j] != hi[j]) tot++;
    			if(tot == 1) {
    				if(id1 == -1) id1 = j;//keep track of mismatched element's index
    			}
    			if(tot == 2) {
    				if(id2 == -1) id2 = j;//either no mismatched element or two or more.
    			}
    		}
    		if(tot > 2) {//no ans
    			cout << "-1\n";
    			end = true;
    			break;
    		}

    		if(tot) cool = false;//not already sorted

    		if(tot == 2) break;//swap these columns and verify
    	}
    	if(end) continue;

    	if(cool) {//already sorted, just swap same column with itself
    		cout << "1 1\n";
    		continue;
    	}

    	for(int j = 0; j < n; j++) { 
    		swap(a[j][id1], a[j][id2]);	//swapping element of 2 column in each row
    	}

    	bool lo = false;
        //checking if all row is sorted after one move 
		for(int i = 0; i < n; i++) {
			for(int j = 1; j < m; j++) {
				if(a[i][j - 1] > a[i][j]) {
					lo = true;//whole row is not sorted in non-decreasing order
					break;
				}
			}
		}    	

		if(lo) cout << "-1\n";
		else cout << id1 + 1 << " " << id2 + 1 << "\n";//from 0 to 1 based indexing
    	
    }
}