//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
    int n = arr.size();
    int repeating = -1, missing = -1;

    // Step 1: Find the repeating number
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1; // Get the index for the current number
        if (arr[index] < 0) {
            repeating = index + 1; // If the value is negative, it means the number is repeated
        } else {
            arr[index] = -arr[index]; // Mark the number as visited by negating it
        }
    }

    // Step 2: Find the missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) { // The index + 1 of the positive value is the missing number
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends