class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
        }
        double maxi = 1;
        queue<pair<double,int>>q;
        q.push({1,start_node});
        vector<double>probabilities(n,0);
        while(!q.empty()){
            int curr = q.front().second;
            double prob = q.front().first;
            q.pop();
            for(auto i : adj[curr]){
                int next = i.first;
                double mult = i.second;
                double temp = mult*prob;
                if(temp>probabilities[next]){
                    probabilities[next] = temp;
                    q.push({temp,next});
                }
            }
        }
        return probabilities[end_node];
    }
};