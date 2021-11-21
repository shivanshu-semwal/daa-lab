#include <bits/stdc++.h>
using namespace std;

int shortest_weigt(int **graph, int ver, int u, int v, int k) {
    if (k <= 0)
        return INT_MAX;
    if (k == 0 && u == v)
        return 0;
    if (k == 1 && graph[u][v] != INT_MAX)
        return graph[u][v];
    int res = INT_MAX;
    for (int i = 0; i < ver; i++) {
        if (graph[u][i] != 0 && u != i && v != i) {
            int recu = shortest_weigt(graph, ver, i, v, k - 1);
            if (recu != INT_MAX)
                res = min(res, graph[u][i] + recu);
        }
    }
    return res;
}

int main() {
    int ver, u, v, k, ans;
    cin >> ver;
    int **graph = (int **)malloc(ver * sizeof(int *));
    for (int i = 0; i < ver; i++)
        graph[i] = (int *)malloc(sizeof(int) * ver);
    for (int i = 0; i < ver; i++)
        for (int j = 0; j < ver; j++)
            cin >> graph[i][j];
    cin >> u >> v >> k;
    ans = shortest_weigt(graph, ver, u - 1, v - 1, k);
    cout << "Weight of shortest path from (" << u
         << "," << v << ") with " << k << " edges :" << ans;
}