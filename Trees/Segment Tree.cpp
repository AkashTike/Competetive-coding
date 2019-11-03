// Tested - OK

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fp(i,x,n) for(int i=x;i<n;i++)

const int LIM = 100005;
const int VAL = INT_MAX;

int seg[LIM*4];

int a[LIM];

int combine(int x, int y){
    return min(x,y);
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

void update(int t,int l,int r, int i, int x){
    
    if(l == r){
        seg[t] = x;
        return;
    }
    
    int mid = (l+r)/2;
    
    if(i <= mid)
        update(2*t,l,mid,i,x);
    else
        update(2*t+1,mid+1,r,i,x);
    
    seg[t] = combine(seg[2*t],seg[2*t+1]);
}

int query(int t,int l,int r,int ql,int qr){
    
    if(ql <= l && qr >= r)
        return seg[t];
    
    if(ql > r || qr < l)
        return VAL;
        
    int mid = (l+r)/2;   
        
    return combine(query(2*t,l,mid,ql,qr),query(2*t+1,mid+1,r,ql,qr));
}

int main() {
    
    int n, q, x, y;
    
    char c;
    
    cin >> n >> q;
    
    fp(i,0,n)
        cin >> a[i];
        
    build(1,0,n-1);
    
    while(q--){
        
        cin >> c >> x >> y;
        
        if(c == 'q')
            cout << query(1,0,n-1,x-1,y-1) << endl;
        else
            update(1,0,n-1,x-1,y);
    }
    return 0;
}
