/*
 * Given an array of nonnegative integers, design a linear algorithm and
 * implement it using a program to find whether given key element is persent in
 * the array or not. Also find the total number of comparisions for each input
 * case. Time complexity = O(n), where n is the size of the input
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
        int count = 0;
        bool flag = false;
        for (int i = 0; i < v.size(); i++) {
            if (++count && v[i] == key) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "Present " << count << endl;
        } else {
            cout << "Not Present " << count << endl;
        }
    }
    return 0;
}
