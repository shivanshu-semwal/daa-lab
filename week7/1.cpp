#include <bits/stdc++.h>
using namespace std;

int bellman_ford(int **graph, int source, int destination, int vertices) {
    int dist[vertices];
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < vertices; j++) {
            for (int k = 0; k < vertices; k++) {
                if (dist[j] != INT_MAX && graph[j][k] != 0 && dist[j] + graph[j][k] < dist[k]) {
                    dist[k] = dist[j] + graph[j][k];
                }
            }
        }
    }
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[j] != INT_MAX && graph[j][i] != 0 && dist[j] + graph[j][i] < dist[i]) {
                return -1;
            }
        }
    }
    return dist[destination];
}
int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    int **graph = new int *[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    int source, destination;
    cin >> source >> destination;
    int ans = bellman_ford(graph, source, destination, vertices);
    if (ans == INT_MAX) {
        cout << "-1";
    } else {
        cout << ans;
    }
    return 0;
}