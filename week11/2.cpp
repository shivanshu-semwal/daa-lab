#include <bits/stdc++.h>
using namespace std;

int memo(int i, int current, vector<vector<int>> &dp, vector<int> &coin, int n) {
    if (i == n) {
        return (current == 0);
    }
    if (current < 0)
        return 0;
    if (current == 0)
        return 1;
    if (dp[i][current] != -1)
        return dp[i][current];
    return dp[i][current] = memo(i + 1, current, dp, coin, n) +
                            memo(i, current - coin[i], dp, coin, n);
}
int main() {
    int n;
    cin >> n;
    int target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cin >> target;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << memo(0, target, dp, coins, n);
}