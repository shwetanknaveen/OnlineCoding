//Problem link - https://leetcode.com/problems/rotate-list/

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
    int length(ListNode *head)
    {
        ListNode *temp = head;
        if(!head) return 0;
        int count = 1;
        while(temp->next)
        {
            count++;
            temp = temp->next;
        }
        temp->next = head;//make the list circular
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !(head->next)) return head;
        int len = length(head);
        k = k%len;
        ListNode* newHead;
        int travel = len-k-1;
        while(travel--)
        {
            head = head->next;
        }
        newHead = head->next;//assign new head
        head->next = NULL;//break the connection which is pointing to it
        return newHead;
    }
};

