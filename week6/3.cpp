#include <bits/stdc++.h>
using namespace std;
//given a directed graph, find wethere a cycle exists or not
bool isCyclicUtil(int v, bool visited[], bool *recStack, vector<int> adj[]) {
    if (visited[v] == false) {
        //mark current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        //recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack, adj))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    //the node is not part of recursion stack
    recStack[v] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    // Mark all the vertices as not visited and not part of recursion stack
    bool visited[V];
    bool recStack[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    // Call the recursive helper function to detect cycle in different DFS trees
    for (int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack, adj))
            return true;
    return false;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << isCyclic(n, arr);
    return 0;
}