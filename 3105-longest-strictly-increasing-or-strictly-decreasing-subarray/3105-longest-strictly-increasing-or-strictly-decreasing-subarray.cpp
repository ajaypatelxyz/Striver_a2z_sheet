class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longest = 0;
        int currInc = 1;
        int currDec = 1;
        for(int i = 1; i < nums.size(); i++){
            //Increasing order
            if(nums[i - 1] < nums[i]){
                currInc++;
            }else{
                longest = max(longest, currInc);
                currInc = 1;
            }

            //Decreasing order
            if(nums[i - 1] > nums[i]){
                currDec++;
            }else{
                longest = max(longest, currDec);
                currDec = 1;
            }
        }
        longest = max(longest, currInc);
        longest = max(longest, currDec);
        return longest;
    }
};