//Problem link - https://leetcode.com/problems/merge-k-sorted-lists/
//See "Striver180/Flatterning a Linked List"

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
    ListNode *mergeTwo(ListNode *lis1,ListNode *lis2)
    {
        if(!lis1) return lis2;
        if(!lis2) return lis1;
        ListNode *head;
        if(lis1->val<lis2->val)
        {
            head = lis1;
            lis1 = lis1->next;
        }
        else
        {
            head = lis2;
            lis2 = lis2->next;
        }
        ListNode *temp = head;
        while(lis1 && lis2)
        {
            if(lis1->val<lis2->val)
            {
                temp->next = lis1;
                lis1 = lis1->next;
            }
            else
            {
                temp->next = lis2;
                lis2 = lis2->next;
            }
            temp = temp->next;
        }
        if(lis1) temp->next = lis1;
        else temp->next = lis2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *ans = NULL;
        for(auto lis:lists)
            ans = mergeTwo(ans,lis);
        return ans;
    }
};
