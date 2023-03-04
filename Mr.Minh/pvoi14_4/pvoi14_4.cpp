#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "pvoi14_4"
const int maxn = 5e4+5;

using namespace std;

struct pii {
    int f, s;
    bool operator < (const pii& x) const {
        return f < x.f;
    }
};

int n, a[maxn], bit1[maxn], bit2[maxn], bit3[maxn], bit4[maxn];
pii b[maxn];

void update_up(int x, int val, int bit[]){
    if (x == 0) return;
    while (x <= n){
        bit[x] = max(bit[x], val);
        x += x & -x;
    }
}

void update_down(int x, int val, int bit[]){
    while (x > 0){
        bit[x] = max(bit[x], val);
        x -= x & -x;
    }
}

int get_up(int x, int bit[]){
    int ans = 0;
    if (x == 0) return 0;
    while (x <= n){
        ans = max(ans, bit[x]);
        x += x & -x;
    }
    return ans;
}

int get_down(int x, int bit[]){
    int ans = 0;
    while (x > 0){
        ans = max(ans, bit[x]);
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    scanf("%d", &n);
    fi(i, 1, n) scanf("%d", &b[i].f), b[i].s = i;
    sort(b+1, b+n+1);
    a[b[1].s] = 1;
    int id = 1;
    fi(i, 2, n){
        if (b[i].f != b[i-1].f) id++;
        a[b[i].s] = id;
    }
    int res = 0;
    fi(i, 1, n){
        int l1 = get_down(a[i]-1, bit1);
        int l2 = get_up(a[i]+1, bit2);
        int l3 = get_down(a[i]-1, bit3);
        int l4 = get_up(a[i]+1, bit4);
        if (l4 >= 4) res = max(res, l4+1);
        if (l3 >= 3) l4 = max(l4, l3);
        if (l2 >= 2) l3 = max(l3, l2);
        if (l1 >= 1) l2 = max(l2, l1);
        update_up(a[i], l1+1, bit1);
        if (l2 >= 1) update_down(a[i], l2+1, bit2);
        if (l3 >= 2) update_up(a[i], l3+1, bit3);
        if (l4 >= 3) update_down(a[i], l4+1, bit4);
    }
    cout << res;
}
