typedef long long ll;
class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& g) {
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto t:g){
            adj[t[0]].push_back({t[1],t[2]});
            adj[t[1]].push_back({t[0],t[2]});
        }

        vector<ll> dist(n,1e18),ways(n,0);
        set<pair<ll,ll>> pq;
        pq.insert({0,0});
        dist[0]=0,ways[0]=1;

        while(!pq.empty()){
            auto it=*pq.begin();
            pq.erase(pq.begin());
            ll node=it.second;
            ll d=it.first;

            for(auto t:adj[node]){
                ll adjnode=t.first;
                ll wt=t.second;

                if(d+wt<dist[adjnode]){
                    dist[adjnode]=d+wt;
                    ways[adjnode]=ways[node];
                    pq.insert({d+wt,adjnode});
                }
                else if(d+wt==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};