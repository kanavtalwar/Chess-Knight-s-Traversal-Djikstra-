#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int board[8][8];
    int paths[50][8][8];
    int x,y;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            board[i][j]=50;
            for(int k=0; k<50; k++){
                paths[k][i][j] = 0;
            }
        }
    }
    cout<<"Enter the starting position :-\n";
    cin>>x>>y;
    if(x>8||y>8||x<1||y<1)
    {
    	cout<<"YOU SHOULD KNOW ABOUT DIMENSIONS OF CHESS BOARD ";
    	return 0;
	}
    board[x-1][y-1] = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"Enter the end position :-\n";
    cin>>x>>y;
    if(x>8||y>8||x<1||y<1)
    {
    	cout<<"YOU SHOULD KNOW ABOUT DIMENSIONS OF CHESS BOARD ";
    	return 0;
	}
    x--;
    y--;
    while(board[x][y] == 50){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j] != 50){
                    if(i+2 < 8 && j+1 < 8) {
                        if(board[i+2][j+1] > board[i][j]+1) {
                            board[i+2][j+1] = board[i][j]+1;
                            int k=0;
                            while(paths[k][i][j] != 0) {
                                paths[k][i+2][j+1] = paths[k][i][j];
                                k++;
                            }
                            paths[k][i+2][j+1] = 10*(i+1) + (j+1);
                            paths[k+1][i+2][j+1] = 0;
                        }
                        board[i+2][j+1] = min(board[i+2][j+1],board[i][j]+1);
                    }
                    if(i+2 < 8 && j-1 >= 0) {
                        if(board[i+2][j-1] > board[i][j]+1) {
                            board[i+2][j-1] = board[i][j]+1;
                            int k=0;
                            while(paths[k][i][j] != 0) {
                                paths[k][i+2][j-1] = paths[k][i][j];
                                k++;
                            }
                            paths[k][i+2][j-1] = 10*(i+1) + (j+1);
                            paths[k+1][i+2][j-1] = 0;
                        }
                        board[i+2][j-1] = min(board[i+2][j-1],board[i][j]+1);
                    }
                    if(i+1 < 8 && j+2 < 8) {
                        if(board[i+1][j+2] > board[i][j]+1) {
                            board[i+1][j+2] = board[i][j]+1;
                            int k=0;
                            while(paths[k][i][j] != 0) {
                                paths[k][i+1][j+2] = paths[k][i][j];
                                k++;
                            }
                            paths[k][i+1][j+2] = 10*(i+1) + (j+1);
                            paths[k+1][i+1][j+2] = 0;
                        }
                        board[i+1][j+2] = min(board[i+1][j+2],board[i][j]+1);
                    }
                    if(i+1 < 8 && j-2 >= 0) {
                        if(board[i+1][j-2] > board[i][j]+1) {
                            board[i+1][j-2] = board[i][j]+1;
                            int k=0;
                            while(paths[k][i][j] != 0) {
                                paths[k][i+1][j-2] = paths[k][i][j];
                                k++;
                            }
                            paths[k][i+1][j-2] = 10*(i+1) + (j+1);
                            paths[k+1][i+1][j-2] = 0;
                        }
                        board[i+1][j-2] = min(board[i+1][j-2],board[i][j]+1);
                    }
                    if(i-1 >= 0 && j+2 < 8) {
                        if(board[i-1][j+2] > board[i][j]+1) {
                            board[i-1][j+2] = board[i][j]+1;
                            int k=0;
                            while(paths[k][i][j] != 0) {
                                paths[k][i-1][j+2] = paths[k][i][j];
                                k++;
                            }
                            paths[k][i-1][j+2] = 10*(i+1) + (j+1);
                            paths[k+1][i-1][j+2] = 0;
                        }
                        board[i-1][j+2] = min(board[i-1][j+2],board[i][j]+1);
                    }
                    if(i-1 >= 0 && j-2 >= 0) {
                        if(board[i-1][j-2] > board[i][j]+1) {
                            board[i-1][j-2] = board[i][j]+1;
                            int k=0;
                            while(paths[k][i][j] != 0) {
                                paths[k][i-1][j-2] = paths[k][i][j];
                                k++;
                            }
                            paths[k][i-1][j-2] = 10*(i+1) + (j+1);
                            paths[k+1][i-1][j-2] = 0;
                        }
                        board[i-1][j-2] = min(board[i-1][j-2],board[i][j]+1);
                    }
                    if(i-2 >= 0 && j+1 < 8) {
                        if(board[i-2][j+1] > board[i][j]+1) {
                            board[i-2][j+1] = board[i][j]+1;
                            int k=0;
                            while(paths[k][i][j] != 0) {
                                paths[k][i-2][j+1] = paths[k][i][j];
                                k++;
                            }
                            paths[k][i-2][j+1] = 10*(i+1) + (j+1);
                            paths[k+1][i-2][j+1] = 0;
                        }
                        board[i-2][j+1] = min(board[i-2][j+1],board[i][j]+1);
                    }
                    if(i-2 >= 0 && j-1 >= 0) {
                        if(board[i-2][j-1] > board[i][j]+1) {
                            board[i-2][j-1] = board[i][j]+1;
                            int k=0;
                            while(paths[k][i][j] != 0) {
                                paths[k][i-2][j-1] = paths[k][i][j];
                                k++;
                            }
                            paths[k][i-2][j-1] = 10*(i+1) + (j+1);
                            paths[k+1][i-2][j-1] = 0;
                        }
                        board[i-2][j-1] = min(board[i-2][j-1],board[i][j]+1);
                    }
                }
            }
        }   
    }int x1,y1;
    
    int k=0;    
    while(paths[k][x][y] != 0) {
    	x1=paths[k][x][y]/10;
    	y1=paths[k][x][y]%10;
        //cout<<paths[k][x][y]<<"\n";
        cout<<x1<<","<<y1<<"\n";
        k++;
    }
    cout<<x+1<<","<<y+1<<endl;
    cout<<"\n\n\n\n\n\n"<<"Least No. of moves is"<<endl<<board[x][y];    
    return 0;
}
