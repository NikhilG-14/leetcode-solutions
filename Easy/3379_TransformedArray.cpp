class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        // Result array to store the transformed values for each index
        vector<int> result(n, 0);

        // Traverse each index independently as required by the question
        for(int i = 0; i < n; i++) {

            // nums[i] represents how many steps to move:
            //  - positive -> move right
            //  - negative -> move left
            // Using modulo n to handle large shifts in circular array
            int shift = nums[i] % n;     

            // Calculate new index after moving 'shift' steps from index i
            // This works for both right (+) and left (-) movement
            int newIdx = (i + shift) % n;    

            // If newIdx becomes negative (left movement beyond start),
            // wrap it around to the end of the circular array
            if(newIdx < 0) {
                newIdx += n;
            }

            // Set result[i] to the value present at the landing index
            // as per the problem statement
            result[i] = nums[newIdx];
        }

        // Return the final transformed array
        return result;
    }
};
