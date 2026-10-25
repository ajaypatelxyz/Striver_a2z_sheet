class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int n, int m, bool &closed){
        if(r < 0 || c < 0 || r >= n || c >= m){
            closed = false;
            return;
        }
        if(grid[r][c] == 1){
            return;
        }
        grid[r][c] = 1;

        dfs(grid, r - 1, c, n, m, closed);  //UP
        dfs(grid, r + 1, c, n, m, closed);  //DOWN
        dfs(grid, r, c - 1, n, m, closed);  //LEFT
        dfs(grid, r, c + 1, n, m, closed);  //RIGHT
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    bool closed = true;

                    dfs(grid, i, j, n, m, closed);
                    if(closed){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};