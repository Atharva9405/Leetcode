//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool isOperand(char ch){
    return (ch>='a' && ch<='z') || (ch>='A' && ch <='Z');
}
  public:
    string postToInfix(string postfix) {
  stack<string> st;
 
  int len = postfix.size();
  for (int i = 0; i < len; i++) {
      if(isOperand(postfix[i])){
          
          st.push(string(1,postfix[i]));
         
      }
      else{
          string operand1=st.top();
          st.pop();
          
          string operand2=st.top();
          st.pop();
          
          st.push("(" + operand2 + string(1,postfix[i]) + operand1 + ")");
      }
  }
  return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends