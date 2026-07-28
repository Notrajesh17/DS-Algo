class Solution {
private:
    bool dfscheck(int node, vector<int>&vis, vector<int>&pathvis, vector<int>adj[])
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfscheck(it, vis, pathvis, adj)==true) return true;
            }
            else if(pathvis[it])
            {
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>adj[numCourses];
        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfscheck(i,vis, pathvis,adj)==true)
                {
                    return false;
                }
            }
        }
        return true; 
        
    }
};