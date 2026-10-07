class Solution {
public:
    void solve(string &s, vector<string> &ans, int i, string &currAns, int leftRemove, int rightRemove, int balance, bool prevDeleted){
        if(leftRemove + rightRemove > s.length() - i){
            return;
        }

        if(i == s.length()){
            if(leftRemove == 0 && rightRemove == 0 && balance == 0){
                ans.push_back(currAns);
            }
            return;
        }

        char ch = s[i];
        if(ch == '(' && leftRemove > 0){
            if(!(i > 0 && s[i] == s[i - 1] && !prevDeleted)){
                solve(s, ans, i + 1, currAns, leftRemove - 1, rightRemove, balance, true);
            }
        }else if(ch == ')' && rightRemove > 0){
            if(!(i > 0 && s[i] == s[i - 1] && !prevDeleted)){
                solve(s, ans, i + 1, currAns, leftRemove, rightRemove - 1, balance, true);
            }
        }

        if(ch == '('){
            currAns.push_back(ch);
            solve(s, ans, i + 1, currAns, leftRemove, rightRemove, balance + 1, false);
            currAns.pop_back();
        }else if(ch == ')'){
            if(balance > 0){
                currAns.push_back(ch);
                solve(s, ans, i + 1, currAns, leftRemove, rightRemove, balance - 1, false);
                currAns.pop_back();
            }
        }else{
            currAns.push_back(ch);
            solve(s, ans, i + 1, currAns, leftRemove, rightRemove, balance, false);
            currAns.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        for(char ch: s){
            if(ch == '('){
                leftRemove++;
            }else if(ch == ')'){
                if(leftRemove > 0){
                    leftRemove--;
                }else{
                    rightRemove++;
                }
            }
        }

        vector<string> ans;
        string currAns = "";
        int i = 0;

        solve(s, ans, i, currAns, leftRemove, rightRemove, 0, false);
        return ans;
    }
};