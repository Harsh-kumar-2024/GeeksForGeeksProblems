class Solution {
    public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
          vector<vector<int>> ans;
          for(int i = 0; i < points.size(); i ++){
              int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
              pq.push({dis, i});
              if(pq.size() > k)
                  pq.pop();
          }
          while(!pq.empty()){
              ans.push_back(points[pq.top().second]);
              pq.pop();
          }
          return ans;
      }
  };