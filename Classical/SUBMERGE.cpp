/*
 ~ Author    : @tridib_2003
 ~ Title     : SUBMERGE - Submerging Islands
 ~ Link      : https://www.spoj.com/problems/SUBMERGE/
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100005;

vector< vector<int> > adj;
set<int> ap;
bool vis[MAX_SIZE];
int dT[MAX_SIZE];
int lT[MAX_SIZE];
int p[MAX_SIZE];

void findAP(int u) {

    static int t = 0;
    int child = 0;

    vis[u] = true;
    dT[u] = lT[u] = t++;

    for (int i = 0; i < adj[u].size(); ++i) {

        int v = adj[u][i];
        if (!vis[v]) {

            ++child;
            p[v] = u;

            findAP(v);

            lT[u] = min(lT[u], lT[v]);

            if (p[u] == -1 && child > 1)
                ap.insert(u);
            if (p[u] != -1 && lT[v] >= dT[u])
                ap.insert(u);
        }
        else if (v != p[u])
            lT[u] = min(lT[u], dT[v]);
    }
}

int main() {

    int n, m;
    while (scanf("%d%d", &n, &m)) {

        if (!n && !m)
            break;

        adj.resize(n + 1);

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            vis[i] = false;
            dT[i] = -1;
            lT[i] = -1;
            p[i] = -1;
        }

        for (int i = 0; i < m; ++i) {
            int src, dest;
            scanf("%d%d", &src, &dest);
            adj[src].emplace_back(dest);
            adj[dest].emplace_back(src);
        }


        for (int i = 1; i <= n; ++i) {
            if (!vis[i])
                findAP(i);
        }

        printf("%d\n", ap.size());
        ap.clear();
    }

    return 0;
}