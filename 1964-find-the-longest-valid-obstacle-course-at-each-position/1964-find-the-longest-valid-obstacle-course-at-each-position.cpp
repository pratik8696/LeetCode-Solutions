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

void dfs(int v, v64 &vis, uv64 &adj)
{
    vis[v] = 1;
    for (auto child : adj[v])
    {
        if (vis[child] == 0)
        {
            dfs(child, vis, adj);
        }
    }
}

void build(int arr[], int tree[], int s, int e, int tn)
{
    if (s == e)
    {
        tree[tn] = arr[s];
        return;
    }
    int mid = (s + e) / 2;
    build(arr, tree, s, mid, 2 * tn);
    build(arr, tree, mid + 1, e, (2 * tn) + 1);
    tree[tn] = max(tree[2 * tn],tree[(2 * tn) + 1]);
}

int query(int arr[], int tree[], int s, int e, int tn, int l, int r)
{
    int mid = (s + e) / 2;
    // out
    if (s > r || l > e)
    {
        return 0;
    }
    // in
    if (s >= l && r >= e)
    {
        return tree[tn];
    }
    int ans1 = query(arr, tree, s, mid, 2 * tn, l, r);
    int ans2 = query(arr, tree, mid + 1, e, (2 * tn) + 1, l, r);
    return max(ans1, ans2);
}

void update(int arr[], int tree[], int s, int e, int tn, int idx, int val)
{
    if (s == e)
    {
        arr[idx] = val;
        tree[tn] = val;
        return;
    }
    int mid = (s + e) / 2;
    if (idx > mid)
    {
        update(arr, tree, mid + 1, e, (2 * tn) + 1, idx, val);
    }
    else
    {
        update(arr, tree, s, mid, 2 * tn, idx, val);
    }
    tree[tn] = max(tree[2 * tn], tree[(2 * tn) + 1]);
}


class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        v32 res=obstacles;
        sort(all(res));
        map<int,int> hsh;
        ll cc=0;
        for(auto t:res)
        {
            if(hsh.count(t)==0)
            {
                cc++;
                hsh[t]=cc;
                // cout<<t<<" "<<cc<<endl;
            }
        }
        int arr[int(cc+1)];
        int tree[int(4*(cc)+1)];
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        build(arr,tree,0,(cc+1)-1,1);
        forn(i,sz(obstacles))
        {
            obstacles[i]=hsh[obstacles[i]];
            // cout<<obstacles[i]<<" ";
        }
        // cout<<endl;
        map<int,int> m;
        v32 ans;
        for(auto t:obstacles)
        {
            // largest no uske piche ka
            ll q=query(arr,tree,0,cc+1-1,1,0,t);
            ll past=1+q;
            // update the value of t
            // cout<<past<<" ";
            ans.push_back(past);
            update(arr,tree,0,cc+1-1,1,t,past);
        }
        // cout<<endl;
        return ans;
    }
};