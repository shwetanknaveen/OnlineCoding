//Problem link - https://leetcode.com/problems/magnetic-force-between-two-balls/

//This problem is almost same as Striver180/Aggressive cows


class Solution {
public:
    bool isValid(vector<int> &positions,int m,int minDistance)//is it possible to allocate m no. of balls to positions with
														//minimum distance = minDistance
{
	//get sorted positions here
	int n=positions.size(),prevPos = 0;
	for(int i=0;i<n && m>0;i++)
	{
		if(i==0)//if this is first position, then allot this position to one ball without comparing its distance with any 
				//other position
		{
			prevPos = positions[0];
			m--;//one ball has been alloted
			continue;//look for the next ball
		}
		if(positions[i]-prevPos>=minDistance)//if we can allot ball to this pos with min distance constraint
		{
			m--;
			prevPos = positions[i];
		}
	}
	if(m>0) return false;//all the balls coudn't be allocated
	return true;
}
    int maxDistance(vector<int>& position, int m) {
    sort(position.begin(),position.end());
	int low = 1,//minimum distance has to be 1 otherwise placing them in same bucket will give zero force
	high = position[position.size()-1]-position[0],//max force can be when balls are placed in farthest buckets
	mid,res;
	while(low<=high)
	{
		mid = low + (high-low)/2;
		if(isValid(position,m,mid))
		{
			res = mid;//store this limit
			low = mid+1;//if this limit on minimum distance is possible then we can search for larger limits as we need max
						//ans
		}
		else
		{
			high = mid-1;//If that much minDist=mid was not possible to allocate with then we reduce the search space
		}
	}
	return res;//return the stored ans;
    }
};
