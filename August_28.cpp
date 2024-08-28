class DSU {
    vector<int> size;
    vector<int> parent;
    
public:
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int get_parent(int u) {
        if(parent[u] == u) return u;
        return parent[u] = get_parent(parent[u]);
    }

    void union_size(int u, int v) {
        u = get_parent(u);
        v = get_parent(v);
        if(u != v) {
            if(size[u] >= size[v]) {
                size[u] += size[v];
                parent[v] = u;
            } else {
                size[v] += size[u];
                parent[u] = v;
            }
        }
    }
};

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        DSU dsu(m * n);
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    for(auto& dir : directions) {
                        int newi = i + dir.first;
                        int newj = j + dir.second;
                        if(newi >= 0 && newi < m && newj >= 0 && newj < n && grid2[newi][newj] == 1) {
                            dsu.union_size(i * n + j, newi * n + newj);
                        }
                    }
                }
            }
        }
        
        unordered_set<int> component_ids;
        vector<bool> is_sub_island(m * n, true);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1 && is_sub_island[i * n + j] == true) {
                    int parent_id = dsu.get_parent(i * n + j);
                    component_ids.insert(parent_id);
                    if(grid1[i][j] == 0) {
                        is_sub_island[parent_id] = false;
                    }
                }
            }
        }
        
        int count = 0;
        for(int id : component_ids) {
            if(is_sub_island[id]) {
                count++;
            }
        }
        
        return count;
    }
};
