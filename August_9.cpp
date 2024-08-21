class Solution {
private:
    bool check(int i, int j, vector<vector<int>>& grid) {
        unordered_set<int> st;
        vector<int> col(3, 0);
        vector<int> row(3, 0);
        int left_diag = 0;
        int right_diag = 0;
        int maxi = 0;

        // Check if the 3x3 grid is a magic square
        for(int a = i; a < i + 3; a++) {
            for(int b = j; b < j + 3; b++) {
                maxi = max(maxi, grid[a][b]);
                row[a - i] += grid[a][b];
                col[b - j] += grid[a][b];
                st.insert(grid[a][b]);
                if(a - i == b - j) left_diag += grid[a][b];
                if((a - i) + (b - j) == 2) right_diag += grid[a][b];
            }
        }

        if(st.size() != 9 || maxi != 9) return false;
        if(left_diag == right_diag && right_diag == row[0] && row[0] == row[1] && row[1] == row[2] && row[2] == col[0] && col[0] == col[1] && col[1] == col[2]) return true;
        return false;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m < 3 || n < 3) return 0;
        int ans = 0;

        // Iterate through each possible 3x3 grid and check if it's a magic square
        for(int i = 0; i < m - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                if(check(i, j, grid)) ans++;
            }
        }
        return ans;
    }
};
