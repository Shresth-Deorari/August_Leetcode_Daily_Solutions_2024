class Solution {
private:
    void f(vector<int>&candidates,int target,int i,vector<vector<int>>&ans,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int j = i;j<candidates.size();j++){
            if(j!=i && candidates[j]==candidates[j-1])continue;
            if(candidates[j]<=target){
                temp.push_back(candidates[j]);
                f(candidates,target-candidates[j],j+1,ans,temp);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(candidates,target,0,ans,temp);
        return ans;
    }
};