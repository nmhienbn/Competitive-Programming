#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "caro"
const int maxn = 1e4 + 5;

using namespace std;

struct dl {
    int f, s, t;
};

int n, m, sl;
dl a[maxn], b[maxn];
int win, id;

bool cmp_ngang(dl a, dl b){
    return a.f == b.f ? a.s < b.s : a.f < b.f;
}

void ngang(dl a[], int n){
    sort(a + 1, a + n + 1, cmp_ngang);
    int cnt = 1, maxx = a[1].t;
    fi(i, 2, n){
        if (a[i].f != a[i - 1].f) cnt = 1, maxx = a[i].t;
        else {
            if (a[i].s == a[i - 1].s + 1){
                cnt++; maxx = max(maxx, a[i].t);
                if (cnt >= 5){
                    if (maxx < sl || cnt > 5){
                        cout << "Inconsistent";
                        exit(0);
                    }
                    win = id;
                }
            }
            else cnt = 1, maxx = a[i].t;
        }
    }
}

bool cmp_doc(dl a, dl b){
    return a.s == b.s ? a.f < b.f : a.s < b.s;
}

void doc(dl a[], int n){
    sort(a + 1, a + n + 1, cmp_doc);
    int cnt = 1, maxx = a[1].t;
    fi(i, 2, n){
        if (a[i].s != a[i - 1].s) cnt = 1, maxx = a[i].t;
        else {
            if (a[i].f == a[i - 1].f + 1){
                cnt++; maxx = max(maxx, a[i].t);
                if (cnt >= 5){
                    if (maxx < sl || cnt > 5){
                        cout << "Inconsistent";
                        exit(0);
                    }
                    win = id;
                }
            }
            else cnt = 1, maxx = a[i].t;
        }
    }
}

bool cmp_chinh(dl a, dl b){
    return a.f - a.s == b.f - b.s ? a.f < b.f : a.f - a.s < b.f - b.s;
}

void chinh(dl a[], int n){
    sort(a + 1, a + n + 1, cmp_chinh);
    int cnt = 1, maxx = a[1].t;
    fi(i, 2, n){
        if (a[i].f - a[i].s != a[i-1].f - a[i-1].s) cnt = 1, maxx = a[i].t;
        else {
            if (a[i].f == a[i - 1].f + 1){
                cnt++; maxx = max(maxx, a[i].t);
                if (cnt >= 5){
                    if (maxx < sl || cnt > 5){
                        cout << "Inconsistent";
                        exit(0);
                    }
                    win = id;
                }
            }
            else cnt = 1, maxx = a[i].t;
        }
    }
}

bool cmp_phu(dl a, dl b){
    return a.f + a.s == b.f + b.s ? a.s > b.s : a.f + a.s < b.f + b.s;
}

void phu(dl a[], int n){
    sort(a + 1, a + n + 1, cmp_phu);
    int cnt = 1, maxx = a[1].t;
    fi(i, 2, n){
        if (a[i].f + a[i].s != a[i-1].f + a[i-1].s) cnt = 1, maxx = a[i].t;
        else {
            if (a[i].f == a[i - 1].f + 1){
                cnt++; maxx = max(maxx, a[i].t);
                if (cnt >= 5){
                    if (maxx < sl || cnt > 5){
                        cout << "Inconsistent";
                        exit(0);
                    }
                    win = id;
                }
            }
            else cnt = 1, maxx = a[i].t;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sl;
    fi(i, 1, sl){
        if (i & 1){
            n++;
            cin >> a[n].f >> a[n].s;
            a[n].t = i;
        }
        else {
            m++;
            cin >> b[m].f >> b[m].s;
            b[m].t = i;
        }
    }

    id = 1;
    ngang(a, n);
    doc(a, n);
    chinh(a, n);
    phu(a, n);

    id = 2;
    ngang(b, m);
    doc(b, m);
    chinh(b, m);
    phu(b, m);

    if (win == 1) cout << "First player won";
    else if (win == 2) cout << "Second player won";
    else cout << "Draw";
}
