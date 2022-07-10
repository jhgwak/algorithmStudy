#include<iostream>
using namespace std;

#define INF -1
#define MAX 5000
int n;
int W[MAX][MAX];
int minlength;
int P[MAX][MAX];
int D[MAX][MAX];
char cityname[12][12] = { "서울","인천","강릉","천안","청주","동해","대전","울진","광주","대구","울산","부산" };
char cityname2[12][12] = { "대구","인천","강릉","천안","청주","동해","대전","울진","광주","서울","울산","부산" };
//D 값과 P 값 W 값을 확인하기 위한 프린트함수 
void printCheck(int n, int m[][MAX]) {
    for (int i = 1; i <= pow(2,n-1); i++) {
        for (int j = 1; j <= pow(2, n - 1); j++) {
            cout << "  " << m[i][j];
        }
        cout << endl;
    }
}
int OneCount(int A) {
    int count=0;
    while (A != 0) {
        count += A % 2;//나머지 연산으로 1의 갯수를 계속 더함 
        A /= 2;
    }
    return count;

}

int minimum(int A, int i, int* minJ) {
    int j, m, min;
    min = INF;
    for (j = 1; j < (int)pow(2, n - 1); j++) {
        if (!(A & (1 << (j - 2))) != 0)continue;//속해져 있는것중에 값이 있어야 한다 
        m = W[i][j] + D[j][(A & (~(1 << (j - 2))))];//포함 되어져 있는 것 중에 j 가 A 에 없는 것을 값을 넣어줌 
        if (min > m) {
            min = m;
            *minJ = j;
        }
    }
    return min;
}
//값이 포함되어있는지 체크하는 함수 
//int isin(int i,int A) {
//    return ((A & (1 << (i - 2))) != 0) ? 1 : 0;
//}
void travel() {
    int i, j, k, A;
    for (i = 1; i <= n; i++) {
        D[i][0] = W[i][1];//처음 결로 입력 
       // cout << W[i][1];
        //cout << D[i][0];
    }
   //printCheck(n, D);
    for (k = 1; k <= n - 2; k++) {
        for (A = 0; A < (int)pow(2, n - 1); A++) {//부분집합의 갯수 
            if (OneCount(A)!=k)continue;//1의 갯수가 같아야함 
            for (i = 2; i <= n; i++) {
                if (((A & (1 << (i - 2))) != 0))continue;//A 가 속해저 있으면 속해져 있는 관계의 비트를 체크
                D[i][A] = minimum(A, i, &j);//A 가 i 에 속해져 있을 때 속해져 있는 것을 찾는 함수구현 
                P[i][A] = j;//최소값 
            }
        }
      //printCheck(n, P);
    }
   // printCheck(n, D);
    A = (int)pow(2, n - 1) - 1;
    D[1][A] = minimum(A, 1, &j);
    P[1][A] = j;
    minlength = D[1][A];//최소값 
}
//경로 출력 
void printpath(int v, int A) {
    if (A == 0) {
        cout << "->서울" << endl;
        //cout << "->대구" << endl;//출발지 출력
        //cout << "v1" << endl;
        cout << minlength;//경로 최소값 
    }
    else {
        
        //cout << cityname[P[v][A]] << "->";
       cout << P[v][A] << "->";
        printpath(P[v][A], (A & (~(1 << (P[v][A] - 2)))));
    }
    
}
int main() {
    int i, j,size,v;
   
    int DeaGuMap[12][12] = {
        {0,INF,INF,INF,INF,6,-1,6,INF,INF,2,1},//대구
         {7, 0, INF, 1, INF,INF,INF,INF,INF,INF,INF,INF},//인천
        {3, INF, 0, INF,INF, 3, INF,INF,INF,INF,INF,INF},//강릉
        {INF,3,INF,0,4,INF,4,INF,INF,INF,INF,INF},//천안
        {13,INF,INF,3,0,1,INF,2,INF,9,INF,INF},//청주
        {INF,INF,5,INF,2,0,INF,5,INF,INF,INF,INF},//동해
        {INF,INF,INF,5,INF,INF,0,5,3,3,INF,INF},//대전
        {INF,INF,INF,INF,2,3,5,0,INF,3,3,INF},//울진
        {INF,INF,INF,INF,INF,INF,3,INF,0,6,INF,5},//광주
        { INF, 3, 5, INF, 8, INF,INF,INF,INF, 0, INF,INF},//서울
        {INF,INF,INF,INF,INF,INF,INF,1,INF,INF,0,2},//울산
        {INF,INF,INF,INF,INF,INF,INF,INF,4,INF,3,0}//부산
    };
    int SeoulMap[12][12] = {
        //서울 인천 강릉 천안 청주 동해 대전 울진 광주 대구 울산 부산 
       {0, 3, 5, INF, 8, INF,INF,INF,INF,INF,INF,INF},
       {7, 0, INF, 1, INF,INF,INF,INF,INF,INF,INF,INF},
       {3, INF, 0, INF, INF, 3, INF,INF,INF,INF,INF,INF},
       {INF,3,INF,0,4,INF,4,INF,INF,INF,INF,INF},
       {13,INF,INF,3,0,1,INF,2,INF,INF,INF,INF},
       {INF,INF,5,INF,2,0,INF,5,INF,INF,INF,INF},
       {INF,INF,INF,5,INF,INF,0,5,3,3,INF,INF},
       {INF,INF,INF,INF,2,3,5,0,INF,3,3,INF},
       {INF,INF,INF,INF,INF,INF,3,INF,0,6,INF,5},
       {INF,INF,INF,INF,6,INF,6,INF,INF,0,2,1},
       {INF,INF,INF,INF,INF,INF,1,INF,INF,0,2},
       {INF,INF,INF,INF,INF,INF,INF,INF,4,INF,3,0}
       
    };
    //test 경로 
    int adj[4][4] = {
        {0,2,9,INF},
        {1,0,6,4},
        {INF,7,0,8},
        {6,3,INF,0},
    };
    n = 12;
    size = pow(2, n-1);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            W[i][j] = SeoulMap[i - 1][j - 1];
        }
    }
    
    travel();
    v = 1;
    
    printpath(v, size-1);
   //cout << endl;
   //printCheck(n, D);
   //cout << endl;
   //printCheck(n, P);
}


