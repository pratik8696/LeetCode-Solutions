class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n=a.size(),prev=0;
        vector<pair<int,int>> arr,ans;
        for(auto t:a)
        {
            arr.push_back({t[0],t[1]});
        }
        sort(begin(arr),end(arr));
        // for(auto t:arr)
        // {
        //     cout<<t.first<<" "<<t.second<<endl;
        // }
        // cout<<endl;
        // cout<<endl;
        ans.push_back({arr[0].first,arr[0].second});
        prev = ans.back().second;
        for(int i=1;i<n;i++)
        {
            // cout<<arr[i].first<<" "<<arr[i].second<<" "<<prev<<endl;
            if(prev >= arr[i].first)
            {
                ans.back().second=0;
                prev = min(prev,arr[i].second);
                // cout<<"INSIDE"<<endl;
                // cout<<arr[i].first<<" "<<arr[i].second<<" "<<prev<<endl;                
            }
            else
            {
                // cout<<"OUTSIDE"<<endl;
                prev = arr[i].second;
                ans.push_back(arr[i]);
            }
        }
        // for(auto t:ans)
        // {
        //     cout<<t.first<<" "<<t.second<<endl;
        // }
        // cout<<ans.size()<<endl;
        return (int)ans.size();
    }
};