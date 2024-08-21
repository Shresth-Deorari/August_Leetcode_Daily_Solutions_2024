class Solution {
private:
    int f(const vector<vector<int>>&points,int i,int j,vector<vector<int>>&dp,const int &m,const int &n){
        if(i==m)return 0;
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        int temp = 0;
        for(int k = 0;k<n;k++){
            if(j==-1){
                temp = max(temp,points[i][k] + f(points,i+1,k,dp,m,n));
            }
            else if(points[i][k]>=abs(j-k)){
                temp = max(temp,points[i][k] - abs(j-k) + f(points,i+1,k,dp,m,n));
            }
        }
        return dp[i][j+1] = temp;
    }
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long>dp(n);
        for(int i = 0;i<n;i++)dp[i] = points[0][i];
        for(int i =1;i<m;i++){
            vector<long long>left(n);
            vector<long long>right(n);
            vector<long long>new_dp(n);
            left[0] = dp[0];
            right[n-1] = dp[n-1];
            for(int j = 1;j<n;j++){
                left[j] = max(left[j-1]-1,dp[j]);
            }
            for(int j= n-2;j>=0;j--){
                right[j] = max(right[j+1]-1,dp[j]);
            }
            for(int j = 0;j<n;j++){
                new_dp[j] = points[i][j] + max(right[j],left[j]);
            }
            dp = new_dp;
        }
        long long ans = INT_MIN;
        for(int j =0;j<n;j++){
            ans = max(dp[j],ans);
        }
        return ans;
    }
};