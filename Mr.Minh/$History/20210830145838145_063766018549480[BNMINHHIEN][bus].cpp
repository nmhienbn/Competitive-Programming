#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "bus"
const int maxn = 105, maxm = 10005;

using namespace std;

int n, k, a[maxn], L[maxm], pre[maxm], cnt[maxm], m;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i];
    }
    fi(i, 1, k){
        L[i] = 1e9;
        fi(j, 1, n) if (i >= j){
            if (L[i] > L[i-j] + a[j]){
                L[i] = L[i-j] + a[j];
                pre[i] = j;
            }
        }
    }
    cout << L[k] << ' ';
    while (k > 0){
        cnt[++m] = pre[k];
        k -= pre[k];
    }
    cout << m << '\n';
    fi(i, 1, m) cout << cnt[i] << ' ';
}
