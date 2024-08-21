class DSU {
    vector<int> size;
    vector<int> parent;

public:
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int a) {
        if(a != parent[a]) parent[a] = find(parent[a]);
        return parent[a];
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU dsu(n);

        // Compare all pairs of strings to determine similarity
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isSimilar(strs[i], strs[j])) dsu.union_sets(i, j);
            }
        }

        // Count unique groups
        unordered_set<int> unique_groups;
        for(int i = 0; i < n; i++) {
            unique_groups.insert(dsu.find(i));
        }
        return unique_groups.size();
    }

    bool isSimilar(const string& a, const string& b) {
        int diff_count = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) diff_count++;
            if(diff_count > 2) return false;
        }
        return diff_count == 2 || diff_count == 0;
    }
};
