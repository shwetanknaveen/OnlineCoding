//Problem link - https://leetcode.com/problems/sort-list/

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
    int getLength(ListNode *head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
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
    ListNode* sortList(ListNode* head) //T(n) = 2T(n/2) + 3(O(n)) = nlog(n)
    {
        int len = getLength(head);//O(n)
        if(len<2) return head;//A list of length shorter than 2 need not be sorted
        ListNode *lis1 = head,*lis2;
        int lenOfList1 = len/2;//break the list in two halves
        for(int i=0;i<lenOfList1-1;i++)
        {
            head = head->next;
        }
        lis2 = head->next;
        head->next = NULL;//break the second list from first list
        
        ListNode *sortedList1 = sortList(lis1);//sort these lists individually -> T(n/2)
        ListNode *sortedList2 = sortList(lis2);
        
        return mergeTwo(sortedList1,sortedList2);//merge the two lists -> O(n)
    }
};
