#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "photo"
const int maxn = 1e5+5;

using namespace std;

int n, a[maxn][6], res[maxn];

bool cmp(int x, int y){
    int cnt = 0;
    fi(i, 1, 5){
        cnt += a[x][i] < a[y][i];
    }
    return cnt >= 3;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) res[i] = i;
    fi(j, 1, 5){
        fi(i, 1, n){
            int x;
            cin >> x;
            a[x][j] = i;
        }
    }
    sort(res+1, res+n+1, cmp);
    fi(i, 1, n) cout << res[i] << ' ';
}
