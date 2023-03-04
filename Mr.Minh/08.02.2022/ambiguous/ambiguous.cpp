#include <bits/stdc++.h>
#define fi(i, a, b) for( int i = a; i <= b; i++ )
#define fid(i, a, b) for( int i = a; i >= b; i-- )
#define getbit( x, i ) (( x>>i)&1)
#define ll long long
#define pb push_back
#define pp pair<int,int>
#define f first
#define s second
#define hien "Ambiguous"
#define maxn 5009
using namespace std;
int n;
string a[maxn];
queue<pp> fe[maxn];
int l[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen(hien".inp", "r", stdin);
    freopen(hien".out", "w", stdout);
    cin >> n;
    fi( i, 1, n ) cin >> a[i];

    fi( i, 1, n ) l[i][0] = a[i].length(), fe[a[i].length()].push({ i, 0 });

    fi( t, 1, 5000 ){
        while( !fe[t].empty() ){
            pp pe = fe[t].front(); fe[t].pop();
            int u = pe.f, v = pe.s;
//            cout << u << " " << v << '\n';
            if( l[u][v] != t ) continue;

//            cout << u << " " << v << '\n';
            if( v == a[u].length() ){
                cout << t;
                exit(0);
            }
            int cl = a[u].length() - v;
            fi( i, 1, n ){
                if( v == 0 && u == i ) continue;
                if( a[i].length() >= cl ){
                    bool ok = 0;
                    fi( j, 1, cl ) if( a[i][j-1]!=a[u][v+j-1] ){ok = 1; break;}
//                    cout << i << " " << ok << '\n';
                    if( ok ) continue;
                    if( l[i][cl] == 0 || l[i][cl] > t + a[i].length() - cl ){
                        l[i][cl] = t + a[i].length() - cl;
                        fe[l[i][cl]].push({ i, cl });
                    }
                }
                else{
                    bool ok = 0;
                    fi( j, 1, a[i].length() ) if( a[i][j-1]!=a[u][v+j-1] ){ok = 1; break;}
                    if( ok ) continue;
                    int ms = v + a[i].length();
                    if( l[u][ms] == 0 || l[u][ms] > t ){
                        l[u][ms] = t;
                        fe[t].push({ u, ms });
                    }

                }
            }
        }
    }
//    fi( i, 1, n )
//        fi( j, 0, a[i].length() ) if( l[i][j] ) cout << i << " " << j << " " << l[i][j] << '\n';
    cout << -1;

}
