//Problem link - https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head,*prev=NULL,*next;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev = curr;
            curr=next;
        }
            
        return prev;
    }
};
