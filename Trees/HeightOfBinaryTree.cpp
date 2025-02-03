class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        if(!node) return -1;
        int left = height(node -> left) + 1;
        int right = height(node -> right) + 1;
        return max(left, right);
    }
};