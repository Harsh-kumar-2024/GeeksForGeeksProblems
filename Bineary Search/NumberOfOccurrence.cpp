//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        vector<int> pos(2, -1);
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low ) / 2;
            if(target == nums[mid]){
                pos[1] = mid;
                low = mid + 1;
            }else if(target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }

        low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low ) / 2;
            if(target == nums[mid]){
                pos[0] = mid;
                high = mid - 1;
            }else if(target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        if(pos[0] == -1)
            return 0;
        return pos[1] - pos[0] + 1;
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends