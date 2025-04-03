//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        int n = V ;
        // Creating the Adjlist
        unordered_map<int, list<pair<int,int>> >adjlist;
        for(int i = 0 ; i < n ; i++){
            for(auto & edges : adj[i]){
                    
                    int u = i;
                    int v = edges[0];
                    int w = edges[1];
                    
                    adjlist[u].push_back({v,w});
                    adjlist[v].push_back({u,w});
            }

        }
        
        vector<int>key(n,INT_MAX);
        vector<bool>MST(n,false);
        vector<int>parent(n,-1);
        
        
        //Lets start algo of Prim's algo
        
        key[0] = 0 ;
        for(int i = 0 ; i < n ; i++){
            int mini = INT_MAX;
            int u ;
           
            // step I : finding u 
            for(int v = 0 ; v < n ;v++){
                if(MST[v] == false && key[v] < mini){
                    u = v ;
                    mini = key[v];
                }
            }
            MST[u] = true;
            
            //step II : adjacent vertex ko lao and update key[]
            for(auto it : adjlist[u]){
                int v = it.first;
                int w = it.second;
                if(MST[v] == false && w < key[v]){
                    parent[v] = u ;
                    key[v] = w;
                }
            }
        }
        
        // Now calculating the min cost
        int sum = 0 ;
        for(int cost : key){
            sum += cost;
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends