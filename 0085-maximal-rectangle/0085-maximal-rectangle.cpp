class Solution {
public:
    int largestRectangleArea(vector<int> heights){
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int length = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i-st.top()-1;
                maxArea = max(maxArea, length*width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> height(m, 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};