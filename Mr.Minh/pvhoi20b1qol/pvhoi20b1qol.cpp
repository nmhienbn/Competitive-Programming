#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "pvhoi20b1qol"
const int maxn = 3005;

using namespace std;

int n, m, h, w, a[maxn][maxn], b[maxn][maxn];

bool check(int g){
    fi(i, 1, n) fi(j, 1, m){
        int tg = 0;
        if (a[i][j] >= g) tg = 1;
        else tg = -1;
        b[i][j] = tg + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    }
    fi(i, h, n) fi(j, w, m){
        if (b[i][j] + b[i-h][j-w] > b[i-h][j] + b[i][j-w]){
            return true;
        }
    }
    return false;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> h >> w;
    fi(i, 1, n){
        fi(j, 1, m){
            cin >> a[i][j];
        }
    }
    if (h == 1 && w == 1){
        cout << m*n;
        exit(0);
    }
    if (h == n && w == m){
        cout << (m*n+1)/2;
        exit(0);
    }
    int d = 1, c = m*n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c;
}
