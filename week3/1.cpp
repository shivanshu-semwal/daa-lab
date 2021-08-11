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

        int comp = 0, shifts = 0;

        for (int i = 1; i < n; i++) {
            int key = v[i];
            int j = i - 1;
            while (++comp && j >= 0 && key < v[j]) {
                v[j + 1] = v[j];
                shifts++;
                j--;
            }
            j++;
            v[j] = key;
        }
        
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        cout << "comparisions = " << comp << "\n";
        cout << "shifts = " << shifts << "\n";
    }
    return 0;
}