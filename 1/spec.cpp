#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    int n, k;
    long long ans;
    vector<int> c;
    vector<string> w;
    void InputFormat() {
        LINE(n, k);
        LINE(c % SIZE(n));
        LINES(w) % SIZE(k);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void rand_arr(int n, int k){
        c.resize(n);
        w.resize(k);
        for(int i=0;i<n;i++){
            c[i] = rnd.nextInt(0, 1e7);
        }
        for(int i=0;i<k;i++){
            int m = rnd.nextInt(1, 100);
            string tmp = to_string(m);
            for(int j=0;j<m;j++){
                int a = rnd.nextInt(0, n-1);
                int b = rnd.nextInt(1, 100);
                tmp += " " + to_string(a) + " " + to_string(b);
            }
            w[i] = tmp;
        }
    }
    void BeforeTestCase(){
        c.clear();
        w.clear();
    }
    void TestCases() {
        for(int i=0;i<10;i++){
            CASE(n = 1, k = 1, rand_arr(n, k));
        }
        for(int i=0;i<40;i++){
            CASE(n = rnd.nextInt(1, 10), k = rnd.nextInt(1, 100), rand_arr(n, k));

        }
        for(int i=0;i<50;i++){
            CASE(n = rnd.nextInt(1, 1000), k = rnd.nextInt(1, 10000), rand_arr(n, k));
        }
    }
};