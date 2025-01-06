class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        vector<int> ans(2);
        sort(arr.begin(), arr.end());
        if(arr.size() < 2) return {};
        int left = 0, right = arr.size() - 1;
        int minDiff = INT_MAX;
        while(left < right){
            int sum = arr[left] + arr[right];
            int currDiff = abs(target - sum);
            if(minDiff > currDiff){
                minDiff = currDiff;
                ans[0] = arr[left];
                ans[1] = arr[right];
            }else if(minDiff == currDiff){
                if(abs(ans[0] - ans[1]) < abs(arr[left] - arr[right])){
                    ans[0] = arr[left];
                    ans[1] = arr[right];
                }
            }
            if(sum == target){
                left ++;
                right --;
            }
            else if(sum < target){
                left ++;
            }else{
                right --;
            }
            
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};