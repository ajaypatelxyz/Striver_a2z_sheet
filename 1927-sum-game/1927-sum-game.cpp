class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n/2;
        int q1 = 0, q2 = 0, sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            if(i < half){
                if(num[i] == '?') q1++;
                else sum1 += num[i] - '0';
            }else{
                if(num[i] == '?') q2++;
                else sum2 += num[i] - '0';
            }
        }
        if((q1 + q2) % 2 == 1){
            return true;
        }

        int diff = sum1 - sum2;
        int qDiff = q1 - q2;

        return diff != -9 * qDiff/2;
    }
};