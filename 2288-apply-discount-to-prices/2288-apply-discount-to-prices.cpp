class Solution {
public:
    string discountPrices(string s, int discount) {
        s.push_back(' ');
        string res="",curr="";
        for(auto t:s)
        {
            if(t==' ')
            {
                if(curr[0]=='$')
                {
                    if(curr.size()>1)
                    {
                        bool flag=true;
                        for(int i=1;i<curr.size();i++)
                        {
                            if(!(int(curr[i]-'0')>=0&&int(curr[i]-'0')<=9))
                            {
                                flag=false;
                                break;
                            }
                        }   
                        long double val=0;
                        if(flag)
                        {
                            for(int i=1;i<curr.size();i++)
                            {
                                val=val*10+int(curr[i]-'0');
                            }   
                            val*=(100-discount);
                            val/=100;
                            string temp=to_string(val);
                            while(temp.size()>=3&&temp[temp.size()-3]!='.')
                            {
                                temp.pop_back();
                            }
                            curr="$"+temp;
                        }
                    }
                }
                res+=curr;
                res+=" ";
                curr.clear();
                
            }
            else
            {
                curr.push_back(t);
            }
        }
        res.pop_back();
        return res;
    }
};