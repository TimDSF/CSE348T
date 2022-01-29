/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode *head, int k) {
        ListNode *prev = NULL;
        ListNode *trav = head;
        int count = 0;
        while(trav != NULL && (count % k != 0 || count == 0)) {
            count++;
            ListNode *temp = trav->next;
            trav->next = prev;
            prev = trav;
            trav = temp;
            if(count % k == 0) {
                head->next = reverseKGroup(trav, k);
            }   
        }
        
        if(count % k != 0){
            return revert(prev);
        }

        return prev;
    }
    
    
    ListNode* revert(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *trav = head;
         while(trav != NULL) {
            ListNode *temp = trav->next;
            trav->next = prev;
            prev = trav;
            trav = temp;  
        }
        return prev;
    }
};