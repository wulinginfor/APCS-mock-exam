#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<double,double> pdd;
#define SQ(i) ((i)*(i))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define SZ(i) int(i.size())
#define FOR(i, j, k, in) for (int i=j ; i<(k) ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=(k) ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REP1(i,j) FOR(i, 1, j+1, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(_a) _a.begin(),_a.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#ifdef jayinnn
#define TIME(i) Timer i(#i)
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
class Timer {
private:
    string scope_name;
    chrono::high_resolution_clock::time_point start_time;
public:
    Timer (string name) : scope_name(name) {
        start_time = chrono::high_resolution_clock::now();
    }
    ~Timer () {
        auto stop_time = chrono::high_resolution_clock::now();
        auto length = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();
        double mlength = double(length) * 0.001;
        debug(scope_name, mlength);
    }
};
#else
#define TIME(i)
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#endif

const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const ll MAXN = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Line {
    // ax + by = c, y = mx + n
    int a, b, c;

    double m, n;
};

inline double slope(pii a, pii b){
    if(b.X - a.X == 0) return INF;
    return (double)(b.Y-a.Y) / (double)(b.X-a.X);
}

Line create_line(pii a, pii b){
    Line res;
    // y = mx + n;
    // res.a = (b.Y - a.Y);
    // res.b = (b.X - a.X);
    // res.c = res.a * a.X + res.b * a.Y;
    res.m = slope(a, b);
    res.n = a.Y - res.m * a.X;

    return res;
}

void print(vector<vector<ll>> a){
    for(auto i:a){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    // freopen("test.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll m, n, s, d, k;
    cin >> n >> m >> s >> d >> k;
    vector<vector<ll>> p(n, vector<ll>(m));
    vector<vector<ll>> t(n, vector<ll>(m, 0));

    ll ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> p[i][j];
        }
    }


    for(int i=0;i<s;i++){
        int x, y;
        cin >> x >> y;
        cin >> t[x][y];
        ans += t[x][y];
    }

    while(d--){
        int f;
        cin >> f;
        for(int i=0;i<f;i++){
            pii a, b;
            int w;
            cin >> a.X >> a.Y >> b.X >> b.Y >> w;
            b.X ++;
            b.Y ++;
            Line cur = create_line(a, b);
            ll n_mov = p[a.X][a.Y] * w / 1000;
            ll tab = t[a.X][a.Y] * w / 1000;
            p[a.X][a.Y] -= n_mov;
            t[a.X][a.Y] -= tab;     
            p[b.X-1][b.Y-1] += n_mov;
            t[b.X-1][b.Y-1] += tab;
            // debug(n_mov);
            // vector<vector<bool>> vis(n, vector<bool>(m, false));
            // vis[a.X][a.Y] = true;
            // vis[b.X-1][b.Y-1] = true;

            for(int x=a.X;x<b.X;x++){
                double y1 = cur.m * (double)x + cur.n;
                double y2 = cur.m * (double)(x+1) + cur.n;
                // if(y1 - (ll)y1 == 0) y1++;
                if(y2 - (ll)y2 <= 1e-8){
                    debug(y1, y2);
                    y2 -= 1;
                }
                // debug(x, y1, y2);
                for(int y=y1;y<=y2;y++){
                    if((x != a.X || y != a.Y) && (x != b.X - 1 || y != b.Y - 1)){
                        if(x < 0 || x >= n || y < 0 || y >= m) continue;
                        // debug(x, y, tab * k / 1000, p[x][y] - t[x][y]);
                        ll delta = min(tab * k / 1000, (ll)p[x][y] - (ll)t[x][y]);
                        t[x][y] += delta;
                        ans += delta;
                    }
                }
            }
            // print(p);
            // cout << endl;
            // print(t);
            // debug(t);
            // debug(p);
        }
    }
    
    cout << ans << endl;



    return 0;
}
