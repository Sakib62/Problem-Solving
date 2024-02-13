/**
 *       Author :   Sakib62
 *       Created:   Tue__13.Feb.2024__11:32:26
 *       File   :   C_Jatayu_s_Balanced_Bracket_Sequence.cpp
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

int method1(string &s) {
    stack<char>st;
    st.push(s[0]);

    int n = s.length();
    int single = 0, joined = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == '(') {
            if(st.size() && st.top() == '(' && s[i-1] == ')') joined++; //parallel : ( ()() )
            st.push(s[i]);
        }
        else {
            single++;
            st.pop();
            if(st.empty() && i + 1 != n) joined++;//adjacent islands : (()) (()) -> 2
        }
    }
    return single - joined;
}

int method2(string &s) {
    int n = s.length();
    int cnt = 1;//overall outer component.
    for(int i = 1; i < n; i++) {
        if(s[i] == '(' && s[i] == s[i - 1]) {//this nested ones are single, no ties to other components
            cnt++;
        }
    }
    return cnt;
}

int method3(string &s) {
    int n = s.length();
    int cnt = 1 + n/2;//all opening brackets + outer
    for(int i = 1; i < n; i++) {
        if(s[i] == ')' and s[i-1] == '(') cnt--;//subtract every opening brackets that are part of balanced sequence
    }
    return cnt;//total unbalanced opening brackets
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;

    cin >> testCase;
    for(int TC = 1; TC <= testCase; TC++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        //cout << method1(s) << "\n";
        //cout << method2(s) << "\n";
        cout << method3(s) << "\n";
    }
}
