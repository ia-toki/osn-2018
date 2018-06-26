#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int MAGIC=1;
//Const magic buat las vegas, sementara pasang kecil dulu biar pas di run gak lama
//Range nilai sekitar >=80 tergantung const magic

bool between(int x,int l,int r) {
	return (l<=x && x<=r);
}

int toInt(string S) {
	int ret=0;
	for (int i=0;i<S.size();i++) ret*=10, ret+=(S[i]-'0');
	return ret;
}

int getDistance(string S) {
	string temp=""; 
	for (int i=0;i<(int)S.size()-1;i++) temp+=S[i]; 
	return toInt(temp);
}

int n,p;
string UP[510], DOWN[510], LEFT[510], RIGHT[510];
string GRID[510], tempGRID[510], ANS[510];
bool RED[510][510], BLUE[510][510];
int idxR[510][510], idxB[510][510];
vector<pii> R,B;
vector<pii> edge;
bool vis[510][510];
int parentR[2010], parentB[2010];
int curQ;
int step[510][510];
queue<pii> BFS;
stack<pii> stepClear;
int Mx[4]={-1,0,1,0};
int My[4]={0,1,0,-1};

inline void read() {
	cin>>n>>p;
	for (int i=0;i<n;i++) cin>>UP[i];
	for (int i=0;i<n;i++) cin>>LEFT[i]>>RIGHT[i];
	for (int i=0;i<n;i++) cin>>DOWN[i];
}

inline void init() {
	memset(RED,true,sizeof RED); memset(BLUE,true,sizeof BLUE);
	memset(idxR,-1,sizeof idxR); memset(idxB,-1,sizeof idxB);
	memset(step,-1,sizeof step);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) GRID[i]+="-";
	}
}

void flood(int x, int y, int c) {
    vis[x][y]=true;
    if (x>0 && GRID[x-1][y]==c && !vis[x-1][y]) flood(x-1,y,c);
    if (y>0 && GRID[x][y-1]==c && !vis[x][y-1]) flood(x,y-1,c);
    if (x<n-1 && GRID[x+1][y]==c && !vis[x+1][y]) flood(x+1,y,c);
    if (y<n-1 && GRID[x][y+1]==c && !vis[x][y+1]) flood(x,y+1,c);
}

inline int getRegion() {
	int Q=0;
	memset(vis,false,sizeof vis);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (!vis[i][j] && GRID[i][j]!='-') flood(i,j,GRID[i][j]), Q++;
		}
	}
	return Q;
}

inline void step1() {	//As is
	for (int i=0;i<n;i++) {
		if (UP[i]!="-" && UP[i]!="0") {
			int d=getDistance(UP[i]);
			char c=UP[i].back();
			if (c=='M') {
				GRID[d-1][i]='M';
				BLUE[d-1][i]=false;
				if (idxR[d-1][i]==-1) idxR[d-1][i]=R.size(), R.push_back({d-1,i});
			}
			if (c=='B') {
				GRID[d-1][i]='B';
				RED[d-1][i]=false;
				if (idxB[d-1][i]==-1) idxB[d-1][i]=B.size(), B.push_back({d-1,i});
			}
		}
		if (LEFT[i]!="-" && LEFT[i]!="0") {
			int d=getDistance(LEFT[i]);
			char c=LEFT[i].back();
			if (c=='M') {
				GRID[i][d-1]='M';
				BLUE[i][d-1]=false;
				if (idxR[i][d-1]==-1) idxR[i][d-1]=R.size(), R.push_back({i,d-1});
			}
			if (c=='B') {
				GRID[i][d-1]='B';
				RED[i][d-1]=false;
				if (idxB[i][d-1]==-1) idxB[i][d-1]=B.size(), B.push_back({i,d-1});
			}
		}
		if (RIGHT[i]!="-" && RIGHT[i]!="0") {
			int d=getDistance(RIGHT[i]);
			char c=RIGHT[i].back();
			if (c=='M') {
				GRID[i][n-d]='M';
				BLUE[i][n-d]=false;
				if (idxR[i][n-d]==-1) idxR[i][n-d]=R.size(), R.push_back({i,n-d});
			}
			if (c=='B') {
				GRID[i][n-d]='B';
				RED[i][n-d]=false;
				if (idxB[i][n-d]==-1) idxB[i][n-d]=B.size(), B.push_back({i,n-d});
			}
		}
		if (DOWN[i]!="-" && DOWN[i]!="0") {
			int d=getDistance(DOWN[i]);
			char c=DOWN[i].back();
			if (c=='M') {
				GRID[n-d][i]='M';
				BLUE[n-d][i]=false;
				if (idxR[n-d][i]==-1) idxR[n-d][i]=R.size(), R.push_back({n-d,i});
			}
			if (c=='B') {
				GRID[n-d][i]='B';
				RED[n-d][i]=false;
				if (idxB[n-d][i]==-1) idxB[n-d][i]=B.size(), B.push_back({n-d,i});
			}
		}
	}
	curQ=getRegion();
	for (int i=0;i<n;i++) ANS[i]=GRID[i];
}

inline void step2() {	//Flagging petak yang gak boleh diwarnain merah/biru
	for (int i=0;i<n;i++) {
		if (UP[i]!="-") {
			if (UP[i]=="0") for (int j=0;j<n;j++) RED[j][i]=BLUE[j][i]=false;
			else {
				int d=getDistance(UP[i]);
				char c=UP[i].back();
				if (c=='M') for (int j=0;j<d-1;j++) RED[j][i]=BLUE[j][i]=false;
				if (c=='B') for (int j=0;j<d-1;j++) RED[j][i]=BLUE[j][i]=false;
			}
		}
		if (LEFT[i]!="-") {
			if (LEFT[i]=="0") for (int j=0;j<n;j++) RED[i][j]=BLUE[i][j]=false;
			else {
				int d=getDistance(LEFT[i]);
				char c=LEFT[i].back();
				if (c=='M') for (int j=0;j<d-1;j++) RED[i][j]=BLUE[i][j]=false;
				if (c=='B') for (int j=0;j<d-1;j++) RED[i][j]=BLUE[i][j]=false;
			}
		}
		if (RIGHT[i]!="-") {
			if (RIGHT[i]=="0") for (int j=0;j<n;j++) RED[i][j]=BLUE[i][j]=false;
			else {
				int d=getDistance(RIGHT[i]);
				char c=RIGHT[i].back();
				if (c=='M') for (int j=n-d+1;j<n;j++) RED[i][j]=BLUE[i][j]=false;
				if (c=='B') for (int j=n-d+1;j<n;j++) RED[i][j]=BLUE[i][j]=false;
			}
		}
		if (DOWN[i]!="-") {
			if (DOWN[i]=="0") for (int j=0;j<n;j++) RED[j][i]=BLUE[j][i]=false;
			else {
				int d=getDistance(DOWN[i]);
				char c=DOWN[i].back();
				if (c=='M') for (int j=n-d+1;j<n;j++) RED[j][i]=BLUE[j][i]=false;
				if (c=='B') for (int j=n-d+1;j<n;j++) RED[j][i]=BLUE[j][i]=false;
			}
		}
	}
}

inline bool allowedColor(int x,int y,char c) {
	if (c=='M') return RED[x][y]; return BLUE[x][y];
}

inline int getIndexNode(int x,int y,char c) {
	if (GRID[x][y]!=c) return -1;
	if (c=='M') return idxR[x][y]; return idxB[x][y];
}

void findFriend(int x,int y,vector<int> &res,char c) {
	vis[x][y]=true;
	int temp=getIndexNode(x,y,c);
	if (temp!=-1) res.push_back(temp);
	if (x > 0 && !vis[x-1][y] && allowedColor(x-1,y,c)) findFriend(x-1,y,res,c);
    if (y > 0 && !vis[x][y-1] && allowedColor(x,y-1,c)) findFriend(x,y-1,res,c);
    if (x < n-1 && !vis[x+1][y] && allowedColor(x+1,y,c)) findFriend(x+1,y,res,c);
    if (y < n-1 && !vis[x][y+1] && allowedColor(x,y+1,c)) findFriend(x,y+1,res,c);
}

inline void step3() {	//Create adjacency for Red/Blue
	memset(vis,false,sizeof vis);
	for (int i=0;i<R.size();i++) {
		if (vis[R[i].first][R[i].second]) continue;
		vector<int> res;
		findFriend(R[i].first,R[i].second,res,'M');
		for (int j=0;j<res.size();j++) {
			for (int k=j+1;k<res.size();k++) {
				edge.push_back({res[j],res[k]});
			}
		}
	}
	memset(vis,false,sizeof vis);
	for (int i=0;i<B.size();i++) {
		if (vis[B[i].first][B[i].second]) continue;
		vector<int> res;
		findFriend(B[i].first,B[i].second,res,'B');
		for (int j=0;j<res.size();j++) {
			for (int k=j+1;k<res.size();k++) {
				edge.push_back({res[j]+2000,res[k]+2000});
			}
		}
	}
}

int findParent(int cur,char c) {
	if (c=='M') {
		if (parentR[cur]==cur) return cur;
		return parentR[cur]=findParent(parentR[cur],c);
	}
	if (c=='B') {
		if (parentB[cur]==cur) return cur;
		return parentB[cur]=findParent(parentB[cur],c);
	}
}

bool validPetak(int x,int y) {
	return (between(x,0,n-1) && between(y,0,n-1));
}

bool join(int from,int to,char c) {
	int pfrom=findParent(from,c), pto=findParent(to,c);
	if (pfrom==pto) return false;
	while (!BFS.empty()) BFS.pop();
	while (!stepClear.empty()) {
		pii cur=stepClear.top(); stepClear.pop();
		step[cur.first][cur.second]=-1;
	}
	pii awal,akhir;
	if (c=='M') awal=R[from], akhir=R[to];
	if (c=='B') awal=B[from], akhir=B[to];
	BFS.push(awal);
	step[awal.first][awal.second]=0; stepClear.push(awal);
	bool BFSdone=false;
	while (!BFS.empty()) {
		pii cur=BFS.front(); BFS.pop();
		for (int i=0;i<4;i++) {
			pii next=cur; next.first+=Mx[i]; next.second+=My[i];
			if (!validPetak(next.first,next.second)) continue;
			if (c=='M' && !RED[next.first][next.second]) continue;
			if (c=='B' && !BLUE[next.first][next.second]) continue;
			if (step[next.first][next.second]!=-1) continue;
			if (GRID[next.first][next.second]!='-' && GRID[next.first][next.second]!=c) continue;
			step[next.first][next.second]=step[cur.first][cur.second]+1; stepClear.push(next);
			if (next==akhir) {
				BFSdone=true; break;
			}
			BFS.push(next);
		}
		if (BFSdone) break;
	}
	if (step[akhir.first][akhir.second]==-1) return false;
	pii cur=akhir;
	while (cur!=awal) {
		for (int i=0;i<4;i++) {
			pii prev=cur; prev.first+=Mx[i]; prev.second+=My[i];
			if (!validPetak(prev.first,prev.second)) continue;
			if (step[prev.first][prev.second]+1==step[cur.first][cur.second]) {
				GRID[prev.first][prev.second]=c; cur=prev; break;
			}
		}
	}
	if (c=='M') parentR[pfrom]=pto;
	if (c=='B') parentB[pfrom]=pto;
}

inline void step4() {	//Random Spanning Tree, Las Vegas
	for (int i=0;i<R.size();i++) parentR[i]=i;
	for (int i=0;i<B.size();i++) parentB[i]=i;
	for (int i=0;i<n;i++) tempGRID[i]=GRID[i];
	random_shuffle(edge.begin(),edge.end());
	for (auto data:edge) {
		if (data.first>=2000) {
			join(data.first-2000,data.second-2000,'B');
		}
		else {
			join(data.first,data.second,'M');
		}
	}
	int tempQ=getRegion();
	if (tempQ<curQ) {
		curQ=tempQ;
		for (int i=0;i<n;i++) ANS[i]=GRID[i];
	}
	else {
		for (int i=0;i<n;i++) GRID[i]=tempGRID[i];
	}
}

inline void write() {
	for (int i=0;i<n;i++) cout<<ANS[i]<<endl;
	cerr<<"Region : "<<curQ<<" "<<p<<endl;
}

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read();
	init();
	step1();
	step2();
	step3();
	for (int i=0;i<MAGIC;i++) step4();
	write();
	return 0;
}
