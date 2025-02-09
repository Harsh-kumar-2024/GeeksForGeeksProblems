class Solution {
<<<<<<< HEAD
=======
    
>>>>>>> 4e1c229247b7feb1250f0f341c75dd8f01cd61a9
    private:
    void leftBoundary(vector<int> &ans, Node *root){
        if(!root)
            return;
        else if(!(root -> left) && !(root -> right))
            return;
        else if(!(root -> left)){
            ans.push_back(root -> data);
            leftBoundary(ans, root -> right);
        }
        else{
            ans.push_back(root -> data);
            leftBoundary(ans, root -> left);
        }
    }
    
    void leafNodes(vector<int> &ans, Node *root){
        if(!root)
            return;
        if(!(root -> left) && !(root -> right)){
            ans.push_back(root -> data);
        }
        leafNodes(ans, root -> left);
        leafNodes(ans, root -> right);
    }
    
    void rightBoundary(vector<int> &ans, Node *root){
        if(!root)
            return;
        else if(!(root -> left) && !(root -> right))
            return;
        else if(!(root -> right)){
            rightBoundary(ans, root -> left);
            ans.push_back(root -> data);
        }
        else{
            rightBoundary(ans, root -> right);
            ans.push_back(root -> data);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(!(root -> left) && !(root -> right))
            return {root -> data};
        ans.push_back(root -> data);
        if(root -> left)
            leftBoundary(ans, root -> left);
        leafNodes(ans, root);
        if(root -> right)
            rightBoundary(ans, root -> right);
        return ans;
    }
};