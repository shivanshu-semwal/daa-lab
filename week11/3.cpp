#include <bits/stdc++.h>
using namespace std;
int memo(int i, int current, vector<vector<int>> &dp, vector<int> arr, int n) {
    if (current == 0)
        return 1;
    if (current < 0)
        return 0;
    if (i == n)
        return 0;
    if (dp[i][current] != -1)
        return dp[i][current];
    return dp[i][current] = memo(i + 1, current - arr[i], dp, arr, n) ||
                            memo(i + 1, current, dp, arr, n);
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 2 == 1) {
        cout << "No" << endl;
    } else {
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
        if (memo(0, sum / 2, dp, arr, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}