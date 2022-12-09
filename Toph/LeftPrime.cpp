// Problem: Left Prime
// Contest: Toph
// URL: https://toph.co/p/left-prime
// Time Limit: 1000 ms Memory Limit: 512 MB
// Parsed at: 2022-12-09 19:07:01

/*
    Bismillahir Rahmanir Rahim
    Author: Sakib62
*/
#include <bits/stdc++.h>
using namespace std;

#define range 10000001
int isComposite[range/32+1];//int(32bits), not bool
vector < int > primes;

bool check(int n, int pos) {
	return (bool)(n & (1<<pos));
}

int setBit(int n, int pos) {
	return n |= (1 << pos);
}

void sieve(int n) {
    for(int i = 3; i * i <= range; i += 2) {
        if(check(isComposite[i/32], i%32) == 0) {
            for(int j = i * i; j <= range; j += i + i) {
                isComposite[j/32] = setBit(isComposite[j/32], j%32);//j%32 bit is modified
            }
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= range; i += 2) {
        if(check(isComposite[i/32], i%32) == 0) primes.push_back(i); 
    }
}

int main() {
    sieve(range);
    
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        cout << lower_bound(primes.begin(), primes.end(), n) - primes.begin() << "\n";
    }
    return 0;
}