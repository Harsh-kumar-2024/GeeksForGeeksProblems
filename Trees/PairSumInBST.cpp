class Solution {
    public:
      bool traverse(Node* root, unordered_set<int> &s, int target){
          if(!root)
              return false;
          if(s.find(target - root -> data) != s.end())
              return true;
          s.insert(root -> data);
          return traverse(root -> left, s, target) || traverse(root -> right, s, target); 
      }
      bool findTarget(Node *root, int target) {
          unordered_set<int> u_set;
          return traverse(root, u_set, target);
      }
  };