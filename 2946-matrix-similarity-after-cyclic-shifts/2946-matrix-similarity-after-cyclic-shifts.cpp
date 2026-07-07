class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k = k % m;

        vector<vector<int>> temp = mat;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i % 2 == 0){
                    int idx = (j-k+m)%m;
                    temp[i][idx] = mat[i][j];
                }else{
                    int idx2 = (j+k)%m;
                    temp[i][idx2] = mat[i][j];
                }
            }
        }
        if(mat == temp) return true;
        return false;
    }
};