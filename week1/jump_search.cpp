/*
 * jump search
 */

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

        bool flag = false;
        int count = 0;

        int power = 0;
        while (++count && power < n && key >= v[power]) {
            if (key == v[power]) {
                flag = true;
                break;
            }
            power = (power == 0) ? 2 : power * 2;
        }
        if (!flag) {
            int start = power / 2;
            int end = min(power, n);
            if (end == 0) {
                flag = false;
            } else {
                for (int i = start + 1; i < end; i++) {
                    if (++count && v[i] == key) {
                        flag = true;
                        break;
                    }
                }
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
