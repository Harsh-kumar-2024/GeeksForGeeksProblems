class Solution {
    public:
      // Function to count inversions in the array.
      int merge(vector<int> &arr, int low, int mid, int high){
          
          vector<int> temp;
          int left = low;
          int right = mid + 1;
          int count = 0;
          
          while(left <= mid && right <= high){
              if(arr[left] <= arr[right]){
                  temp.push_back(arr[left]);
                  left ++;
              }else{
                  count += mid - left + 1;
                  temp.push_back(arr[right]);
                  right ++;
              }
          }
          
          while(left <= mid){
              temp.push_back(arr[left]);
              left ++;
          }
          
          while(right <= high){
              temp.push_back(arr[right]);
              right ++;
          }
          
          for(int i = 0; i < temp.size(); i ++){
              arr[low + i] = temp[i];
          }
          
          return count;
      }
      
      int mergeSort(vector<int> &temp, int left, int right){
          if(left >= right)
              return 0;
          int mid = (left + right) / 2;
          int one = mergeSort(temp, left, mid);
          int two = mergeSort(temp, mid + 1, right);
          int three =  merge(temp, left, mid, right);
          return one + two + three;
      }
      
      int inversionCount(vector<int> &arr) {
          vector<int> temp = arr;
          return mergeSort(temp, 0 , arr.size() - 1);
      }
  };