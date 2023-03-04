#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define getbit(x, t) ((x >> t) & 1)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "sums"
const int maxn = 45, nn = (1 << 20);

using namespace std;

int n;
ll a[maxn], L[nn], M[nn], S, res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> S;
    fi(i, 1, n) cin >> a[i];
    int u = n/2;
    int v = n-u;
    fi(i, 1, (1 << u) - 1){
        fi(j, 0, u-1){
            if (getbit(i, j)){
                L[i] = L[i - (1 << j)] + a[j+1];
            }
        }
    }
    fi(i, 1, (1 << v) - 1){
        fi(j, 0, v-1){
            if (getbit(i, j)){
                M[i] = M[i - (1 << j)] + a[u+j+1];
            }
        }
    }
    u = (1 << u) - 1, v = (1 << v) - 1;
    sort(L+1, L+u+1);
    sort(M+1, M+v+1);
    fi(i, 0, u){
        int d = 0, c = v;
        while (d <= c){
            int g = (d + c) >> 1;
            if (M[g] >= S - L[i]) c = g-1;
            else d = g+1;
        }
        int vt1 = d;
        d = 0, c = v;
        while (d <= c){
            int g = (d + c) >> 1;
            if (M[g] <= S - L[i]) d = g+1;
            else c = g-1;
        }
        int vt2 = c;
        res += vt2 - vt1 + 1;
    }
    cout << res;
}
