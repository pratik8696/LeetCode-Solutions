class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a, vector<string>& b) {
        string x="",y="";
        for(auto t:a)
        {
            x+=t;
        }
        for(auto t:b)
        {
            y+=t;
        }
        if(x==y)
        {
            return true;
        }
        return false;        
    }
};