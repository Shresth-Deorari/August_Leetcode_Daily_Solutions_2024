class Solution {
    int f(string & s,vector<vector<int>>&dp,int i,int j){
        if(i>j)return 0;
        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j] = 1 + f(s,dp,i+1,j);
        for(int k = i+1;k<=j;k++){
            if(s[i]==s[k])
            dp[i][j] = min(dp[i][j], f(s,dp,i,k-1) + f(s,dp,k+1,j));
        }
        return dp[i][j];
    }
public:
    int strangePrinter(string s) {
        int n= s.size();
        string reduced_s;
        reduced_s.push_back(s[0]);
        for(int i = 1;i<n;i++){
            if(s[i]!=s[i-1])reduced_s.push_back(s[i]);
        }
        // cout<<reduced_s<<endl;
        int m= reduced_s.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return f(reduced_s,dp,0,m-1);
   }
};