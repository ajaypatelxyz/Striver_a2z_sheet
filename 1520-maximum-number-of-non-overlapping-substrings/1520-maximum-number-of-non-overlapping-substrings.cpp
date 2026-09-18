class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> ans;

        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for(int i = 0; i < s.length(); i++){
            int index = s[i] - 'a';

            if(first[index] == -1){
                first[index] = i;
            }
            last[index] = i;
        }

        vector<pair<int, int>> intervals;
        for(int i = 0; i < s.length(); i++){
            if(i != first[s[i] - 'a']){
                continue;
            }
            int end = last[s[i] - 'a'];
            bool valid = true;
            for(int j = i; j <= end; j++){
                int index = s[j] - 'a';
                if(first[index] < i){
                    valid = false;
                    break;
                }
                end = max(end, last[index]);
            }
            if(valid){
                intervals.push_back({i, end});
            }
        }
        sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.second < b.second;
        });

        int prevEnd = -1;
        for(auto it: intervals){
            int start = it.first;
            int end = it.second;

            if(start > prevEnd){
                ans.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }
        return ans;
    }
};