#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
// use less_equal to make it multiset
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef unsigned long long ull; 
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll,ll> m64;
typedef map<ll,v64> mv64;
typedef unordered_map<ll,v64> uv64;
typedef unordered_map<ll,ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
typedef priority_queue<ll> pq64;
typedef priority_queue<ll,v64,greater<ll>> pqs64;
const int MOD = 1000000007;
double eps = 1e-12;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(p64 x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.second + FIXED_RANDOM);
    }
    size_t operator()(ll x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef gp_hash_table<ll, ll, custom_hash> fm64;
typedef gp_hash_table<p64, ll, custom_hash> fmp64;

#define ln "\n"
#define mp make_pair
#define ie insert
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr,n) arr,arr+n
#define sz(x) ((ll)(x).size())
#define dbg(a) cout<<a<<endl;
#define dbg2(a) cout<<a<<' ';
using ld = long double;
using db = double;
using str = string; // yay python!
// INPUT
#define tcT template <class T
#define tcTU tcT, class U
#define tcTUU tcT, class... U
tcT > void re(T &x)
{
    cin >> x;
}
tcTUU > void re(T &t, U &...u)
{
    re(t);
    re(u...);
}
vector<bool> sieve(int n)
{
    n*=2;
    vector<bool> arr(n,true);
    ll i;
    arr[0] = false;
    arr[1] = false;
    for (i = 0; i * i < n; i++)
    {
        if (arr[i] == true)
        {
            // prime.pb(i);
            for (ll j = i * i; j < n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    return arr;
}


v32 order;
void dfs(int v, v32 &vis, uv64 &adj,vector<bool> &prime)
{
    vis[v] = 1;
    order.pb(v);
    for (auto child : adj[v])
    {
        if (vis[child] == 0 && prime[child]==0)
        {
            dfs(child, vis, adj,prime);
        }
    }
}

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        uv64 adj;
        for(auto t:edges)
        {
            int u=t[0];
            int v=t[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> prime=sieve(n);
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<prime[i]<<" ";
        // }
        // cout<<endl;
        vector<int> values(n+1);
        vector<int> vis(n+1);
        for(int i=1;i<=n;i++)
        {
            if(prime[i]==0&&vis[i]==0)
            {
                order.clear();
                dfs(i,vis,adj,prime);
                for(auto t:order)
                {
                    values[t]=order.size();
                }
            }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<values[i]<<" ";
        // }
        // cout<<endl;
        
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            vector<ll> group_sizes;
            ll end_at_prime = 0, pass_through_prime = 0;
            if(prime[i]==1)
            {
                ll curr=1;
                for(auto child:adj[i])
                {
                    if(prime[child]==0)
                        group_sizes.push_back(values[child]);
                    end_at_prime+=values[child];
                }
                
                for (ll group_size: group_sizes)
                    pass_through_prime += group_size * (end_at_prime - group_size);
                pass_through_prime /= 2; // we counted each path twice (once from each end)                
                
                ans += end_at_prime + pass_through_prime;
            }
        }
        return ans;
    }
};