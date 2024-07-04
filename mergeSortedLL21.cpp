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

    //recurssion
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    ListNode* result;

    if (list1->val < list2->val) {
        result = list1;
        result->next = mergeLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeLists(list1, list2->next);
    }
    return result;
}

int main()
{

    int n; 
    cin>>n;
    ListNode* l1 = nullptr;
    ListNode* temp;

    for(int i = 0; i<n; i++)
    {
        int element;
        cin>>element;
        if(l1 == nullptr)
        {
            l1 = new ListNode(element);
            temp = l1;
        }
        else
        {
            temp->next = new ListNode(element);
            temp = temp->next;
        }
    }

    //secondList

    cin>>n;

    ListNode* l2 = nullptr;

    for(int i = 0; i<n; i++)
    {
        int element;
        cin>>element;
        if(l2 == nullptr)
        {
            l2 = new ListNode(element);
            temp = l2;
        }
        else
        {
            temp->next = new ListNode(element);
            temp = temp->next;
        }
    }

    ListNode* res = mergeTwoLists(l1, l2);

    while(res!=nullptr)
    {
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;

    // res = mergeLists(l1, l2);
    // while(res!=nullptr)
    // {
    //     cout<<res->val<<" ";
    //     res = res->next;
    // }
    // cout<<endl;

    return 0;
}