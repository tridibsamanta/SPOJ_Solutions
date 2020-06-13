/*
 ~ Author    : @tridib_2003
 ~ Title     : FASHION - Fashion Shows
 ~ Link      : https://www.spoj.com/problems/FASHION/
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

    int tc = 1;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;

        vector<int> m;
        vector<int> w;

        int a;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            m.emplace_back(a);
        }
        for (int i = 0; i < n; ++i) {
            cin >> a;
            w.emplace_back(a);
        }

        sort(m.begin(), m.end());
        sort(w.begin(), w.end());

        int res = 0;
        for (int i = 0; i < n; ++i)
            res += (m[i] * w[i]);

        cout << res << '\n';

    }

    return 0;
}