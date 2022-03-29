//Problem link - https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1#

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
        int v = matrix.size();
        for(int usingVert = 0; usingVert<v; usingVert++)
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    if(i!=j)
                    {
                        if(matrix[i][usingVert] != -1 && matrix[usingVert][j] != -1)//edge should be existing
                        {
                            if(matrix[i][j]==-1)//if in previous step, there was no edge between i and j then obviously whatever
                            					//cost is for i to usingVert and from usingVert to j, it will be minimum
                                matrix[i][j] = matrix[i][usingVert] + matrix[usingVert][j];
                            else
                                matrix[i][j] = min(matrix[i][j],matrix[i][usingVert] + matrix[usingVert][j]);
                        }
                    }
                }
            }
        }
	}
};
