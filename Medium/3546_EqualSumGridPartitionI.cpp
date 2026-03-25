class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        
        // Step 1: Calculate total sum
        for (auto &row : grid) {
            for (int val : row) {
                total += val;
            }
        }
        
        // If total sum is odd → impossible
        if (total % 2 != 0) return false;
        
        long long half = total / 2;
        
        // Step 2: Try horizontal cuts
        long long sum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum == half) return true;
        }
        
        // Step 3: Try vertical cuts
        sum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
            }
            if (sum == half) return true;
        }
        
        return false;
    }
};