//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    
    Node* rev(Node* head){
        Node* p = NULL;
        Node* n = head;
        Node* c = head;
        
        while(n){
            n = n->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }

  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        while(num1->data == 0){
            num1 = num1->next;
        }
        
        while(num2->data == 0){
            num2 = num2->next;
        }
        
        Node* rNum1 = rev(num1);
        Node* rNum2 = rev(num2);
        
        int carry = 0;
        Node* ans = NULL;
        Node* maintain = NULL;
        
        while(rNum1 && rNum2){
            int sum = (rNum1->data)+(rNum2->data)+carry;
            carry = sum/10;
            sum %=10;
            
            if(ans==NULL){
                ans = new Node(sum);
                maintain = ans;
            }
            else{
                maintain->next = new Node(sum);
                maintain = maintain->next;
            }
            
            rNum1 = rNum1->next;
            rNum2 = rNum2->next;
            
        }
        
        while(rNum1){
            int sum = (rNum1->data)+carry;
            carry = sum/10;
            sum%=10;
            
            if(ans==NULL){
                ans = new Node(sum);
                maintain = ans;
            }
            else{
                maintain->next = new Node(sum);
                maintain = maintain->next;
            }
            
            rNum1 = rNum1->next;
            
        }
        
        while(rNum2){
            int sum = (rNum2->data)+carry;
            carry = sum/10;
            sum%=10;
            
            if(ans==NULL){
                ans = new Node(sum);
                maintain = ans;
            }
            else{
                maintain->next = new Node(sum);
                maintain = maintain->next;
            }
            
            rNum2 = rNum2->next;
            
        }
        
        if(carry){
            maintain -> next =new Node(carry);
        }
        
        return rev(ans);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends