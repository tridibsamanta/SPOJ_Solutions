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

const int MAXN = 2 * 1e5 + 5;

int n;
ll arr[MAXN];
int bit[MAXN];

void compress() {
    map<ll, int> mp;

    for (int i = 1; i <= n; ++i) {
        mp[arr[i]];
    }

    int idx = 1;

    for (auto& pr : mp) {
        pr.second = idx++;
    }

    for (int i = 1; i <= n; ++i) {
        arr[i] = mp[arr[i]];
    }
}

void update(int i, int val) {
    for (; i < MAXN; i += (i & -i)) {
        bit[i] += val;
    }
}

int querySum(int i) {
    int ans = 0;
    for (; i > 0; i -= (i & -i)) {
        ans += bit[i];
    }
    return ans;
}

void solve() {

    memset(bit, 0, sizeof(bit));

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    compress();

    ll invCnt = 0;

    for (int i = 1; i <= n; ++i) {
        invCnt += querySum(MAXN) - querySum(arr[i]);
        update(arr[i], 1);
    }

    cout << invCnt;
}

signed main() {

    FIO;

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
        cout << '\n';
    }

    return 0;
}
