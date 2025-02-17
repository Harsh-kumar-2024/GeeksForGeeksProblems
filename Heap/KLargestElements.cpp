class Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
          priority_queue<int, vector <int>, greater<int>> pq;
          for(int i : arr){
              pq.push(i);
              if(pq.size() > k)
                  pq.pop();
          }
          vector<int> ans;
          while(!pq.empty())
          {
              ans.push_back(pq.top());
              pq.pop();
          }
          reverse(ans.begin(),ans.end());
          
          return ans;
      }
  };