class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int n=nums.size();
        
        if(nums[i]<=nums[j])return nums[i];
        
        while(i<=j){
            int mid=i+(j-i)/2;
            int next=(mid+1)%n;
            int pre=(mid+n-1)%n;
            
            if(nums[mid]<=nums[next] && nums[mid]<=nums[pre]){
                return nums[mid];
            }
            else if(nums[i]<=nums[mid]&&nums[i]>nums[j]){
                i=mid+1;
            }
            else if(nums[mid]<=nums[j]){
                j=mid-1;
            }
        }
        return -1;
    }
};