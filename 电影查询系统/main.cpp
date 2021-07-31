#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<conio.h>   //这个在_getch()那里需要，用于实现输入不回显功能
#include<string.h> 
struct MOV
{
	int    num;
	char   name[30];
	char   type[10][10];
	char   country[5][20];
	int    time;
	char   actor[5][20];
	char   director[5][20];
};
//函数声明区
int  input(MOV  mo[]);
int  search(MOV mo[],int number);
int search_2(MOV m[], int number,int n);
void print_movie(MOV m[],int number);
void enter_movie(MOV M[],int number);

void  kaishi();
void false_input();
void  exit_all();

void save(MOV m);
int collection(MOV m[], int number);


//函数实现区
int  main()
{
	int num_of_movie=0;
	struct MOV movie[999];          //最多999个电影，对于一般用户足够了
	num_of_movie=input(movie);
	kaishi();
	for (;;)                              //空循环，用户在那个菜单里选择退出系统，会直接退出
		search(movie,num_of_movie);
	//main函数到此结束，因为如果上面那个循环里选择退出系统，会直接结束程序
}
//读取电影
int  input(MOV mo[])
{
	
	FILE  *p;
	int many=0;
	p = fopen("lists.txt", "r");
	if (p==NULL)
	{
		printf("电影列表读取失败！（文件无法打开！）");
		exit(-1);
	}
	//fseek(p, 0, SEEK_SET);     //表示文件指针指向文件开头
	while (!feof(p))   //直到结束 
	{
		struct  MOV  *a = new MOV;
		//初始化，很重要
		a->num = 0;
		a->time = 0;
		sscanf("c", "%s", a->name);

		for (int dd = 0; dd < 10; dd++)
			sscanf("c", "%s", a->type[dd]);

		for (int dd = 0; dd < 5; dd++)
			sscanf("c", "%s", a->country[dd]);

		for (int dd = 0; dd < 5; dd++)
			sscanf("c", "%s", a->actor[dd]);

		for (int dd = 0; dd < 5; dd++)
			sscanf("c", "%s", a->director[dd]);
		//初始化结束	
		char c[50];
		//排名
		fscanf(p, "%10d", &a->num);
		
		fscanf(p, "%s", &c);       //读取分号   下同

		//电影名
		fscanf(p, "%30s", a->name); //加上30是因为防止溢出
		fscanf(p, "%s",&c);
	
		
		//导演
		int i = 0, j = 0, k = 0,m=0,n=0;
		fscanf(p, "%s", &c);
		while (strcmp(c ,";")!=0 && i < 5)
		{
			sscanf(c, "%s", a->director[i]);             //sscanf是从字符串中读取数据
			i++;
			fscanf(p, "%s", &c);
		}

		//演员
		fscanf(p, "%s", &c);
		while (strcmp(c, ";") != 0 && j< 5)
		{
			sscanf(c, "%s", a->actor[j]);             //sscanf是从字符串中读取数据
			j++;
			fscanf(p, "%s", &c);
		}

		//类型
		fscanf(p, "%s", &c);
		while (strcmp(c, ";") != 0 && k< 10)
		{
			sscanf(c, "%s", a->type[k]);             //sscanf是从字符串中读取数据
			k++;
			fscanf(p, "%s", &c);
		}

		//国家
		fscanf(p, "%s", &c);
		while (strcmp(c, ";") != 0 && m< 5)
		{
			sscanf(c, "%s", a->country[m]);             //sscanf是从字符串中读取数据
			m++;
			fscanf(p, "%s", &c);
		}

		//时间
		fscanf(p, "%s", &c);
		while (strcmp(c, "#") != 0)
		{
			sscanf(c, "%d", &a->time);             //sscanf是从字符串中读取数据
			fscanf(p, "%s", &c);
		}
		//存储
		mo[many] = *a;
		many++;
		delete a;
	}
	fclose(p);
	return many;
}

int  search(MOV mo[], int number)
{
loop1:
	system("cls");   //清屏
	printf("\n\n\n\t\t* * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*              查询电影     \t\t*\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*                                       *\n");
	printf("\t\t*               1.电影名称              *\n");
	printf("\t\t*               2.排名                  *\n");
	printf("\t\t*               3.类型                  *\n");
	printf("\t\t*               4.国家                  *\n");
	printf("\t\t*               5.上映时间              *\n");
	printf("\t\t*               6.导演                  *\n");
	printf("\t\t*               7.主演                  *\n");
	printf("\t\t*               8.我的收藏              *\n");
	printf("\t\t*               9.退出系统              *\n");
	printf("\t\t*                                       *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * *\n");
	
	printf("请选择");
	switch (_getch())
	{

	case '1':system("cls");
		search_2(mo, number, 1);
		break;
	case '2':system("cls");
		search_2(mo, number, 2);
		break;
	case '3':system("cls");
		search_2(mo, number, 3);
		break;
	case '4':system("cls");
		search_2(mo, number, 4);
		break;
	case '5':system("cls");
		search_2(mo, number, 5);
		break;
	case '6':system("cls");
		search_2(mo, number, 6);
		break;
	case '7':system("cls");
		search_2(mo, number, 7);
		break;
	case '8':system("cls");
		collection(mo, number);
		break;
	case '9':system("cls");
		exit_all();
		break;
	default:system("cls");
		false_input();
		system("cls");
		goto loop1;
	}
	
	return 0;
}
//真正的查找函数，采用精确查找，即用户关键词与系统相对应的信息完全相同，方可找到
int search_2(MOV m[], int number, int n)
{
	struct MOV found[100];
	int j = 0;
	if (n == 1)
	{
		char p[50];
		printf("\n\n请输入电影名：");
		scanf("%30s", p);
		int i = 0;
		for (;i<number; i++)
		{
			if (strcmp(p, m[i].name) == 0)
			{
				found[j] = m[i];
				j++;
			}	
		}
	}
	if (n == 2)
	{
		int p;     //排名是整数
		printf("\n\n请输入电影排名：");
		scanf("%d", &p);
		int i = 0;
		for (; i<number; i++)
		{
			if (p==m[i].num)
			{
				found[j] = m[i];
				j++;
			}
		}
	}
	if (n == 3)
	{
		char p[50];
		printf("\n\n请输入电影类型：");
		scanf("%10s", p);
		int i = 0,k=0;
		for (; i<number; i++)
		{
			for (k=0;k<10;k++)
			{
				if (strcmp(p, m[i].type[k]) == 0)
				{
					found[j] = m[i];
					j++;
				}
			}
			
		}
	}
	if (n == 4)
	{
		char p[50];
		printf("\n\n请输入电影制作国家：");
		scanf("%30s", p);
		int i = 0, k = 0;
		for (; i<number; i++)
		{
			for (k=0;k<5; k++)
			{
				if (strcmp(p, m[i].country[k]) == 0)
				{
					found[j] = m[i];
					j++;
				}
			}

		}
	}
	if (n == 5)
	{
		int p;     //上映时间是整数
		printf("\n\n请输入电影上映时间：");
		scanf("%d", &p);
		int i = 0;
		for (; i<number; i++)
		{
			if (p == m[i].time)
			{
				found[j] = m[i];
				j++;
			}
		}
	}
	if (n == 6)
	{
		char p[50];
		printf("\n\n请输入导演名字（中间的点用\"/\"代替）:");
		scanf("%30s", p);
		int i = 0,  k = 0;
		for (; i<number; i++)
		{
			for (k = 0;k<5; k++)
			{
				if (strcmp(p, m[i].director[k]) == 0)
				{
					found[j] = m[i];
					j++;
				}
			}

		}
	}
	if (n == 7)
	{
		char p[50];
		printf("\n\n请输入主演名字（中间的点用\"/\"代替）:");
		scanf("%30s", p);
		int i = 0, k = 0;
		for (; i<number; i++)
		{
			for (k=0;k<5; k++)
			{
				if (strcmp(p, m[i].actor[k]) == 0)
				{
					found[j] = m[i];
					j++;
				}
			}

		}
	}

	if (j==0)
	{
		system("cls");    //清屏
		printf("\n\n\n\t\t★---------------------------------------------★\n");
		printf("\t\t|\t\t\t\t\t\t|\n");
		printf("\t\t|\t\t没有符合条件的电影 ！\t\t|\n");
		printf("\t\t|\t\t\t\t\t\t|\n");
		printf("\t\t★---------------------------------------------★\n");
		_getch();
		return 0;
	}
	
	system("cls");    //清屏
	printf("\n\n为您找到以下电影：\t\t（1.进一步筛选  2.进入电影  3.退出)\n\n");
	print_movie(found, j);
loop2:
	printf("\n1.进一步筛选  2.进入电影  3.退出\n");
	printf("\n请选择：");

	switch (_getch())
	{
	case '1':search(found, j);
		break;
	case '2':enter_movie(found, j);
		break;
	case '3':break;
	default:
		goto loop2;
	}
		
	return 0;

	
}

void print_movie(MOV m[], int number)
{
	int i = 0;
	printf("排名\t\t电影名\t\t\t    上映时间\n\n");
	for (; i<number; i++)
	{
		printf("%d\t\t%s", m[i].num, m[i].name);
		int  len = strlen(m[i].name);
		for (; len < 30; len++)
			printf(" ");
		printf("%d\n", m[i].time);
	}
	
}
void enter_movie(MOV m[], int number)
{
	int n, t = 0, jjjj = 0;;
	struct MOV a;
	loop3:
	printf("\n请输入电影排名：");
	scanf("%d", &n);
	for (t=0; t < number; t++)
	{
		if (m[t].num == n)
		{
			a = m[t];
			jjjj++;
		}	
	}
	if (jjjj==0)
	{
		printf("\n不存在该电影！\n");
		goto loop3;                           //goto 语句,跳到loop3那里，loop3 是一个位置
	}
	//如过a.num存在，进入它

	//开始进入该电影
	//图形界面
	//显示具体的一个电影 a
	system("cls");    //清屏  //图形界面的话不需要，到时候建立480*640的图形界面就行
	printf("图形界面还没有做好！不妨先看看黑白界面\n");

	printf("图片:\n\n");
	printf("无\n\n\n");
	printf("排名:");
	printf("%d", a.num);
	printf("\n\n");
	printf("电影名:");
	printf("%s", a.name);
	printf("\n\n");
	printf("上映时间:");
	printf("%d", a.time);
	printf("\n\n");
	printf("国家:");
	int j = 0;
	for (;strcmp( a.country[j],"c")!=0&&j<5; j++)
		printf("%s  ", a.country[j]);
	printf("\n\n");

	printf("类型:");
	for (j = 0; strcmp(a.type[j],"c")!=0&&j<10; j++)
		printf("%s  ", a.type[j]);
	printf("\n\n");
	printf("导演:");
	for (j = 0;strcmp(a.director[j],"c")&&j<5; j++)
		printf("%s  ", a.director[j]);
	printf("\n\n");
	printf("主演:");
	for (j = 0;strcmp( a.actor[j] ,"c")!=0&&j<5; j++)
		printf("%s  ", a.actor[j]);
	printf("\n\n");
	
	loop4:
	printf("\n\n1.收藏该电影  2.退出  \n");
	switch (_getch())
	{
	case '1':save(a);
		break;
	case '2':
		break;
	default:goto loop4;
	
	}
	
    //关闭图形界面
}

void kaishi()
{
	system("cls");
	printf("\n\n\n\t\t★---------------------------------------------★\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t|\t\t  \"  某某  \"   \t\t\t|\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t|\t     电影查询系统欢迎您 !\t\t|\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t★---------------------------------------------★\n");
	_getch();
}
void  exit_all()
{
	
	printf("\n\n\n\t\t★---------------------------------------------★\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t|\t\t    谢谢使用！\t\t\t|\n");
	printf("\t\t|\t          欢迎下次再来\t\t\t|\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t★---------------------------------------------★\n");
	_getch();
	exit(1);
}
void false_input()
{
	printf("\n\n\n\t\t★---------------------------------------------★\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t|\t      输入错误!   请重试 !\t\t|\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t★---------------------------------------------★\n");
	_getch();
}
//收藏
void save(MOV m)
{
	FILE *p;
	p=fopen( "my_movies.txt", "a");
	if (p == NULL)
	{
		//printf("（文件无法打开！）");
		p = fopen("my_movies.txt", "w");  //新建
		fprintf(p, "%d  ;  ", m.num);

	}
	else {
		fprintf(p, "%d  ;  ", m.num);
	}
	
	fclose(p);
	printf("\n\n收藏成功！！！\n\n");
	_getch();
}
//显示收藏
int  collection(MOV m[],int number)
{
	FILE  *p;
	struct MOV my[999];
	int j = 0;
	p = fopen("my_movies.txt", "r");
	if (p == NULL)
	{
		printf("收藏读取失败！（文件无法打开！）");
		_getch();
		return 0;
	}
	//fseek(p, 0, SEEK_SET);     //表示文件指针指向文件开头
	while (!feof(p))   //直到结束 
	{
		int num = 0;
		char c[10];
		//读取文件，即读取排名
		fscanf(p, "%10d", &num);

		fscanf(p, "%s", &c);       //读取分号   下同

		//查找
		int i = 0;
		for (; i<number; i++)
		{
			if (num == m[i].num)     //所有电影里查
			{
				int ok = 1;
				for (int h = 0; h < j; h++)  //已有的电影里查，文件里面可以重复，但是输出时不能重复
				{
					if (my[h].num == num)
						ok = 0;
				}
				if (ok == 1)
				{
					my[j] = m[i];
					j++;
				}
				
			}
		}
	}
	fclose(p);
	printf("\n\n被收藏的电影列表：\n");
	print_movie(my, j);
loop2:
	printf("\n\n1.进入电影  2.退出\n");
	printf("\n请选择：");

	switch (_getch())
	{
	case '1':enter_movie(my, j);
		break;
	case '2':break;
	default:
		goto loop2;
	}
	return 0;
}

//结束
