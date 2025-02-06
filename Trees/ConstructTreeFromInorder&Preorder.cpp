class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    
    Node *buildTreeRec(unordered_map<int, int> &mp, vector<int> &pre, int &preIndex, int left, int right){
        if(left > right)
            return nullptr;
            
        int rootval = pre[preIndex];
        int index = mp[rootval];
        preIndex++;
        Node *root = new Node(rootval);
        root -> left = buildTreeRec(mp, pre, preIndex, left, index - 1);
        root -> right = buildTreeRec(mp, pre, preIndex, index + 1, right);
        return root;
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i ++){
            mp[inorder[i]] = i;
        }
        int preIndex = 0;
        return buildTreeRec(mp, preorder, preIndex, 0, inorder.size() - 1);
    }
};