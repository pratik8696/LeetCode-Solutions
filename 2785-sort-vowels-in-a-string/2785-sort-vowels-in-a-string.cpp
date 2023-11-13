class Solution {
public:
    bool check(char x)
    {
        vector<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        for(auto t:vowels)
        {
            if(x==t)
            {
                return true;
            }
        }
        return false;
    }
    
    string sortVowels(string s) 
    {
        vector<char> vowels;
        for(auto t:s)
        {
            if(check(t))
            {
                vowels.push_back(t);
            }
        }
        sort(begin(vowels),end(vowels));    
        int j=0;
        for(auto &t:s)
        {
            if(check(t))
            {
                t=vowels[j++];
            }
        }
        return s;
    }
};