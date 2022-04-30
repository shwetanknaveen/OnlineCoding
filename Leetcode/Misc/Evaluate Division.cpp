//Problem link - https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> nodeNum;
        int nEq = equations.size();
        int vertex = 0;
        for(int i=0;i<nEq;i++)
        {
            for(auto var:equations[i])
            {
                if(nodeNum.find(var)==nodeNum.end())//Encode vertices with numerical values starting from 0
                {
                    nodeNum[var] = vertex++;
                }
            }
        }
        
        //Now total count of distinct variables (quivalent nodes in the graph) = vertex
        
		vector<vector<double>> matrix(vertex,vector<double>(vertex,DBL_MAX));
        for(int i=0;i<nEq;i++)
        {
            matrix[nodeNum[equations[i][0]]][nodeNum[equations[i][1]]] = values[i];// var1/var2 = values[i]
            matrix[nodeNum[equations[i][1]]][nodeNum[equations[i][0]]] = 1/values[i];// =>var2/var1 = 1/values[i]
        }
        
        //Using Floyd Warshall algorithm
        for(int usingVert = 0;usingVert<vertex;usingVert++)
        {
            for(int i=0;i<vertex;i++)
            {
                for(int j=0;j<vertex;j++)
                {
                    if(i==j)//For any variable var/var = 1
                        matrix[i][j] = 1;
                    else if(matrix[i][usingVert] != DBL_MAX && matrix[usingVert][j] != DBL_MAX)//if i/usingVert and usingVert/j exist
                    {																		//then i/j can be calculated as following
                        matrix[i][j] = matrix[i][usingVert] * matrix[usingVert][j];//no need to look for min() as var1/var2 will have same value
                        															//no matter that how we calculate it
                    }
                }
            }
        }
        int nQuer = queries.size();
        vector<double> ans(nQuer,-1.0);
        for(int i=0;i<nQuer;i++)
        {
            if(nodeNum.find(queries[i][0])==nodeNum.end() || nodeNum.find(queries[i][1])==nodeNum.end())
            {
             //Do nothing as if any of the variable in the query wasn't in the set of equations then it means that this query can't be evaluated
			 //and we have already initialised ans vector with -1.0  
            }
            else if(matrix[nodeNum[queries[i][0]]][nodeNum[queries[i][1]]] != DBL_MAX)//if value can be calculated
            {
                ans[i] = matrix[nodeNum[queries[i][0]]][nodeNum[queries[i][1]]];
            }
        }
        return ans;
    }
};
