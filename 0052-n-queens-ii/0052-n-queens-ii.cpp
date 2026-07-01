class Solution {
public:
    bool isValid(int row, int col, vector<string>& board, int n){
        int newRow = row;
        int newCol = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = newRow;
        col = newCol;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = newRow;
        col = newCol;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int n, vector<vector<string>> &ans, vector<string> &board, int col){
        if(col >= n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isValid(row, col, board, n)){
                board[row][col] = 'Q';
                solve(n, ans, board, col+1);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        int col = 0;
        solve(n, ans, board, col);
        return ans.size();
    }
};