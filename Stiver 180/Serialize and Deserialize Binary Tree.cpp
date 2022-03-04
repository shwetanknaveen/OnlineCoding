//Problem link - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
//Video link - https://www.youtube.com/watch?v=-YbXySKJsX8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=38

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        queue<TreeNode*> qu;
        TreeNode *temp;
        qu.push(root);
        string serString;
        while(!qu.empty())
        {
            temp = qu.front();
            qu.pop();
            if(temp == NULL)//for NULL nodes place N with delimeter ','
                serString.append("N,");
            else 
            {
                serString.append(to_string(temp->val)+",");//for non null nodes, place node value with delimeter ','
                qu.push(temp->left);
                qu.push(temp->right);
            }
        }
        //cout<<serString;
        return serString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        queue<TreeNode*> qu;
        TreeNode *root,*curr;
        stringstream s(data);
		/*A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream
		 (like cin)
		 https://www.geeksforgeeks.org/stringstream-c-applications/
		 */        
        string str;
        getline(s,str,',');
        //cout<<"\n"<<str;
        root = new TreeNode(stoi(str));//by default, left and right children are NULL
        qu.push(root);
        while(!qu.empty())
        {
            curr = qu.front();
            qu.pop();
            
            /*
            The C++ getline() is a standard library function that is used to read a string or a line from an input stream.
            istream& getline(istream& is, string& str, char delim);
            is: It is an object of istream class and tells the function about the stream from where to read the input from.
			str: It is a string object, the input is stored in this object after being read from the stream.
			delim: It is the delimitation character which tells the function to stop reading further input after reaching 
			this character
            */
            
            getline(s,str,',');
            //cout<<"\n"<<str;
            if(str != "N")//it means there is a value node to be linked with current node
            {
                curr->left = new TreeNode(stoi(str));//by default, left and right are NULL
                qu.push(curr->left);//in level order, this node will get its children as left and right
            }
            
            getline(s,str,',');
            //cout<<"\n"<<str;
            if(str != "N")
            {
                curr->right = new TreeNode(stoi(str));
                qu.push(curr->right);
            }
        }
        return root;
    }
};

