#include <iostream>
#include <vector>

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

        int lb = 0, ub = 0;
        int start = 0, end = n - 1;

        while (start < end) {
            int mid = (start + end) / 2;
            if (v[mid] == key) {
                lb = mid;
                ub = mid + 1;
                for (int j = mid - 1; j >= 0 && v[j] == key; j--) lb--;
                for (int j = mid + 1; j < n && v[j] == key; j++) ub++;
                break;
            } else if (v[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (ub - lb > 0) {
            cout << key << " - " << ub-lb << "\n";
        }
    }
    return 0;
}