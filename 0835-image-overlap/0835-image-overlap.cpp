class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        for(int row = -(n - 1); row <= n - 1; row++){
            for(int col = -(n - 1); col <= n - 1; col++){

                int countOne = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        int newRow = i + row;
                        int newCol = j + col;

                        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n){
                            if(img2[i][j] == 1 && img1[newRow][newCol] == 1){
                                countOne++;
                            }
                        }
                    }
                }
                ans = max(ans, countOne);
            }
        }
        return ans;
    }
};