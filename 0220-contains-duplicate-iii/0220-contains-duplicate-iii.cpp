typedef long long ll;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        ll n=nums.size();
        multiset<ll> s;
        ll diff=1e18;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(s.size()>=indexDiff+1)
            {
                auto it1=s.find(nums[j]);
                ll front=1e17;
                ll back=-1e17;
                if(it1!=s.begin())
                {
                    it1--;
                    front=*it1;
                    it1++;
                }
                it1++;
                if(it1!=s.end())
                {
                    back=*it1;
                }
                diff=min(abs(front-back),diff);
                s.erase(s.find(nums[j]));
                j++;
            }
            auto it=s.lower_bound(nums[i]);
            if(s.size()==0)
            {
                s.insert(nums[i]);
            }
            else
            {
                ll front=1e17;
                ll back=-1e17;
                auto it=s.lower_bound(nums[i]);
                if(it!=s.end())
                {
                    back=*it;
                }
                if(it!=s.begin())
                {
                    it--;
                    front=*it;
                }
                diff=min(diff,abs(front-nums[i]));
                diff=min(diff,abs(back-nums[i]));
                s.insert(nums[i]);
            }
            if(diff<=valueDiff)
            {
                return true;
            }
        }
        
        return false;
    }
};