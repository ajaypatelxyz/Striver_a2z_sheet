class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> visit(101, false);
        for(int x: nums){
            visit[x] = true;
        }

        int ans = k;
        while(ans < 101){
            if(!visit[ans]){
                return ans;
            }
            ans += k;
        }
        return ans;
    }
};