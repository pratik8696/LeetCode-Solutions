class Encrypter {
public:
    map<char,string> m;
    map<string,int> counter;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) 
    {
        for(int i=0;i<keys.size();i++)
        {
            m[keys[i]]=values[i];
        }
        for(auto s:dictionary)
        {
            string ans="";
            for(int i=0;i<s.length();i++)
            {
                ans+=m[s[i]];
            }
            if(ans.length()==s.length()*2)
                counter[ans]++;
        }
    }
    
    string encrypt(string s) 
    {
        string ans="";
         for(int i=0;i<s.length();i++)
         {
            if(m.count(s[i]))
            {
                ans+=m[s[i]];
            }
             else
             {
                 return "";
             }
         }
        return ans;
    }
    
    int decrypt(string s) 
    {
        return counter[s];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */