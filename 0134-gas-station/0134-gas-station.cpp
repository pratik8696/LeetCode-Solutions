deque<int> smaller;
void add(int idx,vector<int> &pre)
{
    while(smaller.size()&&pre[idx]<=pre[smaller.back()])
    {
        smaller.pop_back();
    }
    smaller.push_back(idx);
}

void rem(int i)
{
    while(smaller.size()&&i>=smaller.front())
    {
        smaller.pop_front();
    }
}

int get()
{
    return smaller.front();
}

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        smaller.clear();
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
        int i=1;
        // create the window
        for(int j=1;j<n+1;j++)
        {
            add(j,pre);
        }
        // check for conditions
        if(pre[get()]-pre[i-1]>=0)
        {
            return 0;
        }
        for(int j=n+1;j<2*n;j++)
        {
            // add
            add(j,pre);
            // remove
            rem(i);
            i++;
            // check for conditions
            if(pre[get()]-pre[i-1]>=0)
            {
                return i-1;
            }                  
        }
        return -1;
    }
};