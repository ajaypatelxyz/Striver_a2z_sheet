class Solution {
public:
    int maxDepth(string s) {
        int level = 0;
        int maxCount = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                level++;
                if(level > maxCount){
                    maxCount = level;
                }
            }else if(s[i] == ')'){
                level--;
            }
        }
        return maxCount;
    }
};