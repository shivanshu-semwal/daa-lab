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

        bool flag = true;

        for (int i = 1; i < n; i++) {
            int key = v[i];
            int j = i - 1;
            while (j >= 0 && key < v[j]) {
                v[j + 1] = v[j];
                j--;
            }
            j++;
            v[j] = key;
            if (v[j - 1] == v[j]) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}