class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;

        // Count the number of 1s in the array
        for(auto i : nums) if(i) ones++;
        
        int swaps = INT_MAX;
        int zero = 0;

        // Count the number of 0s in the first window of size 'ones'
        for(int i = 0; i < ones; i++) {
            if(nums[i] == 0) zero++;
        }
        
        // Slide the window across the array and compute the minimum number of swaps
        for(int i = 0; i < n; i++) {
            swaps = min(swaps, zero);

            // Update zero count for the new window
            if(nums[(i + ones) % n] == 0) zero++;
            if(nums[i] == 0) zero--;
        }

        return swaps;
    }
};
