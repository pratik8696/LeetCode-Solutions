typedef long long ll;
struct node{
    node* nxt[27];
    int idx=0;
    node()
    {
        for(int i=0;i<27;i++)
        {
            this->nxt[i] = NULL;
        }
    }
};

node* root;

void insert(string s,int index)
{
    node* curr=root;
    for(auto t:s)
    {
        int res=int(t-'a');
        if(t=='#'){res=26;}
        if(curr->nxt[res]==NULL)
        {
            curr->nxt[res]=new node();
        }
        curr->nxt[res]->idx=index;
        curr=curr->nxt[res];
    }
}

int search(string s)
{
    node* curr=root;
    int ans=1e9;
    for(auto t:s)
    {
        int res=int(t-'a');
        if(t=='#'){res=26;}
        if(curr->nxt[res]==NULL)
        {
            return -1;
        }
        curr=curr->nxt[res];
    }
    return curr->idx;
}

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        root=new node();
        for(int j=0;j<words.size();j++)
        {
            auto &s=words[j];
            string curr=s+"#"+s;
            for(int i=0;i<=s.length();i++)
            {
                insert(curr.substr(i),j);
            }
        }
    }
    
    int f(string pref, string suff) 
    {
        return search(suff+"#"+pref);
    }
};