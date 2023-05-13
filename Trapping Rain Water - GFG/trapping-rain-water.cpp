//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

typedef long long ll;

class Solution{


    ll trap(int height[],int n) {
        // int n = height.size();
        ll left = 0, right = n - 1;
        ll left_max = 0, right_max = 0;
        ll ans = 0;
    
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    ans += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    ans += right_max - height[right];
                }
                right--;
            }
        }
    
        return ans;
    }


    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        return trap(arr,n);
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends