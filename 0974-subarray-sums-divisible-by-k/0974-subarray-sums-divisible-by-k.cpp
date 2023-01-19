typedef long long ll;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        long long int ans=0,sum=0;
        unordered_map<int,int> m;
        vector<ll> v;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]+k*1e4;         
            v.push_back(sum);
        }
        m[0]=1;
        for(int i=0;i<v.size();i++)
        {
            v[i]%=k;
            // cout<<v[i]<<" ";
            ans+=m[v[i]];
            m[v[i]]++;
        }
        // cout<<endl;
        return ans;
    }
};