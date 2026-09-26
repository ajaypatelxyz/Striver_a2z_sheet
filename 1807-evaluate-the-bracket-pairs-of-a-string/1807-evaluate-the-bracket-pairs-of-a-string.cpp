class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(int i = 0; i < knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0;
        string ans = "";
        while(i < s.length()){
            if(s[i] != '('){
                ans += s[i];
                i++;
                continue;
            }else{
                i++;
                string key = "";
                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }
                if(mp.find(key) != mp.end()){
                    ans += mp[key];
                }else{
                    ans += '?';
                }
                i++;
            }
        }
        return ans;
    }
};