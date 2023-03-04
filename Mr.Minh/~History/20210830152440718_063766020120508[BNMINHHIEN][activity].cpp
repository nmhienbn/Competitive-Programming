#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "activity"
const int maxn = 1e4+5;

using namespace std;

struct pii {
    int f, s, id;
    bool operator < (const pii& x) const {
        return s < x.s;
    }
};

int n, L[maxn], pre[maxn], re[maxn], id, m;
pii a[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].f >> a[i].s;
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    fi(i, 1, n){
        fi(j, 0, i-1){
            if (a[j].s <= a[i].f && L[i] < L[j] + 1){
                L[i] = L[j] + 1;
                pre[i] = j;
            }
        }
        if (L[i] > L[id]) id = i;
    }
    while (id > 0){
        re[++m] = a[id].id;
        id = pre[id];
    }
    sort(re+1, re+m+1);
    cout << m << '\n';
    fi(i, 1, m) cout << re[i] << '\n';
}
