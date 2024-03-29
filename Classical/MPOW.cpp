/*
 ~ Author    : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  acos(-1)
#define MOD                 1000000007 // 998244353
#define EPS                 1e-9
#define vi                  vector<int>
#define vb                  vector<bool>
#define vvi                 vector<vector<int> >
#define vll                 vector<long long>
#define vvll                vector<vector<long long> >
#define pii                 pair<int, int>
#define pll                 pair<long long, long long>
#define vpii                vector<pair<int, int> >
#define vpll                vector<pair<long long, long long> >
#define pb                  push_back
#define eb                  emplace_back
#define mp                  make_pair
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, a)        for (auto& (i) : (a))
#define print(a)            cout << a << '\n'
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
#define FIO                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {

    int n = A.size(), m = A[0].size(), k = B[0].size();

    vector<vector<int> > res(n, vector<int>(k, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            long long curr = 0; // handles overflow
            for (int l = 0; l < m; ++l) {
                curr += (A[i][l] * 1LL * B[l][j]) % MOD;
            }
            res[i][j] = curr % MOD;
        }
    }

    return res;
}

vector<vector<int> > matrix_expo(vector<vector<int> >& A, int k) {
    int n = A.size();

    vector<vector<int> > res(n, vector<int>(n)), B = A;

    // initialize res with identity matrix
    for (int i = 0; i < n; i++)
        res[i][i] = 1;

    while (k) {
        if (k & 1)
            res = multiply(res, B);

        k >>= 1;
        B = multiply(B, B);
    }

    return res;
}

void solve() {

    int m, n;
    cin >> m >> n;

    vector<vector<int> > mat(m, vector<int> (m));

    FOR (i, 0, m) {
        FOR (j, 0, m) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int> > res = matrix_expo(mat, n);

    FOR (i, 0, m) {
        FOR (j, 0, m) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {

    FIO;

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
        // cout << '\n';
    }

    return 0;
}
