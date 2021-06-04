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


const int MAXN = 1e6 + 5;

int BLOCK_SIZE, curr_l, curr_r, cnt;
int freq[MAXN];
vi arr;

struct query {
    int l, r, idx;
};

bool cmp_mo_s(query a, query b) {
    if ((a.l / BLOCK_SIZE) != (b.l / BLOCK_SIZE))
        return (a.l / BLOCK_SIZE) < (b.l / BLOCK_SIZE);
    return ((a.l / BLOCK_SIZE) & 1) ? (a.r < b.r) : (a.r > b.r);
}

void expand(int idx) {
    if (++freq[arr[idx]] == 1)
        ++cnt;
}

void shrink(int idx) {
    if (--freq[arr[idx]] == 0)
        --cnt;
}

int mo_s_sqrt_dcmp(int l, int r) {

    // expand current range if needed
    while (curr_l > l) {
        --curr_l;
        expand(curr_l);
    }
    while (curr_r < r) {
        ++curr_r;
        expand(curr_r);
    }

    // shrink current range if needed
    while (curr_l < l) {
        shrink(curr_l);
        ++curr_l;
    }
    while (curr_r > r) {
        shrink(curr_r);
        --curr_r;
    }

    return cnt;
}

void solve() {

    int n;
    cin >> n;

    arr.resize(n);

    FOR (i, 0, n) {
        cin >> arr[i];
    }

    BLOCK_SIZE = (int) sqrt(n + .0) + 1;

    int q;
    cin >> q;

    query queries[q];

    FOR (i, 0, q) {
        int l, r;
        cin >> l >> r;

        queries[i].l = --l;
        queries[i].r = --r;
        queries[i].idx = i;
    }

    sort(queries, queries + q, cmp_mo_s);

    int ans[q];
    curr_l = 0, curr_r = -1;

    FOR (i, 0, q) {
        ans[queries[i].idx] = mo_s_sqrt_dcmp(queries[i].l, queries[i].r);
    }

    FOR (i, 0, q) {
        cout << ans[i] << '\n';
    }
}

signed main() {

    FIO;

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
        // cout << '\n';
    }

    return 0;
}
