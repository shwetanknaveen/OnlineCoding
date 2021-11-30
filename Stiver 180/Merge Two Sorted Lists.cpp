//Problem link - https://leetcode.com/problems/merge-two-sorted-lists/

//Approach 1 - Iterative approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head,*temp;
        if(!list1) return list2;//if list1 is empty then return list2
        if(!list2) return list1;//if list2 is empty then return list1
        if(list1->val < list2->val)//whichever list's first value is smaller is assigned as head of merged list
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }
        temp = head;//temp will traverse and head will remain pointing to the head of the merged list
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;//once merged list gets minimum node from either of the lists, it advances
        }
        temp->next = list1==NULL ? list2 : list1;//merged list will get reamining part of the other list if one gets exhausted
        return head;
        
    }
};

//Approach 2 -> Recursive approach
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
