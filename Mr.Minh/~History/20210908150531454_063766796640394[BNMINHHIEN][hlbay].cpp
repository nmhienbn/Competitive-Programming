#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "hlbay"
const int maxn = 1e5+5;

using namespace std;

int n, m, a[maxn], b[maxn], c[maxn];
double res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i];
    }
    fi(i, 1, m){
        cin >> b[i] >> c[i];
    }
    fi(i, 1, n){
        double t = 1e9;
        fi(j, 1, m){
            t = min(t, sqrt((double)(b[j]-a[i])*(b[j]-a[i]) + c[j]*c[j]));
        }
        res = max(res, t);
    }
    cout << fixed << setprecision(3) << res;
}
