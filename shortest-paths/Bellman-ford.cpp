#include <bits/stdc++.h>
using namespace std;

#define fp(i,x,n) for(int i=x;i<n;i++)

const int maxval = INT_MAX;

void bellman_ford(int src, int n, int v, map<pair<int,int>,int> mymap){
    
    int dist[n];  // 0 based
    
    fp(i,0,n){
        
        if(i == src)
            dist[i] = 0;
        else
            dist[i] = maxval;
    }
    
    map<pair<int,int>,int>::iterator it;
    
    while(v--){
        
        for(it=mymap.begin();it!=mymap.end();it++){
            
            dist[it->first.second] = min(dist[it->first.second], dist[it->first.first] + it->second);
        }
    }
    
    
    fp(i,0,n)
        cout << dist[i] << endl;
    
}

int main() 
{
    int n,m,x,y,w,t;
        
    cin >> n >> m;
    
    vector<int> v[n+1]; 
    
    map<pair<int,int>,int> mymap;
    
    fp(i,0,m){
        
        cin >> x >> y >> w;
        
        mymap[{x,y}] = w;   // directed
    }
    
    bellman_ford(0,n,n-1,mymap);
        
    return 0;
}
