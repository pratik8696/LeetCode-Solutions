typedef long long ll;
typedef vector<ll> v64;
#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<char> sz;
struct DSU
{
    v64 e;
    DSU(ll n)
    {
        e.assign(n + 1, -1);
    }
    bool same(ll a, ll b) { return find(a) == find(b); }
    char size(ll x) { return sz[find(x)]; }
    ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    void join(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            e[b] = a;
            sz[a] = min(sz[b],sz[a]);
        }
    }
};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        fast_cin();
        vector<char> x;
        for(char a='a';a<='z';a++)
        {
            x.pb(a);
        }
        sz=x;
        DSU d(26);
        for(int i=0;i<s1.size();i++)
        {
            d.join(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++)
        {
            baseStr[i]=d.size(baseStr[i]-'a');
        }
        return baseStr;
    }
};