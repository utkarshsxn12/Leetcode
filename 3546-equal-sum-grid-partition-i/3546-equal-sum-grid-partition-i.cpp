class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        for (auto &row : grid) {
            for (int val : row) {
                total += val;
            }
        }
        if (total % 2 != 0) return false;
        long long target = total / 2;
        long long curr = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                curr += grid[i][j];
            }
            if (curr == target) return true;
        }
        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }
        curr = 0;
        for (int j = 0; j < n - 1; j++) {
            curr += colSum[j];
            if (curr == target) return true;
        }
        return false;
    }
};