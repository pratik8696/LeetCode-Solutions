class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int skip_s=0;
        int skip_tt=0;
        int i=s.length()-1,j=t.length()-1;
        while(i>=0&&j>=0)
        {
            if(s[i]=='#')
            {
                skip_s++;
                i--;
            }
            else if(t[j]=='#')
            {
                skip_tt++;
                j--;
            }
            else
            {
                if(skip_s==0&&skip_tt==0)
                {
                    if(s[i]==t[j])
                    {
                        // good 
                        i--,j--;
                    }
                    else
                    {
                        // cout<<"MERA 1"<<endl;
                        return false;
                    }
                }
                else if(skip_s)
                {
                    skip_s--;
                    i--;
                }
                else if(skip_tt)
                {
                    skip_tt--;
                    j--;
                }
            }
        }
        cout<<i<<" "<<j<<endl;
        while(i>=0)
        {
            if(s[i]=='#')
            {
                skip_s++;
                i--;
            }
            else
            {
                if(skip_s==0)
                {
                    // cout<<"MERA 2"<<endl;
                    return false;
                }
                else
                {
                    skip_s--;
                    i--;
                }
            }
        }
        while(j>=0)
        {
            if(t[j]=='#')
            {
                skip_tt++;
                j--;
            }
            else
            {
                if(skip_tt==0)
                {
                    // cout<<"MERA 3"<<endl;
                    return false;
                }
                else
                {
                    skip_tt--;
                    j--;
                }
            }
        }
        return true;
    }
};