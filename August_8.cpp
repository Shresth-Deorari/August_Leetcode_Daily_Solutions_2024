class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int i = rStart, j = cStart;
        int step = 1;
        int total = rows * cols;
        int count = 0;

        // Generate spiral order starting from (rStart, cStart)
        while(count != total) {
            int temp = step;

            // Move right
            while(temp--) {
                if(j >= 0 && j < cols && i >= 0 && i < rows) {
                    count++;
                    ans.push_back({i, j});
                }
                j++;
            }

            temp = step;

            // Move down
            while(temp--) {
                if(j >= 0 && j < cols && i >= 0 && i < rows) {
                    count++;
                    ans.push_back({i, j});
                }
                i++;
            }

            step++;
            temp = step;

            // Move left
            while(temp--) {
                if(j >= 0 && j < cols && i >= 0 && i < rows) {
                    count++;
                    ans.push_back({i, j});
                }
                j--;
            }

            temp = step;

            // Move up
            while(temp--) {
                if(j >= 0 && j < cols && i >= 0 && i < rows) {
                    count++;
                    ans.push_back({i, j});
                }
                i--;
            }

            step++;
        }
        return ans;
    }
};
