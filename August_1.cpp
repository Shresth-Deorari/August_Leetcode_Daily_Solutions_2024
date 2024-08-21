class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;  // Initialize the count of seniors to 0

        // Iterate over each string in the details vector
        for (auto i : details) {
            // Extract the age from the string by converting the characters at index 11 and 12 to an integer
            int age = ((i[11] - '0') * 10 + i[12] - '0');

            // If the age is greater than 60, increment the count
            if (age > 60) ans++;
        }

        return ans;  // Return the total count of seniors
    }
};
