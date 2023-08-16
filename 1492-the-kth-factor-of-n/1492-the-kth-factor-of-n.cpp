class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> res;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(n/i==i)
                {
                    res.push_back(i);
                }
                else
                {
                    res.push_back(i);
                    res.push_back(n/i);
                }
            }
        }
        sort(begin(res),end(res));
        return (k>res.size()?-1:res[k-1]);
    }
};