#include <tcframe/spec.hpp>
using namespace tcframe;

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF=1E9;

class ProblemSpec : public BaseProblemSpec {
protected:
	string HEADER;
    int N,K;
    vector<int> P;
    vector<int> A;
    vector<int> B;
    
    int ans;

    void InputFormat() {
		LINE(HEADER);
        LINE(N,K);
        LINE(P%SIZE(K));
        LINE(A%SIZE(N));
        LINE(B%SIZE(N));
    }

    void OutputFormat() {
        LINE(ans);
    }
    
    void StyleConfig() {
        BatchEvaluator();
    }


    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }
    
    void Constraints() {
		CONS(HEADER.size()==8);
		CONS(ValidHeader(HEADER));
		CONS(Between(N,1,100000));
		CONS(Between(K,1,N));
		CONS(Unique(P));
		CONS(AllBetween(A,1,K));
		CONS(AllBetween(B,1,K));
		CONS(Permutation(A,B));
		CONS(AllExist(A,1,K));
		CONS(AllExist(B,1,K));
	}
	
	void Subtask1() {	//Open Subtask 1
		Points(6);
		CONS(HEADER[1]=='1');
		CONS(N==5);
		CONS(K==1);
		vector<int> p={3};
		vector<int> a={1,1,1,1,1};
		vector<int> b={1,1,1,1,1};
		CONS(P==p);
		CONS(A==a);
		CONS(B==b);
	}
	
	void Subtask2() {	//Open Subtask 2
		Points(8);
		CONS(HEADER[2]=='2');
		CONS(N==9);
		CONS(K==4);
		vector<int> p={2,3,5,8};
		vector<int> a={2,2,1,3,3,2,3,4,4};
		vector<int> b={2,1,3,2,3,3,2,4,4};
		CONS(P==p);
		CONS(A==a);
		CONS(B==b);
	}
	
	void Subtask3() {	//Cek ada solusi/tidak
		Points(10);
		CONS(HEADER[3]=='3');
		CONS(N==K);
	}
	
	void Subtask4() {	//Bruteforce
		Points(15);
		CONS(HEADER[4]=='4');
		CONS(Between(N,1,10));
	}
	
	void Subtask5() {	//Cuma ada 1 garis
		Points(23);
		CONS(HEADER[5]=='5');
		CONS(K==1);
	}
	
	void Subtask6() {	//Tidak ada garis lurus
		Points(18);
		CONS(HEADER[6]=='6');
		CONS(NoStraightLine(A,P));
		CONS(NoStraightLine(B,P));
	}
	
	void Subtask7() {	//Full
		Points(20);
		CONS(HEADER[7]=='7');
	}
private:
	bool Between(int x,int l,int r) {
		return (l<=x && x<=r);
	}
	bool AllBetween(vector<int> &V,int l,int r) {
		for (int data:V) if (!Between(data,l,r)) return false; return true;
	}
	bool ValidHeader(string h) {
		for (int i=0;i<h.size();i++) if (h[i]!='.' && h[i]!=i+'0') return false; return true;
	}
	bool Unique(vector<int> &V) {
		set<int> S; S.clear();
		for (int data:V) S.insert(data);
		return S.size()==V.size();
	}
	bool Permutation(vector<int> &A, vector<int> &B) {
		vector<int> tempA=A, tempB=B;
		sort(tempA.begin(),tempA.end()); sort(tempB.begin(),tempB.end());
		for (int i=0;i<tempA.size();i++) if (tempA[i]!=tempB[i]) return false; return true;																										
	}
	bool AllExist(vector<int> &V,int l,int r) {
		set<int> S; S.clear();
		for (int data:V) S.insert(data);
		for (int i=l;i<=r;i++) if (!S.count(i)) return false; return true;
	}
	bool NoStraightLine(vector<int> &V, vector<int> &P) {
		for (int i=0;i<V.size();i++) if (P[V[i]-1]-1==i) return false; return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
		Subtasks({4,5,7});
        Input({
			"0...45.7",
            "6 1",
            "3",
            "1 1 1 1 1 1",
            "1 1 1 1 1 1"
        });
        Output({
            "36"
        });
    }
    
    void SampleTestCase2() {
		Subtasks({4,7});
        Input({
			"0...4..7",
            "6 2",
            "1 4",
            "1 1 2 2 2 2",
            "2 2 1 2 1 2"
        });
        Output({
            "0"
        });
    }

    void TestGroup1() {	//Open Subtask 1
		Subtasks({1,4,5,7});
		CASE(HEADER=".1..45.7",
			N=5, K=1,
			P={3},
			A={1,1,1,1,1},
			B={1,1,1,1,1}
		);
	}
	
	void TestGroup2() {	//Open Subtask 2
		Subtasks({2,4,7});
		CASE(HEADER="..2.4..7",
			N=9, K=4,
			P={2,3,5,8},
			A={2,2,1,3,3,2,3,4,4},
			B={2,1,3,2,3,3,2,4,4}
		);	
	}
	void TestGroup3() {	//K=N=1
		Subtasks({3,4,5,7}); string h="...345.7";
		CASE(HEADER=h,N=K=1,P={1},A={1},B={1});
	}
	
	void TestGroup4() {	//K=N, N<=10, gak ada garis lurus
		Subtasks({3,4,6,7}); string h="...34.67";
		CASE(HEADER=h,N=K=2,P={1,2},A={2,1},B={2,1});
		
		for (int i=0;i<3;i++) {
			CASE(HEADER=h, N=K=rnd.nextInt(8,10),randomP(P,K,N),randomAB(A,B,P,N,K,false));
			CASE(HEADER=h, N=K=10,randomP(P,K,N),randomAB(A,B,P,N,K,false));
		}
	}
	
	void TestGroup5() {	//K=N, N<=100k, gak ada garis lurus
		Subtasks({3,6,7}); string h="...3..67";
		
		//10<N<=10000
		{
			int MIN_N=11, MAX_N=10000;
			CASE(HEADER=h, N=K=rnd.nextInt(MIN_N,MIN_N+100),randomP(P,K,N),randomAB(A,B,P,N,K,false));
			CASE(HEADER=h, N=K=rnd.nextInt(MIN_N,MAX_N),randomP(P,K,N),randomAB(A,B,P,N,K,false));
			CASE(HEADER=h, N=K=rnd.nextInt(MAX_N-100,MAX_N),randomP(P,K,N),randomAB(A,B,P,N,K,false));
		}
		
		//10000<N<=100k
		{
			int MIN_N=10001, MAX_N=100000;
			CASE(HEADER=h, N=K=rnd.nextInt(MIN_N,MIN_N+100),randomP(P,K,N),randomAB(A,B,P,N,K,false));
			CASE(HEADER=h, N=K=rnd.nextInt(MIN_N,MAX_N),randomP(P,K,N),randomAB(A,B,P,N,K,false));
			CASE(HEADER=h, N=K=rnd.nextInt(MAX_N-100,MAX_N),randomP(P,K,N),randomAB(A,B,P,N,K,false));
		}
	}
	
	void TestGroup6() {	//K=N, N<=10
		Subtasks({3,4,7}); string h="...34..7";
		
		CASE(HEADER=h,N=K=2,P={1,2},A={1,2},B={1,2});
		CASE(HEADER=h,N=K=2,P={1,2},A={1,2},B={2,1});
		CASE(HEADER=h,N=K=2,P={1,2},A={2,1},B={1,2});
		
		CASE(HEADER=h,N=K=rnd.nextInt(3,10),blocksAB(A,B,P,N,K));
		CASE(HEADER=h,N=K=10,blocksAB(A,B,P,N,K));
		
		for (int i=0;i<3;i++) {
			CASE(HEADER=h,N=K=rnd.nextInt(8,10),randomP(P,K,N),randomAB(A,B,P,N,K));
			CASE(HEADER=h,N=K=10,randomP(P,K,N),randomAB(A,B,P,N,K));
		}
	}
	
	void TestGroup7() {	//K=N, N<=100k
		Subtasks({3,7}); string h="...3...7";
		
		//10<N<=10000
		{
			int MIN_N=11, MAX_N=10000;
			CASE(HEADER=h,N=K=rnd.nextInt(MIN_N,MIN_N+100),blocksAB(A,B,P,N,K));
			CASE(HEADER=h,N=K=rnd.nextInt(MIN_N,MAX_N),blocksAB(A,B,P,N,K));
			CASE(HEADER=h,N=K=rnd.nextInt(MAX_N-100,MAX_N),blocksAB(A,B,P,N,K));
			CASE(HEADER=h,N=K=rnd.nextInt(MIN_N,MAX_N),randomP(P,K,N),randomAB(A,B,P,N,K));
		}
		
		//10000<N<=100000
		{
			int MIN_N=10001, MAX_N=100000;
			CASE(HEADER=h,N=K=rnd.nextInt(MIN_N,MIN_N+100),blocksAB(A,B,P,N,K));
			CASE(HEADER=h,N=K=rnd.nextInt(MIN_N,MAX_N),blocksAB(A,B,P,N,K));
			CASE(HEADER=h,N=K=rnd.nextInt(MAX_N-100,MAX_N),blocksAB(A,B,P,N,K));
			CASE(HEADER=h,N=K=rnd.nextInt(MIN_N,MAX_N),randomP(P,K,N),randomAB(A,B,P,N,K));
		}
	}
	
	void TestGroup8() {	//K=1, N<=10
		Subtasks({4,5,7}); string h="....45.7";
		CASE(HEADER=h,N=2,K=1,P={1},A={1,1},B={1,1});
		CASE(HEADER=h,N=2,K=1,P={2},A={1,1},B={1,1});
		
		for (int i=0;i<2;i++) {
			int temp=rnd.nextInt(3,9);
			CASE(HEADER=h,N=temp,K=1,randomP(P,K,N),randomAB(A,B,P,N,K));
			CASE(HEADER=h,N=temp+1,K=1,randomP(P,K,N),randomAB(A,B,P,N,K));
		}
		
		for (int i=0;i<3;i++) {
			int temp=rnd.nextInt(3,9);
			CASE(HEADER=h,N=temp,K=1,blocksAB(A,B,P,N,K));
			CASE(HEADER=h,N=temp+1,K=1,blocksAB(A,B,P,N,K));
		}
		
		CASE(HEADER=h,N=9,K=1,randomP(P,K,N),randomAB(A,B,P,N,K));
		CASE(HEADER=h,N=9,K=1,blocksAB(A,B,P,N,K));
		CASE(HEADER=h,N=10,K=1,randomP(P,K,N),randomAB(A,B,P,N,K));
		CASE(HEADER=h,N=10,K=1,blocksAB(A,B,P,N,K));
		
	}
	
	void TestGroup9() {	//K=1, N<=100k
		Subtasks({5,7}); string h=".....5.7";
		//10<N<=10000
		generateTestGroup9(h,11,10000);
		
		//10000<N<=100k
		generateTestGroup9(h,10001,100000);
	}
	
	void TestGroup10() {	//Tidak ada garis lurus, N<=10
		Subtasks({4,6,7}); string h="....4.67";
		CASE(HEADER=h,N=4,K=2,P={2,3},A={1,2,1,2},B={1,2,1,2});
		CASE(HEADER=h,N=7,K=3,P={3,4,5},A={1,1,2,3,2,3,3},B={3,3,2,1,2,3,1});
		for (int i=0;i<5;i++) {
			CASE(HEADER=h,N=10,generateAll(A,B,P,K,N,false));
		}
		for (int i=0;i<5;i++) {
			CASE(HEADER=h,N=10,generateAll(A,B,P,K,N,false,false));
		}
		CASE(HEADER=h,N=10,K=rnd.nextInt(2,9),randomP(P,K,N),randomAB(A,B,P,N,K,false));
		CASE(HEADER=h,N=10,K=rnd.nextInt(2,9),randomP(P,K,N),randomAB(A,B,P,N,K,false));
	}
	
	void TestGroup11() {	//Tidak ada garis lurus, N<=100k
		Subtasks({6,7}); string h="......67";
		//10<N<=10000
		{
			int MIN_N=11, MAX_N=10000;
			CASE(HEADER=h,N=rnd.nextInt(MIN_N,MAX_N),generateAll(A,B,P,K,N,false));
			CASE(HEADER=h,N=rnd.nextInt(MAX_N-100,MAX_N),generateAll(A,B,P,K,N,false));
			CASE(HEADER=h,N=rnd.nextInt(MIN_N,MAX_N),generateAll(A,B,P,K,N,false,false));
			CASE(HEADER=h,N=rnd.nextInt(MAX_N-100,MAX_N),generateAll(A,B,P,K,N,false,false));
		}
		
		//10000<N<=100k
		{
			int MIN_N=10001, MAX_N=100000;
			CASE(HEADER=h,N=rnd.nextInt(MIN_N,MAX_N),generateAll(A,B,P,K,N,false));
			CASE(HEADER=h,N=rnd.nextInt(MAX_N-100,MAX_N),generateAll(A,B,P,K,N,false));
			CASE(HEADER=h,N=rnd.nextInt(MIN_N,MAX_N),generateAll(A,B,P,K,N,false,false));
			CASE(HEADER=h,N=rnd.nextInt(MAX_N-100,MAX_N),generateAll(A,B,P,K,N,false,false));
		}
	}
	
	void TestGroup12() {	//N<=10
		Subtasks({4,7}); string h="....4..7";
		
		for (int i=0;i<5;i++) {
			CASE(HEADER=h,N=rnd.nextInt(7,10),generateAll(A,B,P,K,N));
			CASE(HEADER=h,N=10,generateAll(A,B,P,K,N));
		}
		
		for (int i=0;i<5;i++) {
			CASE(HEADER=h,N=rnd.nextInt(3,10),K=rnd.nextInt(2,N-1),blocksAB(A,B,P,N,K));
			CASE(HEADER=h,N=10,K=rnd.nextInt(2,N-1),blocksAB(A,B,P,N,K));
		}
		
		CASE(HEADER=h,N=rnd.nextInt(5,10),K=rnd.nextInt(2,N-1),randomP(P,K,N),randomAB(A,B,P,N,K));
		CASE(HEADER=h,N=10,K=rnd.nextInt(2,N-1),randomP(P,K,N),randomAB(A,B,P,N,K));
	}
	
	void TestGroup13() {	//N<=100k
		Subtasks({7}); string h=".......7";

		//10<N<=100
		generateTestGroup13(h,11,100);

		//100<N<=1000
		generateTestGroup13(h,101,1000);
		
		//1000<N<=10000
		generateTestGroup13(h,1001,10000);
		
		//10000<N<=90k
		generateTestGroup13(h,10001,90000);
		
		//90k<N<=100k
		generateTestGroup13(h,90001,100000);
	}
private:
	void generateTestGroup9(string h,int MIN_N,int MAX_N) {
		//Random
		generateTestGroup9Random(h,rnd.nextInt(MIN_N,MIN_N+100));
		generateTestGroup9Random(h,rnd.nextInt(MIN_N,MAX_N-1));
		generateTestGroup9Random(h,rnd.nextInt(MAX_N-100,MAX_N-1));
		
		//Blocks
		generateTestGroup9Blocks(h,rnd.nextInt(MIN_N,MIN_N+100));
		generateTestGroup9Blocks(h,rnd.nextInt(MIN_N,MAX_N-1));
		generateTestGroup9Blocks(h,rnd.nextInt(MAX_N-100,MAX_N-1));
	}
	void generateTestGroup9Random(string h,int VAL_N) {
		CASE(HEADER=h,N=VAL_N,K=1,randomP(P,K,N),randomAB(A,B,P,N,K));
		CASE(HEADER=h,N=VAL_N+1,K=1,randomP(P,K,N),randomAB(A,B,P,N,K));
	}
	void generateTestGroup9Blocks(string h,int VAL_N) {
		CASE(HEADER=h,N=VAL_N,K=1,blocksAB(A,B,P,N,K));
		CASE(HEADER=h,N=VAL_N+1,K=1,blocksAB(A,B,P,N,K));
	}
	
	void generateTestGroup13(string h,int MIN_N,int MAX_N) {
		//All
		CASE(HEADER=h,N=rnd.nextInt(MIN_N,MIN_N+100),generateAll(A,B,P,K,N));
		CASE(HEADER=h,N=rnd.nextInt(MIN_N,MAX_N),generateAll(A,B,P,K,N));
		CASE(HEADER=h,N=rnd.nextInt(MAX_N-100,MAX_N),generateAll(A,B,P,K,N));
		
		//Blocks, 1<K<MAX_N
		generateTestGroup13Blocks(h,MIN_N,MAX_N,2,MAX_N-1);
		
		//Blocks, 10<K<MAX_N
		generateTestGroup13Blocks(h,MIN_N,MAX_N,11,MAX_N-1);
		
		//Random
		CASE(HEADER=h,N=rnd.nextInt(MAX_N-100,MAX_N),K=rnd.nextInt(2,N-1),randomP(P,K,N),randomAB(A,B,P,N,K));
	}
	void generateTestGroup13Blocks(string h,int MIN_N,int MAX_N,int MIN_K,int MAX_K) {
		CASE(HEADER=h,N=rnd.nextInt(MIN_N,MIN_N+100),K=rnd.nextInt(MIN_K,min(MAX_K,N-1)),blocksAB(A,B,P,N,K));
		CASE(HEADER=h,N=rnd.nextInt(MIN_N,MAX_N),K=rnd.nextInt(MIN_K,min(MAX_K,N-1)),blocksAB(A,B,P,N,K));
		CASE(HEADER=h,N=rnd.nextInt(MAX_N-100,MAX_N),K=rnd.nextInt(MIN_K,min(MAX_K,N-1)),blocksAB(A,B,P,N,K));
	}
	
	void randomP(vector<int> &V,int k,int n) {
		V.clear();
		vector<int> temp;
		for (int i=1;i<=n;i++) temp.push_back(i);
		rnd.shuffle(temp.begin(),temp.end());
		for (int i=0;i<k;i++) V.push_back(temp[i]);
	}
	void randomAB(vector<int> &A,vector<int> &B,vector<int> &P,int n,int k,bool garisLurus=true) {	
		A.clear(); B.clear();
		vector<int> temp;
		for (int i=1;i<=k;i++) temp.push_back(i);
		while (A.size()!=n) {
			rnd.shuffle(temp.begin(),temp.end());
			for (int data:temp) {
				if (A.size()==n) break;
				A.push_back(data);
			}
		}
		rnd.shuffle(A.begin(),A.end());
		B=A;
		if (garisLurus)  {
			while (true) {
				bool cek=false;
				for (int i=0;i<n;i++) if (P[A[i]-1]-1==i) {
					cek=true; break;
				}
				if (!cek) rnd.shuffle(A.begin(),A.end());
				else break;
			}
			while (true) {
				bool cek=false;
				for (int i=0;i<n;i++) if (P[B[i]-1]-1==i) {
					cek=true; break;
				}
				if (!cek) rnd.shuffle(B.begin(),B.end());
				else break;
			}
		}
		else {
			while (true) {
				bool cek=false;
				for (int i=0;i<n;i++) if (P[A[i]-1]-1==i) {
					cek=true; break;
				}
				if (cek) rnd.shuffle(A.begin(),A.end());
				else break;
			}
			while (true) {
				bool cek=false;
				for (int i=0;i<n;i++) if (P[B[i]-1]-1==i) {
					cek=true; break;
				}
				if (cek) rnd.shuffle(B.begin(),B.end());
				else break;
			}
		}
	}
	void reindexing(vector<int> &P,vector<int> &A,vector<int> &B) {	//Zero based
		vector<int> conv=P; rnd.shuffle(conv.begin(),conv.end());
		int idxConv[100010]; for (int i=0;i<P.size();i++) idxConv[conv[i]]=i;
		int convAB[P.size()+10]; for (int i=0;i<P.size();i++) convAB[i]=idxConv[P[i]];
		for (int i=0;i<A.size();i++) A[i]=convAB[A[i]], B[i]=convAB[B[i]];
		P=conv;
	}
	
	
	void blocksAB(vector<int> &A,vector<int> &B,vector<int> &P,int n,int k) {	
		//Blok blok, P=mid(blok)
		A.clear(); B.clear(); P.clear();
		int pos=1;
		for (int i=1;i<=k;i++) {
			int sisa=rnd.nextInt(k-i,n-1);
			int ambil=n;
			if (i!=k) ambil-=sisa;
			int mid=(pos+(pos+ambil-1))/2;
			if (ambil%2==0) mid=rnd.nextInt(mid,mid+1);
			P.push_back(mid);
			for (int j=pos;j<pos+ambil;j++) A.push_back(i), B.push_back(i);
			pos+=ambil; n=sisa;
		}
		for (int i=0;i<P.size();i++) P[i]--;
		for (int i=0;i<A.size();i++) A[i]--, B[i]--;
		
		reindexing(P,A,B);
		
		for (int i=0;i<P.size();i++) P[i]++;
		for (int i=0;i<A.size();i++) A[i]++, B[i]++;
	}
	
	bool validAssign(int a,int p,int b,bool garisLurus) {
		if (garisLurus) return (a<=p&&p<=b)||(b<=p&&p<=a);
		return (a<p&&p<b)||(b<p&&p<a);
	}
	int getRandomElementInSet(int l,int r,set<int> &S,bool hapus=true) {
		int temp=rnd.nextInt(l,r);
		auto it=S.lower_bound(temp);
		if (it==S.end()) return -1;
		if (l<=(*it)&&(*it)<=r && S.count(*it)) {
			if (hapus) S.erase(it);
			return *it;
		}
		return -1;
	}
	int pickRandomB(int a,int p,int n,bool garisLurus,set<int> &S,bool hapus=true) {
		if (garisLurus) {
			if (a==p && 0<=n-1) return getRandomElementInSet(0,n-1,S,hapus);
			if (a>p && 0<=p) return getRandomElementInSet(0,p,S,hapus);
			if (a<p && p<=n-1) return getRandomElementInSet(p,n-1,S,hapus);
			return -1;
		}
		if (a>p && 1<=p-1) getRandomElementInSet(1,p-1,S,hapus);
		if (a<p && p+1<=n-2) return getRandomElementInSet(p+1,n-2,S,hapus);
		return -1;
	}
	void generateAll(vector<int> &A,vector<int> &B,vector<int> &P,int &K,int n,bool garisLurus=true,bool solutionExists=true) {
		//Subtask 6 (gak ada garis lurus), garisLurus=false
		//Dijamin ada solusi (N>10), solutionExists=true
		while (true) {
			A.clear(); B.clear(); P.clear();
			for (int i=0;i<n;i++) A.push_back(-1), B.push_back(-1);
			int stuck=0;
			
			set<int> tempP,tempB,setP; tempP.clear(); tempB.clear(); setP.clear();
			int idxP[100010]; memset(idxP,-1,sizeof idxP);
			for (int i=0;i<n;i++) tempP.insert(i), tempB.insert(i);
			
			for (int i=0;i<n;i++) {
				auto it=tempB.end(); it--;
				int p,b;
				while (true) {
					b=getRandomElementInSet(0,*it,tempB,false);
					if (garisLurus) p=rnd.nextInt(0,n-1);
					else p=rnd.nextInt(1,n-2);
					if (tempP.size()==1 && tempP.count(p)) continue;
					if (solutionExists && validAssign(i,p,b,garisLurus)) break;
					if (!solutionExists && (garisLurus || (p!=i && p!=b))) break;
					if (stuck==10000 && n<=100) break;
					stuck++;
				}
				if (stuck==10000 && n<=10) break;
				if (setP.count(p)) {
					A[i]=B[b]=idxP[p]; tempB.erase(b);
				}
				else {
					A[i]=(int)P.size(); 
					B[b]=(int)P.size();
					idxP[p]=(int)P.size();
					P.push_back(p); 
					setP.insert(p); tempP.erase(p); tempB.erase(b);
				}
			}
			if (stuck==10000 && n<=10) continue;
			else break;
		}
		reindexing(P,A,B);
		K=P.size(); 
		for (int i=0;i<K;i++) P[i]++;
		for (int i=0;i<n;i++) A[i]++, B[i]++;
	}
};
