class Solution {
public:
    long long countCommas(long long n) {
        long long start = 1000;
        long long ans = 0;
        int commas = 1;
        while(start <= n){
            long long end = start * 1000 - 1;
            long long count = min(n, end) - start + 1;
            if(count > 0){
                ans += count * commas;
            }
            start *= 1000;
            commas++;
        }
        return ans;
    }
};