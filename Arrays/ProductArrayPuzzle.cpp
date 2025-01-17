class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;
        int prod = 1, idx = -1;
        for(int i = 0; i < n; i ++){
            if(arr[i] == 0){
                zeros ++;
                idx = i;
            }else{
                prod *= arr[i];
            }
        }
        
        vector<int> ans(n, 0);
        if(zeros == 0){
            for(int i = 0; i < n; i ++){
                ans[i] = prod / arr[i];
            }
        }
        else if(zeros == 1){
            for(int i = 0; i < n; i ++){
                if(arr[i] == 0)
                    ans[i] = prod;
            }
        }
        return ans;
    }
};