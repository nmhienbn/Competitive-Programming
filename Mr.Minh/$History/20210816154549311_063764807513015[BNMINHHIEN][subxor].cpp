#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "subxor"
const int maxn = 1e5+5;

using namespace std;

struct node {
    int child[2], deg;
} T[maxn*32];

int n, k, a[maxn], cnt;
ll res;

void Add(int x){
    int pos = 0;
    fid(i, 31, 0){
        T[pos].deg++;
        int now = (x >> i) & 1;
        if (!T[pos].child[now]) T[pos].child[now] = ++cnt;
        pos = T[pos].child[now];
    }
    T[pos].deg++;
}

void Calc(int x){
    int pos = 0;
    fid(i, 31, 0){
        int now = ((x >> i) & 1), ss = ((k >> i) & 1);
        if (ss){
            if (T[pos].child[now]) res += T[T[pos].child[now]].deg;
            if (T[pos].child[1^now]) pos = T[pos].child[1^now];
            else return;
        }
        else if (T[pos].child[now]) pos = T[pos].child[now];
        else return;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    Add(0);
    fi(i, 1, n){
        cin >> a[i];
        a[i] ^= a[i-1];
        Add(a[i]);
    }
    fi(i, 0, n){
        res--;
        Calc(a[i]);
    }
    cout << res/2;
}
