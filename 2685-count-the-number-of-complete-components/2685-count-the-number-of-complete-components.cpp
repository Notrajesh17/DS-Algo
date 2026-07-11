class Solution {
private:
    void bfs(int node, vector<int> adj[], vector<int>& vis, int &nodes, int &edges)
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            nodes++;

            for(auto it : adj[curr])
            {
                edges++; 

                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vector<int> adj[n];
        for(auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int nodes = 0, edges = 0;

                bfs(i, adj, vis, nodes, edges);

                edges /= 2; 

                if(edges == (nodes * (nodes - 1)) / 2)
                {
                    count++;
                }
            }
        }

        return count;
    }
};