#include<iostream>
using namespace std;

#define INF -1
#define MAX 5000
int n;
int W[MAX][MAX];
int minlength;
int P[MAX][MAX];
int D[MAX][MAX];
char cityname[12][12] = { "����","��õ","����","õ��","û��","����","����","����","����","�뱸","���","�λ�" };
char cityname2[12][12] = { "�뱸","��õ","����","õ��","û��","����","����","����","����","����","���","�λ�" };
//D ���� P �� W ���� Ȯ���ϱ� ���� ����Ʈ�Լ� 
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
        count += A % 2;//������ �������� 1�� ������ ��� ���� 
        A /= 2;
    }
    return count;

}

int minimum(int A, int i, int* minJ) {
    int j, m, min;
    min = INF;
    for (j = 1; j < (int)pow(2, n - 1); j++) {
        if (!(A & (1 << (j - 2))) != 0)continue;//������ �ִ°��߿� ���� �־�� �Ѵ� 
        m = W[i][j] + D[j][(A & (~(1 << (j - 2))))];//���� �Ǿ��� �ִ� �� �߿� j �� A �� ���� ���� ���� �־��� 
        if (min > m) {
            min = m;
            *minJ = j;
        }
    }
    return min;
}
//���� ���ԵǾ��ִ��� üũ�ϴ� �Լ� 
//int isin(int i,int A) {
//    return ((A & (1 << (i - 2))) != 0) ? 1 : 0;
//}
void travel() {
    int i, j, k, A;
    for (i = 1; i <= n; i++) {
        D[i][0] = W[i][1];//ó�� ��� �Է� 
       // cout << W[i][1];
        //cout << D[i][0];
    }
   //printCheck(n, D);
    for (k = 1; k <= n - 2; k++) {
        for (A = 0; A < (int)pow(2, n - 1); A++) {//�κ������� ���� 
            if (OneCount(A)!=k)continue;//1�� ������ ���ƾ��� 
            for (i = 2; i <= n; i++) {
                if (((A & (1 << (i - 2))) != 0))continue;//A �� ������ ������ ������ �ִ� ������ ��Ʈ�� üũ
                D[i][A] = minimum(A, i, &j);//A �� i �� ������ ���� �� ������ �ִ� ���� ã�� �Լ����� 
                P[i][A] = j;//�ּҰ� 
            }
        }
      //printCheck(n, P);
    }
   // printCheck(n, D);
    A = (int)pow(2, n - 1) - 1;
    D[1][A] = minimum(A, 1, &j);
    P[1][A] = j;
    minlength = D[1][A];//�ּҰ� 
}
//��� ��� 
void printpath(int v, int A) {
    if (A == 0) {
        cout << "->����" << endl;
        //cout << "->�뱸" << endl;//����� ���
        //cout << "v1" << endl;
        cout << minlength;//��� �ּҰ� 
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
        {0,INF,INF,INF,INF,6,-1,6,INF,INF,2,1},//�뱸
         {7, 0, INF, 1, INF,INF,INF,INF,INF,INF,INF,INF},//��õ
        {3, INF, 0, INF,INF, 3, INF,INF,INF,INF,INF,INF},//����
        {INF,3,INF,0,4,INF,4,INF,INF,INF,INF,INF},//õ��
        {13,INF,INF,3,0,1,INF,2,INF,9,INF,INF},//û��
        {INF,INF,5,INF,2,0,INF,5,INF,INF,INF,INF},//����
        {INF,INF,INF,5,INF,INF,0,5,3,3,INF,INF},//����
        {INF,INF,INF,INF,2,3,5,0,INF,3,3,INF},//����
        {INF,INF,INF,INF,INF,INF,3,INF,0,6,INF,5},//����
        { INF, 3, 5, INF, 8, INF,INF,INF,INF, 0, INF,INF},//����
        {INF,INF,INF,INF,INF,INF,INF,1,INF,INF,0,2},//���
        {INF,INF,INF,INF,INF,INF,INF,INF,4,INF,3,0}//�λ�
    };
    int SeoulMap[12][12] = {
        //���� ��õ ���� õ�� û�� ���� ���� ���� ���� �뱸 ��� �λ� 
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
    //test ��� 
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


