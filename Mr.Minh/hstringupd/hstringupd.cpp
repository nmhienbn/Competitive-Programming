#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "hstringupd"
const int maxn = 2e5 + 5, mod = 1e9 + 7;

using namespace std;

struct matrix {
    ll a[2][2];
};

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, 1) fi(j, 0, 1){
        C.a[i][j] = 0;
        fi(k, 0, 1) C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
    }
    return C;
}

int n, q, a[maxn][2][2];
matrix st[maxn << 2];
string s;

void xuli(int i){
    fi(u, 0, 1) fi(v, 0, 1) a[i][u][v] = 0;
    if (s[i] == 'S' || s[i] == 'D')
        a[i][1][0] = a[i][1][1] = 1;
    else
        if (s[i] == 'H')
            a[i][0][0] = a[i][0][1] = 1;
        else
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                a[i][0][1] = a[i][1][0] = 1;
            else
                if (s[i] == '?')
                    a[i][0][0] = 19, a[i][0][1] = 6, a[i][1][0] = 7, a[i][1][1] = 20;
                else
                    a[i][0][0] = a[i][1][1] = 1;
}

void build(int id, int l, int r){
    if (l == r){
        fi(i, 0, 1) fi(j, 0, 1)
            st[id].a[i][j] = a[l][i][j];
        return;
    }
    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = st[id * 2 + 1] * st[id * 2];
}

void update(int id, int l, int r, int vt){
    if (l == r){
        fi(i, 0, 1) fi(j, 0, 1)
            st[id].a[i][j] = a[l][i][j];
        return;
    }
    int m = (l + r) >> 1;
    if (vt <= m) update(id * 2, l, m, vt);
    else update(id * 2 + 1, m + 1, r, vt);
    st[id] = st[id * 2 + 1] * st[id * 2];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q >> s;
    s = ' ' + s;
    fi(i, 1, n) xuli(i);
    build(1, 1, n);
    cout << st[1].a[0][0] << '\n';
    while (q--){
        int vt;
        char ms;
        cin >> vt >> ms;
        s[vt] = ms;
        xuli(vt);
        update(1, 1, n, vt);
        //fi(i, 2, 3) {fi(u, 0, 1) fi(v, 0, 1) cout << st[i].a[u][v] << ' '; cout << '|';}
        cout << st[1].a[0][0] << '\n';
    }
}
