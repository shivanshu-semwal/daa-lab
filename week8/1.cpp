// given an undirected graph, find the minimum spanning tree using Prim's algorithm
#include <bits/stdc++.h>
using namespace std;
void minimum_spanning_tree(int n, int m, int **adj, int **adj_cost,
                           int *parent, int *key, int *visited) {
    int i, j, k, min, u, v;
    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    key[0] = 0;
    parent[0] = -1;
    for (i = 0; i < n - 1; i++) {
        min = INT_MAX;
        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && key[j] < min) {
                min = key[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && adj[u][j] && key[j] > adj[u][j]) {
                key[j] = adj[u][j];
                parent[j] = u;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d %d %d\n", parent[i] + 1, i + 1, adj_cost[parent[i]][i]);
        }
    }
}
int main() {
    int n, m, i, j, k, u, v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    int **adj = new int *[n];
    int **adj_cost = new int *[n];
    for (i = 0; i < n; i++) {
        adj[i] = new int[n];
        adj_cost[i] = new int[n];
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
            adj_cost[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++) {
        printf("Enter the edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        adj[u - 1][v - 1] = 1;
        adj_cost[u - 1][v - 1] = w;
        adj[v - 1][u - 1] = 1;
        adj_cost[v - 1][u - 1] = w;
    }
    int *parent = new int[n];
    int *key = new int[n];
    int *visited = new int[n];
    minimum_spanning_tree(n, m, adj, adj_cost, parent, key, visited);
    return 0;
}