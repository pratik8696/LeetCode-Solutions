class Solution {
public:
    vector<int> par;
    int find(int v){
        if(par[v]==v)return v;
        return par[v]=find(par[v]);
    }
    void uni(int x,int y){
        x=find(x),y=find(y);
        if(x!=y){
            par[max(x,y)]=min(x,y);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& g) {
        int n = g.size();
        par.clear();
        for(int i=0;i<n+1;i++)par.push_back(i);
        map<string,int> m;

        for(int i=0;i<n;i++){
            for(int j=1;j<g[i].size();j++){
                if(m.find(g[i][j]) == m.end()){
                    m[g[i][j]]=i;
                }
                else{
                    uni(i,m[g[i][j]]);
                }
            }
        }

        vector<string> merge_mail[n];
        vector<vector<string>> ans;

        for(auto t:m){
            int node=t.second;
            string email=t.first;
            merge_mail[find(node)].push_back(email);
        }

        for(int i=0;i<n;i++){
            if(merge_mail[i].size()==0)continue;
            vector<string> curr;
            curr.push_back(g[i][0]);
            sort(merge_mail[i].begin(),merge_mail[i].end());
            for(auto t : merge_mail[i]){
                curr.push_back(t);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};