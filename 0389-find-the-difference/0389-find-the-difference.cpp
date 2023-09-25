class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hsh(26);
        for(auto x:s)
        {
            hsh[x-'a']--;
        }
        for(auto x:t)
        {
            hsh[x-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(hsh[i])
                return char('a'+i);
        }
        return 'a';
    }
};