#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "paint"
const int maxn = 1e6 + 5;

using namespace std;

int n, k, a[maxn], nex[maxn], bd[26], kt[26];
int typ, x, y;
char c;

void sub1(){
    fi(i, 1, n){
        cin >> typ;
        if (typ == 1){
            cin >> c;
            a[++k] = c - 'a';
        }
        else {
            cin >> c; x = c - 'a';
            cin >> c; y = c - 'a';
            if (x == y) continue;
            fi(j, 1, k){
                if (a[j] == x) a[j] = y;
            }
        }
    }
    fi(i, 1, k) cout << char(a[i] + 'a');
    exit(0);
}

void sub2(){
    fi(i, 1, n){
        cin >> typ;
        if (typ == 1){
            cin >> c; x = c - 'a';
            k++;
            if (!bd[x]) bd[x] = k;
            if (kt[x]) nex[kt[x]] = k;
            kt[x] = k;
        }
        else {
            cin >> c; x = c - 'a';
            cin >> c; y = c - 'a';
            if (x == y) continue;
            if (!bd[x]) continue;
            if (!bd[y]) bd[y] = bd[x];
            if (kt[y]) nex[kt[y]] = bd[x];
            kt[y] = kt[x];
            bd[x] = kt[x] = 0;
        }
    }
    fi(i, 0, 25){
        if (!bd[i]) continue;
        int vt = bd[i];
        while (vt){
            a[vt] = i;
            vt = nex[vt];
        }
    }
    fi(i, 1, k) cout << char(a[i] + 'a');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    if (n <= 10000) sub1();
    sub2();
}
