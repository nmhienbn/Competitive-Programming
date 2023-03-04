#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "so_test"
const int maxn = 1e6 + 5;

using namespace std;

int n, x, y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    FILE *fp1, *fp2;
    fp1 = fopen(Irelia".inp", "r");
    fp2 = fopen(Irelia".out", "r");
    freopen(Irelia".txt", "w", stdout);
    while (x == y){
        n++;
        fscanf(fp1, "%d", &x);
        fscanf(fp2, "%d", &y);
    }
    cout << "Vi tri dau tien khac nhau: " << n << '\n' << x << ' ' << y;
}
