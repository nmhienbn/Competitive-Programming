#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "easytask"
const int maxn = 1e6+5;

using namespace std;

int n, p[maxn], cnt;
ll a[maxn], t[maxn], s[maxn], minx, res = -1e18;

void Erathosenes(){
    p[1] = 1;
    fi(i, 2, 1e3){
        if (!p[i]){
            for (int j = i*i; j <= 1e6; j += i){
                p[j] = 1;
            }
        }
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    Erathosenes();
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        a[i] += a[i-1];
        if (!p[i]){
            t[++cnt] = a[i];
            s[cnt] = a[i-1];
        }
    }
    minx = s[1];
    fi(i, 1, cnt){
        minx = min(minx, s[i]);
        res = max(res, t[i] - minx);
    }
    cout << res;
}
