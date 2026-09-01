class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int sr = 0, sc = 0;
        // give every litter an index
        int litterCount = 0;
        vector<vector<int>> litterId(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(classroom[i][j] == 'S'){
                    sr = i;
                    sc = j;
                }
                if(classroom[i][j] == 'L'){
                    litterId[i][j] = litterCount++;
                }
            }
        }

        // no litter
        if(litterCount == 0){
            return 0;
        }

        int totalMask = 1 << litterCount;
        int fullMask = totalMask - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>> (m, vector<vector<bool>> (energy + 1, vector<bool> (totalMask, false))));

        queue<tuple<int, int, int, int, int>> q;
        // push currect row, col, current energy, mask, moves
        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()){

            auto[r, c, currEnergy, mask, moves] = q.front();
            q.pop();

            // all litter collected
            if(mask == fullMask){
                return moves;
            }

            // if energy is 0 cannot move
            if(currEnergy == 0){
                continue;
            }
            for(int d = 0; d < 4; d++){

                int nr = r + dx[d];
                int nc = c + dy[d];

                // outside grid
                if(nr < 0 || nr >= n || nc < 0 || nc >= m){
                    continue;
                }

                // Obstacle
                if(classroom[nr][nc] == 'X'){
                    continue;
                }

                // 1 move cost
                int newEnergy = currEnergy - 1;
                // collect litter
                int newMask = mask;

                if(classroom[nr][nc] == 'L'){
                    int id = litterId[nr][nc];
                    newMask |= (1 << id);
                }

                // reset energy
                if(classroom[nr][nc] == 'R'){
                    newEnergy = energy;
                }

                if(!visited[nr][nc][newEnergy][newMask]){
                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({nr, nc, newEnergy, newMask, moves+1});
                }
            }
        }
        return -1;
    }
};