//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    long long int xorAll = 0;
    for (long long int i = 0; i < N; i++) {
        xorAll ^= Arr[i];
    }

    long long int rightMostSetBit = xorAll & ~(xorAll - 1);
    long long int b1 = 0, b2 = 0;

    for (long long int i = 0; i < N; i++) {
        if (Arr[i] & rightMostSetBit) {
            b1 ^= Arr[i];
        } else {
            b2 ^= Arr[i];
        }
    }

    vector<long long int> result;
    if (b1 > b2) {
        result.push_back(b1);
        result.push_back(b2);
    } else {
        result.push_back(b2);
        result.push_back(b1);
    }

    return result;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends