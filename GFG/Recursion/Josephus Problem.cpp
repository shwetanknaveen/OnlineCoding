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
        persons.erase(persons.begin()+index);//take example of first killing. We wish to kill k=2nd person in each round.
        									//We are starting from 0th index. We would have passed k-1 = 1.
        									//First person who gets killed will be (0+1) = 1 index person that is 2nd per-
        									//-son who we wished to kill 
        solve(persons,ans,index,k);
    }
    int safePos(int n, int k) {
        // code here
        int ans = -1;
        vector<int> persons;
        for(int i=0;i<n;i++)
        persons.push_back(i+1);
        solve(persons,ans,0,k-1);//pass k-1 because to kill kth guy starting from 0th index, (k-1)th index guy will be killed
        return ans;
    }
};


//Approach -2
//Video link -> https://www.youtube.com/watch?v=46zD5d9y9b4
//refer above video to understand why adding k-1 then mod.....to see the mapping around timestamp 14:28
class Solution {
  public:
    int safePos(int n, int k) {
        // code here
        if (n == 1)
        return 1;
        else
        /* The position returned by josephus(n - 1, k)
        is adjusted because the recursive call
        josephus(n - 1, k) considers the
        original position k % n + 1 as position 1 */
        return (safePos(n - 1, k) + k - 1) % n + 1;
    }
};

/*exact and EASIEST implementation as shown in mapping at 14:28 in above video
(Sub problem)->(Original problem)
0->3
1->4
2->0
3->1
*/

class Solution {
  public:
    
    int solve(int n,int &k)
    {
        if(n==1) return 0;//if there is only one guy in the circle then safe postion is first position that is 0th one
        return (solve(n-1,k)+k)%n;//if in the sub-problem the index returned is ind then it will be (ind+k)%n in the 
        							//original problem as shown in the video.
    }
    int safePos(int n, int k) {
        return solve(n,k)+1;//relation was assumed as 0 based indexing but actually it is 1 based so we add 1 to answer
    }
};
