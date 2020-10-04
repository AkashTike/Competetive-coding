#include <bits/stdc++.h>
using namespace std;

#define fp(i,x,n) for(int i=x;i<n;i++)

stack<int> s;

vector<int> components;

void dfs(int vertex, vector<int> v[], bool visited[]){
    
    visited[vertex] = true;
    
    fp(i,0,v[vertex].size()){
        
        if(!visited[v[vertex][i]])
            dfs(v[vertex][i],v,visited);
    }
    
    s.push(vertex);
}

void dfs1(int vertex, vector<int> v[], bool visited[]){
    
    visited[vertex] = true;
    
    components.push_back(vertex);
    
    fp(i,0,v[vertex].size()){
        
        if(!visited[v[vertex][i]])
            dfs1(v[vertex][i],v,visited);
    }
   
}

// 1 based
void kosaraju(int n, vector<int> v[]){
    
    
    bool visited[n+1] = {false};
    
    vector<vector<int>> scc;
    
    vector<int> vr[n+1];
    
    fp(i,1,n+1){
        
        if(!visited[i])
            dfs(i,v,visited);
    }
    
    fp(i,1,n+1)
        visited[i] = false;
        
    fp(i,1,n+1){
        fp(j,0,v[i].size())
            vr[v[i][j]].push_back(i);
    }
    
    while(s.size()){
        
        if(visited[s.top()]){
            
            s.pop();
            continue;
        }
        
        dfs1(s.top(),vr,visited);
        s.pop();
        scc.push_back(components);
        components.clear();
    }
    
    fp(i,0,scc.size()){
        
        fp(j,0,scc[i].size())
            cout << scc[i][j] << " ";
        cout << "\n";
    }
}

int main() 
{
    int n,m,x,y;
    
    cin >> n >> m;
    
    vector<int> v[n+1]; 
    
    fp(i,0,m){
        
        cin >> x >> y;
        
        v[x].push_back(y);
    }
    
    kosaraju(n,v);
    
    return 0;
}
