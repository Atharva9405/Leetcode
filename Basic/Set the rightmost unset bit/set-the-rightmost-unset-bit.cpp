//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        int rightmostUnsetBit = 0;
        int temp = N;
        while (temp & 1) {
            temp = temp >> 1;
            rightmostUnsetBit++;
        }
        return N | (1 << rightmostUnsetBit);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends