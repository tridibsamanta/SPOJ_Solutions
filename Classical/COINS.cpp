/*
 ~ Author    : @tridib_2003
 ~ Title     : COINS - Bytelandian gold coins
 ~ Link      : https://www.spoj.com/problems/COINS/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

map<int, ll> dp;

ll compute(int c) {

    if (c == 0)
        return 0;

    if (dp[c] != 0)
        return dp[c];

    ll exc = compute(c / 2) + compute(c / 3) + compute(c / 4);

    if (exc > c)
        dp[c] = exc;
    else
        dp[c] = c;

    return dp[c];
}

int main() {

    FIO;

    int c;
    while (cin >> c) {

        ll res = compute(c);
        cout << res << '\n';

    }

    return 0;
}