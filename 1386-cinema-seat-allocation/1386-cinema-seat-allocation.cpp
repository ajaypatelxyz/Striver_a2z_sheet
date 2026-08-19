class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        for(auto &seat: reservedSeats){
            reserved[seat[0]].insert(seat[1]);
        }

        int ans = 0;
        ans = (n - reserved.size()) * 2;
        for(auto &it: reserved){
            int row = it.first;

            unordered_set<int>& seats = it.second;
            bool left = true;
            bool middle = true;
            bool right = true;
            // check left block
            for(int s = 2; s <= 5; s++){
                if(seats.count(s)){
                    left = false;
                    break;
                }
            }
            //check middle block
            for(int s = 4; s <= 7; s++){
                if(seats.count(s)){
                    middle = false;
                    break;
                }
            }
            // check right block
            for(int s = 6; s <= 9; s++){
                if(seats.count(s)){
                    right = false;
                    break;
                }
            }
            //both left and right available
            if(left && right){
                ans += 2;
            }else if(left || middle || right){
                //atleast one block available
                ans += 1;
            }
        }
        return ans;
    }
};