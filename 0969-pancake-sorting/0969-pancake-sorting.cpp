class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int j=arr.size()-1,cc=arr.size(),i=0;
        while(j >= 0)
        {
            while(j>=0 && arr[j] == cc){j--,cc--;}
            if(j<0){break;}
            for(i=0;i<j;i++){if(arr[i]==cc){break;}}
            reverse(begin(arr),begin(arr)+i+1);
            reverse(begin(arr),begin(arr)+j+1);
            ans.push_back(i+1);
            ans.push_back(j+1);
        }
        return ans;
    }
};