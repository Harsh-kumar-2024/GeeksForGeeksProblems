class Solution {
  public:
    Node* rotate(Node* head, int k) {
        int numNode = 0;
        Node *temp = head;
        
        while(temp){
            numNode ++;
            temp = temp -> next;
        }
        
        k = k % numNode;
        if(k == 0)
            return head;
        
        int numNodeSkip = 0;
        temp = head;
        Node * ans = nullptr;
        while(temp -> next){
            numNodeSkip ++;
            if(numNodeSkip == k){
                ans = temp -> next;
                temp -> next = nullptr;
                temp = ans;
            }else{
                temp = temp -> next;
            }
        }
        temp -> next = head;
        return ans;
    }
};