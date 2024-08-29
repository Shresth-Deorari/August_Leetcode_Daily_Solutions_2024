class DSU{
    public:
    vector<int>parent;
    DSU(int n){
        parent.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }
        int get_parent(int u){
            if(parent[u] == u)return u;
            return parent[u] = get_parent(parent[u]);
        }
        void union_size(int u,int v){
            u = get_parent(u);
            v = get_parent(v);
            parent[u] = v;
        }
    };
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m = 0,n=0;
        for(auto i : stones){
            int x = i[0];
            int y = i[1];
            m = max(x,m);
            n = max(y,n);
        }
        DSU dsu(m+n+2);
        unordered_set<int>st;
        for(auto i : stones){
            int x = i[0];
            int y = i[1] + m + 1;
            dsu.union_size(x,y);
            st.insert(x);
            st.insert(y);
        }
        int comp = 0;
        for(auto i : st){
            if(dsu.parent[i]==i){
                comp++;
            }
        }
        return stones.size() - comp;
    }
};