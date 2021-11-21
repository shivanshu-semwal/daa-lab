#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int key;
        cin >> key;
        int count = 0;
        bool flag = false;
        for (int i = 0; i < v.size(); i++) {
            if (++count && v[i] == key) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "Present " << count << endl;
        } else {
            cout << "Not Present " << count << endl;
        }
    }
    return 0;
}
