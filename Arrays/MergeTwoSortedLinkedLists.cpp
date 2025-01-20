class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node *temp1 = head1, *temp2 = head2;
        Node *newHead = nullptr;
        Node *curr = nullptr;
        while(temp1 && temp2){
            if(temp1 -> data <= temp2 -> data){
                if(!newHead){
                    newHead = temp1;
                    curr = temp1;
                    temp1 = temp1 -> next;
                }else{
                    curr -> next = temp1;
                    curr = curr -> next;
                    temp1 = temp1 -> next;
                }
            }else{
                if(!newHead){
                    newHead = temp2;
                    curr = temp2;
                    temp2 = temp2 -> next;
                }else{
                    curr -> next = temp2;
                    curr = curr -> next;
                    temp2 = temp2 -> next;
                }
            }
        }
        
        while(temp1){
            curr -> next = temp1;
            curr = curr -> next;
            temp1 = temp1 -> next;
        }
        
        while(temp2){
            curr -> next = temp2;
            curr = curr -> next;
            temp2 = temp2 -> next;
        }
        
        return newHead;
    }
};