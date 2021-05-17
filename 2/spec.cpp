#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
	int m, n, s, d, k;
    // vector<int> A; // m,n,s,d,k
    vector<int> B; // Pij
    vector<vector<int>> C; // move
    vector<int> si;
    vector<int> sj;
    vector<int> st;
    int ans;

    void InputFormat() {
        LINE(m, n, s, d, k);
        LINES(B) % SIZE(100);
        LINES(si, sj, st) % SIZE(100);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(640000000);
    }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void BeforeTestCase(){
        // A.clear();
        B.clear();
        C.clear();
        si.clear();
        sj.clear();
        st.clear();
    }
    void gen_si(){
    	for(int i=0;i<1e4;i++){
    		si.push_back(rnd.nextInt(0,(int)1e2-1));
		}
	}
    void gen_sj(){
    	for(int i=0;i<1e4;i++){
    		sj.push_back(rnd.nextInt(0,(int)1e2-1));
		}
	}
    void gen_st(){
    	for(int i=0;i<1e4;i++){
    		st.push_back(rnd.nextInt((int)1e2,(int)1e3));
		}
	}
    void gen_B(){
    	for(int i=0;i<1e2;i++){
    		B.push_back(rnd.nextInt((int)1e3,(int)1e4));
		}
	}
    void TestCases() {
    	for(int t=0;t<5;t++){
			vector<vector<int>> move;
			int xa,ya,xb,yb;
			for(int i = 0;i<(int)1e4;i++){
				vector<int> f;
				if(i % 1000 == 0) cout << i << endl;
				f.push_back((int)1e4);
				for(int j = 0;j<1e4;j++){
					xa = rnd.nextInt(0,(int)1e2-2);
					ya = rnd.nextInt(0,(int)1e2-2);
					xb = rnd.nextInt(xa,(int)1e2-1);
					yb = rnd.nextInt(ya,(int)1e2-1);
					
					f.push_back(xa);f.push_back(ya);
					f.push_back(xb);f.push_back(yb);
					f.push_back(rnd.nextInt(1,(int)1e3));//wab
				}
				move.push_back(f);
			}
			CASE(m = n = 100, s = d = 10000, k = rnd.nextInt(1, 1000), gen_B(),gen_si(),gen_sj(),gen_st(),C = move);   		
		}

    }
};
