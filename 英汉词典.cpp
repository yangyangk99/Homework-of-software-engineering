
#include <stdio.h>
#include <string.h>
char path[100] = { "dictionary.txt" };//�ļ���
int worsNumber = 0; //������Ŀ
//����ṹ��洢�ʵ�����
typedef struct dic
{
    char word[20];
    char cn[80];
}data;
data dictionnarySql[100];//�ʵ����ݿ�
//�˵�
void printAction()
{
    printf("-----------------\n");
    printf("1.Ӣ�뺺��\n");
    printf("2.����Ӣ��\n");
    printf("3.�ʻ����벢�����\n");
    printf("4.�ʻ�ɾ����\n");
    printf("0.�˳������\n");
    printf("-----------------\n");
}

//���ص��������ݿ��е�λ��
int searchWord(char word[20])
{
    int i=0;
    for(i=0;i<worsNumber;i++)
    {
        if(strcmp(dictionnarySql[i].word,word)==0)
            return i;
    }
    return -1;//�����ѯ�������ͷ��ظ���
}
//���ط��������ݿ��е�λ��
int searchCn(char cn[80])
{
    //˳�����
    int i=0;
    for(i=0;i<worsNumber;i++)
    {
        if(strstr(dictionnarySql[i].cn,cn)!=NULL)
            return i;
    }
    return -1;//�����ѯ�������ͷ��ظ���
}
//��������
void saveSql()
{
    FILE *fp=NULL;
    fp=fopen("dictionary.txt","w");
    int i=0;
    for(i=0;i<worsNumber;i++)
    {
        if(dictionnarySql[i].word[0]!='#')
        {
 
            fprintf(fp,"%s\t%s\n",dictionnarySql[i].word,dictionnarySql[i].cn);
        }
    }
    fclose(fp);
}
//ָ�����
void dealAction(int action)
{
	if (action == 1)
	{
		char word[20];
		int pos;//����λ��
		printf("��������Ҫ��ѯ�ĵ��ʣ�");
		scanf("%s", word);
		pos = searchWord(word);
		if (pos != -1)
			printf("����\'%s\'��������˼�ǣ� %s\n", word, dictionnarySql[pos].cn);
		else
			printf("�Բ���û���ҵ�������Ҫ�ĵ���\n");
	}
	else if (action == 2)
	{
		int pos;
		char cn[80];
		printf("�������뺺����⣺");
		scanf("%s", cn);
		pos = searchCn(cn);
		if (pos != -1)
			printf("�÷����Ӣ�ﵥ���ǣ� %s\n", dictionnarySql[pos].word);
		else
			printf("�Բ���û���ҵ�������Ҫ�ķ���\n");
	}
	else if (action == 3)
	{
		int d;
		char word[20];
		char cn[80];
		printf("�������뵥��������\n");
		scanf("%d", &d);
		int i;
		for (i = 0; i < d; i++) {
			printf("��������õ���Ӣ�");
			scanf("%s", word);
			strcpy(dictionnarySql[worsNumber].word, word);
			printf("��������õ��ʺ��﷭�룺");
			scanf("%s", cn);
			strcpy(dictionnarySql[worsNumber].cn, cn);
			worsNumber++;
			saveSql();
		}
		printf("���뵥�����\n");

	}
	else if (action == 4)
	{
		char word[50];
		int pos;//����λ��
		printf("��������Ҫɾ���ĵ��ʣ�");
		scanf("%s", word);
		pos = searchWord(word);
		if (pos != -1)
		{
			char a[5] = "#";
			strcpy(dictionnarySql[pos].cn, a);
			strcpy(dictionnarySql[pos].word, a);
			saveSql();
			printf("�Ѿ�ɾ���õ���\n");
		}
		else
			printf("�Բ���û���ҵ�������Ҫ�ĵ���\n");
	}
}

//����������
int main()
{
    int action=-1;
    while(action!=0)
    {
        printAction();
        scanf("%d",&action);
        dealAction(action);
    }
    return 0;
}