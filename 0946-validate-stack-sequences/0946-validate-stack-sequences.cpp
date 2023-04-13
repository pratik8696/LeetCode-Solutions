class Solution {
public:
    bool validateStackSequences(vector<int>& push, vector<int>& pop) {
        vector<int> res;
        int n=push.size();
        reverse(begin(pop),end(pop));
        for(auto t:push)
        {
            cout<<t<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            res.push_back(push[i]);
            while(res.size()&&pop.size()&&res.back()==pop.back())
            {
                res.pop_back();
                pop.pop_back();
            }  
        }
        if(res.size()==0&&pop.size()==0)
        {
            return true;
        }
        return false;
    }
};