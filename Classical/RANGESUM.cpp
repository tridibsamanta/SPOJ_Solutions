/*
 ~ Author    : tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  acos(-1)
#define MOD                 1000000007
#define vi                  vector<int>
#define vvi                 vector<vector<int> >
#define vll                 vector<long long>
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, a)         for (auto& (i) : (a))
#define printall(a)         for (auto& (i) : (a)) cout << i << ' '
#define rsort(a)            sort((a).rbegin(), (a).rend())
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define max3(a, b, c)       max((a), max((b), (c)))
#define min3(a, b, c)       min((a), min((b), (c)))
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {

    int n;
    cin >> n;

    vi arr(n);

    FOR (i, 0, n) {
        cin >> arr[i];
    }

    reverse(all(arr));

    vll pref(n + 1, 0);

    FOR (i, 0, n) {
        pref[i + 1] = pref[i] + arr[i];
    }

    int q;
    cin >> q;

    while (q--) {

        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;

            int rev_l = sz(pref) - l;
            int rev_r = sz(pref) - r;

            cout << pref[rev_l] - pref[rev_r - 1] << '\n';
        }
        else if (type == 2) {
            int x;
            cin >> x;

            pref.eb(pref[sz(pref) - 1] + x);
        }
    }
}

int32_t main() {

    FIO;

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
        // cout << '\n';
    }

    return 0;
}
