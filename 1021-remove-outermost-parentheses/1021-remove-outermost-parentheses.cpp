class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int level = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                level++;
                if(level > 1){
                    ans += '(';
                }
            }else{
                level--;
                if(level > 0){
                    ans += ')';
                }
            }
        }
        return ans;
    }
};