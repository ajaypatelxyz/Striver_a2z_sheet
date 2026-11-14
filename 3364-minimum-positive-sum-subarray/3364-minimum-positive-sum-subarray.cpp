class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        multiset<long long> st;
        long long mini = LLONG_MAX;

        for(int j = l; j <= n; j++){
            st.insert(prefix[j - l]);

            if(j - r - 1 >= 0){
                auto it = st.find(prefix[j - r - 1]);
                st.erase(it);
            }
            auto it = st.lower_bound(prefix[j]);
            
            if(it != st.begin()){
                --it;
                long long sum = prefix[j] - *it;
                mini = min(mini, sum);
            }
        }

        if(mini == LLONG_MAX) return -1;
        return mini;
    }
};