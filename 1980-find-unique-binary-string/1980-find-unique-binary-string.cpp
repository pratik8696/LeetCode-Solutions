class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<int> hsh(1<<n);
        for(auto &s:nums)
        {
            int sum=0;
            for(int i=s.length()-1,j=0;i>=0;i--,j++)
            {
                sum+=(s[i]=='1'?(1<<j):0);
            }
            hsh[sum]++;
        }
        for(int mask=0;mask<(1<<n);mask++)
        {
            if(hsh[mask]==0)
            {
                string res="";
                for(int i=0;i<n;i++)
                {
                    if(mask&(1<<i))
                    {
                        res.push_back('1');
                    }
                    else
                    {
                        res.push_back('0');
                    }
                }
                reverse(begin(res),end(res));
                return res;
            }
        }
        return 0;
    }
};