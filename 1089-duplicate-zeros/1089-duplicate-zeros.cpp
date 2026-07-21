class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);
        int j = 0;
        
        for(int i = 0; i < n && j < n; i++){
            temp[j] = arr[i];
            j++;
            if(arr[i] == 0 && j < n){
                temp[j] = 0;
                j++;
            }
        }
        arr = temp;
    }
};