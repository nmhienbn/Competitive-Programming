#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "mrect1"
const int maxn = 3e5+5;

using namespace std;

struct pii {
    int f, s;
};

int n, p;
pii a[maxn], b[maxn];
int a1, b1, a2, b2;

bool cmp(pii a, pii b){
    return a.f != b.f ? a.f < b.f : a.s < b.s;
}

int BS1(int u, int d, int c, pii a[]){
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g].f >= u) c = g-1;
        else d = g+1;
    }
    return d;
}

int BS2(int u, int d, int c, pii a[]){
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g].f <= u) d = g+1;
        else c = g-1;
    }
    return c;
}

int BS3(int u, int d, int c, pii a[]){
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g].s >= u) c = g-1;
        else d = g+1;
    }
    return d;
}

int BS4(int u, int d, int c, pii a[]){
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g].s <= u) d = g+1;
        else c = g-1;
    }
    return c;
}

void do1(int &res){
    int vt1, vt2, vt3, vt4;
    vt1 = BS1(a1, 1, n, a);
    vt2 = BS2(a1, 1, n, a);
    vt3 = BS3(b1, vt1, vt2, a);
    vt4 = BS4(b2, vt1, vt2, a);
    if (a[vt1].f == a1 && a[vt2].f == a1) res += vt4 - vt3 + 1;
}

void do2(int &res){
    int vt1, vt2, vt3, vt4;
    vt1 = BS1(a2, 1, n, a);
    vt2 = BS2(a2, 1, n, a);
    vt3 = BS3(b1, vt1, vt2, a);
    vt4 = BS4(b2, vt1, vt2, a);
    if (a[vt1].f == a2 && a[vt2].f == a2) res += vt4 - vt3 + 1;
}

void do3(int &res){
    int vt1, vt2, vt3, vt4;
    vt1 = BS1(b1, 1, n, b);
    vt2 = BS2(b1, 1, n, b);
    vt3 = BS3(a1+1, vt1, vt2, b);
    vt4 = BS4(a2-1, vt1, vt2, b);
    if (b[vt1].f == b1 && b[vt2].f == b1) res += vt4 - vt3 + 1;
}

void do4(int &res){
    int vt1, vt2, vt3, vt4;
    vt1 = BS1(b2, 1, n, b);
    vt2 = BS2(b2, 1, n, b);
    vt3 = BS3(a1+1, vt1, vt2, b);
    vt4 = BS4(a2-1, vt1, vt2, b);
    if (b[vt1].f == b2 && b[vt1].f == b2) res += vt4 - vt3 + 1;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].f >> a[i].s;
        b[i] = {a[i].s, a[i]. f};
    }
    sort(a+1, a+n+1, cmp);
    sort(b+1, b+n+1, cmp);
    cin >> p;
    while (p--){
        int res = 0;
        cin >> a1 >> b1 >> a2 >> b2;
        do1(res);
        if (a2 > a1) do2(res);
        do3(res);
        if (b2 > b1) do4(res);
        cout << res << '\n';
    }

}
