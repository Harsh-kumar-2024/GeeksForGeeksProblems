class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int cnt = 0;
        int left = 0, right = arr.size() - 1;
        while(left < right){
            int currSum = arr[left] + arr[right];
            if(currSum < target){
                left ++;
            }
            else if(currSum > target){
                right --;
            }
            else{
                if(arr[left] == arr[right]){
                  int same = right - left + 1;
                  return cnt + (same * (same - 1)) / 2;
                }
                int lcnt = 1;
                int rcnt = 1;
                while(left < right && arr[left] == arr[left + 1]){
                    left ++;
                    lcnt ++;
                }
                while(left < right && arr[right] == arr[right - 1]){
                    right --;
                    rcnt ++;
                }
                cnt += lcnt * rcnt;
                left ++;
                right --;
            }
        }
        return cnt;
    }
};