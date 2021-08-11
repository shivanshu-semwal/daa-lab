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
        vector<int> ans;
        bool flag = false;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                // element to search in the location j+1 to n-1
                int key = v[i] + v[j];
                // using binary serach
                int start = j + 1, end = n - 1;
                while (start <= end) {
                    int mid = (start + end) / 2;
                    if (v[mid] == key) {
                        ans.push_back(i);
                        ans.push_back(j);
                        ans.push_back(mid);
                        flag = true;
                        break;
                    } else if (v[mid] < key) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }

        // printing result
        if (flag) {
            cout << ans[0]+1 << "," << ans[1]+1 << "," << ans[2]+1 << "\n";
        } else {
            cout << "No sequence found.\n";
        }
    }
    return 0;
}