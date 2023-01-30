#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

set<pair<pair<int,int>,int>> s;
unordered_map<int,int> m;
unordered_map<int,int> countt;
unordered_map<int,int> used_last;
int cc;
int val;

class LFUCache {
public:
    LFUCache(int capacity) {
        fast_cin();
        val=capacity;
        m.clear();
        s.clear();
        countt.clear();
        cc=0;
    }
    
    int get(int key) {
        fast_cin();
        // cout<<"Key le le mu mai "<<key<<endl;
        if(m.find(key)==m.end())
        {
            return -1;
        }
        
        cc++;
        countt[key]++;
        
        auto it=s.find({{countt[key]-1,used_last[key]},key});
        
        if(it!=s.end())
            s.erase(it);
        
        
        used_last[key]=cc;
        s.insert({{countt[key],used_last[key]},key});
        
        // for(auto t:s)
        // {
        //     cout<<t.first.first<<" "<<t.first.second<<" "<<t.second<<endl;
        // }
        
        return m[key];
    }
    
    void put(int key, int value) 
    {
        fast_cin();
        // cout<<"VAL PAIR"<<endl;
        // cout<<key<<" "<<value<<endl;
        // cout<<s.size()<<endl;
        cc++;
        // if present then update
        if(m.find(key)!=m.end())
        {
            // use ko bhi update krna pdega
            countt[key]++;
            
            
            auto it=s.find({{countt[key]-1,used_last[key]},key});
            
            if(it!=s.end())
                s.erase(it);
            
            used_last[key]=cc;
            
            s.insert({{countt[key],used_last[key]},key});
            m[key]=value;
        }
        else
        {
            // for(auto t:s)
            // {
            //     cout<<t.first.first<<" "<<t.first.second<<" "<<t.second<<endl;
            // }
            // if full capacity 
            if(val==s.size())
            {
                // remove the least used
                if(val)
                {
                    pair<pair<int,int>,int> it = *s.begin();

                    int value = it.second;

                    // cout<<value<<" "<<it.first.first<<" "<<it.first.second<<endl;

                    s.erase(s.begin());
                    m.erase(value);
                    countt.erase(value);
                    used_last.erase(value);
                }
            }
            
            // then insert the element 
            if(val)
            {
                countt[key]++;
                used_last[key]=cc;
                s.insert({{countt[key],used_last[key]},key});
                m[key]=value;
            }
        }
    }
};