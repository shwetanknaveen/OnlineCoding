//Problem link - https://leetcode.com/problems/linked-list-cycle-ii/
//Video link - https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=38
//PROOF OF COLLISION POINT IN THE VIDEO -> from 10:44 onwards
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next)) return NULL;
        ListNode *slow,*fast;
        bool cycExist = false;
        slow = fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
            {
                cycExist = true;
                break;
            }
        }
        if(!cycExist) return NULL;
        slow = head;//reinitialise slow to head and move slow and fast with same pace
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
