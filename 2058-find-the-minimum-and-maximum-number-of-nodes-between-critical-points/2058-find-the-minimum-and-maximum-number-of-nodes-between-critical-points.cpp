/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL) return {-1, -1};

        ListNode* prev = head;
        head = head->next;
        ListNode* nextNode = head->next;

        int node = 2;
        vector<int> position;

        while(nextNode != NULL){
            if(head->val > prev->val && head->val > nextNode->val){
                position.push_back(node);
            }
            if(prev->val > head->val && head->val < nextNode->val){
                position.push_back(node);
            }
            prev = head;
            head = nextNode;
            nextNode = nextNode->next;
            node++;
        }

        int n = position.size();
        if(n < 2) return {-1, -1};

        int minDistance = INT_MAX;
        int maxDistance = INT_MIN;

        for(int i = 1; i < n; i++){
            minDistance = min(minDistance, position[i] - position[i-1]);
        }
        maxDistance = position[n - 1] - position[0];

        return {minDistance, maxDistance};
    }
};