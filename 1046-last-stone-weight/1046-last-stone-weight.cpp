class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto t:stones)
        {
            q.push(t);
        }
        while(q.size()>1)
        {
            int first=q.top();
            q.pop();
            int second=q.top();
            q.pop();
            if(first!=second)
            {
                q.push(first-second);
            }
        }
        if(q.size()==0)
        {
            return 0;
        }
        return q.top();
    }
};