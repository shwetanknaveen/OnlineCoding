/*
A car manufacturer has data about the production processes of N different cars (numbered from 0 to N-1) and wants to maximize
the number of cars produced in the upcoming months. The manufacturing information is described by an array H, where H[K] denotes
the number of hours required to produce the K-th car.

There are two assembly lines in the factory, the first of which works for X, and the second Y, hours in a month. Every car can be 
constructed using either one of these lines. Only one car at a time can be produced on each assembly line and it is not possible to switch
lines after starting the car's production.
What is the maximum number of different cars that can be produced in the upcoming month?
*/

int knapSackRec(int W1,int W2,vector<int> wt,int n,vector<vector<vector<int>>> &dp)
    {
        if(n==0 || (W1<=0&&W2<=0))
        return 0;
        if(dp[n][W1][W2]!=-1) 
        return dp[n][W1][W2];
        
		if(W1>=wt[n-1] || W2>=wt[n-1])
        {
        	int optOnX = 0,optOnY = 0,optNoWhere=0;
        	if(W1>=wt[n-1])
            	optOnX = 1+knapSackRec(W1-wt[n-1],W2,wt,n-1,dp);
            if(W2>=wt[n-1])
            	optOnY = 1+knapSackRec(W1,W2-wt[n-1],wt,n-1,dp);
            	
            optNoWhere = knapSackRec(W1,W2,wt,n-1,dp);
            dp[n][W1][W2] = max(optOnX,max(optOnY,optNoWhere));
            		
            return dp[n][W1][W2];
        }
        else
        {
            dp[n][W1][W2] = knapSackRec(W1,W2,wt,n-1,dp);
            return dp[n][W1][W2];
        }
    }
    
int main()
{
    int n = H.size(),W1=X,W2=Y;
    vector<vector<vector<int>>> dp(n+1,vector<vector<<int>>(W1+1,vector<int>(W2+1-1)));
	cout<< knapSackRec(W1,W2,H,n,dp);
}
