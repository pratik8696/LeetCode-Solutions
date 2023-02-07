class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        int i=0,k=0,ans=0;
        for(int j=0;j<n;j++)
        {
            // add
            m[arr[j]]++;
            if(m[arr[j]]==1)
            {
                k++;
            }
            // good
            while(k>2)
            {
                // remove
                m[arr[i]]--;
                if(m[arr[i]]==0)
                {
                    k--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};