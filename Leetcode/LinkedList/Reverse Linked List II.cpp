//Problem link - https://leetcode.com/problems/reverse-linked-list-ii/

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

/*
                            left = 2                           right = 4
E.g., list -> 1---------------->2---------------->3---------------->4---------------->5
            head            revHead                         endPointingPart        remPart
        pointingPart
*/
class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head,*prev = NULL,*next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;//No need to reverse anything
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *revHead = dummyHead,*remPart = NULL,*pointingPart,*endPointingPart=NULL,*temp = dummyHead;
        int count = 0;
        while(temp && !remPart)//once remPart is set, it means all pointers have been found
        {
            if(count==left) revHead = temp;
            else if(count==right) endPointingPart = temp;
            else if(count==left-1) pointingPart = temp;
            else if(count==right+1) remPart = temp;
            temp = temp->next;
            count++;
        }
        endPointingPart->next = NULL;//break the connection of end part which is to be reversed
        ListNode *origRevHead = revHead;
        revHead = reverseList(revHead);//reverse the part
        pointingPart->next = revHead;//there will be a pointing part if left is not the first node hence end of that part will now point to the head of reversed list
        origRevHead->next = remPart;//Now the end of reversed list(original head of that part which was to be reversed will now be the end of reversed part) has to point to the remaining unreversed list
        return dummyHead->next;
    }
};
