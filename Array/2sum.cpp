#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> arr, int target){
        unordered_map<int, int> mp;

        for(int i = 0; i < arr.size(); i++){
            int val = target - arr[i];
            auto it = mp.find(val);
            if(it != mp.end()){
                return {it->second, i};
            }
            mp[arr[i]] = i;
        }
        return {-1, -1};
    }
};
