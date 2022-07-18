//Problem link - https://leetcode.com/problems/word-ladder/

class Solution {
public:
    bool isAdj(string &s1,string &s2)//Do these strings differ atmost at one character or not
    {
        bool singleDiff = false;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i] != s2[i])
            {
                if(singleDiff) return false;
                else singleDiff = true;
            }
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> adj;//For each word, all other words which differ just by one character are adjacent
        wordList.push_back(beginWord);//Begin word is not in the wordList hence we insert it so that its adjacent words can also be calculated
        int nWords = wordList.size();
        unordered_set<string> vis;
        for(int i=0;i<nWords;i++)
        {
            for(int j=i+1;j<nWords;j++)
            {
                if(isAdj(wordList[i],wordList[j]))
                {
                    adj[wordList[i]].push_back(wordList[j]);//both will be adjacent of each other
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        //Now we do simple BFS from beginWord to reach endWord in shortest number of transformations
        queue<pair<string,int>> qu;
        qu.push(make_pair(beginWord,1));
        vis.insert(beginWord);
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--)
            {
                auto temp = qu.front();
                qu.pop();
                int dist = temp.second;
                if(endWord.compare(temp.first)==0) return dist;
                for(auto neigh:adj[temp.first])
                {
                    if(vis.find(neigh) == vis.end())
                    {
                        vis.insert(neigh);
                        qu.push(make_pair(neigh,dist+1));
                    }
                }
            }
        }
        return 0;//endWord is not reachable from begin word
        
    }
};
