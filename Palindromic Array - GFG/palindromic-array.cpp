//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    {
        int flag = 1;
        for(int i=0;i<n;i++){
            int rev = 0;
            int x = a[i];
            while(x>0){
                rev = rev*10+x%10;
                x = x/10;
            }
            if(rev!=a[i]){
                flag = 0;
            }
        }
        if(flag==0){
            return 0;
        }
        else{
            return 1;
        }
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends