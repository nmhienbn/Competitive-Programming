#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define ll long long
#define getbit(x, i) ((x >> i) & 1)
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "caribe"
const int maxn = 45, maxk = 2e5+5;

using namespace std;

int n, k, a[maxn], b[maxn];
pll L[1 << 20], M[1 << 20];
ll res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i] >> b[i];
    int u = n/2, v = n - n/2;
    fi(x, 1, (1 << u) - 1){
        fi(i, 0, u-1){
            if (getbit(x, i)){
                L[x] = {L[x - (1 << i)].first + a[i+1], L[x - (1 << i)].second + b[i+1]};
                break;
            }
        }
    }
    fi(x, 1, (1 << v) - 1){
        fi(i, 0, v-1){
            if (getbit(x, i)){
                M[x] = {M[x - (1 << i)].first + a[u+i+1], M[x - (1 << i)].second + b[u+i+1]};
                break;
            }
        }
    }
    sort(L+1, L+u+1);
    sort(M+1, M+v+1);
    fi(x, 1, (1 << v) - 1) M[x].second = max(M[x-1].second, M[x].second);
    u = (1 << u) - 1, v = (1 << v) - 1;
    int j = v;
    fi(i, 0, u){
        while (j >= 0 && L[i].first + M[j].first > k){
            j--;
        }
        if (L[i].first + M[j].first <= k){
            res = max(res, L[i].second + M[j].second);
        }
        else break;
    }
    cout << res;
}
