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
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef unordered_map<ll, v64> uv64;
typedef unordered_map<ll, ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
typedef priority_queue<ll> pq64;
typedef priority_queue<ll, v64, greater<ll>> pqs64;
const int MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
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
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
#define dbg(a) cout << a << endl;
#define dbg2(a) cout << a << ' ';


uv64 red,blue;
int n;
v32 bfs()
{
    vector<vector<int>> dist(n+1,vector<int>(2,1e9));
    queue<pair<int,int>> q;
    q.push({0,0}); // is red
    dist[0][0]=0;
    q.push({0,1}); // is blue
    dist[0][1]=0;
    while(q.size())
    {
        int curr_node=q.front().first;
        int col=q.front().second;
        q.pop();
        if(col==1)
        {
            for(auto child:red[curr_node])
            {
                if(dist[child][0]>dist[curr_node][1]+1)
                {
                    dist[child][0]=dist[curr_node][1]+1;
                    q.push({child,0});
                }
            }
        }
        else
        {
            for(auto child:blue[curr_node])
            {
                if(dist[child][1]>dist[curr_node][0]+1)
                {
                    dist[child][1]=dist[curr_node][0]+1;
                    q.push({child,1});
                }
            }
        }
    }
    v32 ans;
    forn(i,n)
    {
        // cout<<dist[i][0]<<" "<<dist[i][1]<<endl;
        ans.pb((min(dist[i][0],dist[i][1])==1e9?-1:min(dist[i][0],dist[i][1])));
    }
    return ans;
}

class Solution {
public:
    vector<int> shortestAlternatingPaths(int x, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        red.clear();blue.clear();
        n=x;
        for(auto t:redEdges)
        {
            red[t[0]].pb(t[1]);
        }
        for(auto t:blueEdges)
        {
            blue[t[0]].pb(t[1]);
        }
        return bfs();            
    }
};

