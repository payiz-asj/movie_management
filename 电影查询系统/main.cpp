#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<conio.h>   //�����_getch()������Ҫ������ʵ�����벻���Թ���
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
//����������
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


//����ʵ����
int  main()
{
	int num_of_movie=0;
	struct MOV movie[999];          //���999����Ӱ������һ���û��㹻��
	num_of_movie=input(movie);
	kaishi();
	for (;;)                              //��ѭ�����û����Ǹ��˵���ѡ���˳�ϵͳ����ֱ���˳�
		search(movie,num_of_movie);
	//main�������˽�������Ϊ��������Ǹ�ѭ����ѡ���˳�ϵͳ����ֱ�ӽ�������
}
//��ȡ��Ӱ
int  input(MOV mo[])
{
	
	FILE  *p;
	int many=0;
	p = fopen("lists.txt", "r");
	if (p==NULL)
	{
		printf("��Ӱ�б��ȡʧ�ܣ����ļ��޷��򿪣���");
		exit(-1);
	}
	//fseek(p, 0, SEEK_SET);     //��ʾ�ļ�ָ��ָ���ļ���ͷ
	while (!feof(p))   //ֱ������ 
	{
		struct  MOV  *a = new MOV;
		//��ʼ��������Ҫ
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
		//��ʼ������	
		char c[50];
		//����
		fscanf(p, "%10d", &a->num);
		
		fscanf(p, "%s", &c);       //��ȡ�ֺ�   ��ͬ

		//��Ӱ��
		fscanf(p, "%30s", a->name); //����30����Ϊ��ֹ���
		fscanf(p, "%s",&c);
	
		
		//����
		int i = 0, j = 0, k = 0,m=0,n=0;
		fscanf(p, "%s", &c);
		while (strcmp(c ,";")!=0 && i < 5)
		{
			sscanf(c, "%s", a->director[i]);             //sscanf�Ǵ��ַ����ж�ȡ����
			i++;
			fscanf(p, "%s", &c);
		}

		//��Ա
		fscanf(p, "%s", &c);
		while (strcmp(c, ";") != 0 && j< 5)
		{
			sscanf(c, "%s", a->actor[j]);             //sscanf�Ǵ��ַ����ж�ȡ����
			j++;
			fscanf(p, "%s", &c);
		}

		//����
		fscanf(p, "%s", &c);
		while (strcmp(c, ";") != 0 && k< 10)
		{
			sscanf(c, "%s", a->type[k]);             //sscanf�Ǵ��ַ����ж�ȡ����
			k++;
			fscanf(p, "%s", &c);
		}

		//����
		fscanf(p, "%s", &c);
		while (strcmp(c, ";") != 0 && m< 5)
		{
			sscanf(c, "%s", a->country[m]);             //sscanf�Ǵ��ַ����ж�ȡ����
			m++;
			fscanf(p, "%s", &c);
		}

		//ʱ��
		fscanf(p, "%s", &c);
		while (strcmp(c, "#") != 0)
		{
			sscanf(c, "%d", &a->time);             //sscanf�Ǵ��ַ����ж�ȡ����
			fscanf(p, "%s", &c);
		}
		//�洢
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
	system("cls");   //����
	printf("\n\n\n\t\t* * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*              ��ѯ��Ӱ     \t\t*\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*                                       *\n");
	printf("\t\t*               1.��Ӱ����              *\n");
	printf("\t\t*               2.����                  *\n");
	printf("\t\t*               3.����                  *\n");
	printf("\t\t*               4.����                  *\n");
	printf("\t\t*               5.��ӳʱ��              *\n");
	printf("\t\t*               6.����                  *\n");
	printf("\t\t*               7.����                  *\n");
	printf("\t\t*               8.�ҵ��ղ�              *\n");
	printf("\t\t*               9.�˳�ϵͳ              *\n");
	printf("\t\t*                                       *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * *\n");
	
	printf("��ѡ��");
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
//�����Ĳ��Һ��������þ�ȷ���ң����û��ؼ�����ϵͳ���Ӧ����Ϣ��ȫ��ͬ�������ҵ�
int search_2(MOV m[], int number, int n)
{
	struct MOV found[100];
	int j = 0;
	if (n == 1)
	{
		char p[50];
		printf("\n\n�������Ӱ����");
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
		int p;     //����������
		printf("\n\n�������Ӱ������");
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
		printf("\n\n�������Ӱ���ͣ�");
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
		printf("\n\n�������Ӱ�������ң�");
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
		int p;     //��ӳʱ��������
		printf("\n\n�������Ӱ��ӳʱ�䣺");
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
		printf("\n\n�����뵼�����֣��м�ĵ���\"/\"���棩:");
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
		printf("\n\n�������������֣��м�ĵ���\"/\"���棩:");
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
		system("cls");    //����
		printf("\n\n\n\t\t��---------------------------------------------��\n");
		printf("\t\t|\t\t\t\t\t\t|\n");
		printf("\t\t|\t\tû�з��������ĵ�Ӱ ��\t\t|\n");
		printf("\t\t|\t\t\t\t\t\t|\n");
		printf("\t\t��---------------------------------------------��\n");
		_getch();
		return 0;
	}
	
	system("cls");    //����
	printf("\n\nΪ���ҵ����µ�Ӱ��\t\t��1.��һ��ɸѡ  2.�����Ӱ  3.�˳�)\n\n");
	print_movie(found, j);
loop2:
	printf("\n1.��һ��ɸѡ  2.�����Ӱ  3.�˳�\n");
	printf("\n��ѡ��");

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
	printf("����\t\t��Ӱ��\t\t\t    ��ӳʱ��\n\n");
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
	printf("\n�������Ӱ������");
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
		printf("\n�����ڸõ�Ӱ��\n");
		goto loop3;                           //goto ���,����loop3���loop3 ��һ��λ��
	}
	//���a.num���ڣ�������

	//��ʼ����õ�Ӱ
	//ͼ�ν���
	//��ʾ�����һ����Ӱ a
	system("cls");    //����  //ͼ�ν���Ļ�����Ҫ����ʱ����480*640��ͼ�ν������
	printf("ͼ�ν��滹û�����ã������ȿ����ڰ׽���\n");

	printf("ͼƬ:\n\n");
	printf("��\n\n\n");
	printf("����:");
	printf("%d", a.num);
	printf("\n\n");
	printf("��Ӱ��:");
	printf("%s", a.name);
	printf("\n\n");
	printf("��ӳʱ��:");
	printf("%d", a.time);
	printf("\n\n");
	printf("����:");
	int j = 0;
	for (;strcmp( a.country[j],"c")!=0&&j<5; j++)
		printf("%s  ", a.country[j]);
	printf("\n\n");

	printf("����:");
	for (j = 0; strcmp(a.type[j],"c")!=0&&j<10; j++)
		printf("%s  ", a.type[j]);
	printf("\n\n");
	printf("����:");
	for (j = 0;strcmp(a.director[j],"c")&&j<5; j++)
		printf("%s  ", a.director[j]);
	printf("\n\n");
	printf("����:");
	for (j = 0;strcmp( a.actor[j] ,"c")!=0&&j<5; j++)
		printf("%s  ", a.actor[j]);
	printf("\n\n");
	
	loop4:
	printf("\n\n1.�ղظõ�Ӱ  2.�˳�  \n");
	switch (_getch())
	{
	case '1':save(a);
		break;
	case '2':
		break;
	default:goto loop4;
	
	}
	
    //�ر�ͼ�ν���
}

void kaishi()
{
	system("cls");
	printf("\n\n\n\t\t��---------------------------------------------��\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t|\t\t  \"  ĳĳ  \"   \t\t\t|\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t|\t     ��Ӱ��ѯϵͳ��ӭ�� !\t\t|\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t��---------------------------------------------��\n");
	_getch();
}
void  exit_all()
{
	
	printf("\n\n\n\t\t��---------------------------------------------��\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t|\t\t    ллʹ�ã�\t\t\t|\n");
	printf("\t\t|\t          ��ӭ�´�����\t\t\t|\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t��---------------------------------------------��\n");
	_getch();
	exit(1);
}
void false_input()
{
	printf("\n\n\n\t\t��---------------------------------------------��\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t|\t      �������!   ������ !\t\t|\n");
	printf("\t\t|\t\t\t\t\t\t|\n");
	printf("\t\t��---------------------------------------------��\n");
	_getch();
}
//�ղ�
void save(MOV m)
{
	FILE *p;
	p=fopen( "my_movies.txt", "a");
	if (p == NULL)
	{
		//printf("���ļ��޷��򿪣���");
		p = fopen("my_movies.txt", "w");  //�½�
		fprintf(p, "%d  ;  ", m.num);

	}
	else {
		fprintf(p, "%d  ;  ", m.num);
	}
	
	fclose(p);
	printf("\n\n�ղسɹ�������\n\n");
	_getch();
}
//��ʾ�ղ�
int  collection(MOV m[],int number)
{
	FILE  *p;
	struct MOV my[999];
	int j = 0;
	p = fopen("my_movies.txt", "r");
	if (p == NULL)
	{
		printf("�ղض�ȡʧ�ܣ����ļ��޷��򿪣���");
		_getch();
		return 0;
	}
	//fseek(p, 0, SEEK_SET);     //��ʾ�ļ�ָ��ָ���ļ���ͷ
	while (!feof(p))   //ֱ������ 
	{
		int num = 0;
		char c[10];
		//��ȡ�ļ�������ȡ����
		fscanf(p, "%10d", &num);

		fscanf(p, "%s", &c);       //��ȡ�ֺ�   ��ͬ

		//����
		int i = 0;
		for (; i<number; i++)
		{
			if (num == m[i].num)     //���е�Ӱ���
			{
				int ok = 1;
				for (int h = 0; h < j; h++)  //���еĵ�Ӱ��飬�ļ���������ظ����������ʱ�����ظ�
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
	printf("\n\n���ղصĵ�Ӱ�б�\n");
	print_movie(my, j);
loop2:
	printf("\n\n1.�����Ӱ  2.�˳�\n");
	printf("\n��ѡ��");

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

//����
