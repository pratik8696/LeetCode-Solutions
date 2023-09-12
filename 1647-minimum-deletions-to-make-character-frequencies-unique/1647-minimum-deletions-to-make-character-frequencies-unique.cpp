class Solution {
public:
    int minDeletions(string x) {
        map<char,int> m;
        vector<int> arr;
        for(auto t:x)
        {
            m[t]++;
        }
        set<int> s;
        for(int i=1;i<x.length()+26;i++)
        {
            s.insert(i);
        }
        for(auto t:m)
        {
            arr.push_back(t.second);
        }
        sort(begin(arr),end(arr));
        // for(auto t:arr)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;
        int ans=0;
        for(auto t:arr)
        {
            auto it=s.upper_bound(t);
            // cout<<t<<" "<<*it<<endl;
            if(s.begin()==it)
            {
                // cout<<"BEGIN"<<endl;
                // zero maro isko    
                ans+=t;
            }
            else
            {
                // cout<<"NOT BEGIN"<<endl;
                it--;
                if(*it==t)
                {
                    ans+=0;
                }
                else
                {
                    ans+=t-*it;
                }
                s.erase(it);
            }   
        }
        return ans;
    }
    // 1 2 2 3
};