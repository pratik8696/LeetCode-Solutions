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

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m )
    {
        return false;
    }
    return true;
}

ll bfson2d(vector<string> &arr)
{
    n=arr.size();
    m=arr[0].size();
    int x=0,y=0,tot=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='@')
            {
                x=i,y=j;
                arr[i][j]='.';
            }
            if(arr[i][j]>='a'&&arr[i][j]<='z')
            {
                tot++;
            }
        }
    }
    queue<v64> q;
    vector<vector<vector<ll>>> dist(n+1,vector<vector<ll>>(m+1,vector<ll>(65,1e9)));
    dist[x][y][0] = 0;
    q.push({x,y,0});
    // cout<<x<<" "<<y<<" "<<tot<<endl;
    ll ans=1e9;
    while (!q.empty())
    {
        auto it=q.front();
        int currx = it[0];
        int curry = it[1];
        int curr_mask=it[2];
        if(curr_mask==(1<<tot)-1)
        {
            ans=min(ans,dist[currx][curry][curr_mask]);
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = currx + dx[i];
            int y1 = curry + dy[i];
            if (isvalid(currx + dx[i], curry + dy[i]))
            {
                if(arr[x1][y1]=='#')
                {
                    continue;
                }
                if(dist[x1][y1][curr_mask]>dist[currx][curry][curr_mask]+1)
                {
                    dist[x1][y1][curr_mask] = dist[currx][curry][curr_mask] + 1;
                    if(arr[x1][y1]=='.')
                    {
                        q.push({x1,y1,curr_mask});
                    }
                    else if(arr[x1][y1]>='a'&&arr[x1][y1]<='z')
                    {
                        int num=int(arr[x1][y1]-'a');
                        // cout<<num<<" "<<curr_mask<<" "<<new
                        int new_mask=curr_mask|(1<<num);
                        q.push({x1,y1,new_mask});
                        dist[x1][y1][new_mask]=dist[x1][y1][curr_mask];
                    }
                    else if(arr[x1][y1]>='A'&&arr[x1][y1]<='Z')
                    {
                        int num=int(arr[x1][y1]-'A');
                        if(curr_mask&(1<<num))
                        {
                            q.push({x1,y1,curr_mask});
                        }
                    }
                }
            }
        }
    }
    return ans;
}


class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int val=bfson2d(grid);
        return (val==1e9?-1:val);
    }
};