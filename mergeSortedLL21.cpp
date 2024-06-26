/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr || list2 ==nullptr)
        {
           if(list1 == nullptr)
           {
            return list2;
           }
           else
           {
            return list1;
           }
        }
        else
        {
            ListNode* small;
            ListNode* other;
            ListNode* prev;

            if(list1->val<list2->val)
            {
                small = list1;
                other = list2;
            }
            else
            {
                small = list2;
                other = list1;
            }

            ListNode* head = small;
            small = small->next;
            prev = head;

            while(small != nullptr)
            {

                if(small->val <= other->val)
                {
                    prev->next = small;
                    prev = prev->next;
                    small = small->next; 
                }
                else
                {
                    //swap
                    ListNode* swap;
                    swap = small;
                    small = other;
                    other = swap;
                }
            }

            if(small == nullptr)
            {
                //prev = small;
                prev->next = other;
            }

            return head;
        }
        
    }

int main()
{

    //to be completed with test cases
    return 0;
}