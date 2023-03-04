#include <bits/stdc++.h>
#define BPhuong "simulation"
#define maxn 100005
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <>
#define f first
#define se second
using namespace std;

int n, m, it = 1, a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(BPhuong".inp", "r", stdin);
    freopen(BPhuong".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i] >> b[i];
    cin >> m;
    while (m--){
        char typ;
        cin >> typ;
        if (typ == 'B'){if (it > 1) it--;}
        else if (typ == 'F'){if (it < n) it++;}
        else if (typ == 'C') cin >> a[it] >> b[it];
        else {
            int x = 1, y = 1, xx, yy, res = 0;
            fi(i, 1, n){
                xx = x + a[i];
                yy = y + b[i];
                if (xx*x < 0) res++;
                if (yy*y < 0) res++;
                x = xx;
                y = yy;
            }
            cout << res << '\n';
        }
    }

}
