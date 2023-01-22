#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
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
typedef unsigned long long ull;
typedef long long ll;
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
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define m64 map<ll, ll>
#define mv64 map<ll, v64>
#define u64 unordered_map<ll, ll>
#define uv64 unordered_map<ll, v64>
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
#define see(x) cout << x << ln


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        queue<pair<pair<int,int>,int>> q;
        int ans=INT_MAX;
        bool flag=false;
        int dx[8]={0,0,1,-1,1,-1,1,-1},dy[8]={1,-1,0,0,1,-1,-1,1};

        q.push({{0,0},1});
        vis[0][0]=1;

        if(g[0][0] != 0 || g[n-1][m-1]!=0)return -1;

        while(!q.empty()){
            auto t=q.front();
            int x=t.fi.fi;
            int y=t.fi.se;
            int cnt=t.se;
            q.pop();

            if(x==n-1 && y==m-1){
                ans=min(ans,cnt);
            }

            forn(i,8){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx>=0 && yy>=0 && xx<n && yy<m){
                    if(!vis[xx][yy] && g[xx][yy]==0){
                        q.push({{xx,yy},cnt+1});
                        vis[xx][yy]=1;
                    }
                }
            }
        }

        return (ans==INT_MAX?-1:ans);
    }
};