class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        sort(nums.begin(),nums.end());
        int high = nums[n-1] - nums[0];
        while(low<=high){
            int mid = ( low+high)/2;
            int count = 0;
            int left = 0;
            for(int i= 1;i<n;i++){
                while(nums[i]-nums[left] > mid){
                    left++;
                }
                count+= i - left;
            }
            if(count<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};