#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fp(i,x,n) for(int i=x;i<n;i++)

#define pii pair<int,int>
#define pdi pair<long double,int>

void dijkstra(vector<pdi> v[], int n, int st, int en){
    
    priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
    
    vector<long double> dist(n+1,1e15);
    pq.push({0,st});
    dist[st] = 0;
    
    while(pq.size()){
        
        ll vr = pq.top().second; 
        
        pq.pop();
        
        fp(i,0,v[vr].size()){
            
            if(dist[v[vr][i].second] > dist[vr] + v[vr][i].first){
                
                dist[v[vr][i].second] = dist[vr] + v[vr][i].first;
                pq.push({dist[v[vr][i].second],v[vr][i].second});
            }
        }
    }
    if(dist[en] == 1e15)
        cout << -1 << "\n";
    else
        cout << setprecision(25) <<  dist[en] << "\n";
}

int main(){
    
    int n,m,x,y,t,a,b,st,en;
    double w;
    cin >> t;
    
    while(t--){
    
        cin >> n >> m >> st >> en;
        vector<pdi> v[n+1];
        
        fp(i,0,m){
            
            cin >> x >> y >> a >> b;
            w = (double)a/b;
            v[x].push_back({w,y});
            v[y].push_back({w,x});
        }
        
        dijkstra(v,n,st,en);
    }
    return 0;
}
