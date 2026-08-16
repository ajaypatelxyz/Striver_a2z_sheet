class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for(int x: stones){
            cnt[x % 3]++;
        }
        //one of remainder 1 or 2 is missing
        if(cnt[1] == 0 || cnt[2] == 0){
            return max(cnt[1], cnt[2]) >= 3 && cnt[0] % 2 == 1;
        }
        // both 1 and 2 remainder exits
        if(cnt[0] % 2 == 0){
            return true;
        }
        return abs(cnt[1] - cnt[2]) >= 3;
    }
};