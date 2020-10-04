#include <bits/stdc++.h>
using namespace std;

#define fp(i,x,n) for(int i=x;i<n;i++)

const int maxn = 1e5 + 5;

int arr[maxn];
int size[maxn];

void init(int n){
    
    fp(i,0,n){
        
        size[i] = 1;
        arr[i] = i;
    }
}

int root(int a){
   
    int i = a;
   
    while(i != arr[i])
        i = arr[i];
    
    return i;
}

void u(int a, int b){
    
    int root_a = root(a);
    int root_b = root(b);
    
    if(size[root_a] < size[root_b])
        swap(root_a,root_b);
    
    arr[root_b] = root_a;
    size[root_a] += size[root_b];
}

int find(int a, int b){
    
    return !(root(a)-root(b));
}

int main() 
{
    int n, a, b, q;
    
    char c;
    
    cin >> n >> q;
    
    init(n);
    
    while(q--){
        
        cin >> c >> a >> b;
        
        if(c == 'u')
            u(a,b);
        else
            cout << find(a,b) << endl;
        
    }
    
    return 0;
}
