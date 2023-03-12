class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n=arr.size();
        multiset<int> right,left;
        for(auto t:arr)
        {
            right.insert(t);
        }
        for(int i=0;i<n-1;i++)
        {
            right.erase(right.find(arr[i]));
            if(left.size())
            {
                auto it=right.lower_bound(arr[i]);
                if(it==right.end())
                {
                    it--;
                }
                while(it!=right.begin()&&*it>=arr[i])
                {
                    it--;
                }
                // cout<<*left.begin()<<" "<<arr[i]<<" "<<*it<<endl;
                if(*it>*left.begin()&&*left.begin()<arr[i]&&*it<arr[i])
                {
                    return true;
                }
            }
            left.insert(arr[i]);
        }
        return false;
    }
};