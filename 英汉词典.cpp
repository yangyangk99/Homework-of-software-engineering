
#include <stdio.h>
#include <string.h>
char path[100] = { "dictionary.txt" };//文件名
int worsNumber = 0; //单词数目
//定义结构体存储词典数据
typedef struct dic
{
    char word[20];
    char cn[80];
}data;
data dictionnarySql[100];//词典数据库
//菜单
void printAction()
{
    printf("-----------------\n");
    printf("1.英译汉｜\n");
    printf("2.汉译英｜\n");
    printf("3.词汇输入并保存｜\n");
    printf("4.词汇删除｜\n");
    printf("0.退出程序｜\n");
    printf("-----------------\n");
}

//返回单词在数据库中的位置
int searchWord(char word[20])
{
    int i=0;
    for(i=0;i<worsNumber;i++)
    {
        if(strcmp(dictionnarySql[i].word,word)==0)
            return i;
    }
    return -1;//如果查询不到，就返回负数
}
//返回翻译在数据库中的位置
int searchCn(char cn[80])
{
    //顺序查找
    int i=0;
    for(i=0;i<worsNumber;i++)
    {
        if(strstr(dictionnarySql[i].cn,cn)!=NULL)
            return i;
    }
    return -1;//如果查询不到，就返回负数
}
//保存数据
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
//指令处理函数
void dealAction(int action)
{
	if (action == 1)
	{
		char word[20];
		int pos;//单词位置
		printf("请您输入要查询的单词：");
		scanf("%s", word);
		pos = searchWord(word);
		if (pos != -1)
			printf("单词\'%s\'的中文意思是： %s\n", word, dictionnarySql[pos].cn);
		else
			printf("对不起，没有找到您所需要的单词\n");
	}
	else if (action == 2)
	{
		int pos;
		char cn[80];
		printf("请您输入汉语词意：");
		scanf("%s", cn);
		pos = searchCn(cn);
		if (pos != -1)
			printf("该翻译的英语单词是： %s\n", dictionnarySql[pos].word);
		else
			printf("对不起，没有找到您所需要的翻译\n");
	}
	else if (action == 3)
	{
		int d;
		char word[20];
		char cn[80];
		printf("请您输入单词数量：\n");
		scanf("%d", &d);
		int i;
		for (i = 0; i < d; i++) {
			printf("请您输入该单词英语：");
			scanf("%s", word);
			strcpy(dictionnarySql[worsNumber].word, word);
			printf("请您输入该单词汉语翻译：");
			scanf("%s", cn);
			strcpy(dictionnarySql[worsNumber].cn, cn);
			worsNumber++;
			saveSql();
		}
		printf("输入单词完成\n");

	}
	else if (action == 4)
	{
		char word[50];
		int pos;//单词位置
		printf("请输入您要删除的单词：");
		scanf("%s", word);
		pos = searchWord(word);
		if (pos != -1)
		{
			char a[5] = "#";
			strcpy(dictionnarySql[pos].cn, a);
			strcpy(dictionnarySql[pos].word, a);
			saveSql();
			printf("已经删除该单词\n");
		}
		else
			printf("对不起，没有找到您所需要的单词\n");
	}
}

//主函数部分
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