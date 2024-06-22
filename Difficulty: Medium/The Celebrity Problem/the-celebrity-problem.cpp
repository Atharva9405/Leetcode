//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    
    bool knows(vector<vector<int> >& M,int a, int b, int n){
       if(M[a][b] == 1){
           return true;
       } 
       return false;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int candidate = s.top();
        bool rowCheck = false;
        int zeroCount = 0;
        for(int i=0;i<n;i++){
            if(M[candidate][i] == 0){
                zeroCount++;
            }
        }
        if(zeroCount == n) rowCheck = true;
        bool colCheck = false;
        int oneCount = 0;
        for(int i=0;i<n;i++){
            if(M[i][candidate] == 1) oneCount++;
        }
        if(oneCount == n-1) colCheck = true;
        if(rowCheck == true && colCheck ==true){
            return candidate;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends