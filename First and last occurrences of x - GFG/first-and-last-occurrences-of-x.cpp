//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
 
int first(int arr[],int n ,int x){
    int s=0;
    int e=n-1;
    int mid = s +(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid] == x){
            ans = mid;
            e= mid-1;
        }
        else if(x>arr[mid]){
            s = mid+1;
        }
        else if(x<arr[mid]){
            e = mid-1;
        }
        mid = s +(e-s)/2;
    }
    return ans;
}

int last(int arr[],int n ,int x){
    int s=0;
    int e=n-1;
    int mid = s +(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid] == x){
            ans = mid;
            s = mid+1;
        }
        else if(x>arr[mid]){
            s = mid +1;
        }
        else if(x<arr[mid]){
            e= mid-1;
        }
        mid = s +(e-s)/2;
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    vector<int> v;
    v.push_back(first(arr,n,x));
    v.push_back(last(arr,n,x));
    
    return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends