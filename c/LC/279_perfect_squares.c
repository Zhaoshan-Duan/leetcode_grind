// name: Zhaoshan Duan 
// email: duan.zha@northeastern.edu
// Leetcode link: https://leetcode.com/problems/perfect-squares/description/ 
int min(int a, int b) {
    return (a < b) ? a: b;
}

int numSquares(int n) {
    // store minimum number of perfect squares requried to sum up from 0 to n
    int dp[n+1];

    // it takes 0 perfect squares to sum up to 0
    dp[0] = 0;

    // iterate from 1 to n
    for (int i = 1; i < n+1; i++) { 
        // initalize to the maximum possible number of perfect sqaures sum up to this number
        dp[i] = i;
        
        // iterate through all the perfect squares less than or equal to the current number
        for (int s = 1; s < i + 1; s++) {
            int square = s * s;
            if (i - square < 0) break;
            
            // for each square, calcuate the minimum of dp[i] and 1 + dp[i - square]
            dp[i] = min(dp[i], 1 + dp[i - square]);
        }
    }
    return dp[n];
}
