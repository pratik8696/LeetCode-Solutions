string a,b;
int dp[50][50][50][50];

bool isvalid(vector<int> &a,vector<int> &b)
{
    for(int i=0;i<26;i++)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}

bool check(int i1,int j1,int i2,int j2)
{
    if(i2==j2)
    {
        return (a[i1]==b[i2]);
    }
    auto &x=dp[i1][j1][i2][j2];
    if(x!=-1)
    {
        return x;
    }
    vector<int> hsh1(26),hsh2(26);
    int ans=0;
    // same side 
    for(int idx1=i1,idx2=i2;idx1<j1&idx2<j2;idx1++,idx2++)
    {
        hsh1[int(a[idx1]-'a')]++;
        hsh2[int(b[idx2]-'a')]++;
        if(isvalid(hsh1,hsh2))
        {
            ans|=(check(i1,idx1,i2,idx2)&check(idx1+1,j1,idx2+1,j2));
        }
    }
    // alternate side swap
    fill(hsh1.begin(),hsh1.end(),0);
    fill(hsh2.begin(),hsh2.end(),0);
    for(int idx1=i1,idx2=j2;idx1<j1&idx2>0;idx1++,idx2--)
    {
        hsh1[int(a[idx1]-'a')]++;
        hsh2[int(b[idx2]-'a')]++;
        if(isvalid(hsh1,hsh2))
        {
            ans|=(check(i1,idx1,idx2,j2)&check(idx1+1,j1,i2,idx2-1));
        }
    }
    fill(hsh1.begin(),hsh1.end(),0);
    fill(hsh2.begin(),hsh2.end(),0);
    for(int idx1=j1,idx2=i2;idx1>0&idx2<j2;idx1--,idx2++)
    {
        hsh1[int(a[idx1]-'a')]++;
        hsh2[int(b[idx2]-'a')]++;
        if(isvalid(hsh1,hsh2))
        {
            ans|=(check(idx1,j1,i2,idx2)&check(i1,idx1-1,idx2+1,j2));
        }
    }
    return x = ans;
}

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
        {
            return false;
        }
        a=s1,b=s2;
        memset(dp,-1,sizeof(dp));
        int n=s1.length();
        return check(0,n-1,0,n-1);
    }
};