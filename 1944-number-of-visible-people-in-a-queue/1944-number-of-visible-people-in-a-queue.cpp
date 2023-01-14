class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> stack,res(heights.size());
        for(int i=0;i<heights.size();i++)
        {
            while(stack.size()&&heights[stack.back()]<=heights[i])
            {
                res[stack.back()]++;
                stack.pop_back();
            }
            if(stack.size())
            {
                res[stack.back()]++;
            }
            stack.push_back(i);
        }
        return res;
    }
};