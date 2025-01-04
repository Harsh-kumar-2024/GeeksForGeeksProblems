class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long count = 0;
        unordered_map<int, int> ump;
        int currXOR = 0;
        for(int num : arr){
            currXOR = currXOR ^ num;
            count += ump[currXOR ^ k];
            if(currXOR == k)
                count ++;
            ump[currXOR] ++;
        }
        return count;
    }
};