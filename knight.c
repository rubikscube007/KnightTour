#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define n 20
void knighttour(int x,int y,int movecount);
void getnextmove(int *x,int *y);
int getaccessibility(int x,int y);
void printboard(int board[][n]);
int setmove[2][8]={{2,2,-2,-2,1,1,-1,-1},{1,-1,1,-1,2,-2,2,-2}};
int board[n][n];
int main(int argc,char **argv){
	if( argc!=3){
		printf("Need to pass the x and y cordinate of board between 0-19\nExample:./a.out 14 11");
		return 0;

	}
	int x=atoi(*(argv+1));
	int y=atoi(*(argv+2));
	int movecount=1;
	knighttour(x,y,movecount);
	return 0;
}
void knighttour(int x,int y,int movecount){
	if(movecount>pow(n,2)){
		printboard(board);
	}
	else{
		getnextmove(&x,&y);
		board[x][y]=movecount;
		movecount++;
		knighttour(x,y,movecount);
	}
}
void printboard(int board[][n]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%3d ",board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int validmove(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<n&&board[x][y]==0){
		return 1;
	}
	return 0;
}
void getnextmove(int *x,int *y){
	int posx=*x;
	int posy=*y;
	int access=8;
	for(int i=0;i<8;i++){
		if(validmove(posx+setmove[0][i],posy+setmove[1][i])){
			if(getaccessibility(posx+setmove[0][i],posy+setmove[1][i])<access){
				access=getaccessibility(posx+setmove[0][i],posy+setmove[1][i]);
				*x=posx+setmove[0][i];
				*y=posy+setmove[1][i];
			}
		}
		
	}
}
int getaccessibility(int x,int y){
	int posx=x;
	int posy=y;
	int access=0;
	for(int i=0;i<8;i++){
		if(validmove(posx+setmove[0][i],posy+setmove[1][i])){
			access++;
		}
	}
	return access;
}
