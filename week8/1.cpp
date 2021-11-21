#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int weight;
    int a, b;
    Edge(){};
    Edge(int aa, int bb, int w) {
        weight = w;
        a = aa;
        b = bb;
    }
    bool operator()(Edge &a, Edge &b) {
        return a.weight > b.weight;
    }
};

int primsMST(vector<vector<int>> &g) {
    set<int> tree;
    int n = g.size();
    // Min heap
    priority_queue<Edge, vector<Edge>, Edge> q;
    int mn = INT_MAX;
    Edge mini;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] != 0) {
                if (g[i][j] < mn) {
                    mn = g[i][j];
                    mini.a = i;
                    mini.b = j;
                    mini.weight = mn;
                }
            }
        }
    }
    int ans = 0;
    q.push(mini);
    while (!q.empty()) {
        if (tree.size() == n) break;
        Edge u = q.top();
        q.pop();
        int both = 0;
        if (tree.find(u.a) == tree.end()) {
            for (int i = 0; i < n; i++) {
                if (i == u.a or i == u.b) continue;
                if (g[i][u.a] != 0) {
                    Edge temp(i, u.a, g[i][u.a]);
                    q.push(temp);
                }
                if (g[u.a][i] != 0) {
                    Edge temp(u.a, i, g[u.a][i]);
                    q.push(temp);
                }
            }
            tree.insert(u.a);
            both++;
        }
        if (tree.find(u.b) == tree.end()) {
            for (int i = 0; i < n; i++) {
                if (i == u.b or i == u.a) continue;
                if (g[i][u.b] != 0) {
                    Edge temp(i, u.b, g[i][u.b]);
                    q.push(temp);
                }
                if (g[u.b][i] != 0) {
                    Edge temp(u.b, i, g[u.b][i]);
                    q.push(temp);
                }
            }
            tree.insert(u.b);
            both++;
        }
        if (both != 0) ans += u.weight;
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
    int ans = primsMST(g);
    cout << "Minimum Spanning Weight: ";
    cout << ans << '\n';
    return 0;
}
