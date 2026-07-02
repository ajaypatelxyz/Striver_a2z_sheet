class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0) return -1;
        if(k%5 == 0) return -1;

        int a = 1;
        for(int i=1;i<=k;i++){
            if(a%k == 0){
                return i;
            }
            a = (a*10+1)%k;
        }
        return -1;
    }
};