class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long maxi = max(need1, need2);
        long long mini = min(need1, need2);
        long long reqcost1 = 0;
        long long reqcost2 = 0;
        reqcost1 = maxi * costBoth;
        reqcost2 = mini * costBoth;
        if(mini == need2){
            long long required = need1 - need2;
            reqcost2 += required * cost1;
        }else{
            long long required = need2 - need1;
            reqcost2 += required * cost2;
        }
        long long reqcost3 = 1LL * cost1 * need1;
        reqcost3 += 1LL * cost2 * need2;

        return min(reqcost1, min(reqcost2, reqcost3));
    }
};