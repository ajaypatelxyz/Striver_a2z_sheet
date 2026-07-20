class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(n*m == k) return grid;

        vector<int> val;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                val.push_back(grid[i][j]);
            }
        }
        
        vector<int> temp(val.size());
        for(int i = 0; i < val.size(); i++){
            int newIndex = (i + k) % val.size();
            temp[newIndex] = val[i];
        }
        vector<vector<int>> ans(n, vector<int> (m));
        int idx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = temp[idx];
                idx++;
            }
        }
        return ans;
    }
};