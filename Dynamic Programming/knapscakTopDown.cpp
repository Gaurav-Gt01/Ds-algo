    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include <math.h>
    using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // Top Down knapSack
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    // initialization is same as the base case for memoization :
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            }
        }
    return dp[n][W];
}