//Question link - https://practice.geeksforgeeks.org/problems/sort-a-stack/1
//Aditya verma video link - https://www.youtube.com/watch?v=MOGBRkkOhkY
//Aditya verma referal video link in which he solved similar question - sorting a vector using recursion
//https://www.youtube.com/watch?v=AZ4jEY_JAVc&t=1550s

//Time complexity -> O(n^2)
//T(n) = T(n-1) + O(n)	//O(n) is for insert()

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int> &s, int tempVal)
{
    if(s.empty()){
        s.push(tempVal);//if stack is empty simply insert the value
        return;}
    if(s.top()<tempVal){//since top of stack has to be greatest so if top of stack
                    //is smaller than value to be inserted then push the value on 
                    //top of stack
        s.push(tempVal);
        return;
    }
    int popedOutVal = s.top();//save the top of stack value
    s.pop();//remove top of stack
    insert(s,tempVal);//try to insert the value in new stack
    s.push(popedOutVal);//push the earlier popped out value after insertion
}
void SortedStack :: sort()
{
    if(s.empty()) return;// simply return for empty stack
    if(s.size()==1) return;//one element is always sorted
    int val = s.top();//save top of stack
    s.pop();//remove top of stack
    sort();//sort the new stack
    insert(s,val);//insert the value in the sorted stack
}

