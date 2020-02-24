#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h> 
using namespace std;
const int num = 100;//city number
const int MAX = 999999;
typedef struct node{
	int x;
	int y;
}city;

city citys[num];
double dic[num][num];
bool visit[num];
int N;//real citys
int path[num];
double answer;

//void init()
//{
//	N = 10;
//	citys[0].x=2066; citys[0].y=2333;
//	citys[1].x=935; citys[1].y=1304;
//	citys[2].x=1270; citys[2].y=200;
//	citys[3].x=1389; citys[3].y=700;
//	citys[4].x=984; citys[4].y=2810;
//	citys[5].x=2253; citys[5].y=478;
//	citys[6].x=949; citys[6].y=3025;
//	citys[7].x=87; citys[7].y=2483;
//	citys[8].x=3094; citys[8].y=1883;
//	citys[9].x=2706; citys[9].y=3130;
//}

void set_dic()//初始化距离 
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			dic[i][j]=sqrt(pow(citys[i].x - citys[j].x, 2) + pow(citys[i].y - citys[j].y, 2));
		}
	}
}

double solve()
{
	for(int i = 0; i < N; i++)
	{
		visit[i] = false;
	}
	visit[0] = true;
	path[0] = 1;
	int k = 0;//k代表当前城市，0代表城市1。
	int next = k + 1;
	double min = MAX;
	int count = 1;
	while(count < N)
	{
		for(int j = 0; j < N; j++)
		{
			if(visit[j] == false)
			{
				if(dic[k][j] < min)
				{
					min = dic[k][j];
					next = j;
				}	
			}
		}
		answer = answer + min;
		path[count] = next + 1;
		visit[next] = true;
		k = next;
		count ++;
		min = MAX;
		next = k + 1;
	}
}

void test1()
{
	FILE *file;
	int data[300];
	int i = 0;
	if(!(file=fopen("data.txt","r")))
	{
		cout<<"open error\n";
		exit(0); 
	}
	while(!feof(file))
	{
		if(fscanf(file, "%d", &data[i]) != 1)
		break;
		i++;
	}
	N = data[i - 3];
	for(int j = 0; j < i; j++)
	{
		if(j % 3 == 1)
			citys[j / 3].x = data[j];
		else if(j % 3 == 2)
			citys[j / 3].y = data[j];
	}
	fclose(file); 
}

void test2()
{
	FILE *file;
	int data[300];
	int i = 0;
	if(!(file=fopen("data2.txt","r")))
	{
		cout<<"open error\n";
		exit(0); 
	}
	while(!feof(file))
	{
		if(fscanf(file, "%d", &data[i]) != 1)
		break;
		i++;
	}
	N = data[i - 3];
	for(int j = 0; j < i; j++)
	{
		if(j % 3 == 1)
			citys[j / 3].x = data[j];
		else if(j % 3 == 2)
			citys[j / 3].y = data[j];
	}
	fclose(file);
}

void output()
{
	cout<<"the best road is:\n";
	for(int i = 0; i < N; i++)
	{
		cout << path[i];
		if(i == N)
			cout << endl;
		else 
			cout << " -> ";
	} 
	cout << path[0] << endl;
	answer = answer + dic[path[N-1]-1][0];	//加上回到原点的距离 
	cout << "the length of the road is " << answer << endl;
}

int main()
{
//	init();
	clock_t start,end;
	start = clock();
	test1(); 
	set_dic();
	solve();
	output();
	end=clock();
	cout<<"10个点的TSP问题所花费的时间:"<<end-start<<"毫秒"<<endl;
	cout << endl;
	clock_t start1,end1;
	start1 = clock();
	test2();
	set_dic();
	solve();
	output();
	end=clock();
	cout<<"100个点的TSP问题所花费的时间:"<<end1-start1<<"毫秒"<<endl;
}











