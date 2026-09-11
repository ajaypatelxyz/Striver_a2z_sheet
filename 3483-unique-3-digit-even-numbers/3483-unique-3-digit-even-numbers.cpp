class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> ans;
        for(int i=0;i<n;i++){
            if(digits[i] == 0) continue;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                for(int k=0;k<n;k++){
                    if(k == i || k == j) continue;
                    int num = 100*digits[i] + 10*digits[j] + digits[k];
                    if(num % 2 == 0){
                        ans.insert(num);
                    }
                }
            }
        }
        return ans.size();
    }
};