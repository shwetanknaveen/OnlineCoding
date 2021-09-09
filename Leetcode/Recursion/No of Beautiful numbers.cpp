
//Video link - https://www.youtube.com/watch?v=vhHrUeSdFGU&t=681s
class Solution {
public:
    void getCount(vector<bool> &visited, int pos,int n, int &ans)
{
	if(pos>n)
	{
		ans++;//only those recursive call will reach the end which will have beautiful arrangement
		return;
	}
	for(int i = 1;i<=n;i++)//i is the number
	{
		if(!visited[i] && ((i%pos == 0) || (pos%i ==0)))
		{
			visited[i] = true;//this i won't be taken down in the recursive call....see video for help
			getCount(visited,pos+1,n,ans);
			visited[i] = false;//this element is again free to be taken in another branch
		}
	}
}

int countArrangement(int n) {
	
	vector<bool> visited(n+1,false);//since we are taking here indexing from 1 so taking size as n+1
	int ans = 0;
	getCount(visited,1,n,ans);
    return ans;    
    }
};
