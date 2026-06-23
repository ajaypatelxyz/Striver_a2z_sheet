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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        for(int i = 1; i < left; i++){
            temp = temp->next;
        }
        //Find first place from where we have to reverse
        ListNode* start = temp->next;
        //make 2nd node to find 2nd place 
        ListNode* end = start;
        for(int i = left; i < right; i++){
            end = end->next;
        }
        //got last node from where we have to reverse
        ListNode* newPart = end->next;
        //make next node null
        end->next = NULL;

        //reverse the node
        ListNode* rev = reverseLL(start);
        // join the node from reverse point
        temp->next = rev;
        // join last point of reverse node with remaining node
        start->next = newPart;
        return dummy->next;
    }
};