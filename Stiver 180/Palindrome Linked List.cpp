//Problem link - https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* reverse(ListNode* node)
    {
        if(!node) return node;
        ListNode *prev = NULL,*curr = node,*next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow,*fast;
        slow = fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast)//when link length is odd fast reaches last element and fast->next 
                //becomes null. There slow is pointing to the middle element which
                //doesn't play role in palindrome hence we advance slow for once again.
        slow = slow->next;//now slow stores the head of the second half of the list
        
        slow = reverse(slow);//reverse the second half of the list
        
        while(slow && head)//compare the two halves
        {
            if(slow->val != head->val) return false;
            slow=slow->next;
            head = head->next;
        }
        return true;//default case is to return true after comparing both halves completely
    }
};
