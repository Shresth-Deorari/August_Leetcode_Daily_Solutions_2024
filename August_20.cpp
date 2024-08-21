class Solution {
    int f(vector<int>&piles,vector<vector<vector<int>>>&dp,int i,int M ,int n,bool chance){
        if(i==n)return 0;
        if(dp[i][M][chance]!=-1)return dp[i][M][chance];
        int ans = chance?-1:INT_MAX;
        for(int j = i;j<min(n,i+2*M);j++){
                int sum = piles[j] - (i>0?piles[i-1]:0);
                if(chance){
                    ans = max(ans,sum + f(piles,dp,j+1,max(M,j-i+1),n,!chance));
                }
                else{
                    ans = min(ans,f(piles,dp,j+1,max(M,j-i+1),n,!chance));
                }
        }
        return dp[i][M][chance] =ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n= piles.size();
        int M = 1;
        for(int i  = 1;i<n;i++){
            piles[i] += piles[i-1];
        }
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        bool chance = 1;
        return f(piles,dp,0,M,n,chance);
    }
};