//Problem link - https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    int n = A.size();
    if(n<B) return ans;
    unordered_map<int,int> mp;//no. -> frequency in the window
    for(int i=0;i<B;i++)	//Initially pushing number's frequency in the window
    {
        mp[A[i]]++;
    }
    for(int i=0;i<=n-B;i++)//last window has starting index of n-B
    {
        ans.push_back(mp.size());//Push number of unique numbers in this window
        if(mp[A[i]]==1)//if number going out of window has frequency 1 then it has to be deleted.
            mp.erase(A[i]);
        else mp[A[i]]--;//otherwise number going out of scope of window has frequency more than 1 then it means it can remain
        				//in window with reduced frequency
        mp[A[i+B]]++;//update the frequency of upcoming number in the frequency
    }
    return ans;
}
