class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last(m, -1);
        int i = n - 1;
        int j = m - 1;
        while(i >= 0 && j >= 0){
            if(word1[i] == word2[j]){
                last[j] = i;
                j--;
            }
            i--;
        }

        j = 0;
        vector<int> ans;
        bool mismatchUsed = false;
        for(int i = 0; i < n; i++){
            if(j == m) break;

            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }else if(!mismatchUsed){
                if(j == m - 1 || i < last[j + 1]){
                    ans.push_back(i);
                    j++;
                    mismatchUsed = true;
                }
            }
        }

        if(j == m) return ans;
        return {};
    }
};