class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int val = n;
        while(val != 0){
            int digit = val % 10;
            sum += digit;
            product *= digit;
            val = val/10;
        }
        int finalSum = sum + product;
        if(n % finalSum == 0) return true;
        return false;
    }
};