#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "guards"
const int maxn = 105;
const int N = 1e4 + 5;
using namespace std;

int n, m;
int a[maxn][maxn], b[N];
int vt[maxn][maxn], id;
bool kt[N][N];

int c[N], d[N], result;

bool is_clique(int b){
	fi(i, 1, b){
		fi(j, i + 1, b)
			if (kt[c[i]][c[j]] == 0)
				return 0;
	}
	if (result < b){
        result = b;
        fi(i, 1, b) d[i] = c[i] - 1;
	}
	return 1;
}

int maxCliques(int i, int l){
	int res = 0;
	fi(j, i, id){
		c[l] = j;
		if (is_clique(l)) {
			res = max(res, l);
			res = max(res, maxCliques(j, l + 1));
		}
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        vt[i][j] = ++id;
        b[id] = a[i][j];
    }
    fi(i, 1, m) fi(j, 1, n) if (!a[i][j]){
        fi(k, i + 1, m){
            if (a[k][j] == 2) break;
            kt[vt[i][j]][vt[k][j]] = a[k][j] ^ 1;
            kt[vt[k][j]][vt[i][j]] = a[k][j] ^ 1;
        }
        fi(k, j + 1, n){
            if (a[i][k] == 2) break;
            kt[vt[i][j]][vt[i][k]] = a[i][k] ^ 1;
            kt[vt[i][k]][vt[i][j]] = a[i][k] ^ 1;
        }
    }
    fi(i, 1, id) fi(j, i + 1, id){
        if (!kt[i][j] && !b[i] && !b[j]){
            kt[i][j] = 1;
            kt[j][i] = 1;
        }
        else {
            kt[i][j] = 0;
            kt[j][i] = 0;
        }
    }
    cout << maxCliques(1, 1) << '\n';
    fi(i, 1, result){
        cout << d[i] / n + 1 << ' ' << d[i] % n + 1 << '\n';
    }
}
