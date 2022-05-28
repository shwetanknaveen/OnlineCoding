//Problem link - https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
//Video link - https://www.youtube.com/watch?v=ysytSSXpAI0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=39

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *merge(Node *l1, Node *l2)
{
    if(!l1) return l2;
    if(!l2) return l1;
    Node *head,*temp;
    if(l1->data<l2->data)
    {
        head = l1;
        l1=l1->bottom;
    }
    else
    {
        head = l2;
        l2=l2->bottom;
    }
    temp = head;
    while(l1 && l2)
    {
        if(l1->data<l2->data)
        {
            temp->bottom = l1;
            l1 = l1->bottom;
        }
        else
        {
            temp->bottom = l2;
            l2 = l2->bottom;
        }
        temp = temp->bottom;
    }
    temp->bottom = l1==NULL? l2 : l1;
    return head;
}
Node *flatten(Node *root)
{
   if(!root || !(root->next)) return root;

  Node *temp=root;
  while(root)
  {
      temp = merge(temp,root->next);
      root = root->next;
  }
    return temp;

        /*RECURSIVE APPROACH to write flatten() function
        root->next = flatten(root->next); 
        //now merge 
        root = merge(root, root->next); 
        return root; 
        */
}
