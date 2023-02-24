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
typedef priority_queue<ll> pq64;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
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
 
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
 
bool isvalid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    return true;
}
 
void bfson2dformonsters(vp64 &monsters, vector<vector<int>> &arr, vv64 &dist)
{
    queue<pair<int, int>> q;
    for (auto t : monsters)
    {
        dist[t.fi][t.se] = 0;
        q.push(mp(t.fi, t.se));
    }
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = currx + dx[i];
            int y1 = curry + dy[i];
            if (isvalid(currx + dx[i], curry + dy[i]) && arr[x1][y1] != 2)
            {
                if(dist[x1][y1]>dist[currx][curry]+1)
                {
                    dist[x1][y1] = dist[currx][curry] + 1;
                    q.push(mp(x1, y1));                    
                }
            }
        }
    }
}
 
bool isvalidpeople(int x, int y, vv64 &dist, int time)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    
    if(time==dist[x][y]&&x==n-1&&y==m-1)
    {
        return true;
    }
    
    if (time >= dist[x][y])
    {
        return false;
    }

    return true;
}

bool bfson2dpeople(int x, int y, vector<vector<int>> &arr, vv64 &mondist,int timer)
{
    queue<pair<int, int>> q;
    vv64 time(n,v64(m,1e16));
    time[x][y] = timer;
    q.push(mp(x, y));
    while (!q.empty())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = currx + dx[i];
            int y1 = curry + dy[i];
            if (isvalidpeople(currx + dx[i], curry + dy[i], mondist, time[currx][curry] + 1) && arr[x1][y1] != 2)
            {
                if(time[x1][y1] > time[currx][curry] + 1)
                {
                    time[x1][y1] = time[currx][curry] + 1;
                    q.push({x1,y1});
                }
            }
        }
    }
    
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<time[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
    return (time[n-1][m-1]!=1e16);
}


class Solution {
public:
    int maximumMinutes(vector<vector<int>>& arr) {
        n=arr.size(),m=arr[0].size();
        vp64 fire;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==1)
                {
                    fire.pb({i,j});
                }
            }
        }
        vv64 mondist(n,v64(m,1e16));
        bfson2dformonsters(fire,arr,mondist);
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 cout<<mondist[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<endl;
//         cout<<endl;
        
        ll i=0,j=1e9,ans=-1;
        // cout<<bfson2dpeople(0,0,arr,mondist,3)<<endl;
        while(i<=j)
        {
            ll mid=(i+j)/2;
            // cout<<mid<<endl;
            if(bfson2dpeople(0,0,arr,mondist,mid))
            {
                ans=mid;
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return ans;
    }
};