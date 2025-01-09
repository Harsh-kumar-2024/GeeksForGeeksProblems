class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        vector<int> ans = {-1};
        map<int, int> mp;
        int prefixSum = 0;
        for(int i = 0; i < n; i ++){
            prefixSum += arr[i];
            if(prefixSum == target){
                ans[0] = mp[prefixSum - target] + 1;
                ans.push_back(i + 1);
                break;
            }
    
            if(mp.find(prefixSum - target) != mp.end()){
                ans[0] = mp[prefixSum - target] + 2;
                ans.push_back(i + 1);
                break;
            }
            if(mp.find(prefixSum) == mp.end())
                mp[prefixSum] = i;
        }
        
        // for(auto it : mp){
        //     cout << it.first << " " << it.second << endl;
        // }
        return ans;
    }
};