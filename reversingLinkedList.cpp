#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 // Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    
    while (curr != nullptr) {
        next = curr->next; // Save the next node
        curr->next = prev; // Reverse the current node's pointer
        prev = curr;       // Move prev to the current node
        curr = next;       // Move to the next node
    }
    return prev; // New head of the reversed list
}

 void printList(ListNode* head)
 {
    ListNode* temp = head;
    while(temp!= nullptr)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
 }

 int main()
 {
    int n;
    cin>>n;

    ListNode* head = nullptr;
    ListNode* temp;
    for(int i = 0; i<n; i++)
    {
      int element; 
      cin>>element;
      if(head == nullptr)
      {
         head = new ListNode(element);
         temp = head;
      }
      else{
      temp->next = new ListNode(element);
      temp = temp->next;
      }
    }

    printList(head);

    head = reverseList(head);
    printList(head);
 }