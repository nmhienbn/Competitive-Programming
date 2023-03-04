#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "ando"
const int maxn = 3e5+5;

using namespace std;

struct node {
    int child[2], val, deg;
} T[maxn*32];

int n, a[maxn], cnt, res;

void Add(int x){
    int pos = 0;
    fid(i, 31, 0){
        int now = (x >> i) & 1;
        if (!T[pos].child[now]) T[pos].child[now] = ++cnt;
        pos = T[pos].child[now];
        T[pos].deg++;
    }
    T[pos].val = x;
    //cout << pos << ' ';
}

int Get(int x){
    int vt = 0;
    priority_queue<pii> q;
    q.push({31, 0});
    while (q.size()){
        int i = q.top().first;
        if (i < 0) break;
        int pos = q.top().second;
        int now = (x >> i) & 1;
        q.pop();
        if (now){
            if (T[pos].child[1]) vt = T[pos].child[1], q.push({i-1, T[pos].child[1]});
            else vt = T[pos].child[0], q.push({i-1, T[pos].child[0]});
        }
        else {
            if (T[pos].child[1]) vt = T[pos].child[1], q.push({i-1, T[pos].child[1]});
            if (T[pos].child[0]) vt = T[pos].child[0], q.push({i-1, T[pos].child[0]});
        }
    }
    //cout << vt << ' ' << T[vt].val << '\n';
    return T[vt].val;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        res = max(res, a[i] & Get(a[i]));
        Add(a[i]);
    }
    cout << res;
}
