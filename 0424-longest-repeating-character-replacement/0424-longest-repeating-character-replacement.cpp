class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, right = 0;
        int maxCount = 0;
        int maxLen = 0;

        while(right < s.size()){
            freq[s[right] - 'A']++;

            maxCount = max(maxCount, freq[s[right] - 'A']);
            if((right - left + 1) - maxCount > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, (right - left + 1));
            right++;
        }
        return maxLen;
    }
};