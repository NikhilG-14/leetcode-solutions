class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Sort the array
        // After sorting, we can use a sliding window where
        // nums[i] = minimum element of the window
        // nums[j] = maximum element of the window
        sort(begin(nums), end(nums));

        int L = 1;              // Stores the length of the largest valid (balanced) subarray
        int maxEl = nums[0];    // Maximum element in current window
        int minEl = nums[0];    // Minimum element in current window
        int i = 0;              // Left pointer of sliding window
        int j = 0;              // Right pointer of sliding window

        // Step 2: Sliding window approach
        while(j < n) {
            // Current window's min and max
            minEl = nums[i];
            maxEl = nums[j];

            // If window is NOT balanced:
            // maxEl > k * minEl
            // move left pointer to reduce minEl effect
            while(i < j && maxEl > (long long) k * minEl) {
                i++;
                minEl = nums[i];
            }

            // Update maximum length of a valid balanced subarray
            L = max(L, j - i + 1);

            // Expand window from the right
            j++;
        }

        // Step 3: Minimum removals =
        // total elements - largest balanced subarray length
        return n - L;   // deletions
    }
};
