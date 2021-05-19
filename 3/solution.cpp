#include <bits/stdc++.h>
using namespace std;

struct Guest {int arrival, leave;};
vector<Guest> g;
int k;

bool cmp(int i, int j)
{
    return abs(i) <= abs(j);
}
 
void maximum_guest()
{
    vector<int> time;
    time.clear();
    for (int i=0; i<k; i++)
    {
        time.push_back(+g[i].arrival);
        time.push_back(-g[i].leave);
    }
 
    sort(time.begin(), time.end(), cmp);
 	for(int i=0;i<10;i++){
 		cout << time[i] <<endl;
	}
    int n = 0, maximum = 0;
    for (int i=0; i<time.size(); i++)
    {
        if (time[i] >= 0)
            n++;
        else
            n--;
 
        maximum = max(maximum, n);
    }
    cout << maximum << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("sample input.txt","r",stdin);
	k = 0;
	int tmp_arrival, tmp_leave;
	g.clear();
	cin >> k;
	for(int i = 0; i < k ; i ++){
		cin >> tmp_arrival >> tmp_leave;
		g.push_back({tmp_arrival, tmp_leave});
	}
	maximum_guest();
	return 0;	
}