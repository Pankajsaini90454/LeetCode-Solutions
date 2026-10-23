class Solution {
private:
    int dp[501][501];
    
    int solve(int i, int rem, const vector<int>& cost, const vector<int>& time, int n) {
        if (rem <= 0) return 0;
        if (i == n) return 1e9;
        
        if (dp[i][rem] != -1) return dp[i][rem];
        
        int take = cost[i] + solve(i + 1, rem - time[i] - 1, cost, time, n);
        int skip = solve(i + 1, rem, cost, time, n);
        
        return dp[i][rem] = min(take, skip);
    }

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, cost, time, n);
    }
};