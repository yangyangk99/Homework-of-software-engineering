#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int tishu = 1;//��Ŀ����
int fuhaoshu = 1;//����������
char symbo[5] = { 0 };//��������
int max = 1;//�����
int kuohao = 0;//�Ƿ������ţ�1��ʾ�����ţ�0��ʾû�����ţ�
int xiaoshu = 0;//�Ƿ���С����1��ʾ��С����0��ʾû��С����
int Print = 0;//�û�ѡ�������ʽ��1��ʾ������ļ���0��ʾ�����Ļ��
float number[5] = { 0 };//ʹ�õ�����,Ĭ��Ϊ0
char symbol[5] = { 0 };//ʹ�õķ���

void menu(void)//���˵�����
{
	printf(" ��������ϰ���Զ�������\n");
	printf("\n");
	printf("�밴��ʾ������ϰ������\n");
}
void randomnumber(void)//�����������
{
	for (int i = 0; i<4; i++)
	{
		if (xiaoshu == 0)//�����������
		{
			number[i] = rand() % (max + 1);
		}
		else//�������С��
		{
			number[i] = rand() % max;
			number[i] = number[i] + rand() % 100 * 0.01;
		}
	}
}

void randomsymbol(void)//�����������
{
	for (int i = 0; i<3; i++)
	{
		symbol[i] = symbo[rand() % fuhaoshu];
	}
}

void shuchu(void)//�������
{
	int kuohaoweizhi;//����λ��
	FILE *fp;
	fp = fopen("��������", "w");//���ļ�д����
	for (int m = 0; m<tishu; m++)
	{
		randomnumber();//�����������
		randomsymbol();//�����������
		for (int i = 0; i<3; i++)
		{
			if ((symbol[i] == '/') && (number[i + 1] == 0))
			{
				number[i + 1] = number[i + 1] + 1;
			}
		}
		if (xiaoshu == 0)//����С��
		{
			if (Print == 0)//�������Ļ
			{
				if (kuohao == 0)//û������
				{
					printf("%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
				}
				else//������
				{
					kuohaoweizhi = rand() % 3;
					if (kuohaoweizhi == 0)//�����ڵ�һ�����͵ڶ�������
					{
						printf("��%.0f%c%.0f��%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 1)//�����ڵڶ������͵���������
					{
						printf("%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 2)//�����ڵ��������͵��ĸ�����
					{
						printf("%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
				}
			}
			else//������ļ�
			{
				if (kuohao == 0)//û������
				{
					fprintf(fp, "%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
				}
				else//������
				{
					kuohaoweizhi = rand() % 3;
					if (kuohaoweizhi == 0)
					{
						fprintf(fp, "��%.0f%c%.0f��%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 1)
					{
						fprintf(fp, "%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 2)
					{
						fprintf(fp, "%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
				}
			}
		}
		else//��С��
		{
			if (Print == 0)//�������Ļ
			{
				if (kuohao == 0)//û������
				{
					printf("%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
				}
				else//������
				{
					kuohaoweizhi = rand() % 3;
					if (kuohaoweizhi == 0)
					{
						printf("��%.2f%c%.2f��%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 1)
					{
						printf("%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 2)
					{
						printf("%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
				}
			}
			else//������ļ�
			{
				if (kuohao == 0)//û������
				{
					fprintf(fp, "%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
				}
				else//������
				{
					kuohaoweizhi = rand() % 3;
					if (kuohaoweizhi == 0)
					{
						fprintf(fp, "��%.2f%c%.2f��%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 1)
					{
						fprintf(fp, "%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 2)
					{
						fprintf(fp, "%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
				}
			}
		}
	}
	fclose(fp);//�ر��ļ�
}

void shezhi()
{
	printf("��������Ŀ����\n");
	scanf("%d", &tishu);
	if (tishu <= 0)
	{
		printf("������������Ŀ����\n");
		scanf("%d", &tishu);
	}
	printf("�����������������(1~4֮�������)\n");
	scanf("%d", &fuhaoshu);
	if ((fuhaoshu<1) || (fuhaoshu>4))
	{
		printf("���������������������(1~4֮�������)\n");
		scanf("%d", &fuhaoshu);
	}
	printf("����������ʹ�õ���������ڡ�+������-������*������/����ѡ�����룩\n");
	scanf("%s", symbo);
	printf("�����������\n");
	scanf("%d", &max);
	if (max <= 0)
	{
		printf("�������������������������\n");
		scanf("%d", &max);
	}
	printf("��ѡ���Ƿ������ţ�0��ʾû�����ţ�1��ʾ�����ţ�\n");
	scanf("%d", &kuohao);
	printf("��ѡ���Ƿ���С����0��ʾû��С����1��ʾ��С����\n");
	scanf("%d", &xiaoshu);
	printf("��ѡ�������ʽ��0��ʾ�������Ļ��1��ʾ������ļ���\n");
	scanf("%d", &Print);
}

int main()
{
	menu();//���˵�����
	shezhi();//��������
	srand((int)time(0));//��֤ÿ�β������������ͬ
	shuchu();//�������
	system("pause");
	return 0;
}