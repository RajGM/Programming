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


void moveRight(int xC,itn yC);
void moveDown(int xC,int yC);
void moveLeft(int xC,int yC);
void moveUp(int xC,int yC);
};

void array::moveRight(int xC,itn yC){
xComponent.push(xC);
yComponent.push(yC);
visited[xC][yC]='v';
tempChar=mapArray[xC][yC];
answer.push_back(tempChar);
}
