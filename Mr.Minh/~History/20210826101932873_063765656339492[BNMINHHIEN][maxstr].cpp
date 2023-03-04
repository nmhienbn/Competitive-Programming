#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Hue "maxstr"

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }

typedef pair<int, int> II;

const double PI = acos(-1.0);
const double eps = 1e-9;

const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};

const int inf = (int)1e9 + 5;
const ll linf = (ll)1e17 + 5;
const ll mod = (ll)1e9 + 7;

#define maxn 200005
#define maxa 30

int n, from, to, nc, a[maxn], p[maxn], c[maxn], pn[maxn], cn[maxn], cnt[maxn], lcp[maxn];
char s[maxn];

void suffix_array() {
    Rep(i, n) a[i] = s[i] - 'a' + 1;
    a[n++] = 0;

    ms(cnt, 0);
    Rep(i, n) ++cnt[a[i]];
    For(i, 1, maxa - 1) cnt[i] += cnt[i - 1];
    Repd(i, n) p[--cnt[a[i]]] = i;

    nc = 1; c[p[0]] = 0;
    For(i, 1, n - 1) {
        if (a[p[i]] > a[p[i - 1]]) ++nc;
        c[p[i]] = nc - 1;
    }

    for (int h = 1; h < n; h <<= 1) {
        Rep(i, n) {
            pn[i] = p[i] - h;
            if (pn[i] < 0) pn[i] += n;
        }

        ms(cnt, 0);
        Rep(i, n) ++cnt[c[pn[i]]];
        For(i, 1, nc - 1) cnt[i] += cnt[i - 1];
        Repd(i, n) p[--cnt[c[pn[i]]]] = pn[i];

        nc = 1; cn[p[0]] = 0;
        For(i, 1, n - 1) {
            int x = (p[i] + h) % n, y = (p[i - 1] + h) % n;
            if (c[p[i]] > c[p[i - 1]] || c[x] > c[y]) ++nc;
            cn[p[i]] = nc - 1;
        }
        Rep(i, n) c[i] = cn[i];
    }

    int h = 0;
    Rep(i, n) {
        if (c[i] > 0) {
            int j = p[c[i] - 1];
            while (a[i + h] == a[j + h]) ++h;
            lcp[c[i]] = h;
            if (h > 0) --h;
        }
    }

}

bool check(int d){
    if(d > n) return false;
    int run = 1, MAX = 0;
    For(i, 1, n - 1){
        if(lcp[i] < d){
            run = 1;
        }
        else run++;
        MAX = max(run, MAX);
    }
    return MAX >= 2;
}

int main(){
    //freopen(Hue".inp", "r", stdin);
    //freopen(Hue".out", "w", stdout);
    cin >> n;
    scanf("%s", s);
    suffix_array();
    int l = 1, r = n, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(check(mid)){
            l = mid + 1;
        }
        else r = mid;
    }

    cout << l - 1 << endl;

    return 0;
}
