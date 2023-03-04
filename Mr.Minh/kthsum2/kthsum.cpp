#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 100005
#define MOD
#define Seraphine "kthsum"

using namespace std;

int n, k, a[maxn], b[maxn];

bool check(ll g){
    int j = 0, cnt = 0;
    fid(i, n, 1){
        while (j < n && a[i] + b[j+1] <= g){
            j++;
        }
        if (a[i] + b[j] <= g) cnt += j;
        if (cnt >= k) return 1;
    }
    return 0;
}

int res[maxn];

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    ll d = a[1] + b[1], c = a[n] + b[n];
    b[0] = 1e9;
    while (d <= c){
        ll g = (d + c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    int cnt = 0;
    fi(i, 1, n){
        fi(j, 1, n){
            if (a[i] + b[j] >= d) break;
            res[++cnt] = a[i] + b[j];
        }
    }
    sort(res+1, res+cnt+1);
    fi(i, cnt+1, k) res[i] = d;
    fi(i, 1, k) cout << res[i] << ' ';
}
