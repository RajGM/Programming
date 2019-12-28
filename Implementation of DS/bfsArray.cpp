#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct array {
private:
	char mapArray[10][10];
	char tempChar;
	queue<int> xComponent;
	queue<int> yComponent;
	vector<vector<char>> visited;
	vector<char> answer;


	void moveRight(int xC, int yC);
	void moveDown(int xC, int yC);
	void moveLeft(int xC, int yC);
	void moveUp(int xC, int yC);
	void move();
	bool isOk(int xC, int yC);
};

void array::moveRight(int xC, int yC) {
	xComponent.push(xC);
	yComponent.push(yC);
	visited[xC][yC] = 'v';
	tempChar = mapArray[xC][yC];
	answer.push_back(tempChar);
}

void array::moveDown(int xC, int yC) {
	xComponent.push(xC);
	yComponent.push(yC);
	visited[xC][yC] = 'v';
	tempChar = mapArray[xC][yC];
	answer.push_back(tempChar);
}

void array::moveLeft(int xC, int yC) {
	xComponent.push(xC);
	yComponent.push(yC);
	visited[xC][yC] = 'v';
	tempChar = mapArray[xC][yC];
	answer.push_back(tempChar);
}

void array::moveUp(int xC, int yC) {
	xComponent.push(xC);
	yComponent.push(yC);
	visited[xC][yC] = 'v';
	tempChar = mapArray[xC][yC];
	answer.push_back(tempChar);
}

bool array::isOk(int xC, int yC) {
	if (visited[xC][yC] == 'v')
		return false;
	else
		if (mapArray[xC][xC] == 'x')
			return false;
		else
			return true;
}

void array::move() {
	int currX = 0, currY = 0;
	while (mapArray[currX][currY] != 't') {
		if (isOk(currX + 1, currY))
			moveRight(currX + 1, currY);
		if (isOk(currX, currY + 1))
			moveDown(currX, currY + 1);
		if (isOk(currX - 1, currY))
			moveLeft(currX - 1, currY);
		if (isOk(currX, currY + 1))
			moveUp(currX, currY + 1);
	}
	xComponent.push(currX);
	yComponent.push(currY);
	visited[currX][currY] = 'v';
	tempChar = mapArray[currX][currY];
	answer.push_back(tempChar);
}

int main() {
	cout << "Hello World" << endl;


	return 0;
}




