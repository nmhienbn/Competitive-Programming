#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "incseq"
const int maxn = 1e6+5;

using namespace std;

int n, a[maxn], b[maxn], L[maxn], cnt, cn, vt[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        int d = 1, c = cnt;
        while (d <= c){
            int g = (d+c) >> 1;
            if (b[g] < a[i]) d = g+1;
            else c = g-1;
        }
        b[d] = a[i];
        cnt = max(cnt, d);
        L[i] = d;
    }
    cout << cnt << '\n';
    fi(i, 1, n) L[i] = cnt - L[i]+1, vt[i] = -2e9-1;
    fid(i, n, 1){
        if (L[i] == cn+1) vt[++cn] = a[i];
        else if (a[i] > vt[L[i]] && L[i] <= cn){
            fi(j, L[i]+1, cn) vt[j] = -2e9-1;
            cn = L[i];
            vt[L[i]] = a[i];
        }
    }
    fid(i, cn, 1) cout << vt[i] << '\n';
}
