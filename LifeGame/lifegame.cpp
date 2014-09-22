#include <iostream>
#include <ctime>
using namespace std;

const int row = 30;
const int col = 30;
bool world[row][col];

int neighbor(int x, int y){
	int count = 0;
	try{	count+=(world[x-1][y-1] && y-1>=0 && x-1>=0);	}catch(bool){}
	try{	count+=(world[x-1][y] && x-1>=0);				}catch(bool){}
	try{	count+=(world[x-1][y+1] && y+1<col && x-1>=0);	}catch(bool){}
	try{	count+=(world[x][y-1] && y-1>=0);				}catch(bool){}
	try{	count+=(world[x][y+1] && y+1<col);				}catch(bool){}
	try{	count+=(world[x+1][y-1] && y-1>=0 && x+1<row);	}catch(bool){}
	try{	count+=(world[x+1][y] && x+1<row);				}catch(bool){}
	try{	count+=(world[x+1][y+1] && y+1<col && x+1<row);}catch(bool){}
	return count;
}

bool nextSecond(){
	bool any_change = false;
	bool mirror[row][col];
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(neighbor(i,j)==3)
				mirror[i][j] = true;
			else if(neighbor(i,j)==2)
				mirror[i][j] = world[i][j];
			else
				mirror[i][j] = false;

			if(!any_change && mirror[i][j]!=world[i][j])
				any_change = true;
		}
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			world[i][j] = mirror[i][j];
		}
	}

	return any_change;
}

void printInfo(int count){
	cout <<"[ROW:\t"<<row<<"]"<<endl;
	cout <<"[COL:\t"<<col<<"]"<<endl;
	cout <<"[Life:\t"<<count<<"]"<<endl;
}

void printWorld(){
	int count = 0;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(world[i][j])	{
				cout << "O";
				count++;
			}
			else	cout << " ";
		}
		cout << endl;
	}
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

	printInfo(count);
}



int main(){

	srand((unsigned)time(NULL));

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			world[i][j] = rand()%2;
		}
	}

	printWorld();
	while(nextSecond()){
		printWorld();
		sleep(1);
	}

	return 0;
}
