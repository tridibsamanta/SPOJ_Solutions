/*
 ~ Author    : @tridib_2003
 ~ Title     : GAMES - How Many Games?
 ~ Link      : https://www.spoj.com/problems/GAMES/
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

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {

    FIO;

    int tc = 1;
    cin >> tc;
    while (tc--) {

        string s;
        cin >> s;

        int n = 0, deno = 1;
        bool start_deno = false;

        for (int i = 0; i < s.length(); ++i) {
            if (start_deno)
                deno *= 10;
            if (s[i] == '.') {
                start_deno = true;
                continue;
            }
            n = n * 10 + (s[i] - '0');
        }

        int g_c_d = gcd(n, deno);

        cout << (deno / g_c_d) << '\n';

    }

    return 0;
}