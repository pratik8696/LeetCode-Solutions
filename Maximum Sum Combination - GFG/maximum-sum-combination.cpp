//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &b, vector<int> &a) {
        multiset<int> pq;
        sort(begin(a),end(a),greater<int>());
        sort(begin(b),end(b),greater<int>());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pq.size()<k)
                {
                    pq.insert(a[i]+b[j]);
                }
                else if(pq.size() == k && *pq.begin() < a[i]+b[j])
                {
                    pq.erase(pq.begin());
                    pq.insert(a[i]+b[j]);
                }
                else
                {
                    break;
                }
            }
        }
        vector<int> ans;
        for(auto t:pq)
        {
            ans.push_back(t);
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends