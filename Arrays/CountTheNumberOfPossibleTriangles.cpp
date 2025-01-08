class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        sort(arr.begin(), arr.end());
        for(int i = 2; i < n; i ++){
            int left = 0, right = i - 1;
            while(left < right){
                if (arr[left] + arr[right] > arr[i]) {
                cnt += right - left; 
                right--; 
            } 
              else {
                    left++; 
                }
            }
        }
        return cnt;
    }
};