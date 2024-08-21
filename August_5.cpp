class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        
        // Count frequency of each string
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        
        string ans;
        
        // Find the k-th distinct string
        for(int i = 0; i < arr.size(); i++) {
            if(mp[arr[i]] == 1) {
                k--;
                if(k == 0) {
                    ans = arr[i];
                    break;
                }
            }
        }
        
        return k > 0 ? "" : ans;
    }
};
