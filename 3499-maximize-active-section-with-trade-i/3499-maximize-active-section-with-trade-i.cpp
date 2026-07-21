class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char ch: s){
            if(ch == '1') ones++;
        }

        string a = "1" + s + "1";
        vector<pair<char, int>> temp;
        for(int i = 0; i < a.length();){
            char ch = a[i];
            int count = 0;
            while(i < a.length() && a[i] == ch){
                count++;
                i++;
            }
            temp.push_back({ch, count});
        }

        int ans = ones;
        for(int i = 1; i < temp.size()-1; i++){
            if(temp[i].first == '1' && temp[i-1].first == '0' && temp[i+1].first == '0'){
                int gain = temp[i-1].second + temp[i+1].second;
                ans = max(ans, ones + gain);
            }
        }
        return ans;
    }
};