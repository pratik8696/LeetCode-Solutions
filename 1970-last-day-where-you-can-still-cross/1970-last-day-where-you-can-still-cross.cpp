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

v64 e, sz;

struct DSU
{
    DSU(ll n)
    {
        e.assign(n + 1, -1);
        sz.assign(n + 1, 1);
    }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll size(ll x) { return sz[find(x)]; }
    ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    void join(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            e[b] = a;
            sz[a] *= sz[b];
            
            if(sz[a]%6==0)
            {
                sz[a]=6;
            }
            else if(sz[a]%3==0)
            {
                sz[a]=3;
            }
            else if(sz[a]%2==0)
            {
                sz[a]=2;
            }
            
            if(sz[b]%6==0)
            {
                sz[b]=6;
            }
            else if(sz[b]%3==0)
            {
                sz[b]=3;
            }
            else if(sz[b]%2==0)
            {
                sz[b]=2;
            }
        }
    }
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y,int n,int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    return true;
}


class Solution {
public:
    int latestDayToCross(int n, int m, vector<vector<int>>& c) {
        vector<vector<int>> arr(n,vector<int>(m));
        vector<vector<int>> active(n,vector<int>(m));
        int cc=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j]=++cc;
            }
        }
        DSU d(cc);
        for(int i=1;i<=m;i++)
        {
            sz[i]*=2;   
        }
        for(int i=cc;i>cc-m;i--)
        {
            sz[i]*=3;
        }
        reverse(begin(c),end(c));
        int x=1;
        for(auto t:c)
        {
            int i=t[0]-1,j=t[1]-1;
            active[i][j]++;
            for(int k=0;k<4;k++)
            {
                int i1=i+dx[k];
                int j1=j+dy[k];
                if(isvalid(i1,j1,n,m))
                {
                    if(active[i1][j1])
                    {
                        d.join(arr[i][j],arr[i1][j1]);
                    }
                }
            }
            if(d.size(arr[i][j])%6==0)
            {
                return n*m-x;
            }
            x++;
        }
        return 0;
    }
};