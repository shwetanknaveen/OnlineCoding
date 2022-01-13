//Problem link - https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
//Video link - https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=60

bool isValid(bool graph[101][101],int V,int clr,int &nV,unordered_map<int,int> &vertClr)
{
    for(int i=0;i<nV;i++)//check for all vertices
    {
        if(graph[V-1][i]==1)//if the vertex is adjacent to this vertex
        {
            if(vertClr[i+1]==clr)//if the vertex has same colour
            return false;
        }
    }
    return true;//default case that no vertex has same colour hence vertex V can be coloured with colour clr
}
bool solve(bool graph[101][101],int &nv,int &m,unordered_map<int,int> &vertClr)
{
    for(int v=1;v<=nv;v++)//there is no base case rather in each call each vertex is checked
    {
        if(vertClr[v]==0)//if vertex is not coloured
        {
            for(int clr=1;clr<=m;clr++)//with which colour we can colour the vertex
            {
                if(isValid(graph,v,clr,nv,vertClr))//if we can colour this vertex with colour clr
                {
                    vertClr[v] = clr;//colour it
                    if(solve(graph,nv,m,vertClr))//if we can solve further after colouring this 
                        return true;//then return true
                    vertClr[v] = 0;//other wise remove the colour so that other options can be explored when recursion call 
                    				//returns to the same level
                }
            }
            return false;//since in the above loop we were trying filling different colour in the non coloured vertex 
                    //hence we have to return a default value in case if none of the colour worked for the solution
					//checked all possible colours and hasn't returned true for any possible value
        }
    }
    return true;//all vertex have been checked and coloured
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    unordered_map<int,int> vertClr;
    return solve(graph,V,m,vertClr);
}
