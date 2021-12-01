//Problem link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow,*fast,*temp;
        
        ListNode *holdHead = new ListNode();
        holdHead->next = head;
        slow = fast = holdHead;//Initialise the slow and fast before the head
        
        while(n--)//fast pointer should be ahead of slow pointer by n nodes
            fast = fast->next;
        while(fast->next != NULL)//fast will go upto end node and then slow->next will be pointing the node which is to be deleted
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return holdHead->next;
    }
};

/*
free() function in C++ deallocates a block of memory previously allocated using calloc, malloc or realloc functions,on the
 heap making it available for further allocations. So here calling it on slow->next will throw an error
*/
