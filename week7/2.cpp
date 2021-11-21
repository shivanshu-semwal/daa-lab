#include <bits/stdc++.h>
using namespace std;

void calulate(vector<int> &pa, int i) {
    cout << i + 1 << " ";
    if (pa[i] >= 0)
        calulate(pa, pa[i]);
}

void find_path(int **graph, int m, int sour) {
    vector<int> dis(m, INT_MAX), pa(m, -1);
    dis[sour] = 0;
    for (int ki = 0; ki < m - 1; ki++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] != 0) {
                    if (dis[j] > dis[i] + graph[i][j]) {
                        dis[j] = dis[i] + graph[i][j];
                        pa[j] = i;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        calulate(pa, i);
        cout << ": " << dis[i] << endl;
    }
}

int main() {
    int m, source, ed;
    cin >> m;
    int **graph = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        graph[i] = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    cin >> source;
    find_path(graph, m, source - 1);
}