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
    // For this solution we use 2 pointers to create a gap size of n
    // Once that gap is created, we can simply move both pointers forward one until we hit
    // the end on the 2nd one. This will allow us to reach the end.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        // We start out with a new pointer to check where to begin
        ListNode * begin = new ListNode(0);
        ListNode * fast = begin;
        ListNode * slow = begin;
        begin->next = head;
        int count = 0;
        // We move the fast pointer to be ahead of the slower pointer by N
        while(count < n+ 1)
        {
            fast = fast->next;
            count++;
        }
        
        
        // We move the pointers at the end to skip the nth pointer
        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        // We skip the pointer to be deleted
        slow->next = slow->next->next;
        return begin->next;
    }
    
  
};