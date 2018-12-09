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
};// ��ʼ����ͼ 
int length=2,bo=1;//�ߵĳ����Լ���Ϸ�Ƿ�����ı�־ 
int x[21]={0,1,1};//��ʾ��ÿ����λ��x 
int y[21]={0,2,1};//��ʾ��ÿ����λ��y 
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
	for(int i=0;i<10;++i)
			printf("%s\n",map[i]);//�����ͼ 
	}
int main(){
	while(bo){
		output();//�����ͼ 
		char ch=getchar();
		while(ch!='A'&&ch!='D'&&ch!='W'&&ch!='S')ch=getchar();//ֱ��������Ч�ַ� 
		if(ch=='A')move(0,-1);
		else if(ch=='D')move(0,1);
		else if(ch=='W')move(-1,0);
		else if(ch=='S')move(1,0);
}
}
