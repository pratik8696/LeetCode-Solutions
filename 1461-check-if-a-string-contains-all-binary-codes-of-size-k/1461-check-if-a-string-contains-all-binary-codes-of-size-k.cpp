typedef long long ll;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k)
        {
            return false;
        }
        unordered_map<ll,ll> hsh;
        ll curr=0;
        for(int i=0;i<k;i++)
        {
            curr=curr*2+(s[i]-'0');
        }
        hsh[curr]++;
        int i=0;
        for(int j=k;j<s.length();j++)
        {
            curr%=(1<<(k-1));
            i++;
            curr=curr*2+(s[j]-'0');
            hsh[curr]++;
        }
        return (hsh.size()==(1<<k));
    }
};