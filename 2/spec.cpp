#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    vector<int> A; // m,n,s,d,k
    vector<int> B; // Pij
    vector<vector<int>> C; // move
    vector<int> si;
    vector<int> sj;
    vector<int> st;
    int ans;

    void InputFormat() {
        LINE(A);
        LINES(B) % SIZE(1e2);
        LINES(si,sj,st) % SIZE(1e2);
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
        A.clear();
        B.clear();
        C.clear();
        si.clear();
        sj.clear();
        st.clear();
    }
    void gen_si(){
    	for(int i=0;i<1e4;i++){
    		si.push_back(rnd.nextInt(0,1e2-1));
		}
	}
    void gen_sj(){
    	for(int i=0;i<1e4;i++){
    		sj.push_back(rnd.nextInt(0,1e2-1));
		}
	}
    void gen_st(){
    	for(int i=0;i<1e4;i++){
    		st.push_back(rnd.nextInt(1e2,1e3));
		}
	}
    void gen_B(){
    	for(int i=0;i<1e2;i++){
    		B.push_back(rnd.nextInt(1e3,1e4));
		}
	}
    void TestCases() {
    	//vector <int> tmp;
    	vector <int> line1;
    	for(int t=0;t<5;t++){
    		line1.clear();
     		line1.push_back(1e2);//m
     		line1.push_back(1e2);//n
     		line1.push_back(1e4);//s
     		line1.push_back(1e4);//d
			line1.push_back(rnd.nextInt(1,1e3));//k 
			/*vector<vector<int>> p;
			vector <int> tmp;			
     		for(int i = 0;i<1e2;i++){
     			tmp.clear();
     			for(int j = 0;j<1e2;j++){
     				tmp.push_back(rnd.nextInt(1e3,1e4));
				}
    			p.push_back(tmp);
			}*/
			vector<vector<int>> move;
			vector<int> f;
			move.clear();
			f.clear();
			int xa,ya,xb,yb;
			for(int i = 0;i<1e4;i++){
				f.clear();
				f.push_back(1e4);
				for(int j = 0;j<1e4;j++){
					do{
						xa = rnd.nextInt(0,1e2-2);
						ya = rnd.nextInt(0,1e2-2);
						xb = rnd.nextInt(xa,1e2-1);
						yb = rnd.nextInt(ya,1e2-1);
					}while(xa == xb && ya == yb);
					f.push_back(xa);f.push_back(ya);
					f.push_back(xb);f.push_back(yb);
					f.push_back(rnd.nextInt(1,1e3));//wab
				}
				move.push_back(f);
			}
			CASE(A = line1, gen_B(),gen_si(),gen_sj(),gen_st(),C = move);   		
		}

    }
};
