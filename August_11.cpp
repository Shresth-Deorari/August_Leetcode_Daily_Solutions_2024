class Solution {
bool disconnected(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    int comp = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) {
                comp++;
                vis[i][j] = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                
                while (!q.empty()) {
                    int curri = q.front().first;
                    int currj = q.front().second;
                    q.pop();
                    
                    for (auto dir : directions) {
                        int newi = curri + dir.first;
                        int newj = currj + dir.second;
                        
                        if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] == 1 && vis[newi][newj] == 0) {
                            vis[newi][newj] = 1;
                            q.push({newi, newj});
                        }
                    }
                }
            }
        }
    }
        return comp==1?false:true;
}
public:
    int minDays(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int comp = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) {
                comp++;
                vis[i][j] = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                
                while (!q.empty()) {
                    int curri = q.front().first;
                    int currj = q.front().second;
                    q.pop();
                    
                    for (auto dir : directions) {
                        int newi = curri + dir.first;
                        int newj = currj + dir.second;
                        
                        if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] == 1 && vis[newi][newj] == 0) {
                            vis[newi][newj] = 1;
                            q.push({newi, newj});
                        }
                    }
                }
            }
        }
    }
        if(comp>1 || comp ==0)return 0;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j] = 0;
                    if(disconnected(grid))return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};