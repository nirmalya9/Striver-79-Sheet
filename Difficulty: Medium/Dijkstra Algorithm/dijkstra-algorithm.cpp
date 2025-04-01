//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
         int V=adj.size();
        vector<int> dis(V,0);
        for(int i=0;i<V;i++){
            dis[i]=INT_MAX;
        }
        dis[src]=0;
        //useing the min head
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;      
        pq.push({src,0});
        while(!pq.empty()){
            int currentdis=pq.top().second;
            int currentnode=pq.top().first;
            pq.pop();
            for(auto it: adj[currentnode]){
                int edgedis=it.second;
                int destination_node=it.first;
                if(edgedis+currentdis<dis[destination_node]){
                    dis[destination_node]=edgedis+currentdis;
                    pq.push({destination_node,dis[destination_node]});
                }
            }
        }
        return dis;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends