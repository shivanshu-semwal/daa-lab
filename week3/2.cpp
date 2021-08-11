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

        int comp = 0, swap = 0;

        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (comp++ && v[min] > v[j]) {
                    min = j;
                }
            }
            if (i != min) {
                int temp = v[min];
                v[min] = v[i];
                v[i] = temp;
                swap++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";

        cout << "comparisions = " << comp << "\n";
        cout << "swaps = " << swap << "\n";
    }
    return 0;
}
