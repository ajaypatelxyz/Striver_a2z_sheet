class Solution {
public:
    vector<int> solveBits(int n){
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n+1; i++){
            int count = 0;
            int temp = i;
            while(temp != 0){
                int val = temp & 1;
                if(val) count++;
                temp = temp >> 1;
            }
            dp[i] = count;
        }
        return dp;
    }

    vector<int> countBits(int n) {
        vector<int> ans = solveBits(n);
        return ans;
    }
};