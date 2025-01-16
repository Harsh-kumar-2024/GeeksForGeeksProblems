class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        map<int, int> mp;
        int maxLen = 0;
        int preSum = 0;
        for(int i = 0; i < n; i ++){
            preSum += (arr[i] == 0) ? -1 : 1;
            if (preSum == 0) 
                maxLen = i + 1;
            if (mp.find(preSum) != mp.end())
                maxLen = max(maxLen, i - mp[preSum]);
            else 
                mp[preSum] = i;
        }
        return maxLen;
    }
};