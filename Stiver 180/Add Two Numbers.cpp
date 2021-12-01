//Problem link - https://leetcode.com/problems/add-two-numbers/

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
    
    void pushNode(ListNode *lastNode,int val)
    {
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = NULL;
        lastNode->next = newNode;   
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *headHolder = new ListNode();//it's next will point to the head of the answer linked list
        ListNode *lastNode = headHolder;
        int carry=0,sum = 0;
        while(l1 && l2)
        {
            
            sum = l1->val + l2->val + carry;
            pushNode(lastNode,sum%10);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            lastNode = lastNode->next;
            
        }
        
        while(l1)
        {
            sum = l1->val + carry;
            pushNode(lastNode,sum%10);
            carry = sum/10;
            l1 = l1->next;
            lastNode = lastNode->next;
        }
        while(l2)
        {
            sum = l2->val + carry;
            pushNode(lastNode,sum%10);
            carry = sum/10;
            l2 = l2->next;
            lastNode = lastNode->next;
        }
        if(carry) pushNode(lastNode,carry);//when both lists have exhausted but still there is carry   
        return headHolder->next;
    }
};
