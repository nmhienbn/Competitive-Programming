#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "tien"
const int maxn = 105, maxm = 10005;

using namespace std;

int n, m, a[maxn], L[maxm], vt[maxm], cnt[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) L[i] = 1e9;
    L[0] = 0;
    fi(i, 1, n) {L[a[i]] = 1; vt[a[i]] = i;}
    fi(i, 1, m)
        fi(j, 1, n)
            if (a[j] <= i && L[i] > L[i-a[j]] + 1){
                L[i] = L[i-a[j]] +1;
                vt[i] = j;
            }
    if (L[m] == 1e9) {cout << 0; return 0;}
    cout << L[m] << '\n';
    int i = m;
    while (i > 0){
        cnt[vt[i]]++;
        i -= a[vt[i]];
    }
    fi(i, 1, n) cout << cnt[i] << ' ';
}
