#include <iostream>

using namespace std;

int main() {

    /* first array */
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    /* second array */
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    return 0;
}