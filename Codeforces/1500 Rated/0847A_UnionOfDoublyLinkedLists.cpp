/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Sat__23-Mar-2024__12:19:55
 *       File    :   A_Union_of_Doubly_Linked_Lists.cpp
**/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

vector<int> par(105);
vector<int> sz(105, 1);

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 100; i++) {
        par[i] = i;
    }

    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, s;
        cin >> u >> s;
        v[i] = {u, s};
        if (u != 0) merge(u, i);
        if (s != 0) merge(s, i);
    }

    map<int, vector<int>>mp;
    for (int i = 1; i <= n; i++) {
        int tmp = find(i);
        mp[tmp].push_back(i);
    }

    vector<pair<int, int>> fin;
    for (auto i : mp) {
        int x, y;
        for (auto j : i.second) {
            if (v[j].first == 0) x = j;
            if (v[j].second == 0) y = j;
        }
        fin.emplace_back(x, y);
    }

    for (int i = 1; i < fin.size(); i++) {
        v[fin[i-1].second].second = fin[i].first;
        v[fin[i].first].first = fin[i-1].second;
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    
}