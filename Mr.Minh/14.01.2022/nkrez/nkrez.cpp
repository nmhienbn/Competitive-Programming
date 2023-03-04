#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "nkrez"
const int maxn = 3e4+5, M = 3e4;

using namespace std;

int n, st[maxn << 2];
pii a[maxn];

bool cmp(pii a, pii b){
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

void update(int id, int l, int r, int vt, int val){
    if (l > vt || r < vt) return;
    if (l == r){
        st[id] = max(st[id], val);
        return;
    }
    int m = (l + r) >> 1;
    if (vt <= m) update(id * 2, l, m, vt, val);
    else update(id * 2 + 1, m + 1, r, vt, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int d, int c){
    if (r < d || l > c || d > c) return 0;
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    return max(get(id * 2, l, m, d, c),
               get(id * 2 + 1, m + 1, r, d, c));
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+n+1, cmp);
//    fi(i, 1, n){
//        int d = 1, c = i-1;
//        while (d <= c){
//            int g = (d + c) >> 1;
//            if (a[g].second <= a[i].first) d = g+1;
//            else c = g-1;
//        }
//        L[i] = maxL[c] + a[i].second - a[i].first;
//        maxL[i] = max(L[i], maxL[i-1]);
//    }
    fi(i, 1, n){
        int len = get(1, 0, M, 0, a[i].first) + a[i].second - a[i].first;
        update(1, 0, M, a[i].second, len);

    }
    cout << st[1];
}
