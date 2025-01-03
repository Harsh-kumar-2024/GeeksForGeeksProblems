class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int max1 = -1, max2 = -1;
        for(int i : arr){
            if(i > max1){
                max2 = max1;
                max1 = i;
            }
            else if(i > max2 && i != max1){
                max2 = i;
            }
        }
        return max2;
    }
};