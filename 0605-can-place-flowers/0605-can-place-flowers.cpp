class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int k) {
        if(*max_element(begin(arr),end(arr))==0)
        {
            return (arr.size()+1)/2>=k;
        }
        int ans=0,cc=0;
        while(arr.size()&&arr.back()==0)
        {
            cc++;
            arr.pop_back();
        }
        reverse(begin(arr),end(arr));
        ans+=cc/2;
        cc=0;
        while(arr.size()&&arr.back()==0)
        {
            cc++;
            arr.pop_back();
        }
        reverse(begin(arr),end(arr));
        ans+=cc/2;
        cc=0;
        arr.push_back(-1);
        int n=arr.size(),prev=-1;
        for(int i=0;i<n;i++)
        {
            if(prev!=arr[i])
            {
                if(arr[i]==1)
                {
                    ans+=max((cc+1)/2-1,0);
                }
                prev=arr[i];
                cc=1;
            }
            else
            {
                cc++;
            }
        }
        cout<<ans<<endl;
        return ans>=k;
    }
};