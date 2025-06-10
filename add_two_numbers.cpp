#include<iostream> 
#include<vector>

using namespace std; 

struct ListNode{
public:   
     int val; 
     ListNode* next; 
     ListNode(): val(0), next(nullptr){}
     ListNode(int _val): val(_val), next(nullptr){}
     ListNode(int _val, ListNode* _next): val(_val), next(_next){}
};
class Solution{
public: 
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
       ListNode* dummy = new ListNode(0); 
       ListNode* curr = dummy; 
       int carry =0; 
       while(l1 !=nullptr || l2 != nullptr || carry !=0){
         int sum = carry; 
         if(l1!=nullptr) {
           sum += l1->val; 
           l1 = l1->next; 
         }
         if(l2!=nullptr){
           sum +=l2->val; 
           l2 = l2->next; 
         }
         carry = sum/10; 
         curr -> next = new ListNode(sum%10); 
         curr = curr ->next; 
       }
       return dummy -> next; 
     }
};
  ListNode* createList(const vector<int>& digits) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    for (int d : digits) {
        curr->next = new ListNode(d);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: (342) + (465) = (807)
    vector<int> v1 = {2, 4, 3}; // 342
    vector<int> v2 = {5, 6, 4}; // 465

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Sum List: ";
    printList(result);

    return 0;
}
