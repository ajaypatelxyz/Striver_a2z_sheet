class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 1; i <= s.length(); i++){
            int val = 26 - (s[i-1] - 'a');
            int mul = val * i;
            sum += mul;
        }
        return sum;
    }
};