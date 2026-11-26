class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        
        int val = 10;
        int moves = 0;
        while(n >= val){
            n -= val;
            val--;
            moves++;
        }
        return moves % 2 == 1;
    }
};