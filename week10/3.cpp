#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &a, int key, bool first_occ) {
    int l = a.size();
    int b = 0, e = l - 1;
    while (b <= e) {
        int mid = (b + e) / 2;
        if (a[mid] == key) {
            if (first_occ) {
                if (mid == 0 || a[mid - 1] < a[mid])
                    return mid;
                else
                    e = mid - 1;
            } else {
                if (mid == l - 1 || a[mid + 1] > a[mid])
                    return mid;
                else
                    b = mid + 1;
            }
        } else if (a[mid] > key)
            e = mid - 1;
        else
            b = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int c = 0, i = 0;
    while (i < n) {
        int fo = binary_search(a, a[i], true), lo = binary_search(a, a[i], false);
        int nc = lo - fo + 1;
        if (nc > c)
            c = nc;
        i = lo + 1;
    }
    cout << (n * .5 < c ? "yes" : "no") << endl;
    if (n & 1)
        cout << a[n / 2] << endl;
    else
        cout << (a[n / 2] + a[n / 2 + 1]) / 2.0;
    return 0;
}