//Problem link - https://binarysearch.com/problems/Minimum-Number-of-Transfers-to-Settle-Debts

//See similar question with simpler approach -> "Online Coding/MISC/Minimize Cash Flow"

int helper(int indOfGiver, vector<int> &givers, vector<int> &receivers) {
    if (indOfGiver >= givers.size())
        return 0;  // all givers have given hence no transaction is needed

    int ans = INT_MAX - 1;
    for (int i = 0; i < receivers.size(); i++)  // which receiver this giver can give
    {
        if (receivers[i] == 0)
            continue;  // this receiver can't take any amount from givers[indOfGiver]
        int giveAmnt = min(receivers[i], givers[indOfGiver]);
        // let's give this amnt to this receiver
        givers[indOfGiver] -= giveAmnt;
        receivers[i] -= giveAmnt;
        if (givers[indOfGiver] ==
            0)  // now we will look for next giver hence we add +1 to indOfGiver
            ans = min(ans, 1 + helper(indOfGiver + 1, givers,
                                      receivers));  // this guy has no amount to give further
        else  // otherwise this giver has some amount left to give hence we don't increase
              // indOfGiver
            ans = min(ans, 1 + helper(indOfGiver, givers,
                                      receivers));  // this guy has still amount to give

        // store back the state so that this amount can be given to next receivers
        givers[indOfGiver] += giveAmnt;
        receivers[i] += giveAmnt;
    }
    return ans;  // if amount was not given to any receiver, this would return INT_MAX-1 and won't
                 // be part of actual answer
}
int solve(vector<vector<int>> &transfers) {
    vector<int> netAmnt(13, 0);
    for (auto transac : transfers) {
        netAmnt[transac[0]] += transac[2];
        netAmnt[transac[1]] -= transac[2];
    }
    vector<int> givers, receivers;
    for (int i : netAmnt) {
        if (i < 0)
            givers.push_back(-i);
        else if (i > 0)
            receivers.push_back(i);
    }
    return helper(0, givers, receivers);
}
