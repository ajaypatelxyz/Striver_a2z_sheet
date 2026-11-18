class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for(int i = 1; i < s.size(); i += 2){
            if(s[i - 1] == '0' && s[i] == '1'){
                ans++;
            }else if(s[i - 1] == '1' && s[i] == '0'){
                ans++;
            }
        }
        return ans;
    }
};