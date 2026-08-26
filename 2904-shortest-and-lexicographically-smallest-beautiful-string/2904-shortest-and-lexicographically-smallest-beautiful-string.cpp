class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // deque<string> dq;
        // for(int i = 0; i < s.length(); i++){
        //     if(!dq.empty() && (dq.front() == '1' || dq.front() == '0') && count == k){
        //         dq.pop_front();
        //     }else{
        //         if(s[i] == '1') count++;
        //         dq.push_back(s[i]);
        //     }
        // }
        int left = 0;
        int right = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;
        int end = 0;
        bool found = false;
        while(right < s.length()){
            if(s[right] == '1'){
                count++;
            }
            while(count == k){
                int len = right - left + 1;

                if(len < minLen || (len == minLen && s.substr(left, len) < s.substr(start, minLen))){
                    minLen = len;
                    start = left;
                    end = right;
                    found = true;
                }
                if(s[left] == '1'){
                    count--;
                }
                left++;
            }
            right++;
        }

        if(!found) return "";
        return s.substr(start, end - start + 1);
    }
};