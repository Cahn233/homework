// main.c
// snake
// Create by nanzhang

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxline 20
#define head 'H'
#define body 'X'
#define blank_block ' '
#define food '$'
#define wall '*'
char map[11][11]=
{"**********",
"*XH      *",
"*        *",
"*        *",
"*        *",
"*        *",
"*        *",
"*        *",
"*        *",
"**********"
};// 初始化地图 
int length=2,bo=1;//蛇的长度以及游戏是否结束的标志 
int x[21]={0,1,1};//表示蛇每个部位的x 
int y[21]={0,2,1};//表示蛇每个部位的y 
void putmoney(){
	int xx1=rand()%9+1;
	int yy1=rand()%9+1;
	while(map[xx1][yy1]!=' '){
	xx1=rand()%9+1;
	yy1=rand()%9+1;	
	}
	map[xx1][yy1]='$';
}
void move(int addx,int addy){
	if(map[x[1]+addx][y[1]+addy]!=' '&&map[x[1]+addx][y[1]+addy]!='$'){
				bo=!bo;
			}
			else if(map[x[1]+addx][y[1]+addy]=='$'){
					length++;
					for(int i=1;i<=length;++i)
					map[x[i]][y[i]]=' ';
					for(int i=length;i>1;--i){
						x[i]=x[i-1];
						y[i]=y[i-1];
						map[x[i]][y[i]]='X';
					}
					x[1]=x[1]+addx;
					y[1]=y[1]+addy;
					map[x[1]][y[1]]='H';
					putmoney();
			}
			else{
				for(int i=1;i<=length;++i)
					map[x[i]][y[i]]=' ';
				for(int i=length;i>1;--i){
						x[i]=x[i-1];
						y[i]=y[i-1];
						map[x[i]][y[i]]='X';
					}
					x[1]=x[1]+addx;
					y[1]=y[1]+addy;
					map[x[1]][y[1]]='H';
			}
}
void output(){
	system("CLS");
	for(int i=0;i<10;++i)
			printf("%s\n",map[i]);//输出地图 
	}
void GG(){
	for(int i=1;i<10;++i) 
	printf("Game Over!\n");//游戏结束 
}
int main(){
	putmoney();//放置食物 
	while(bo){
		output();//输出地图 
		char ch=getchar();
		while(ch!='A'&&ch!='D'&&ch!='W'&&ch!='S')ch=getchar();//直到读到有效字符 
		if(ch=='A')move(0,-1);
		else if(ch=='D')move(0,1);
		else if(ch=='W')move(-1,0);
		else if(ch=='S')move(1,0);
}
	GG();//游戏结束 
}
