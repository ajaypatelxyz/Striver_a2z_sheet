class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            freq[ch - 'a']++;
        }

        string middle = "";
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 1){
                middle += char('a' + i);
                break;
            }
        }

        string left = "";
        for(int i = 0; i < 26; i++){
            left += string(freq[i]/2, char('a' + i));
        }
        string right = left;
        reverse(right.begin(), right.end());

        string ans = left + middle + right;
        return ans;
    }
};