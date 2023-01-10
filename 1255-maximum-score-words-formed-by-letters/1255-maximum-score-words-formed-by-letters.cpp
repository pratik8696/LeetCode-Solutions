class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> m;
        int xyz=words.size();
        for(auto t:letters)
        {
            m[t]++;
        }
        int res=0;
        // cout<<xyz<<endl;
        for(int mask=1;mask<pow(2,xyz);mask++)        
        {
            unordered_map<char,int> hsh;
            
            int ans=0;
            // cout<<"MASK IS "<<mask<<endl;
            for(int j=0;j<xyz;j++)
            {
                int res=mask & (1<<j);
                if(res)
                {
                    auto &s = words[j];
                    // cout<<s<<" ";
                    int n = s.length();
                    for(int i=0;i<n;i++)
                    {
                        hsh[s[i]]++;
                        ans+=score[s[i]-'a'];
                    }
                }
            }
            // cout<<endl;
            int flag=1;
            
            // cout<<ans<<endl;
            
            for(char a='a';a<='z';a++)
            {
                if(hsh[a] > m[a])
                {
                    flag = 0;
                    ans=0;
                    break;
                }
            }
            
            if(flag)
            {
                res=max(res,ans);
            }            
        }
        return res;
    }
};