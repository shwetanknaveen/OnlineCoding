//Question Link - https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1#
//Aditya Verma - https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19
class Solution {
  public:
    void solve(vector<int> &persons,int &ans,int index,int k)//Auxilary space allowed is O(1) hence passing persons by value
    													//may cause SIGABRT on big test cases
    {
        if(persons.size()==1)//only guy remaning
        {
            ans = persons[0];
            return;
        }
        index = (index+k)%(persons.size());
        persons.erase(persons.begin()+index);
        solve(persons,ans,index,k);
    }
    int safePos(int n, int k) {
        // code here
        int ans = -1;
        vector<int> persons;
        for(int i=0;i<n;i++)
        persons.push_back(i+1);
        solve(persons,ans,0,k-1);//pass k-1 because to skip k people starting from 0th index, (k-1)th index guy will be killed
        return ans;
    }
};
