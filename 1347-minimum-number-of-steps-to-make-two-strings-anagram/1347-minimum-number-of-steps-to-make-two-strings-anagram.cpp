class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> hsh(26);
        for(auto t:s)
        {
            hsh[int(t-'a')]++;
        }
        for(auto x:t)
        {
            if(hsh[int(x-'a')])
            {
                hsh[int(x-'a')]--;
            }
        }   
        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans+=hsh[i];
        }
        return ans;
    }
};