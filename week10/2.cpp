#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0];
        v[i][2] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i][1];
    }
    sort(v.begin(), v.end(), [&](vector<int> a, vector<int> b) {
        if (a[1] == b[2])
            return a[0] < b[0];
        return a[1] < b[1];
    });
    priority_queue<pair<int, int>> maxheap;
    int current_time = 0;
    vector<int> selected(n, 0);
    for (int i = 0; i < n; i++) {
        if (current_time + v[i][0] <= v[i][1]) {
            current_time += v[i][0];
            maxheap.push({v[i][0], v[i][2]});
            selected[v[i][2]] = 1;
        } else if (maxheap.size()) {
            if (current_time - maxheap.top().first + v[i][0] <= v[i][1] &&
                maxheap.top().first > v[i][0]) {
                selected[maxheap.top().second] = 0;
                maxheap.pop();
                current_time = current_time - maxheap.top().first + v[i][0];
                selected[v[i][2]] = 1;
                maxheap.push({v[i][0], v[i][2]});
            }
        }
    }
    int total = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        total += selected[i];
        if (selected[i]) ans.push_back(i + 1);
    }
    cout << "Max number of tasks = " << total << endl
         << "Selected task numbers : ";
    for (int i : ans)
        cout << i << ' ';
}