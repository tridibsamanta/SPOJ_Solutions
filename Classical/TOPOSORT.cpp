/*
 ~ Author    : @tridib_2003
 ~ Title     : TOPOSORT - Topological Sorting
 ~ Link      : https://www.spoj.com/problems/TOPOSORT/
*/

#include<bits/stdc++.h>
using namespace std;

void getTaskOrdering(int V, vector<vector<int> > adj) {

    vector<int> indegree(V + 1, 0);
    for (int i = 1; i <= V; ++i) {
        for (int j = 0; j < adj[i].size(); ++j)
            ++indegree[adj[i][j]];
    }

    set<int> todo;
    for (int i = 1; i <= V; ++i) {
        if (indegree[i] == 0)
            todo.insert(i);
    }

    vector<int> res;
    while (!todo.empty()) {

        int cV = *(todo.begin());
        todo.erase(todo.begin());
        res.emplace_back(cV);

        for (int i = 0; i < adj[cV].size(); ++i) {
            if (--indegree[adj[cV][i]] == 0)
                todo.insert(adj[cV][i]);
        }
    }

    if (res.size() != V) {
        printf("Sandro fails.");
        return;
    }

    for (int i = 0; i < V; ++i)
        printf("%d ", res[i]);
}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int> > adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int src, dest;
        scanf("%d%d", &src, &dest);
        adj[src].emplace_back(dest);
    }

    getTaskOrdering(n, adj);

    return 0;
}
