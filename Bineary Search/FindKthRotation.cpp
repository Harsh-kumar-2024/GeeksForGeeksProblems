//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans_index;
        int ans = INT_MAX;
        while(left <= right){
            int mid = left + ( right - left ) / 2;
            if(arr[left] <= arr[mid]) {
                if(arr[left] < ans){
                    ans_index = left;
                    ans = arr[left];
                }
                left = mid + 1;
            }
            else {
                if(arr[mid] < ans){
                    ans_index = mid;
                    ans = arr[mid];
                }
                right = mid - 1;
            }
        }
        return ans_index;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends