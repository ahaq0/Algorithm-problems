/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        // so the iterative solution is the most efficient due to recursive stack being large
        // idea here is that we make a dummy node and then add to it from the new list

        ListNode dummy(INT_MIN);

        ListNode *pointerToDummy = &dummy;

        // we will iterative through both lists and when they're empty we'll add in the remaining portion
        while (l1 != nullptr && l2 != nullptr)
        {

            if (l1->val <= l2->val)
            {

                // add it to the new/merged list
                pointerToDummy->next = l1;
                l1 = l1->next;
            }
            else
            {
                pointerToDummy->next = l2;
                l2 = l2->next;
            }
            pointerToDummy = pointerToDummy->next;
        }

        if (l2 == nullptr && l1 != nullptr)
        {
            pointerToDummy->next = l1;
        }

        else if (l1 == nullptr && l2 != nullptr)
        {
            pointerToDummy->next = l2;
        }

        // we return the next pointer because the initial one is pointing to garbage
        return dummy.next;
    }
};