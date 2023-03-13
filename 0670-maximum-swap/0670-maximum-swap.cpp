class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string ans=s;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i+1;j<s.length();j++)
            {
                string res=s;
                swap(res[i],res[j]);
                if(res>ans)
                {
                    ans=res;
                }
            }
        }
        cout<<ans<<endl;
        return stoi(ans);
        // return 0;
    }
};