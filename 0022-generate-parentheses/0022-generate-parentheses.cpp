class Solution {
public:
    void solve(int n, int low, int high, string curr, vector<string> &ans){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(low < n) solve(n, low+1, high, curr+'(', ans);
        if(high < low) solve(n, low, high+1, curr+')', ans);
    }
    
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> ans;
        solve(n, 0, 0, curr, ans);
        return ans;
    }
};