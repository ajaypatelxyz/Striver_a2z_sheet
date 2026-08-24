class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n);
        prefix[0] = stones[0];
        for(int i = 1; i < n; i++){
            prefix[i] = stones[i] + prefix[i - 1];
        }

        //if alice take all stones
        int ans = prefix[n - 1];
        for(int i = n - 2; i >= 1; i--){
            ans = max(ans, prefix[i] - ans);
        }
        return ans;
    }
};