/*
 ~ Author    : @tridib_2003
 ~ Title     : SAMER08F - Feynman
 ~ Link      : https://www.spoj.com/problems/SAMER08F/
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

int main() {

    FIO;

    ll n;
    cin >> n;

    while (n) {

        ll res = (n * (n + 1) * ((2 * n) + 1)) / 6;
        cout << res << '\n';

        cin >> n;

    }

    return 0;
}