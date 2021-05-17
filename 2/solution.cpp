#include <bits/stdc++.h>
using namespace std;

struct data{
	int t;// case(include T0 and other kinds of T)
	int p;// population
	int r;// basic reproduction number
};

data city[200][200];
int m, n;
float line_m, line_k;

/*void morning_report(void){
	for(int i = 0; i < m; i ++){
		for(int j = 0;j < n;j ++){
			city[i][j].t = min(city[i][j].t * (city[i][j].r+1),city[i][j].p); // remind %10000007
		}
	}
}*/
void ABchange(int xa, int ya, int xb, int yb, int w, int tab){
	int tmpab = city[xa][ya].p;
	city[xa][ya].p -= (city[xa][ya].p*w)/1000;
	city[xa][ya].t -= tab;
	city[xb][yb].p += (tmpab*w)/1000;
	city[xb][yb].t += tab;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("2_1.in","r",stdin);
	//freopen("1.txt","r",stdin);
	// initialize
	int d, s, k;
	int tmp_i, tmp_j;
	// input data
	cin >> m >> n >> s >> d >> k;
	// input p
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			cin >> city[i][j].p;
		}
	}
	// input r
	/*for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			cin >> city[i][j].r;
		}
	}*/
	while(s --){
		cin >> tmp_i >> tmp_j;
		cin >> city[tmp_i][tmp_j].t;
	}
	// day initialize 
	int f;// move times
	int xa, ya, xb, yb;
	int w;
	float f_xa, f_ya, f_xb, f_yb;
	int tab;
	float pre, now;
	//execution 
	while(d --){
		//morning_report();
		cin >> f;
		while(f --){
			cin >> xa >> ya >> xb >> yb >> w;
			f_xa = xa; f_ya = ya; f_xb = xb; f_yb = yb;
			tab = (city[xa][ya].t * w)/1000;
			ABchange(xa,ya,xb,yb,w,tab);//a move to b
			//build line : line_m*x - y = line_k
			line_m = (f_xb+1 - f_xa)/(f_yb+1 - f_ya);
			line_k = line_m * f_ya - f_xa;
			// cross city (city c)
			now = xa;

			for(int i = ya+1; i <= yb+1; i++){
				pre = (int)now;
				now = line_m * i - line_k;
				for(int j = pre; j< now; j++){
					//cout << tab * (k/1000) * ((city[i][j].p - city[i][j].t)/city[i][j].p) <<endl;
					if((i == ya||i == ya+1) && j == xa || i == yb+1 && (j == xb+1|| j == xb)){continue;}
					city[j][i-1].t = min(city[j][i-1].t + (tab * k)/1000,city[j][i-1].p);
				}
			}
			/*cout <<"p:"<<endl;
			for(int i = 0; i < m; i ++){
				for(int j = 0; j < n; j ++){
				cout << city[i][j].p <<" ";
				}
				cout <<endl;
			}
			cout <<"t:"<<endl;
			for(int i = 0; i < m; i ++){
				for(int j = 0; j < n; j ++){
				cout << city[i][j].t <<" ";
				}
				cout <<endl;
			}*/
		}
	}
	int total = 0;
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			total += city[i][j].t;
		}
	}
	cout << total <<endl;	
	
	return 0;
}

