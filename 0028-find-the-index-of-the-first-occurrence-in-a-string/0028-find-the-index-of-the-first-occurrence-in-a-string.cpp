vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        string res=needle+"#"+haystack;
        vector<int> v=prefix_function(res);
        for(int i=0;i<v.size();i++)
        {
            if(needle.length()==v[i])
            {
                return i-2*needle.size();
            }
        }
        return -1;
    }
};