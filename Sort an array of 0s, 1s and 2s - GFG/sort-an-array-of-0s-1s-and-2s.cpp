//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int countZero = 0, countOne = 0, countTwo = 0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                countZero++;
            }
            if(a[i]==1){
                countOne++;
            }
            if(a[i]==2){
                countTwo++;
            }
        }
        int i =0;
        while(countZero !=0){
            a[i] = 0;
            i++;
            countZero--;
        }
        while(countOne !=0){
            a[i] = 1;
            i++;
            countOne--;
        }
        while(countTwo !=0){
            a[i] = 2;
            i++;
            countTwo--;
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends