class Solution {
    public:
      stack<pair<int, int> > s;
  
      Solution() {
          // code here
      }
  
       void push(int x) {
          int newMin = s.empty() ? x : min(x, s.top().second);
          s.push({ x, newMin });
      }
      
      void pop() {
          if (!s.empty()) {
              s.pop();
          }
      }
      
      int peek() {
          if (s.empty()) {
              return -1;
          }
  
          int top = s.top().first;
          return top;
      }
      
      int getMin() {
          if (s.empty()) {
              return -1;
          }
          
          int mn = s.top().second;
          return mn;
      }
  };