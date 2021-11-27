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


static int row4D[] = { -1, 0, 1, 0};
static int col4D[] = {0, 1, 0, -1};

int n, m;
vvi grid, lvl;
queue<pii> todo;
vector<vb> visited;

void init() {
    grid.clear();
    grid.resize(n);

    FOR (i, 0, n) {
        grid[i].resize(m, 0);
    }

    visited.clear();
    visited.resize(n);

    FOR (i, 0, n) {
        visited[i].resize(m, false);
    }

    lvl.clear();
    lvl.resize(n);

    FOR (i, 0, n) {
        lvl[i].resize(m);
    }
}

bool isValid(int x, int y) {
    return ((x >= 0 && x < n) && (y >= 0 && y < m));
}

void bfs() {
    while (!todo.empty()) {
        int m = sz(todo);

        FOR (i, 0, m) {
            pii curr = todo.front();
            todo.pop();

            int currX = curr.first;
            int currY = curr.second;

            FOR (k, 0, 4) {
                int adjX = currX + row4D[k];
                int adjY = currY + col4D[k];

                if (isValid(adjX, adjY)) {
                    if (!visited[adjX][adjY]) {

                        todo.push({adjX, adjY});
                        visited[adjX][adjY] = true;
                        lvl[adjX][adjY] = lvl[currX][currY] + 1;
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    init();

    FOR (i, 0, n) {
        FOR (j, 0, m) {
            char ch;
            cin >> ch;

            grid[i][j] = ch - '0';

            if (grid[i][j] == 1) {
                todo.push({i, j});
                visited[i][j] = true;
                lvl[i][j] = 0;
            }
        }
    }

    bfs();

    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cout << lvl[i][j] << ' ';
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
        cout << '\n';
    }

    return 0;
}
