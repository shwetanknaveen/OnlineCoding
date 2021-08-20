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
 
 //PROBLEM LINK - https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *root = new ListNode();
        if((!l1)&&(!l2)) return NULL;
        if((!l1)&&l2) return l2;
        if(l1&&(!l2)) return l1;
           if(l1->val<l2->val){
               root->val = l1->val;
               root->next = mergeTwoLists(l1->next,l2);
           }
           else{
               root->val = l2->val;
               root->next = mergeTwoLists(l1,l2->next);
           }
           return root;
           }
};
