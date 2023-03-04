#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define X first
#define Y second
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "ipoints"
const int maxn = 5005, maxm = 1005;

using namespace std;

ll res;
int n, u, v, s, t, kt[maxm][maxm];
pii a[maxn], b[maxn];

bool check(pii u, pii a, pii b){
    return (min(a.X, b.X) <= u.X && u.X <= max(a.X, b.X) && min(a.Y, b.Y) <= u.Y && u.Y <= max(a.Y, b.Y));
}

int gcd(int a, int b){
    return __gcd(abs(a), abs(b));
}

void toigian(int& a, int& b, int& c){
    if (a < 0) a = -a, b = -b, c = -c;
    int k = gcd(a, gcd(b, c));
    a /= k;
    b /= k;
    c /= k;
}

bool cmp(pii a, pii b){
    return a.X == b.X ? a.Y > b.Y : a.X > b.X;
}

void solve(pii A, pii B, pii C, pii D){
    int a1 = B.Y - A.Y;
    int b1 = A.X - B.X;
    int c1 = a1*A.X + b1*A.Y;
    toigian(a1, b1, c1);
    int a2 = D.Y - C.Y;
    int b2 = C.X - D.X;
    int c2 = a2*C.X+ b2*C.Y;
    toigian(a2, b2, c2);
    int det = a1*b2 - a2*b1;
    if (det == 0){
        if (a1 == a2 && b1 == b2 && c1 == c2){
            if (cmp(A, C) || (A == C && cmp(B, D))) swap(A, C), swap(B, D);
            if (B.X >= C.X){
                int sl = gcd(B.X-C.X, B.Y-C.Y);
                if (sl == 0){
                    kt[B.X+500][B.Y+500]++;
                    return;
                }
                int u = (B.X-C.X)/sl;
                int v = (B.Y-C.Y)/sl;
                fi(i, 0, sl){
                    kt[B.X+500][B.Y+500]++;
                    B.X -= u;
                    B.Y -= v;
                }
            }
        }
        return;
    }
    if ((b2*c1 - b1*c2) % det || (a1*c2 - a2*c1) % det) return;
    pii u = {(b2*c1 - b1*c2)/det, (a1*c2 - a2*c1)/det};
    if (check(u, A, B) && check(u, C, D)) kt[u.X+500][u.Y+500]++;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> u >> v >> s >> t;
        res += gcd(s-u, t-v) + 1;
        a[i] = {u, v};
        b[i] = {s, t};
        if (cmp(a[i], b[i])) swap(a[i], b[i]);
    }
    fi(i, 1, n) fi(j, i+1, n){
        solve(a[i], b[i], a[j], b[j]);
    }
    fi(i, 0, 1e3) fi(j, 0, 1e3){
        res -= int(sqrt(kt[i][j]*2));
        //if (kt[i][j]) cout << i << ' ' << j << ' ' << int(sqrt(kt[i][j]*2)) << '\n';
    }
    cout << res;
}
