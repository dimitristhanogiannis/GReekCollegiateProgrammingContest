#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> A[i][j];

    vector<Edge> edges;

    // Add edges between islands
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            edges.push_back({i, j, A[i][j]});
        }
    }

    // Add edges from super node (node N) to each island with cost = p(x)
    for(int i = 0; i < N; i++) {
        edges.push_back({N, i, A[i][i]});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(N+1); // N islands + 1 super node
    long long total_cost = 0;

    for(auto &e : edges) {
        if(dsu.unite(e.u, e.v)) {
            total_cost += e.w;
        }
    }

    cout << total_cost << "\n";
    return 0;
}