class Solution {
public:
    vector<int> nextSmallValue(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i = n-1; i >= 0; i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallValue(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < n; i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallValue(heights);
        vector<int> prev = prevSmallValue(heights);

        for(int i = 0; i < next.size(); i++){
            if(next[i] == -1){
                next[i] = next.size();
            }
        }

        int maxArea = INT_MIN;
        for(int i = 0; i < next.size(); i++){
            int width = next[i] - prev[i] - 1;
            int length = heights[i];

            int currArea = length * width;
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};