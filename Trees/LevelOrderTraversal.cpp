class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        vector<Node*> table;
        table.push_back({root});
        while(!table.empty()){
            vector<Node*> tbl_add;
            vector<int> data_tmp;
            for(auto x : table){
                data_tmp.push_back(x -> data);
                if(x -> left){
                    tbl_add.push_back(x -> left);
                }
                if(x -> right){
                    tbl_add.push_back(x -> right);
                }
            }
            table = tbl_add;
            ans.push_back(data_tmp);
        }
        return ans;
    }
};