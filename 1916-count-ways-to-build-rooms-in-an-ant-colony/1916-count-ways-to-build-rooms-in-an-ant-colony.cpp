typedef long long ll;
const int N=1e5+1;
const int MOD=1e9+7;
ll fact[N];
void initfact()
{
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=1;
        fact[i]*=fact[i-1];
        fact[i]%=MOD;
        fact[i]*=i;
        fact[i]%=MOD;
    }
}

ll modpow(ll a,ll b,ll c)
{
    a%=MOD;
    if(b==0)
    {
        return 1;
    }
    ll ans=1;
    while(b)
    {
        if(b%2)
        {
            ans*=a;
            ans%=MOD;
        }
        a*=a;
        a%=MOD;
        b/=2;
    }
    return ans;
}

ll inv(ll a,ll b)
{
    return (a*modpow(b,MOD-2,MOD))%MOD;
}

unordered_map<int,int> sub;
void dfs(int v,vector<ll> &vis,unordered_map<ll,vector<ll>> &adj)
{
    vis[v]=1;
    sub[v]=1;
    for(auto child:adj[v])
    {
        if(vis[child]==0)
        {
            dfs(child,vis,adj);
            sub[v]+=sub[child];
        }
    }
}

class Solution {
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        initfact();
        sub.clear();
        ll n=prevRoom.size();
        unordered_map<ll,vector<ll>> adj;
        for(int i=1;i<n;i++)
        {
            adj[i].push_back(prevRoom[i]);
            adj[prevRoom[i]].push_back(i);
        }
        vector<ll> vis(n+1);
        dfs(0,vis,adj);
        ll num=fact[n];
        for(auto t:sub)
        {
            ll val=t.second;
            num=inv(num,val);
        }
        return num;
    }
};