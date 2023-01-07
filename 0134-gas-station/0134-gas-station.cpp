class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> pre;
        pre.push_back(0);
        for(int i=0;i<n;i++)
        {
            pre.push_back(gas[i]-cost[i]);
        }
        for(int i=0;i<n;i++)
        {
            pre.push_back(gas[i]-cost[i]);
        }
        for(int i=1;i<2*n;i++)
        {
            pre[i]+=pre[i-1];
        }
        multiset<int> s;
        int i=1;
        // create the window
        for(int j=1;j<n+1;j++)
        {
            s.insert(pre[j]);
        }
        // check for conditions
        if(*s.begin()-pre[i-1]>=0)
        {
            return 0;
        }
        for(int j=n+1;j<2*n;j++)
        {
            // add
            s.insert(pre[j]);
            // remove
            s.erase(s.find(pre[i]));
            i++;
            // check for conditions
            if(*s.begin()-pre[i-1]>=0)
            {
                return i-1;
            }                  
        }
        return -1;
    }
};