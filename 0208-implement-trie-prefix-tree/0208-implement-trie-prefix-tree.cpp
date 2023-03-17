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
 
bool search_node(string s)
{
    node *curr = root;
    for(int i=0;i<s.length();i++)
    {
        ll temp = s[i] - 'a';
        if (curr->nxt[temp] == NULL)
        {
            return false;
        }
        curr = curr->nxt[temp];
    }
    return curr->is_end;
}


class Trie {
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        insert_node(word);
    }
    
    bool search(string word) {
        return search_node(word);
    }
    
    bool startsWith(string s) {
        node *curr=root;
        for(int i=0;i<s.length();i++)
        {
            int temp=s[i]-'a';
            if(curr->nxt[temp]==NULL)
            {
                return false;
            }
            curr=curr->nxt[temp];
        }
        return true;
    }
};