#include <bits/stdc++.h>
using namespace std;

int fp(vector<int> p, int i) {
    if (p[i] < 0)
        return i;
    return fp(p, p[i]);
}
bool unionbyweig(vector<int> &p, int u, int v) {
    int pu = fp(p, u);
    int pv = fp(p, v);
    if (pu != pv) {
        if (p[pu] <= p[pv]) {
            p[pu] += p[pv];
            p[pv] = pu;
        } else {
            p[pv] += p[pu];
            p[pu] = pv;
        }
        return true;
    }
    return false;
}

int kruskal(vector<vector<int>> &v, int n) {
    int ans = 0;
    vector<pair<int, pair<int, int>>> g;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (v[i][j] != 0)
                g.push_back(make_pair(v[i][j], make_pair(i, j)));
    sort(g.begin(), g.end(), greater<pair<int, pair<int, int>>>());
    vector<int> p(n, -1);
    for (auto i : g) {
        int u = i.second.first;
        int v = i.second.second;
        int w = i.first;
        if (unionbyweig(p, u, v))
            ans = ans + w;
    }
    return ans;
}

int main() {
    int n, t;
    cin >> n;
    vector<vector<int>> v;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.clear();
        for (int j = 0; j < n; j++) {
            cin >> t;
            vec.push_back(t);
        }
        v.push_back(vec);
    }
    cout << "Maximum spanning weight : " << kruskal(v, n);
}