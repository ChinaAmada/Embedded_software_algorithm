#include <stdio.h>
#define MAX 100			//Ԫ�ظ��������ֵ
int R[MAX],R1[MAX];		//���������ݴ��������R[]�У�����R1[]Ϊ��������
int n;					//ʵ��Ԫ�ظ�����Ϊȫ�ֱ���

void disp(int S[]);
//�ڲ��㷨
//�鲢������������
void MERGE(int P[],int Q[],int low,int mid,int high)
{
	int i,j,k;
	i=low;j=mid;k=low;
	while(i<mid && j<high)		//ȡС�߸���
		if(P[i] <= P[j] ) Q[k++] = P[i++];
		else Q[k++] = P[j++];
	while(i<mid) Q[k++] = P[i++];	//���Ƶ�һ������ʣ��Ԫ��
	while(j<high) Q[k++] = P[j++];	//���Ƶڶ�������ʣ��Ԫ��
}

//�в��㷨
void MERGEPASS(int M[],int N[],int length)
{
	int i,j;
	i=0;		//ָ���һ�����е���ʼ��
	while(i+2*length -1 < n)		//�鲢��������Ϊlength������
	{
		MERGE(M,N,i,i+length,i+2*length);	
		i+=2*length;			//ָ����һ�����е���ʼ�ˡ�
	}
	if(i+length <n)
		MERGE(M,N,i,i+length,n);	//��2�����г���С��length
	else for(j=i;j<n;j++)
		N[j]=M[j];				//�����һ�����и��Ƹ�����N
}

//����㷨
void MERGESORT()
{
	int length=1;			//�������еĳ��ȳ�ʼ��Ϊ1���ӵ���Ԫ�ؿ�ʼ���й鲢
	while(length <n)			//ֻҪ�������黹���Էֳ�������������
	{	
		MERGEPASS(R,R1,length);	//����һ�ֹ鲢����R[]��R1[]
		disp(R1);				//��ʾ��һ�ֹ鲢������Ľ��
		length *=2;				//һ�ֹ鲢���������еĳ�������һ��
		MERGEPASS(R1,R,length);	//�ٽ���һ�ֹ鲢��������ظ�R[]
		length *=2;				//һ�ֹ鲢���������еĳ�������һ��
		disp(R);				//��ʾ��һ�ֹ鲢�����Ľ��
	}
}

void disp(int S[])
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",S[i]);
	printf("\n");
}

void main()
{
	int i;
	while(1)
	{
		printf("\n������ʵ��Ԫ�ظ�����");
		scanf("%d",&n);
		if(n<=MAX)break;
		printf("\nʵ��Ԫ�ظ������ܳ���%d",MAX);
	}
	for(i=0;i<n;i++)
	{
		printf("\n�����%d��Ԫ�ص�ֵ��",i+1);
		scanf("%d",&R[i]);
	}
	disp(R);
	MERGESORT();
}