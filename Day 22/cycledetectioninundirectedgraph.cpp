//https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_8230798?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here
    vector<vector<int>>adj(n+1);
    for(auto edge:edges){
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
    }
    
    vector<bool>visited(n+1,false);

    vector<int>parent(n+1,-1);

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            if(visited[curr])
            continue;
            visited[curr]=true;
            for(int j:adj[curr]){
                if(visited[j]){
                    if(parent[curr]==j)
                    continue;
                    else return "Yes";
                }
                else
                {
                    q.push(j);
                    parent[j]=curr;
                }
            }
            }
        }
    }
    return "No";
}
