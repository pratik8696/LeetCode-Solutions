class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> stack;
        int ans=0;
        for(auto t:target)
        {
            if(stack.size()&&stack.back()>=t)
            {
                ans+=stack.back()-t;
                while(stack.size()&&stack.back()>=t)
                {
                    stack.pop_back();
                }                    
            }
            stack.push_back(t);
        }
        if(stack.size())
        {
            ans+=stack.back();
        }
        return ans;
    }
};