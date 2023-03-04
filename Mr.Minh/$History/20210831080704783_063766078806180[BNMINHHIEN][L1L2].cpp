#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "L1L2"
const int maxn = 100005;

using namespace std;

int n, a[maxn], L[maxn][3], res, bit[maxn];

void update(int x, int val){
    if (x == 0) return;
    while (x <= n){
        bit[x] = max(bit[x], val);
        x += x & -x;
    }
}

int get(int x){
    if (x <= 0) return 0;
    int ans = 0;
    while (x > 0){
        ans = max(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        a[x] = i;
    }
    fi(i, 1, n){
        fi(u, 0, 2){
            int l = get(a[i+u-1]-1);
            L[i][u] = l+1;
            if (L[i][u] > res) res = L[i][u];
        }
        fi(u, 0, 2){
            update(a[i+u-1], L[i][u]);
        }
    }
    cout << res;
}
