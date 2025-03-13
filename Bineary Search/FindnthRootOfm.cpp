//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int nthRoot(int n, int m) {
        int left = 1, right = m;
        int ans = -1;
        while(left <= right){
            int mid = left + ( right - left ) / 2;
            int nthmul = 1;
            for(int i = 1; i <= n; i ++)
                nthmul *= mid;
            if(nthmul == m){
                ans = mid;
                break;
            }
            else if(nthmul > m){
                right = mid - 1;
            }
            else{
                left = mid + 1;    
            }
        }
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends