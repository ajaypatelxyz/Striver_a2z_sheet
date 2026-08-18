class Solution {
public:
    int solveStone(vector<int>& stoneValue, int left, int right, vector<vector<int>> &dp, vector<int> &prefix){
        if(left == right){
            return 0;
        }
        //answer already exists
        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int ans = 0;
        for(int mid = left; mid < right; mid++){
            int leftSum = prefix[mid + 1] - prefix[left];
            int rightSum = prefix[right + 1] - prefix[mid + 1];

            // //find leftSum
            // for(int i = left; i <= mid; i++){
            //     leftSum += stoneValue[i];
            // }
            // //find rightSum
            // for(int i = mid+1; i <= right; i++){
            //     rightSum += stoneValue[i];
            // }
            //left side is small
            if(leftSum < rightSum){
                ans = max(ans, leftSum + solveStone(stoneValue, left, mid, dp, prefix));
            }else if(rightSum < leftSum){
                //right side is small
                ans = max(ans, rightSum + solveStone(stoneValue, mid + 1, right, dp, prefix));
            }else{
                //both equal, alice choose
                ans = max(ans, leftSum + solveStone(stoneValue, left, mid, dp, prefix));
                ans = max(ans, rightSum + solveStone(stoneValue, mid + 1, right, dp, prefix));
            }
        }
        dp[left][right] = ans;
        return dp[left][right];
    }

    int stoneGameV(vector<int>& stoneValue) {
        int i = 0;
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int ans = solveStone(stoneValue, i, n - 1, dp, prefix);
        return ans;
    }
};