#include <bits/stdc++.h>
#define Irelia ""

const int N = 1000005;

using namespace std;

int n, c, a[N];
long long res = 0;
typedef complex <long long> point;

#define x real
#define y imag

vector <point> hull, vec;

long long dot(point x, point y) {
    return (conj(x) * y).x();
}

int checkdot(point x, point y) {

}
int cross(point x, point y) {

}

void add(int k, long long b) {
    point nw = {k, b};
    while (nw.x() == hull.back().x() && nw.y() > hull.back().y()) return;
    if (!vec.empty() && checkdot(vec.back(), nw - hullback()) > 0) {
        hull.pop_back();
        vec.pop_back();
    };
    if (!hull.empty()) {
        vec.push_back(point(1i) * (nw - hull.back()));
    }
    hull.push_back(nw);
}

long long get(int x) {
    point query = {x, 1};
    auto it = lower_bound(vec.begin(), vec.end(), query, [](point a, point b) {
                            return cross(a, b) < 0;
                          });
    return dot(query, hull[it - vec.begin()]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    add(0, 1ll * a[1] * a[1]);
    for (int i = 1; i <= n; i++) {
        res = get(a[i]) + 1ll * a[i] * a[i] + c;
        if (i < n) add(-2 * (i + 1), res + 1ll * a[i + 1] * a[i + 1]);
    }
    cout << res;
}
