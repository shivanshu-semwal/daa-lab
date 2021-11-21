#include <bits/stdc++.h>
using namespace std;

bool isBipartiteUtil(vector<int> G[], int src, int colorArr[], int V) {
    colorArr[src] = 1; // set one color
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // self loop
        if (G[u][u] == 1) return false;
        for (int v = 0; v < V; ++v) {
            if (G[u][v] != 0 && colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u]; // assign opposite color
                q.push(v);
            } else if (G[u][v] != 0 && colorArr[v] == colorArr[u])
                return false; // edge with same color exist
        }
    }
    return true;
}

bool isBipartite(vector<int> G[], int V) {
    /* -1 -> no color, 1-> red color, 0 -> blue color */
    int colorArr[V];
    for (int i = 0; i < V; ++i) colorArr[i] = -1;
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (isBipartiteUtil(G, i, colorArr, V) == false)
                return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> G[n];
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            G[i].push_back(temp);
        }
    }
    if (isBipartite(G, n)) {
        cout << "Yes Bipartite\n";
    } else {
        cout << "Not Bipartite\n";
    }
    return 0;
}
