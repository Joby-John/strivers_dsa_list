//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten(Node* root);

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node* temp = NULL;
        struct Node* head = NULL;
        struct Node* pre = NULL;
        struct Node* tempB = NULL;
        struct Node* preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            } else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                } else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node* fun = head;
        Node* fun2 = head;

        Node* root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

//function to merge two sorted ll

Node* mergeList(Node* l1, Node* l2)
{
    if( l1 == nullptr)
    {
        return l2;
    }
    else if(l2 == nullptr)
    {
        return l1;
    }
    else
    {
        Node* small;
        Node* other;
        
        if(l1->data <= l2->data)
        {
            small = l1;
            other = l2;
        }
        else
        {
            small = l2;
            other = l1;
        }
        
        Node* head = small;
        Node* temp = head;
        
        while(small!=nullptr)
        {
            if(small->data <= other->data)
            {
                temp->bottom = small;
                temp = temp->bottom;
                small = small->bottom;
            }
            else
            {
                //swap
                Node* swap = small;
                small = other;
                other = swap;
            }
        }
        
        if(small == nullptr)
        {
            temp->bottom = other;
        }
        
        return head;
    }
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root) {
    // Your code here
    if(root == nullptr || root->next == nullptr)
    {
        return root;
    }
    
    root->next = flatten(root->next);
    
    //merge
    root = mergeList(root, root->next);
    
    return root;
    
}
