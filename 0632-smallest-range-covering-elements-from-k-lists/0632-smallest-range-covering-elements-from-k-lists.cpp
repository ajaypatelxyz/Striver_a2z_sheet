class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int data, int rIdx, int cIdx){
        this->data = data;
        this->rowIndex = rIdx;
        this->colIndex = cIdx;
    }
};

class compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;

        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int element = nums[i][0];
            int row = i;
            int col = 0;
            Info* temp = new Info(element, row, col);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!pq.empty()){
            Info* topNode = pq.top();
            int topData = topNode->data;
            int topRow = topNode->rowIndex;
            int topCol = topNode->colIndex;
            pq.pop();

            mini = topData;
            if((maxi - mini) < (ansEnd - ansStart)){
                ansStart = mini;
                ansEnd = maxi;
            }

            if(topCol + 1 < nums[topRow].size()){
                int newElement = nums[topRow][topCol+1];
                maxi = max(maxi, newElement);
                Info* newInfo = new Info(newElement, topRow, topCol+1);
                pq.push(newInfo);
            }else{
                break;
            }
        }
        return {ansStart, ansEnd};
    }
};