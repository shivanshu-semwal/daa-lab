#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> arr[], int source, int V, bool *visited) {
    visited[source] = true;
    for (int i = 0; i < V; i++) {
        if (arr[source][i] != 0 && !visited[i]) {
            // adjacent vertex
            dfs(arr, i, V, visited);
        }
    }
}

bool checkPath(vector<int> arr[], int V, int source, int destination) {
    bool visited[V];
    for (int i = 0; i < V; i++) visited[i] = false;
    dfs(arr, source, V, visited);
    return visited[destination];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr[n];
    /* input the adjacency matrix */
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
    int source, destination;
    cin >> source >> destination;
    if (checkPath(arr, n, source - 1, destination - 1)) {
        cout << "Yes Path Exists.\n";
    } else {
        cout << "No Such Path Exists.\n";
    }
    return 0;
}