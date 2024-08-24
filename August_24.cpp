class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        
        long long lowerBound = pow(10, len - 1) - 1;
        long long upperBound = pow(10, len) + 1;
        
        string prefix = n.substr(0, (len + 1) / 2);
        vector<long long> candidates;
        
        long long prefixNum = stoll(prefix);
        
        for (long long i = -1; i <= 1; ++i) {
            string newPrefix = to_string(prefixNum + i);
            string candidate;
            
            if (len % 2 == 0) {
                candidate = newPrefix + string(newPrefix.rbegin(), newPrefix.rend());
            } else { 
                candidate = newPrefix + string(newPrefix.rbegin() + 1, newPrefix.rend());
            }
            
            candidates.push_back(stoll(candidate));
        }
        
        candidates.push_back(lowerBound);
        candidates.push_back(upperBound);
                long long closest = -1;
        for (long long cand : candidates) {
            if (cand != num) {
                if (closest == -1 || abs(cand - num) < abs(closest - num) || (abs(cand - num) == abs(closest - num) && cand < closest)) {
                    closest = cand;
                }
            }
        }
        
        return to_string(closest);
    }
};
