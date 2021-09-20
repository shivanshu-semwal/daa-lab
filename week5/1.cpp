#include <iostream>

using namespace std;

int main() {

    /* no of test case */
    int t;
    cin >> t;

    while (t--) {

        /* length of array */
        int n;
        cin >> n;

        /* array to store */
        char a[n];
        int count[27] = {0};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            count[a[i] - 'a']++;
        }

        /* finding the maximum count index */
        int max_i = 0;
        for (int i = 0; i < 27; i++) {
            if (count[i] > count[max_i]) {
                max_i = i;
            }
        }
        if (count[max_i] == 1 || count[max_i] == 0) {
            cout << "No Duplicates Present\n";
        } else {
            cout << (char)(max_i+'a') << "-" << count[max_i] << "\n";
        }
    }

    return 0;
}