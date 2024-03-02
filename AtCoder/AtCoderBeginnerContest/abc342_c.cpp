/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Fri__01-Mar-2024__00:35:31
 *       File    :   C_Many_Replacement.cpp
**/

#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    unordered_map<char, char>mp;
    for (char i = 'a'; i <= 'z'; i++) {
        mp.insert({i, i}); //mp.emplace(i, i);
    }

    while (q--) {
        char c, d;
        cin >> c >> d;
        for (auto i : mp) {
            if (i.second == c) mp[i.first] = d;
        }
    }
    for(auto i : s) {
        cout << mp[i];
    }
    cout << "\n";

}