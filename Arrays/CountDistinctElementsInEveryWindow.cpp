class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> ans;
        map<int, int> mp;
        for(int i = 0; i < k; i ++)
            mp[arr[i]] ++;
        ans.push_back(mp.size());
        int left = 0;
        for(int i = k; i <n; i ++){
            mp[arr[left]] --;
            if(mp[arr[left]] == 0){
                mp.erase(arr[left]);
            }
            mp[arr[i]] ++;
            ans.push_back(mp.size());
            left ++;
        }
        return ans;
    }
};