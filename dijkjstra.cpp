#include<vector>
#include<iostream>

#define INF 9999999
int n=12;
using namespace std;
vector<string>nameSeoul={"서울","인천","강릉","천안","청주","동해","대전","울진","광주","대구","경산","부산"};
vector<string>nameGyeongsan={"경산","서울","인천","강릉","천안","청주","동해","대전","울진","광주","대구","부산"};

vector<vector<int>> MAPSeoul={
        {0, 3, 5, INF, 8, INF, INF, INF, INF, INF, INF, INF },//서울
        {7, 0, INF, 1, INF, INF, INF, INF, INF, INF, INF, INF},//인천
        {3, INF, 0, INF, INF, 3, INF, INF, INF, INF, INF, INF},//강릉
        {INF, 3, INF, 0, 4, INF, 4, INF, INF, INF, INF, INF},//천안
        {13, INF, INF, 3, 0, 1, INF, 2, INF, INF, INF, INF},//청주
        {INF, INF, 5, INF, 2, 0, INF, 5, INF, INF, INF, INF},//동해
        {INF, INF, INF, 5, INF, INF, 0, 5, 3, 3, INF, INF},//대전
        {INF, INF, INF, INF, 2, 3, 5, 0, INF, 3, 3, INF},//울진
        {INF, INF, INF, INF, INF, INF, 3, INF, 0, 6, INF, 5},//광주
        {INF, INF, INF, INF, 6, INF, 6, INF, INF, 0, 2, 1},//대구
        {INF, INF, INF, INF, INF, INF, INF, 1, INF, INF, 0, 2},//경산
        {INF, INF, INF, INF, INF, INF, INF, INF, 4, INF, 3, 0}//부산
        };
vector<vector<int>> MAPGyeongsan={
        {0,INF, INF, INF, INF, INF, INF, INF, 1, INF, INF,2},//경산
        {INF,0,3, 5, INF, 8, INF, INF, INF, INF, INF, INF},//서울
        {INF,7,0,INF, 1, INF, INF, INF, INF, INF, INF, INF},//인천
        {INF,3,INF,0,INF,INF,3,INF, INF, INF, INF, INF, INF},//강릉
        {INF,INF,3,INF,0,4,INF,4,INF,INF,INF,INF},//천안
        {INF,13,INF,INF,3,0,1,INF,2,INF,INF,INF},//청주
        {INF,INF,INF,5,INF,2,0,INF,5,INF,INF,INF},//동해
        {INF,INF,INF,INF,5,INF,INF,0,5,3,3,INF},//대전
        {3,INF,INF,INF,INF,2,3,5,0,INF,3,INF},//울진
        {INF,INF,INF,INF,INF,INF,INF,3,INF,0,6,5},//광주
        {2,INF,INF,INF,INF,6,INF,6,INF,INF,0,1},//대구
        {3,INF,INF,INF,INF,INF,INF,INF,INF,4,INF,0},//부산
};
vector<int>touch(n,0);
vector<int>length(n,0);
void dijkstra(){//수도코드와 동일하게 코드 제작ㅇ
    int vnear;
    //초기화 touch 와 length
    for(int i=1;i<n;i++){
        touch[i]=0;//수도코드와 다르게 n-1 로 시작하기 때문에 0으로 해줘야한다
        //length[i]=MAPGyeongsan[0][i];
        length[i]=MAPSeoul[0][i];
    }
    for(int j=1;j<n;j++){
        int min=INF;
        for(int k=1;k<n;k++){
            if(0<=length[k]&&length[k]<min){//다익스트라는 음수가 나오면 안된다
                //경로의 최소비용을 찾는 과정임
                min=length[k];
                vnear=k;
            }
        }
        //경로의 최소비용을 기반으로 값을 계속 업데이트 해주는 과정
        for(int w=0;w<n;w++){
            if(length[vnear]+MAPSeoul[vnear][w]<length[w]){
                length[w]=length[vnear]+MAPSeoul[vnear][w];
                touch[w]=vnear;
            }
            /*if(length[vnear]+MAPGyeongsan[vnear][w]<length[w]){
                length[w]=length[vnear]+MAPGyeongsan[vnear][w];
                touch[w]=vnear;
            }*/
        }
        length[vnear]=-1;
    }
}
void tour(int a){//재귀적 방식으로 경로 출력
    if(a==0){
        a=1;
    }
    if(touch[a]!=0){
        int b=0;
        b=touch[a];
        tour(b);
    }
    if(touch[a]==0){
       //cout<<nameGyeongsan[touch[a]]<<" ";//name의 시작이 0으로 하기 때문
       cout<<nameSeoul[touch[a]]<<" ";//name의 시작이 0으로 하기 때문
    }
    else{
        //cout<<nameGyeongsan[touch[a]]<<" ";//name 의 시작이 0으로 시작해서
        cout<<nameSeoul[touch[a]]<<" ";

    }
}
int main(){
    dijkstra();
    //int startGyeongsan=1;//목적지 서울 경산맵을 사용
    int startSeoul=10;//목적지 경산 서울맵을 사용

    //tour(startGyeongsan);//이친구도 배열 0으로 시작해서 -1 해줌
    //cout<<nameGyeongsan[startGyeongsan];
    /*for(int i=1;i<n;i++){
        cout<<touch[i]<<" ";
    }*/
    tour(startSeoul);
    cout<<nameSeoul[startSeoul];

}

