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


static int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2};
static int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve() {
    string s, d;
    cin >> s >> d;

    if (s == d) {
        cout << 0;
        return;
    }

    int x1 = s[0] - 'a', y1 = s[1] - '1';
    int x2 = d[0] - 'a', y2 = d[1] - '1';

    vvi visited(8, vi(8, -1));

    queue<pii> todo;
    todo.push({x1, y1});
    visited[x1][y1] = 0;

    int moves = 0;

    while (!todo.empty()) {

        int m = sz(todo);
        bool reached = false;

        FOR (i, 0, m) {
            pii curr = todo.front();
            todo.pop();

            int currX = curr.first;
            int currY = curr.second;

            FOR (j, 0, 8) {
                int adjX = currX + dx[j];
                int adjY = currY + dy[j];

                if (adjX == x2 && adjY == y2) {
                    moves = visited[currX][currY] + 1;
                    reached = true;
                    break;
                }

                if ((adjX >= 0 && adjX < 8) && (adjY >= 0 && adjY < 8) && (visited[adjX][adjY] == -1)) {
                    todo.push({adjX, adjY});
                    visited[adjX][adjY] = visited[currX][currY] + 1;
                }
            }

            if (reached)
                break;
        }

        if (reached)
            break;
    }

    cout << moves;
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
