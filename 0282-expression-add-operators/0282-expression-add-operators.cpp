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

vector<string> ans;
    ll calc(string& s, ll sz, ll i, char op) {
        ll j = i;
        long long first = 0, second = 0;
        while (j < sz && s[j] == ' ') j++;
        while (j < sz && s[j] >= '0' && s[j] <= '9') first = first * 10 + s[j++] - '0';
        if (op == '-') first = -first;
        while (j < sz) {
            while (j < sz && s[j] == ' ') j++;
            if (j < sz && s[j] == '+') return first + calc(s, sz, ++j, '+');
            if (j < sz && s[j] == '-') return first + calc(s, sz, ++j, '-');
            if (j < sz && (s[j] == '*' || s[j] == '/')) {
                char cop = s[j++];
                while (j < sz && s[j] == ' ') j++;
                while (j < sz && s[j] >= '0' && s[j] <= '9') second = second * 10 + s[j++] - '0';
                if (cop == '*')
                    first *= second;
                else first /= second;
                second = 0;
            }
        }
        return first;
    }
    ll calculate(string s) {
        ll sz = s.size();
        return calc(s, sz, 0, '+');
    }

ll target;


void sum(int idx,string &s,string &curr)
{
    int n=s.length();
    if(idx==n)
    {
        if(calculate(curr)==target)
        {
            // cout<<curr<<endl;
            ans.push_back(curr);
        }
        return;
    }
    // yha pr hm loop lga demge and new value ko * + - kr lenge prev val se
    if(s[idx]=='0')
    {
        // to simple sa + - * kr do val se
        curr.push_back('*');
        curr.push_back(s[idx]);
        sum(idx+1,s,curr);
        curr.pop_back();
        curr.pop_back();
        // ab +
        curr.push_back('+');
        curr.push_back(s[idx]);
        sum(idx+1,s,curr);
        curr.pop_back();    
        curr.pop_back();
        // ab - se
        curr.push_back('-');
        curr.push_back(s[idx]);
        sum(idx+1,s,curr);
        curr.pop_back();       
        curr.pop_back();
    }
    else
    {
        curr.push_back('+');
        for(int i=idx;i<n;i++)
        {
            curr.push_back(s[i]);
            sum(i+1,s,curr);
        }        
        for(int i=idx;i<n;i++)
        {
            curr.pop_back();
        }        
        curr.pop_back();
        curr.push_back('-');
        for(int i=idx;i<n;i++)
        {
            curr.push_back(s[i]);
            sum(i+1,s,curr);
        }        
        for(int i=idx;i<n;i++)
        {
            curr.pop_back();
        }        
        curr.pop_back();
        curr.push_back('*');
        for(int i=idx;i<n;i++)
        {
            curr.push_back(s[i]);
            sum(i+1,s,curr);
        }        
        for(int i=idx;i<n;i++)
        {
            curr.pop_back();
        }        
        curr.pop_back();                                
    }
}

class Solution {
public:
    vector<string> addOperators(string s, int t) {
        fast_cin();
        target=t;
        ans.clear();
        ll n=s.length();
        if(s[0]=='0')
        {
            string curr="0";
            sum(1,s,curr);
        }
        else
        {
            string curr="";
            for(ll i=0;i<n;i++)
            {
                curr.push_back(s[i]);
                sum(i+1,s,curr);
            }
        }
        return ans;
    }
};