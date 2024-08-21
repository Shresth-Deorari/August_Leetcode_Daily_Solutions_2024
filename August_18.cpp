static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    long long nthUglyNumber(int n) {
        long long ans;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        unordered_set<long long>st;
        pq.push(1);
        st.insert(1);
        int count = 0;
        while(count<n){
            long long curr= pq.top();
            pq.pop();
            count++;
            if(count==n)return curr;
            if(st.find(curr*2)==st.end()){
            pq.push(curr*2);
            st.insert(curr*2);
            }
            if(st.find(curr*3)==st.end()){
            pq.push(curr*3);
            st.insert(curr*3);
            }
            if(st.find(curr*5)==st.end()){
            pq.push(curr*5);
            st.insert(curr*5);
            }
        }
        return -1;
    }
};
