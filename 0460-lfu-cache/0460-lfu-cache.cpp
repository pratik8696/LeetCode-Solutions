set<pair<pair<int,int>,int>> s;
unordered_map<int,int> m;
unordered_map<int,int> countt;
unordered_map<int,int> used_last;
int cc;
int val;

class LFUCache {
public:
    LFUCache(int capacity) {
        val=capacity;
        cc=0;
        m.clear();
        s.clear();
        countt.clear();
    }
    
    int get(int key) {
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
        return m[key];
    }
    
    void put(int key, int value) 
    {
        cc++;
        if(m.find(key)!=m.end())
        {
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
            if(val==s.size())
            {
                if(val)
                {
                    pair<pair<int,int>,int> it = *s.begin();
                    int value = it.second;
                    s.erase(s.begin());
                    m.erase(value);
                    countt.erase(value);
                    used_last.erase(value);
                }
            }
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