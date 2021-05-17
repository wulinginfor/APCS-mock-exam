#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
	int m, n, s, d, k;
    vector<vector<int>> B; // Pij
    vector<vector<int>> C; // move
    vector<int> si;
    vector<int> sj;
    vector<int> st;
    int ans;

    void InputFormat() {
        LINE(m, n, s, d, k);
        GRID(B) % SIZE(100, 100);
        LINES(si, sj, st) % SIZE(1e3);
		GRID(C) % SIZE(d, 5001);
    }

    void OutputFormat() {
        LINE(ans);
    }


};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void BeforeTestCase(){
        B.clear();
        C.clear();
        si.clear();
        sj.clear();
        st.clear();
    }

    void gen_si(){
    	for(int i=0;i<1e3;i++){
    		si.push_back(rnd.nextInt(0,(int)1e2-1));
		}
	}
    void gen_sj(){
    	for(int i=0;i<1e3;i++){
    		sj.push_back(rnd.nextInt(0,(int)1e2-1));
		}
	}
    void gen_st(){
    	for(int i=0;i<1e3;i++){
    		st.push_back(rnd.nextInt((int)1e2,(int)1e3));
		}
	}
	
    void gen_B(){
		B.resize(100, vector<int>(100));
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				B[i][j] = rnd.nextInt((int)1e3,(int)1e4);
			}
		}
	}

	void gen_C(int d){
		int xa,ya,xb,yb;
		for(int i = 0;i<d;i++){
			vector<int> f;
			// if(i % 1000 == 0) cout << i << endl;
			f.push_back((int)1e3);
			for(int j = 0;j<1e3;j++){
				xa = rnd.nextInt(0,(int)1e2-2);
				ya = rnd.nextInt(0,(int)1e2-2);
				xb = rnd.nextInt(xa,(int)1e2-1);
				yb = rnd.nextInt(ya,(int)1e2-1);
				
				f.push_back(xa);f.push_back(ya);
				f.push_back(xb);f.push_back(yb);
				f.push_back(rnd.nextInt(1,(int)1e3)); //wab
			}
			C.push_back(f);
		}
	}
    void TestCases() {
		for(int i=0;i<6;i++){
			CASE(m = n = 1e2, s = 1e3, d = 2, k = rnd.nextInt(1, 1e3), gen_B(), gen_si(), gen_sj(), gen_st(), gen_C(d));
		}
    	for(int i=0;i<14;i++){			
			CASE(m = n = 1e2, s = 1e3, d = rnd.nextInt(1e2, 1e3), k = rnd.nextInt(1, 1e3), gen_B(), gen_si(), gen_sj(), gen_st(), gen_C(d));   		
		}

    }
};
