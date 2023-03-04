#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "fpot"
const int maxn = 1e5+5;

using namespace std;

int n, dis, m[maxn][20], M[maxn][20], res = 1e9;
pii a[maxn];

int getmin(int l, int r){
    int t = log2(r-l+1);
    return min(m[l][t], m[r+1 - (1 << t)][t]);
}

int getmax(int l, int r){
    int t = log2(r-l+1);
    return max(M[l][t], M[r+1 - (1 << t)][t]);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> dis;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1);
    fi(i, 1, n) m[i][0] = M[i][0] = a[i].second;
    fi(j, 1, log2(n)){
        fi(i, 1, n+1 - (1 << j)){
            m[i][j] = min(m[i][j-1], m[i + (1 << (j-1))][j-1]);
            M[i][j] = max(M[i][j-1], M[i + (1 << (j-1))][j-1]);
        }
    }
    fi(i, 1, n-1){
        int d = i+1, c = n;
        while (d <= c){
            int g = (d + c) >> 1;
            if (getmax(i, g) - getmin(i, g) >= dis) c = g-1;
            else d = g+1;
        }
        res = min(res, a[d].first - a[i].first);
    }
    cout << res;
}
