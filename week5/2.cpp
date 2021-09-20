#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    /* test cases */
    int t;
    cin >> t;

    while (t--) {
        /* array input */
        int n;
        cin >> n;
        int arr[n] = {0};
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int key;
        cin >> key;

        /* creating hashmap for the elements */

        unordered_map<int, int> m;
        bool found = false;
        
        for (int i = 0; i < n; i++) {

            /* element found */
            if (m.find(key - arr[i]) != m.end()) {
                found = true;
                cout << arr[i] << " " << (key - arr[i]) << ", ";
            }

            /* register it's presence */
            m[arr[i]]++;
        }

        if (!found) {
            cout << "No Such Pair Exist\n";
        } else {
            cout << "\n";
        }
    }
    return 0;
}