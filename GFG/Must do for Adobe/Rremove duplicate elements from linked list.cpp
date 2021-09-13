//Problem link - https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(!head) return head;
 Node *tempHead = head;
 while(tempHead)
 {
     if(tempHead->next/*NULL check*/ && (tempHead->data == tempHead->next->data))
     {
     tempHead->next = tempHead->next->next;//after connecting next to bypass the duplicate element, next element may again
     										//be equal which needs to be compared with current element hence we don't advance 
     										//our tempHead and check again
     continue;
     }
     
     tempHead = tempHead->next;
 }
 return head;
}
