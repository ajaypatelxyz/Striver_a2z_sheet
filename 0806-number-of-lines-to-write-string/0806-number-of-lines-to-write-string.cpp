class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int word = 0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int val = widths[ch - 'a'];
            if(word+val > 100){
                line++;
                word = val;
            }else{
                word += val;
            }
        }
        return {line, word};
    }
};