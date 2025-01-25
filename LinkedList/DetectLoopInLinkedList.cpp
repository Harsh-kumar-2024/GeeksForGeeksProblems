class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        Node* fast = head;
        Node* slow = head;
        while(fast && slow){
            if(fast -> next && fast -> next -> next)
                fast = fast -> next -> next;
            else
            return false;
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
