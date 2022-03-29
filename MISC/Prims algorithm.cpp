/*
Consider a university having a very big campus spread in acres of land. The university is undergoing computerization. All the 
departments (at-most 50) are to be connected to form the intranet of the university. You have to write a program, implementing 
Prims algorithm, which will suggest the network topology and also minimise the total length of cable for connecting all the 
departments. Input to the program will be names of all the departments and straight line distances between the departments 
(Only those pairs of departments between which cable can be laid will be given). Output of the program should be the minimum 
length of the cable required.

Input - 
The first line will contain 2 natural numbers, N and M, separated by a blank space. N indicated the number of departments in 
the university and M indicates the number of pairs of departments where the cables can be laid. The following M lines will 
specify the distances between M pairs of departments as dept1 dept2 distance
Where dept1 and dept2 are names of the departments (maximum 20 characters) and distance is a positive integer (>0). Assume that
the given distances between each pairs of departments will be unique and these M lines will contain atleast one pair for each 
department.

Output - 
The first line of the output will be names of the departments as they are included in the solution separated by blank space. 
If two or more departments are included at a time then their names should be printed in the alphabetic order. The next line 
will be the minimum length of cable required to form the intranet, terminated with a new line character.

Sample I/O - 
Input

7 10
physics chemistry 8
biology physics 9
biology office 15
chemistry office 4
chemistry sanskrit 5
sanskrit office 7
english office 16
english sanskrit 19
english cs 12
sanskrit cs 6

Output

chemistry office sanskrit cs physics biology english
44
*/

//Prims algorithm - https://www.youtube.com/watch?v=HnD676J56ak
//One test case missing
#include<bits/stdc++.h>
using namespace std;

map<string,bool> visited;
map<string,int> node_number;
map<int, string> department_name;

//if the key at index v has minimum value and hasn't been included yet in MST set then return its index i.e., v
int minKey(int key[], bool mstSet[],int n)
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

int main()
{
    int n,m;
	cin>>n>>m;
	cin.ignore(1,'\n');
	string inp;
	char *loc1,*loc2,*distStr;
	char delim[] = " ";
	int dist;
	int present_node = 0;
    int graph[n][n];
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           graph[i][j] = 0;
        }
    }
    
    string start;
    int minEdgeWeight = INT_MAX;
    
	while(m--)
	{
		getline(cin,inp);
		loc1 = strtok((char *)inp.c_str(),delim);
		loc2 = strtok(NULL,delim);
        
        if(strcmp(loc1,loc2)>0) swap(loc1,loc2); 
        
		if(!visited[loc1]){
            visited[loc1] = true;
            department_name[present_node] = loc1;
            node_number[loc1] = present_node++;
        }
        if(!visited[loc2]){
            visited[loc2] = true;
            department_name[present_node] = loc2;
            node_number[loc2] = present_node++;
        }
        
        distStr = strtok(NULL,delim);
		dist = atoi(string(distStr).c_str());
		
		if(dist<minEdgeWeight)
		{
			minEdgeWeight = dist;
			start = loc1;
		}
		else if(dist == minEdgeWeight)
		{
			if(strcmp(start.c_str(),loc2)>0)
				start = loc2;
		}
        graph[node_number[loc1]][node_number[loc2]] = graph[node_number[loc2]][node_number[loc1]] = dist;        
	}
    
    //Prim
    
    int parent[n]; 
    int key[n]; 
    bool mstSet[n];
    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[node_number[start]] = 0;
    parent[node_number[start]] = -1; // First node is always root of MST
    // The MST will have V vertices
    for (int count = 0; count < n-1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet,n);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        cout<<department_name[u]<<" ";
        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < n; v++)
 
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            //key[v] is cost of adding vertex at index v in present MST
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u, key[v] = graph[u][v];
            }
                
    }

    cout<<department_name[ minKey(key, mstSet,n)];//last key added has to be printed without space
    
    int sum = 0;
    for (int i = 0; i < n; i++){
    	if(parent[i] != -1)
        	sum+=graph[i][parent[i]];
	}
    cout<<"\n"<<sum;
	return 0;
}
