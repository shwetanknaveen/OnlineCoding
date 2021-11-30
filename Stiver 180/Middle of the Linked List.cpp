//Problem link - https://leetcode.com/problems/middle-of-the-linked-list/

//Approach 1 -> By calculating length of linked list
class Solution {
public:
    int lengthOfList(ListNode *head)
    {
    int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int mid=lengthOfList(head)/2;
        while(mid--)
        {
            head=head->next;
        }
        return head;
    }
};

//Approach 2 -> Using two pointers
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head) return head;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)	//Always null check the pointer first if its next has to be checked
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

