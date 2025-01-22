class Solution {
    Node* reverse(Node* head){
        Node* left = nullptr;
        Node* curr = head;
        Node* right = nullptr;
        while(curr){
            right = curr -> next;
            curr -> next = left;
            left = curr;
            curr = right;
        }
        return left;
    }

  public:
    Node* addTwoLists(Node* nums1, Node* nums2) {
        Node* num1 = reverse(nums1);
        Node* num2 = reverse(nums2);
        int sum = 0, carry = 0;
        Node* ans = nullptr, *trav = nullptr;

        while(num1 || num2 || carry) {
            sum = carry;
            if(num1) {
                sum += num1 -> data;
                num1 = num1 -> next;
            }
            if(num2) {
                sum += num2 -> data;
                num2 = num2 -> next;
            }
            
            carry = sum / 10;
            Node* temp = new Node(sum % 10);

            if(!ans) {
                ans = temp;
                trav = ans;
            } else {
                trav -> next = temp;
                trav = trav -> next;
            }
        }

        Node* newHead = reverse(ans);

        while(newHead && newHead->data == 0) {
            Node* temp = newHead;
            newHead = newHead->next;
            delete temp;
        }
        return newHead ? newHead : new Node(0);
    }
};