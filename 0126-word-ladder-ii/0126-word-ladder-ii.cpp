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
ll MOD = 1000000007;
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
#define dbg(x) cout << #x << " = " << x << ln
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


bool check(string &a,string &b)
{
    ll cc=0;
    forn(i,a.length())
    {
        if(a[i]!=b[i])
        {
            cc++;
        }
    }
    return cc == 1;
}

void create(uv64 &adj,vector<string> &word)
{
    forn(i,word.size()-1)
    {
        forsn(j,i+1,word.size()) 
        {
            if(check(word[i],word[j]))
            {
                adj[i].pb(j);
                adj[j].pb(i);                
            }
        }
    }
}


void bfs(uv64 &adj, v64 &dist, ll src,uv64 &parent)
{
    queue<ll> q;
    q.push(src);
    dist[src] = 0;
    parent[src]={-1};
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for (auto child : adj[curr])
        {

            if(dist[child]>dist[curr]+1)
            {
                dist[child]=dist[curr]+1;
                q.push(child);
                parent[child].clear();
                parent[child].push_back(curr);
            }
            else if(dist[child]==dist[curr]+1)
            {
                parent[child].push_back(curr);
            }
        }
    }
}

void getshortestpath(int v,vector<int> &path,uv64 &parent,vector<vector<int>> &ans)
{
    if(v==-1)
    {
        ans.pb(path);
        return;
    }
    for(auto child:parent[v])
    {
        path.pb(child);
        getshortestpath(child,path,parent,ans);
        path.pop_back();
    }
}


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bool haikinai=0,s=0;
        for(auto &t:wordList)
        {
            if(endWord==t)
            {
                haikinai=1;
            }
            if(beginWord==t)
            {
                s=1;
            }
        }
        if(!haikinai)
        {
            return {};
        }
        if(s==0)
        {
            wordList.pb(beginWord);
        }
        ll start,end;
        for(int i=0;i<wordList.size();i++)
        {
            auto t=wordList[i];
            if(t==beginWord)
            {
                start=i;
            }
            if(t==endWord)
            {
                end=i;
            }
        }
        uv64 adj;
        uv64 parent;
        create(adj,wordList);
        v64 dist(wordList.size()+1,INT_MAX);
        bfs(adj,dist,start,parent);
        vector<vector<int>> ans;
        vector<vector<string>> res;
        vector<int> path;
        getshortestpath(end,path,parent,ans);
        for(auto t:ans)
        {
            vector<string> temp;
            for(int i=0;i<t.size()-1;i++)
            {
                temp.push_back(wordList[t[i]]);
            }
            reverse(all(temp));
            temp.pb(endWord);
            res.pb(temp);
        }
        return res;
    }
};
