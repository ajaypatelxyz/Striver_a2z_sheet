class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> val;

        for(int i = 0; i < n; i++){
            int temp = nums[i];
            int sum = 0;
            while(temp != 0){
                sum = sum + (temp % 10);
                temp = temp / 10;
            }
            val.push_back({sum, nums[i]});
        }
        
        vector<pair<int, int>> sorted = val;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++){
            pos[sorted[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swap = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] || pos[nums[i]] == i){
                continue;
            }

            int j = i;
            int cycleSize = 0;
            while(!visited[j]){
                visited[j] = true;
                j = pos[nums[j]];
                cycleSize++;
            }
            if(cycleSize > 1){
                swap += cycleSize - 1;
            }
        }
        return swap;
    }
};