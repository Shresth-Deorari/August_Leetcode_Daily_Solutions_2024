class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequency(26, 0);

        // Count frequency of each letter
        for(auto i : word) frequency[i - 'a']++;
        
        sort(frequency.begin(), frequency.end(), greater<int>());
        int counter = -1;
        int push = 0, ans = 0;

        // Calculate the minimum number of pushes required
        for(auto i : frequency) {
            counter++;
            if(counter % 8 == 0) {
                push++;
            }
            ans += push * i;
        }

        return ans;
    }
};
