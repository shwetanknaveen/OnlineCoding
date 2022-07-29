//Problem link - https://www.codingninjas.com/codestudio/problems/minimize-cash-flow-among-a-given-set-of-friends-who-have-borrowed-money-from-each-other_1170048?leftPanelTab=0
//Note for mistake in question -> Below question should work without custom comparator also if there is no definite order in ans is required

//Approach-> Take the guy who has to receive at max and the guy who has to give max and do the maximum value of transaction


#include<bits/stdc++.h>
struct custom_sort {
    bool operator()(pair<int, int> &a, pair<int, int> &b)  {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    } 
};
vector<vector<int>> minCashFlow(vector<vector<int>>& transaction, int n)
{
   vector<vector<int>> ans(n,vector<int>(n,0));
   vector<int> netAmnt(n,0);
   //ith vector in transaction has n numbers which indicate that ith guy has to pay what amount
   //to other guys
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)//ith guy has to pay jth guy, amount = transaction[i][j]
       {
           netAmnt[i] -= transaction[i][j];
           netAmnt[j] += transaction[i][j];
//            netAmnt[i]+= (transaction[j][i] - transaction[i][j]);
       }
   }
   //Amount->guy number
   priority_queue<pair<int,int>, vector<pair<int,int> >,custom_sort> receivers,givers;//max heap
   for(int i=0;i<n;i++)
   {
       if(netAmnt[i]>0)//this guy has to receive in total
       {
           receivers.push({netAmnt[i],i});
       }
       else if(netAmnt[i]<0)//this guy has to give in total
       {
           givers.push({abs(netAmnt[i]),i});//since we will be keeping both receivers and givers as max heap hence we are pushing abs()
       }
   }
   while(!givers.empty())//when givers becomes empty, receiver will also become empty
   {
       int toGive = givers.top().first,giverInd = givers.top().second;
       givers.pop();
       int toReceive = receivers.top().first, receiverInd = receivers.top().second;
       receivers.pop();
       if(toGive>toReceive)//give all it can
       {
           ans[giverInd][receiverInd] = toReceive;
           givers.push({toGive-toReceive,giverInd});
       }
       else if(toGive<toReceive)//give all
       {
           ans[giverInd][receiverInd] = toGive;
           receivers.push({toReceive-toGive,receiverInd});
       }
       else//toGive==toReceive
       {
           ans[giverInd][receiverInd] = toGive;
       }
   }
   return ans;
}

