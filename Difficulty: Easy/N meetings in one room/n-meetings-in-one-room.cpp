//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Data{
    int start;
    int end;
    int pos;
};
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
     bool static comp(struct Data m1,Data m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
      }
    
    int maxMeetings(int start[], int end[], int n)
    {
      Data arr[n];
      for(int i=0;i<n;i++){
          arr[i].start = start[i];
          arr[i].end = end[i];
          arr[i].pos = i+1;
      }
      sort(arr,arr+n,comp);
      int count = 0;
      int freeTime = arr[0].end;
      vector<int> ans;
      ans.push_back(arr[0].pos);
      for (int i = 1; i < n; i++) {
         if (arr[i].start > freeTime) {
            freeTime = arr[i].end;
            ans.push_back(arr[i].pos);
         }
      }
      return ans.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends