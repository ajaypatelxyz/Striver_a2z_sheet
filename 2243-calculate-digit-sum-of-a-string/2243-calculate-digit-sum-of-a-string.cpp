class Solution {
public:
    string digitSum(string s, int k) {
        string temp = s;
        while(temp.length() > k){
            int sum = 0;
            int len = 0;
            string dummy = "";
            for(int i = 0; i < temp.length(); i++){
                sum += temp[i] - '0';
                len++;
                if(len == k){
                    dummy += to_string(sum);
                    sum = 0;
                    len = 0;
                }
            }
            if(len > 0){
                dummy += to_string(sum);
            }
            temp = dummy;
        }
        return temp;
    }
};