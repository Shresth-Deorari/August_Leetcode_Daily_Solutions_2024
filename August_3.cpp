class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        
        // Count frequency of each element in target
        for(auto i : target) mp[i]++;
        
        unordered_map<int, int> mp2;

        // Count frequency of each element in arr and compare with target
        for(auto i : arr) {
            mp2[i]++;
            if(mp2[i] > mp[i]) return false;
        }
        
        return true;
    }
};
