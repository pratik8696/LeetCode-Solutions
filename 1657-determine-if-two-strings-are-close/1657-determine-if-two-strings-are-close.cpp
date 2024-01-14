class Solution {
public:
    bool closeStrings(string a, string b) {
        vector<int> hsh1(26);
        vector<int> hsh2(26);
        set<int> s1,s2;
        for(auto t:a)
        {
            hsh1[int(t-'a')]++;
            s1.insert(t);
        }
        for(auto t:b)
        {
            hsh2[int(t-'a')]++;
            s2.insert(t);
        }
        sort(begin(hsh1),end(hsh1));
        sort(begin(hsh2),end(hsh2));
        return hsh1==hsh2&&s1==s2;
    }
};