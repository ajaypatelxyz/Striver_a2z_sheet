class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxiGCD(n);
        vector<int> prefixGCD(n);

        maxiGCD[0] = nums[0];
        prefixGCD[0] = gcd(maxiGCD[0], nums[0]);

        for(int i = 1; i < nums.size(); i++){
            maxiGCD[i] = max(nums[i], maxiGCD[i-1]);
            prefixGCD[i] = gcd(maxiGCD[i], nums[i]);
        }

        sort(prefixGCD.begin(), prefixGCD.end());
        vector<int> ans;
        int i = 0;
        int j = prefixGCD.size() - 1;
        while(i < j){
            int val = gcd(prefixGCD[i], prefixGCD[j]);
            ans.push_back(val);
            i++;
            j--;
        }

        long long sum = 0;
        for(int x: ans){
            sum += x;
        }
        return sum;
    }
};