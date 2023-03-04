#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dip"
const int maxn = 1e5+5;

using namespace std;

int n, m, a[maxn], L[maxn][20];
bool kt[maxn];
pii b[maxn];

int get(int l, int r){
    int t = log2(r-l+1);
    return max(L[l][t], L[r+1 - (1 << t)][t]);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    int j = 1;
    fi(i, 1, n){
         while (kt[a[i]]){
            kt[a[j]] = 0;
            j++;
         }
         kt[a[i]] = 1;
         //cout << j << ' ' << i << '\n';
         b[i] = {j, i};
         L[i][0] = i-j+1;
    }
    int zz = log2(n);
    fi(j, 1, zz){
        fi(i, 1, n+1 - (1 << j)){
            L[i][j] = max(L[i][j-1], L[i + (1 << (j-1))][j-1]);
        }
    }
    b[0] = {-1e9, -1e9};
    b[n+1] = {1e9, 1e9};
    while (m--){
        int l, r, res = 0;
        cin >> l >> r;
        l++, r++;
        int d = 1, c = n;
        while (d <= c){
            int g = (d+c) >> 1;
            if (b[g].first >= l) c = g-1;
            else d = g+1;
        }
        int vt1 = d;
        int vt2 = r;
        if (d > r){
            cout << r-l+1 << '\n';
            continue;
        }
        res = max({res, get(vt1, vt2)+1, b[vt1-1].second-l+1, r-b[vt2+1].second+1});
        cout << get(vt1, vt2) << '\n';
    }
}
