class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for(int i = 0; i < piles.size(); i++){
            int element = piles[i];
            maxHeap.push(element);
        }

        while(k != 0){
            int topElement = maxHeap.top();
            maxHeap.pop();

            topElement = topElement - floor(topElement/2);
            maxHeap.push(topElement);
            k--;
        }
        int sum = 0;
        while(!maxHeap.empty()){
            int elem = maxHeap.top();
            sum += elem;
            maxHeap.pop();
        }
        return sum;
    }
};