#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fp(i,x,n) for(int i=x;i<n;i++)

const int LIM = 100005;
const int VAL = INT_MAX;

int seg[LIM*4];

int a[LIM];

bool lazy[LIM*4] = {false};

int val[LIM*4] = {0};

int combine(int x, int y){
    
    return min(x,y);
}

void modify(int t, int x){
    
    lazy[t] = true;
    val[t] += x;
}

void propogate(int t, int l, int r){
    
    if(!lazy[t])
        return;
    
    seg[t] += val[t];
    
    if(l!=r){
        
        lazy[2*t] = lazy[2*t+1] = true;
        val[2*t] += val[t];
        val[2*t+1] += val[t];
    }

    lazy[t] = false;
    val[t] = 0;
}

void build(int t, int l, int r){
    
    if(l == r){
        seg[t] = a[l];
        return;
    }
    
    int mid = (l+r)/2;
    
    build(2*t,l,mid);
    
    build(2*t+1,mid+1,r);
    
    seg[t] = combine(seg[2*t],seg[2*t+1]);
}

void update(int t,int l,int r, int ql,int qr, int x){
    
    propogate(t,l,r);
    
    if(ql <= l && qr >= r){
        modify(t,x);
        propogate(t,l,r);
        return;
    }
    
    if(ql > r || qr < l)
        return;
        
    int mid = (l+r)/2;
        
    update(2*t,l,mid,ql,qr,x);
    
    update(2*t+1,mid+1,r,ql,qr,x);
    
    seg[t] = combine(seg[2*t],seg[2*t+1]);
}

int query(int t,int l,int r,int ql,int qr){
    
    propogate(t,l,r);
    
    if(ql <= l && qr >= r)
        return seg[t];
    
    if(ql > r || qr < l)
        return VAL;
        
    int mid = (l+r)/2;   
        
    return combine(query(2*t,l,mid,ql,qr),query(2*t+1,mid+1,r,ql,qr));
}

int main() {
    
    int n, q, x, y, z;
    
    char c;
    
    cin >> n >> q;
    
    fp(i,0,n)
        cin >> a[i];
        
    build(1,0,n-1);
    
    while(q--){
        
        cin >> c >> x >> y;
        
        if(c == 'q')
            cout << query(1,0,n-1,x-1,y-1) << endl;
        else{
            
            cin >> z;
            update(1,0,n-1,x-1,y-1,z);
        }
    }
    return 0;
}
