//Problem link - https://leetcode.com/problems/odd-even-linked-list/


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *oddHolder = head,*evenHolder = head->next,*evenHead = evenHolder;
        
        while(evenHolder && evenHolder->next)//there is need of rearrangements of links
        {
            oddHolder->next = evenHolder->next;
            oddHolder = oddHolder->next;
            evenHolder->next = oddHolder->next;
            evenHolder = evenHolder->next;
        }
        oddHolder->next = evenHead;
        
        return head;
    }
};
