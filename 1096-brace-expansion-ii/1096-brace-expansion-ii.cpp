class Solution {
public:
    set<string> combine(set<string> &A, set<string> &B){
        set<string> ans;

        for(const string& x: A){
            for(const string& y: B){
                ans.insert(x + y);
            }
        }
        return ans;
    }

    set<string> parseExpression(string &s, int& i){
        set<string> ans = parseTerm(s, i);

        while(i < s.size() && s[i] == ','){
            i++;

            set<string> right = parseTerm(s, i);
            ans.insert(right.begin(), right.end());
        }
        return ans;
    }

    set<string> parseTerm(string &s, int &i){
        set<string> ans = {""};

        while(i < s.size() && s[i] != ',' && s[i] != '}'){
            set<string> curr;

            if(s[i] >= 'a' && s[i] <= 'z'){
                curr.insert(string(1, s[i]));
                i++;
            }else if(s[i] == '{'){
                i++;
                curr = parseExpression(s, i);
                i++;
            }
            ans = combine(ans, curr);
        }
        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parseExpression(expression, i);
        return vector<string>(result.begin(), result.end());
    }
};