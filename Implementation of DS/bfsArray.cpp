#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct array{
private:
char mapArray[10][10];
char tempChar;
queue<int> xComponent;
queue<int> yComponent;
vector<vector<char>> visited;
vector<char> answer;

void inputMap();
void moveRight(int xC,int yC);
void moveDown(int xC,int yC);
void moveLeft(int xC,int yC);
void moveUp(int xC,int yC);
void move();
bool isOk(int xC,int yC);
};

void array::moveRight(int xC,int yC){
xComponent.push(xC);
yComponent.push(yC);
}

void array::moveDown(int xC,int yC){
xComponent.push(xC);
yComponent.push(yC);
}

void array::moveLeft(int xC,int yC){
xComponent.push(xC);
yComponent.push(yC);
}

void array::moveUp(int xC,int yC){
xComponent.push(xC);
yComponent.push(yC);
}

bool array::isOk(int xC,int yC){
return ((visited[xC][yC]!='v') && (mapArray[xC][yC]!='t'));
if(visited[xC][yC]=='v')
return false;
else
if(mapArray[xC][xC]=='x')
return false;
else
return true;
}

void array::move(){
int currX=0,currY=0;
while(mapArray[currX][currY]!='t'){
if(isOk(currX+1,currY))
moveRight(currX+1,currY);

if(isOk(currX,currY+1))
moveDown(currX,currY+1);

if((isOk(currX-1,currY)&&(currX-1!=-1)))
moveLeft(currX-1,currY);

if((isOk(currX,currY-1)&&(currY-1!=-1)))
moveUp(currX,currY-1);

if((xComponent.size()!=0) && (yComponent.size()!=0)){
    visited[xComponent.top()][yComponent.top()]='v';
    xComponent.pop();
    yComponent.pop();
    tempChar=mapArray[xComponent][yComponent];
    answer.push_back(tempChar);
}

}
xComponent.push(currX);
yComponent.push(currY);
visited[currX][currY]='v';
tempChar=mapArray[currX][currY];
answer.push_back(tempChar);
}

void array::inputMap(){
    cout<<"Input values for map"<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<"Input value for i:"<<i<<" j:"<<j<<endl;
            cin>>mapArray[i][j];
        }
    }
}

int main(){
cout<<"Hello World"<<endl;



return 0;
}






