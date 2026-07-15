class Solution {
public:
    int gcdValue(int oddSum, int evenSum){
        while(evenSum != 0){
            int rem = oddSum % evenSum;
            oddSum = evenSum;
            evenSum = rem;
        }
        return oddSum;
    }

    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;
        for(int i = 1; i <= n*2; i++){
            if(i % 2 == 0){
                evenSum += i;
            }else{
                oddSum += i;
            }
        }

        int ans = gcdValue(oddSum, evenSum);
        return ans;
    }
};