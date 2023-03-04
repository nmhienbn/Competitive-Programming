#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define all(a) a.begin(), a.end()
#define Irelia "garden"
using namespace std;

const int N = 2000006, B = 500;
int Count, n;
vector<int> a[N], Big;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
	cin >> n;
	fi(i, 1, n){
		int x, y;
		cin >> x >> y;
		x += 1000000;
		y += 1000000;
		a[x].push_back(y);
	}
	fi(i, 0, N - 6)
		sort(all(a[i]));

	fi(k, 0, N - 6){
        if (a[k].size() > B)
            Big.push_back(k);
        else {
            for (int i = 0; i < a[k].size(); i++){
                for (int j = 0; j < i; j++) {
                    int d = a[k][i] - a[k][j];
                    if (k < d) continue;
                    if (binary_search(all(a[k - d]), a[k][i]))
                    if (binary_search(all(a[k - d]), a[k][j]))
                    Count++;
                }
            }
            for (int i = 0; i < a[k].size(); i++){
                for (int j = 0; j < i; j++) {
                    int d = a[k][i] - a[k][j];
                    if (k + d >= N || a[k + d].size() <= B) continue;
                    if (binary_search(all(a[k + d]), a[k][i]))
                    if (binary_search(all(a[k + d]), a[k][j]))
                    Count++;
                }
            }
        }
	}
	for (int i = 0; i < Big.size(); i++){
        for (int j = 0; j < i; j++) {
            int I = Big[i], J = Big[j];
            int d = I-J;
            for (int k = 0; k < a[I].size(); k++){
                if (binary_search(all(a[I]), a[I][k]-d)
                    && binary_search(all(a[J]), a[I][k])
                    && binary_search(all(a[J]), a[I][k]-d))
                Count++;
            }
        }
	}
	cout << Count << endl;
}
