bool check(int mid,vector<int> &tasks,vector<int> &arr,int pills,int strength)
{
    multiset<int> s;
    for(auto t:arr)
    {
        s.insert(t);
    }
    for(int i=mid-1;i>=0;i--)
    {
        // cout<<tasks[i]<<endl;
        auto it1=s.end();
        --it1;
        if(*it1>=tasks[i])
        {
            s.erase(it1);
        }
        else if(pills>0)
        {
            auto it=s.lower_bound(tasks[i]-strength);
            if(it!=s.end())
            {
                s.erase(it);
                pills--;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        
    }
    return true;
}

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(begin(tasks),end(tasks));
        sort(begin(workers),end(workers));
        int i=0,j=min(int(tasks.size()),int(workers.size())),ans=0;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(check(mid,tasks,workers,pills,strength))
            {
                i=mid+1;
                ans=mid;
            }
            else
            {
                j=mid-1;
            }
        }
        return ans;
    }
};