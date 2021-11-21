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

        int start = 0, end = n - 1;
        int mid = (start + end) / 2;

        bool flag = false;
        int count = 0;
        while (start <= end) {
            mid = (start + end) / 2;
            if (++count && v[mid] == key) {
                flag = true;
                break;
            } else if (v[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (flag) {
            cout << "Present " << count << "\n";
        } else {
            cout << "Not Present " << count << "\n";
        }
    }
    return 0;
}
