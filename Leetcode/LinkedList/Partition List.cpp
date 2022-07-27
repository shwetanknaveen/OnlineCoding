//Problem link - https://leetcode.com/problems/partition-list/

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
This problem statement is not same as saying that all nodes smaller than x should be on its left and
all nodes larger should be on it's right rather what is required here is that all nodes smaller than x should be on left of all nodes greater than or equal to x maintaining the relative order in the list
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *dummyHeadLess = new ListNode();
        ListNode *dummyHeadGreater = new ListNode();
        ListNode *lessCopy = dummyHeadLess, *greaterCopy = dummyHeadGreater;
        while(head)//traverse the list
        {
            if(head->val<x)//if this value is smaller than x then take it on smaller part in order
            {
                lessCopy->next = head;
                lessCopy = lessCopy->next;
            }
            else//if this value is greater than x then take it on larger part in order
            {
                greaterCopy->next = head;
                greaterCopy = greaterCopy->next;
            }
            head = head->next;
        }
        greaterCopy->next = NULL;//Set the last node of greater part to NULL so as to mark the end of the list
        lessCopy->next = dummyHeadGreater->next;//end of smaller part should point to start of greater part
        return dummyHeadLess->next;//head of new list will be head of smaller part
    }
};
