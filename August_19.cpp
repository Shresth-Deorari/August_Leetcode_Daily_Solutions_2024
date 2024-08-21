class Solution {
private:
    int f(int n,int size,vector<vector<int>>&dp,int i){
        if(size>n)return 1e9;
        if(size==n)return 0;
        if(dp[n][i]!=-1)return dp[n][i];
        int copy = 1e9,paste = 1e9;
        if(size>1 && 2*size<=n)copy = 2+f(n,2*size,dp,size);
        if(n-size>=i)paste = 1 + f(n,size+i,dp,i);
        return dp[n][i] = min(copy,paste);
    }
public:
    int minSteps(int n) {
        if(n==1)return 0;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return 1 + f(n,1,dp,1);
        int factor = 2;
        int ans = 0;
        while(n>1){
            while(n%factor==0){
                ans += factor;
                n /= factor;
            }
            factor++;
        }
        return ans;
    }
};