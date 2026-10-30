class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) 
    {
        vector<vector<pair<int,int>>>adj(n);

        for(const auto& edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k+1, 1e9));
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;

        dist[0][1]=0;
        pq.push({0,0,1});

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int d = curr[0];
            int u = curr[1];
            int consecutive = curr[2];
            if(d>dist[u][consecutive]) continue;
            if(u==n-1) return d;

            for(const auto& neighbour : adj[u])
            {
                int v = neighbour.first;
                int weight = neighbour.second;

                int next_consecutive = (labels[v]==labels[u]) ? consecutive+1 :1;
                if(next_consecutive <=k)
                {
                    if(d+weight <dist[v][next_consecutive])
                    {
                        dist[v][next_consecutive] = d+weight;
                        pq.push({d+weight, v, next_consecutive});
                    }
                }
            }
                    
        }
        int min_dist = 1e9;
            for(int i=1; i<=k; i++)
            {
                min_dist = min(min_dist, dist[n-1][i]);
            }
        return min_dist == 1e9 ? -1 : min_dist;
    }
};