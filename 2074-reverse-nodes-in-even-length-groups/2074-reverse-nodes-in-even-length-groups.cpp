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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* previous = NULL;
        ListNode* curr = head;
        int groupSize = 1;
        while(curr != NULL){
            ListNode* temp = curr;
            int count = 0;
            while(temp != NULL && count < groupSize){
                temp = temp->next;
                count++;
            }

            if(count % 2 == 0){
                ListNode* groupStart = curr;
                ListNode* prev = NULL;
                ListNode* node = curr;
                for(int i = 0; i < count; i++){
                    ListNode* nextNode = node->next;
                    node->next = prev;
                    prev = node;
                    node = nextNode;
                }

                if(previous != NULL){
                    previous->next = prev;
                }else{
                    head = prev;
                }

                groupStart->next = node;
                previous = groupStart;
                curr = node;
            }else{
                for(int i = 0; i < count; i++){
                    previous = curr;
                    curr = curr->next;
                }
            }
            groupSize++;
        }
        return head;
    }
};