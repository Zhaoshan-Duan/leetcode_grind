// name: Zhaoshan Duan
// email: duan.zha@northeastern.edu
// Leetcode link: https://leetcode.com/problems/perfect-squares/description/

int min(int a, int b) {
    return (a<b)? a:b;
}
int numSquares(int n) {
    int dp[n+1];
    for (int i = 0; i < n+1; i++) dp[i] = n+1;
    dp[0] = 0;

    int square;
    for (int subproblem = 1; subproblem <= n; subproblem++)  {
        for (int s = 1; s <= subproblem; s++) {
            square = s * s;
            if (subproblem - square < 0) break;
            dp[subproblem] = min(dp[subproblem], 1 + dp[subproblem - square]);
        }
    }

    return dp[n];
}
