#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lamp"
const int maxn = 505, ngg[4] = {-1, -1, 1, 1}, doc[4] = {-1, 1, -1, 1};

using namespace std;

int n, m;
char a[maxn][maxn];
pii q[maxn*maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        fi(j, 1, m){
            cin >> a[i][j];
        }
    }
    if ((m+n)&1){
        cout << "NO SOLUTION";
        return 0;
    }
    int d = n, c = n;
    q[++c] = {1, 1};
    while (d <= c){
        int u = q[d].first, v = q[d++].second;
        fi(i, 0, 3){

        }
    }
}
