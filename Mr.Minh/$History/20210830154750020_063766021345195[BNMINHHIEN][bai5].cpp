#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "bai5"
const int maxn = 1e4+5;

using namespace std;

int n, a[maxn], p, pre[maxn], pos[maxn], m;
ll L[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> p;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        L[i] = 1e18;
        fid(j, i-1, 0){
            int q = a[i] - a[j];
            if (L[i] > L[j] + 1ll*(p-q)*(p-q)){
                L[i] = L[j] + 1ll*(p-q)*(p-q);
                pre[i] = j;
            }
            //if (q > p) break;
        }
    }
    cout << L[n] << '\n';
    while (n > 0){
        pos[++m] = n;
        n = pre[n];
    }
    cout << m << '\n';
    fid(i, m, 1) cout << pos[i] << ' ';
}
