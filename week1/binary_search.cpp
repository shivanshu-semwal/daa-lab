/*
 * Given an already shorted array of positive numbers, design an algorithm and
 * implement it using a program to find whether given key element is presnet in
 * the array or not. Also, find the total number of comparsions for each input
 * case/ Time complexity = O(n*log(n)), where n is the size of input).
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

        int start = 0, end = n - 1;
        int mid = (start + end) / 2;

        bool flag = false;
        int count = 0;
        while (start <= end) {
            mid = (start + end) / 2;
            if (++count && v[mid] == key) {
                flag = true;
                break;
            } else if (v[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
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
