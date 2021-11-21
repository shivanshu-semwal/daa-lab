#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> e;
    UF(int n) { e.assign(n, -1); }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

struct Edge {
    int weight;
    int a, b;
    Edge(int aa, int bb, int w) {
        weight = w;
        a = aa;
        b = bb;
    }
};

int kruskalsMST(vector<vector<int>> &g) {
    int n = g.size();
    UF uf(n + 1);
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 0) continue;
            Edge temp(i, j, g[i][j]);
            edges.push_back(temp);
        }
    }
    sort(edges.begin(), edges.end(), [&](Edge &a, Edge &b) {
        return a.weight < b.weight;
    });
    int ans = 0;
    int c = 0;
    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].weight;
        if (!uf.sameSet(a, b)) {
            ans += w;
            uf.join(a, b);
            c++;
        }
        if (c == n - 1) break;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    int ans = kruskalsMST(g);
    cout << "Minimum Spanning Weight: ";
    cout << ans << '\n';
    return 0;
}
