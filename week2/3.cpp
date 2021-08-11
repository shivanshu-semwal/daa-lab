#include <algorithm>
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
        sort(v.begin(), v.end());
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int find = key + v[i];
            int start = i + 1, end = n - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (v[mid] == find) {
                    count++;
                    break;
                } else if (v[mid] < find) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        cout << count << "\n";
    }
    return 0;
}