class Solution {
    public:
    
      void inorder(Node* root, vector<int> &ans){
          if(!root)
              return;
          inorder(root -> left, ans);
          ans.push_back(root -> data);
          inorder(root -> right, ans);
      }
      int kthSmallest(Node *root, int k) {
          vector<int> ans;
          inorder(root, ans);
          if(ans.size() < k - 1)
              return -1;
          else return ans[k - 1];
      }
  };