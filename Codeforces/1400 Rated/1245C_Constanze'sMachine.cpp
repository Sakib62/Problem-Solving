/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Sat__02-Mar-2024__12:39:47
 *       File    :   C_Constanze_s_Machine.cpp
**/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int mod = 1e9 + 7;

void approachDP(string& s) {
    for (char x : s) {
        if (x == 'm' or x == 'w') {
            cout << "0\n";
            return;
        }
    }
    int n = s.size();
    vector<int> dp(n);
    dp[0] = 1;
    if (n >= 2) {
        if (s[1] == s[0] and (s[1] == 'n' or s[1] == 'u')) {
            dp[1] = 2;
        }
        else {
            dp[1] = 1;
        }
    }

//https://www.youtube.com/watch?v=JAruSSHJfXE
//dpi to be the number of strings that the machine would've turned into the first i characters of s
//how many msgs can eventually be turned into the given msg

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i-1];
        if (s[i] == s[i-1] and (s[i] == 'n' or s[i] == 'u')) {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
    }
    cout << dp[n-1];
}

void fib(vector<int>& fibo) {
    fibo[1] = 1;
    fibo[2] = 2;
    for (int i = 3; i <= 1e5; i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % mod;
    }
}

void approachFib(string& s) {
    vector<int> fibo(1e5 + 1);
    fib(fibo);

    int cnt = 1;
    ll ans = 1;
    bool nope = (s[0] == 'm' or s[0] == 'w');

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1] and (s[i] == 'n' or s[i] == 'u')) {
            cnt++;
        }
        else {
            ans = (ans * fibo[cnt]) % mod;
            cnt = 1;
        }
        nope |= (s[i] == 'm' or s[i] == 'w');
    }

    ans = (ans * fibo[cnt]) % mod;
    if (nope) ans = 0;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    approachDP(s);
    //approachFib(s);

}