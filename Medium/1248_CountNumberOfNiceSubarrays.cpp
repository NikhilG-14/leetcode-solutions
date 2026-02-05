// Approach 1: Array: Time Complexity: O(n) & Space Complexity: O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // Map to store frequency of oddCount seen so far
        // key   -> oddCount
        // value -> number of times this oddCount has appeared
        unordered_map<int, int> mp;

        int result = 0;     // final count of subarrays
        int oddCount = 0;   // prefix count of odd numbers

        // Base case:
        // oddCount = 0 has occurred once before starting
        mp[oddCount] = 1;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            // If nums[i] is odd, increment oddCount
            oddCount += (nums[i] % 2);

            // Check if there exists a prefix with (oddCount - k)
            // That would form a subarray with exactly k odd numbers
            if(mp.count(oddCount - k)) {
                result += mp[oddCount - k];
            }

            // Store current oddCount in map
            mp[oddCount]++;
        }

        return result;
    }
};


// Approach 2: Sliding Window: More Optimized
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int oddCount = 0;   // number of odd elements in current window
        int prevCount = 0;  // number of valid subarrays ending at j
        int result = 0;     // final answer

        int i = 0;  // left pointer
        int j = 0;  // right pointer

        // Expand window using right pointer
        while(j < n) {

            // If current element is odd, update oddCount
            // Reset prevCount because window structure changes
            if(nums[j] % 2 != 0) {
                oddCount++;
                prevCount = 0;
            }

            // Shrink window from left while we have exactly k odd numbers
            while(oddCount == k) {

                // Every shift of i gives a new valid subarray
                prevCount++;

                // If left element is odd, reducing oddCount
                if(i < n && nums[i] % 2 == 1) {
                    oddCount--;
                }

                i++;
            }

            // Add number of valid subarrays ending at index j
            result += prevCount;

            // Move right pointer
            j++;
        }

        return result;
    }
};
