class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        int x = 0;
        int y = 1;
        if(n == 1) return y;
        if(n == 2) return x + y;
        int z = 1;
        int sum = x + y + z;
        for(int i = 3; i < n; i++){
            x = y;
            y = z;
            z = sum;
            sum = (x + y + z);
        }
        return sum;
    }
};