class Solution {
public:
    bool judgeCircle(string moves) {
        int down = 0, up = 0, left = 0, right = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'U'){
                up++;
            }else if(moves[i] == 'D'){
                down++;
            }else if(moves[i] == 'L'){
                left++;
            }else{
                right++;
            }
        }
        if((up == down) && (right == left)) return true;
        return false;
    }
};