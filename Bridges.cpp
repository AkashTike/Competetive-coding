#include <bits/stdc++.h>
using namespace std;

#define fp(i,x,n) for(int i=x;i<n;i++)

const int maxn = 1e5 + 5;

vector<pair<int,int>> bridges;

int cnt;

void dfs(int vertex, vector<int> v[], int visit[], int low[], int parent){
    
    visit[vertex] = low[vertex] = cnt; 
    
    cnt ++;
    
    int isAP = 0, children = 0;
    
    vector<int> temp;
    
    fp(i,0,v[vertex].size()){
        
        if(v[vertex][i] == parent)
            continue;
        
        if(!visit[v[vertex][i]]){
            
            children ++;
            
            dfs(v[vertex][i],v,visit,low,vertex);
            
            if(visit[vertex] < low[v[vertex][i]])
                bridges.push_back({vertex,v[vertex][i]});
            else
                low[vertex] = min(low[vertex],low[v[vertex][i]]);
        }
        else
            low[vertex] = min(low[vertex],visit[v[vertex][i]]);
    }
}

void get_bridges(int n, vector<int> v[]){
    
    int visit[n+1] = {0};
    
    int low[n+1] = {0};
    
    cnt = 1;
    
    fp(i,1,n+1)
        if(!visit[i])
            dfs(i,v,visit,low,0);
            
    fp(i,0,bridges.size())
        cout << bridges[i].first <<  " " << bridges[i].second << endl;
    
}

int main() {
    
    int t,n,m,x,y,q;
    
    cin >> n >> m;
    
    vector<int> v[n+1];
    
    fp(i,0,m){
    
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    get_bridges(n,v);
    
    return 0;
}
