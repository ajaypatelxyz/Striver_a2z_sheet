class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;
    
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            }else{
                int inside = score;
                int before = st.top();
                st.pop();

                if(inside == 0){
                    score = before + 1;
                }else{
                    score = before + 2 * inside;
                }
            }
        }
        return score;
    }
};