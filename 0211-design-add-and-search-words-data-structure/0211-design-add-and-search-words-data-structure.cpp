typedef long long ll;
struct node
{
    node *nxt[26];
    bool is_end;
    node()
    {
        for(int i=0;i<26;i++)
        {
            this->nxt[i] = NULL;
        }
        this->is_end = false;
    }
};
 
node *root;
 
void insert_node(string &s)
{
    node *curr = root;
    for(int i=0;i<s.length();i++)
    {
        ll temp = s[i] - 'a';
        if (curr->nxt[temp] == NULL)
        {
            curr->nxt[temp] = new node();
        }
        curr = curr->nxt[temp];
    }
    curr->is_end = true;
}
 
bool search_node(string &s,node* curr,int idx)
{
    if(idx==s.length())
    {
        return curr->is_end;
    }
    bool ans=0;
    if(s[idx]=='.')
    {
        for(int i=0;i<26;i++)
        {
            if(curr->nxt[i]!=NULL)
            {
                if(search_node(s,curr->nxt[i],idx+1))
                {
                    ans=1;
                }
            }
        }
    }
    else
    {
        int temp=s[idx]-'a';
        if(curr->nxt[temp]!=NULL)
        {
            if(search_node(s,curr->nxt[temp],idx+1))
            {
                ans=1;
            }
        }
    }
    return ans;
}


class WordDictionary {
public:
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        insert_node(word);
    }
    
    bool search(string s) {
        node *curr=root;
        return search_node(s,curr,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */