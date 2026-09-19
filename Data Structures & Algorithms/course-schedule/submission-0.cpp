class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        vector<int> indegree(V , 0);

        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for(int i = 0;i<V;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;

            for(int v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        return count == V ? true : false;
    }
};