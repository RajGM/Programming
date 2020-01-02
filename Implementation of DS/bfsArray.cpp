#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct arr{
private:
char mapArray[10][10];
char tempChar;
int sizeVisited=0;
queue<int> xComponent;
queue<int> yComponent;
char visited[10][10]={'u'};
vector<char> answer;
int xtarget=1+rand() % 10;
int ytarget=1+rand() % 10;

void inputMap();
void moveRight(int xC,int yC);
void moveDown(int xC,int yC);
void moveLeft(int xC,int yC);
void moveUp(int xC,int yC);
void move();
bool isOk(int xC,int yC);
void showPath();
public:
void run();
};

void arr::moveRight(int xC,int yC){
xComponent.push(xC);
yComponent.push(yC);
}

void arr::moveDown(int xC,int yC){
xComponent.push(xC);
yComponent.push(yC);
}

void arr::moveLeft(int xC,int yC){
xComponent.push(xC);
yComponent.push(yC);
}

void arr::moveUp(int xC,int yC){
xComponent.push(xC);
yComponent.push(yC);
}

bool arr::isOk(int xC,int yC){
return ((visited[xC][yC]!='v') && (mapArray[xC][yC]!='t'));
}

void arr::inputMap(){
    cout<<"Values of map"<<endl;
    //Using random numbers
    /*
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<"Input value for i:"<<i<<" j:"<<j<<endl;
            cin>>mapArray[i][j];
        }
    }
    */
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int t=rand() % 9;
            char chA='0' + t;
            //cout<<"T:"<<t<<endl;
            //cout<<"CHA:"<<chA<<endl;
            mapArray[i][j]=chA;
            if(i==xtarget&&j==ytarget){
                mapArray[i][j]='t';
            }
            cout<<"i:"<<i<<" j:"<<j<<" "<<mapArray[i][j]<<endl;;
        }
    }
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            visited[i][j]='u';
        }
    }
    /*
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<"Coordinates x:"<<i<<" y:"<<j<<" "<<visited[i][j]<<endl;
        }
    }
    */
}

void arr::move(){
int currX=0,currY=0;
xComponent.push(0);
yComponent.push(0);
visited[currX][currY]='v';
tempChar=mapArray[currX][currY];
answer.push_back(tempChar);
sizeVisited++;
//cout<<"Debugging move point 1"<<endl;
//Getting infinite loop 
while(mapArray[currX][currY]!='t'){
//cout<<"Debugging while:"<<currX+1<<" "<<endl;
if((isOk(currX+1,currY) && (currX+1!=10) ))
moveRight(currX+1,currY);

if((isOk(currX,currY+1) && (currY+1!=10) ))
moveDown(currX,currY+1);

if((isOk(currX-1,currY) && (currX-1!=-1) ))
moveLeft(currX-1,currY);

if((isOk(currX,currY-1) && (currY-1!=-1) ))
moveUp(currX,currY-1);

if( (!xComponent.empty()) && (!yComponent.empty()) ){
    currX=xComponent.front();
    currY=yComponent.front();
    xComponent.pop();
    yComponent.pop();
    visited[currX][currY]='v';
    tempChar=mapArray[currX][currY];
    answer.push_back(tempChar);
    sizeVisited++;
    cout<<"Last if values"<<" currX:"<<currX<<" currY:"<<currY<<" visited:"<<visited[currX][currY]<<" tempChar:"<<tempChar<<" Visited size:"<<sizeVisited<<endl;
}

}

cout<<"Debugging move point 3"<<endl;

/*
xComponent.push(currX);
yComponent.push(currY);
visited[currX][currY]='v';
tempChar=mapArray[currX][currY];
answer.push_back(tempChar);
*/
}

void arr::run(){
    cout<<"Inside run()"<<endl;
    cout<<"Target Block x:"<<xtarget<<" y:"<<ytarget<<endl;
    inputMap();
    cout<<"inputMap() done"<<endl;
    move();
    cout<<"move() done"<<endl;
    showPath();
    cout<<"showPath() done"<<endl;
}

void arr::showPath(){
    cout<<"Answer:";
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}

int main(){
cout<<"Hello World"<<endl;
arr A;
A.run();
return 0;
}