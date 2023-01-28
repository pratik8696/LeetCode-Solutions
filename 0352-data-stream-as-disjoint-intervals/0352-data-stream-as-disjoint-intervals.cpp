set<int> s;
class SummaryRanges {
public:
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        vector<int> temp;
        int prev=-3,start=-1,end=-1;
        s.insert(INT_MAX);
        for(auto t:s)
        {
            if(t-prev==1)
            {
                end=t;
                prev=t;
            }
            else
            {
                temp.push_back(start);
                temp.push_back(end);
                if(start!=-1)
                    ans.push_back(temp);
                temp.clear();
                prev=t;
                start=t;
                end=t;
            }
        }
        s.erase(INT_MAX);
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */