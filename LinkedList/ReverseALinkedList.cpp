class Solution {
  public:
    Node* reverseList(struct Node* head) {
        if(!(head -> next)) return head;
        Node *back = nullptr, *curr = head, *forward = head -> next;
        while(curr){
            curr -> next = back;
            back = curr;
            curr = forward;
            if(forward)
                forward = forward -> next;
        }
        return back;
    }
};