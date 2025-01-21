class Solution {
  public:
  vector<Node*> reverse(Node *head, int count){
      Node* left = nullptr, *curr = head, *right;
      while(count --){
          right = curr -> next;
          curr -> next = left;
          left = curr;
          curr = right;
      }
      return {left, head, right};
  }
    Node *reverseKGroup(Node *head, int k) {
        int numNodes = 0;
        Node* temp = head;
        while(temp){
            numNodes ++;
            temp = temp -> next;
        }
        int numGrps = numNodes / k;
        int numRemain = numNodes % k;
        temp = head;
        Node* store = nullptr;
        Node* ans = nullptr;
        
        for(int i = 1; i <= numGrps + 1; i ++){
            vector<Node*> rev;
            // first group reversing
            if(i == 1) {
                
                if(i != numGrps + 1) {
                    
                    rev = reverse(temp, k);
                    ans = rev[0];
                    store = rev[1];
                    temp = rev[2];
                
                }else if(numRemain != 0) {
                    
                    rev = reverse(temp, numRemain);
                    ans = rev[0];
                    store = rev[1];
                    temp = rev[2];
                    
                }
        
            }else {
                
                if(i != numGrps + 1) {
                    
                    rev = reverse(temp, k);
                    store -> next = rev[0];
                    store = rev[1];
                    temp = rev[2];
                    
                }else if(numRemain != 0) {
                    
                    rev = reverse(temp, numRemain);
                    store -> next = rev[0];
                    store = rev[1];
                    temp = rev[2];
                    
                }
            }
        }
        return ans;
    }
};