//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    
  public:
    string postToPre(string post_exp) {
        stack<string> st;
        int length = post_exp.size();
        for(int i=0;i<length;i++){
            if(isOperator(post_exp[i])){
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string temp = post_exp[i]+op2+op1;
                st.push(temp);
            }
            else{
                st.push(string(1, post_exp[i]));
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
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends