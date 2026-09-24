class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        // int minIdx = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            string s = to_string(nums[i]);
            int sum = 0;
            for(int j = 0; j < s.length(); j++){
                sum += (s[j] - '0');
            }
            if(sum == i){
                return i;
            }
        }
        return -1;
    }
};