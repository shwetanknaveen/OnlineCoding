//Problem link - https://leetcode.com/problems/smallest-string-with-swaps/

class Solution {
public:
    void makeSet(vector<int> &parent,vector<int> &rank)
	{
	    for(int i=0;i<parent.size();i++)
	    {
	        parent[i] = i;//initially every node is parent of itself
	        rank[i] = 0;//initially rank of every node is zero as no node is attached to it hence its height is 0
	    }
	}
	int findParent(int node,vector<int> &parent,vector<int> &rank)
	{
	    if(parent[node] == node) return node;//reched to the top
	    return parent[node] = findParent(parent[node],parent,rank);//if haven't reached to top then go to top and do compression
	    															//parallely
	}
	void unionNodes(int node1, int node2,vector<int> &parent,vector<int> &rank)
	{
	    node1 = findParent(node1,parent,rank);//now node1 contains its parent
	    node2 = findParent(node2,parent,rank);//now node2 contains its parent
	    
	    if(node1 != node2)//if two nodes have different parents then only their union has to be done
	    {
    	    if(rank[node1]<rank[node2])//set having lower rank has to be attached to set having heigher rank
    	    {
    	        parent[node1] = node2;
    	    }
    	    else if(rank[node1]>rank[node2])
    	    {
    	        parent[node2] = node1;//lower rank node2 is attached to higher rank node1    
    	    }
    	    else//both have equal rank
    	    {
    	        parent[node2] = node1;//attach node2 to node1 -> it can also be other way round
    	        rank[node1]++;//in this case, rank of node1 increases
    	    }
	    }
	}
	
	/*
	We will treat indices of the string as nodes of the graph. Now those indices which can be swapped among each other form one component.
	Each component can be sorted to give lexicographically smallest string and that component's character will be placed at the respective
	sorted index in the original string
	*/
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int V = s.length();
        vector<int> parent(V),rank(V);
        makeSet(parent,rank);
        map<int,vector<int>> parentIndices;	//[indexOfParent-->index of all the vertices in that component including parent]
        
        for(auto p:pairs)
            unionNodes(p[0],p[1],parent,rank);//p[0] and p[1] can be swapped hence they will be part of same component
        
		//Once all unions has been done, while taking parent of any vertex, we will take the most recent parent i.e., we will call 
		//findParent(child) when parent is needed
		for(int i=0;i<V;i++)
            parentIndices[findParent(i,parent,rank)].push_back(i);
        for(auto itr = parentIndices.begin();itr != parentIndices.end(); itr++)
        {
            vector<int> indices = itr->second;//all the vertices of this component will be stored in indices
            string thisComp = "";
            for(int i:indices)
                thisComp.push_back(s[i]);//all characters corresponding to the indices will make up the component string
            sort(thisComp.begin(),thisComp.end());//the smallest possible component substring
            sort(indices.begin(),indices.end());//sort the indices in ascendin order
            for(int i=0;i<thisComp.size();i++)
                s[indices[i]] = thisComp[i];//place sorted component string from left to right at the right place in the actual string
        }
        return s;
    }
};
