class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
    int n = s.size();

    // Frequency of characters in s
    vector<int> freq(26, 0);

    for(char ch : s) {
        freq[ch - 'a']++;
    }

    // temp = remaining characters while matching target
    vector<int> temp = freq;

    int best = -1;

    // Try to match target from left to right
    for(int i = 0; i < n; i++) {

        int curr = target[i] - 'a';

        // Can we make this position greater?
        for(int c = curr + 1; c < 26; c++) {
            if(temp[c] > 0) {
                best = i;
                break;
            }
        }

        // Cannot continue matching target
        if(temp[curr] == 0) {
            break;
        }

        temp[curr]--;
    }

    // No position can be made greater
    if(best == -1) {
        return "";
    }

    string ans = "";

    // Put target prefix before best
    for(int i = 0; i < best; i++) {
        ans += target[i];
        freq[target[i] - 'a']--;
    }

    // Put smallest character greater than target[best]
    int curr = target[best] - 'a';

    for(int c = curr + 1; c < 26; c++) {
        if(freq[c] > 0) {
            ans += char('a' + c);
            freq[c]--;
            break;
        }
    }

    // Put remaining characters in sorted order
    for(int c = 0; c < 26; c++) {
        while(freq[c] > 0) {
            ans += char('a' + c);
            freq[c]--;
        }
    }

    return ans;
}
};