#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "TreeDP"
const int maxn = 1e5+5;

using namespace std;

int n, L[maxn], maxL[maxn], res[maxn], st[maxn << 2];
pii a[maxn];

bool cmp(pii a, pii b){
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}

void build(int id, int l, int r){
    if (l == r){
        st[id] = -2e9;
        return;
    }
    int m = (l + r) >> 1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
}

void update(int id, int l, int r, int vt, int val){
    if (l == r){
        st[id] = max(st[id], val);
        return;
    }
    int m = (l + r) >> 1;
    if (vt <= m) update(id*2, l, m, vt, val);
    else update(id*2+1, m+1, r, vt, val);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int d, int c){
    if (r < d || l > c || d > c) return -2e9;
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    return max(get(id*2, l, m, d, c), get(id*2+1, m+1, r, d, c));
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1, cmp);
    build(1, 1, n);
    //TH1: b[j] > a[i] voi j = (k+1)..(i-1)
    //L[i] = max(L[j] - (b[j] - a[i]) * 2) + (b[i] - a[i]);
    //L[i] = max(L[j] - b[j] * 2) + (a[i] + b[i]);
    //TH2: b[j] <= a[i] voi j = 1..k
    //L[i] = max(L[j]) + (b[i] - a[i]);
    //chat nhi phan
    fi(i, 1, n){
        int d = 1, c = i-1;
        while (d <= c){
            int g = (d + c) >> 1;
            if (a[g].second > a[i].first) c = g-1;
            else d = g+1;
        }
        L[i] = max(maxL[c] + a[i].second - a[i].first,
                   get(1, 1, n, d, i-1) + a[i].first + a[i].second);
        update(1, 1, n, i, L[i] - a[i].second * 2);
        maxL[i] = max(maxL[i-1], L[i]);
    }
    cout << maxL[n];
}
