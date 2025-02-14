class Solution {
    public:
      int majorityElement(vector<int>& arr) {
          int n = arr.size();
          int ele;
          int cnt = 0;
          for(int i = 0; i < n; i ++){
              if(cnt == 0){
                  ele = arr[i];
                  cnt ++;
              }
              else if(arr[i] == ele){
                  cnt ++;
              }else{
                  cnt --;
              }
          }
          cnt = 0;
          for(int x : arr)
              if(x == ele)
                  cnt ++;
          if(cnt > n / 2) return ele;
          else return -1;
      }
  };