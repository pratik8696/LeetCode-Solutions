class Solution {
public:
    vector<int> partitionLabels(string s) 
    {    
        unordered_map<int,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]-'a']=i;
        }
        int left=0,right=-1;
        vector<int> ans;
        for(int i=0;i<s.length();i++)
        {
            left=max(left,m[s[i]-'a']);
            if(left==i)
            {
                ans.push_back(left-right);
                right=i;
            }
        }
        return ans;
    }
};