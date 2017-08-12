/*****
����������
*******/

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_NUM 10000		//����һ���ܴ���������ڲ�����Сֵ�㷨
#define MAX 20				//���������������ֵ
int n;						//��������ʵ�ʸ���

typedef struct						//������������ڵ����������
{
	char c;							//��һ���ַ�����һ���������
	float weight;					//�ñ�������Ӧ��Ȩֵ
	int parent,lchild,rchild;		//���ڵ㣬���ӣ��Һ���ָ��
}HTNode;

HTNode HT[2*MAX-1];
char CODE[MAX][MAX];
char CH[20];				//��������ַ���
char B[60];					//��ű����Ķ������ַ���

void createHFMTree();
void Encoding();
void Decoding();

int main()
{
	int i,j,root;
	printf("\n\n����������ĸ�����");
	scanf("%d",&n);
	for(i=0;i<n;i++)		//����n����������ԭʼ���ݣ���ʼ���ڵ�ָ��
	{
		printf("��������������ַ�:");
		scanf("%s",&HT[i].c);
		printf("�����Ӧ��Ȩֵ��");
		scanf("%f",&HT[i].weight);
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	root = 2*n-2;		//�����һ���м�ڵ���Ϊ���������ĸ��ڵ�
	for(i=n;i<=root;i++)
	{
		HT[i].c = '\0';
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	createHFMTree();		//���ɻ������������ͱ����
	for(i=0;i<n;i++)		//��ʾ�����������
	{
		printf("\n");
		printf("�ַ���%c\t",HT[i].c);
		printf("\tȨֵ��%3.2f\t",HT[i].weight);
		printf("\t��Ӧ�Ĺ��������룺");
		puts(CODE[i]);
	}
	printf("\n���������Ϣ�����ַ�����");
	scanf("%s",CH);
	Encoding();		//���б���
	printf("\n��������ƴ��봮��");
	scanf("%s",B);
	Decoding();		//��������
	getchar();
	return 0;
}

void Encoding()				//���뺯��
{
	int i=0,j;
	B[0]='\0';				//��ʼ��������Ϊ���ַ���
	printf("\n��Ӧ�Ķ����ƴ��봮�ǣ�");		//��ʾ������
	while(CH[i])							//ɨ��������ַ�����ֱ���ַ���������־Ϊֹ
	{
		for(j=0;j<n;j++)					//���������ַ��������������ַ����бȽ�
		
			if(CH[i] == HT[j].c)			//�ҵ���ͬ���ַ�
			{
				printf("%s",CODE[j]);		//�ӱ������ȡ����Ӧ�ı��������ʾ
				strcpy(B,CODE[j]);			//������������
				break;						//�����һ���ַ��ı���
			}
	i++;					//����ɨ����һ���ַ�
	}
	printf("\n");
}

void Decoding()
{
	int i=0;									//ɨ��������봮��ָ��
	int j=0;									//�����������ָ��
	int p;										//ָ�������������ÿ���ڵ�Ķ�ָ̬��
	int root=2*n-2;								//���������������ڵ�ı���
	printf("\n��Ӧ��Ϣ���ǣ�");					//׼������������봮
	while(B[i])
	{
		p=root;		//�ӻ��������������ڵ㿪ʼ
		while(HT[p].lchild || HT[p].rchild)		//�����ǰ�ڵ����ӽڵ�
		{
			if(B[i]=='0')					//��ǰ����������0���ƶ������ӽڵ�
				p = HT[p].lchild;	
			else p=HT[p].rchild;			//��1���ƶ������ӽ��
			i++;					//ȡ��һ����������
		}
		printf("%c",HT[p].c);	//��ʾ��Ҷ�ڵ������Ϣ���ַ�
		CH[j] = HT[p].c;		//�������ַ����浽��������������
		j++;					//���������������ָ��
	}
	CH[j]='\0';
	printf("\n");
}


void createHFMTree()		//���ɻ������������ͱ������㷨
{
	int i,j,k,min,p,q,root;
	char c[MAX];		//�����ʱ����
	root = 2*n-2;		//���һ���м�ڵ�Ϊ�������������ĸ��ڵ�
	for(i=n;i<=root;i++)
	{
		min = MAX_NUM;		//��ʼ����Сֵ
		for(j=0;j<i;j++)
		if(HT[j].parent == 0 && HT[j].weight < min)
		{	
			p=j;					//����Ȩֵ��С�ڵ�ı��
			min = HT[j].weight;		//������Сֵ
		}
		min = MAX_NUM;		//�ٴγ�ʼ����Сֵ��׼��Ѱ�ҵ�2��
		for(j=0;j<i;j++)
		if(HT[j].parent == 0 && j!=p && min > HT[j].weight)	//
		{
			q=j;
			min=HT[j].weight;
		}
	HT[p].parent = i;	//��ǰ�м�ڵ�HT[i]���ӽڵ�HT[p]�ĸ��ڵ�
	HT[q].parent = i;	//��ǰ�м�ڵ�HT[i]���ӽڵ�HT[q]�ĸ��ڵ�
	HT[i].lchild = p;	//�ӽڵ�HT[p]���м�ڵ�HT[i]�����ӽڵ�
	HT[i].rchild = q;	//�ӽڵ�HT[p]���м�ڵ�HT[i]�����ӽڵ�
	HT[i].weight = HT[p].weight + HT[q].weight;		//�м�ڵ��Ȩֵ
		}
	for(i=0;i<n;i++)
	{
		p=i;				//�ӵ�ǰҶ�ڵ����
		q=HT[i].parent;		//�ҵ����ڵ�
		k=n-1;				//��ʼ����¼�����ָ�룬ָ����ʱ�ַ������ĩ��
		c[k]='\0';
		while(q)
		{
			if(p==HT[q].lchild)
				c[--k]='\0';
			else c[--k]='1';
			p=q;			//�����ƶ�һ�㣬ԭ���ĸ��ڵ��Ϊ��ǰ�ڵ�
			q=HT[p].parent;	//�µĸ��ڵ�
		}					//������ڵ�󣬸��ڵ㲻���ڣ�·������
	for(j=0;k<n;j++,k++)
		CODE[i][j]=c[k];
	}
}

