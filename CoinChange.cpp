long long int solve(int i,int n,  int coins[], int sum, vector<vector<long long int>> &dp){
        if(sum == 0) {
            return 1;
        }
        if(i == n) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        long long int a = solve(i+1,n, coins, sum, dp);
        long long int b = 0;
        if(coins[i] <= sum){
            b = solve(i, n, coins, sum - coins[i], dp);
        }
        return dp[i][sum] = a+b;
    }
  public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1, -1));
        return solve(0, N, coins, sum, dp);
    }
};
