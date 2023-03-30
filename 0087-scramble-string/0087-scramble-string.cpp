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
string a,b;
int dp[31][31][31][31];
bool check(int i1,int j1,int i2,int j2)
{
    // cout<<"A is "<<a.substr(i1,j1-i1+1)<<" "<<i1<<" "<<j1<<endl;
    // cout<<"B is "<<b.substr(i2,j2-i2+1)<<" "<<i2<<" "<<j2<<endl;
    if(i2==j2)
    {
        return (a[i1]==b[i2]);
    }
    /*
    great
    01234
    rgaet
    01234
    aetrg
    */
    auto &x=dp[i1][j1][i2][j2];
    if(x!=-1)
    {
        return x;
    }
    int ans=0;
    vector<int> hsh1(26),hsh2(26);
    // same side rkha jaye
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