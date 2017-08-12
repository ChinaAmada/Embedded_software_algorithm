#include <stdio.h>
#define MAX 100			//Ԫ�ظ��������ֵ
#define MAXS (MAX+5)/2
int SR[MAX],TR[MAX];		//���������ݴ��������R[]�У�����R1[]Ϊ��������
int n;					//ʵ��Ԫ�ظ�����Ϊȫ�ֱ���

void disp(int S[]);

typedef struct
{
	int d[MAXS];				//��������Ϊ���еĴ洢�ռ�
	int front,rear;				//ָʾ��ͷ�Ͷ�β�ı�־
}SEQUEUE;						//˳��������Ͷ���
SEQUEUE sq;						//����˳�����

int ENQUEUE(int x)				//˳��ѭ�����е�����㷨
{
	if(sq.front == (sq.rear+1) % MAXS)	//���ӣ����ʧ��(ͷ=β)
		return NULL;
	else 
	{
		sq.rear = (sq.rear+1)%MAXS;		//��β�����ˣ���β��1
		sq.d[sq.rear] = x;				//�������
		return 1;						//��ӳɹ�
	}
}

int DEQUEUE()					//˳��ѭ�����еĳ����㷨
{
	if(sq.front == sq.rear)		//�նӣ�����ʧ��
		return NULL;
	else 
	{
		sq.front = (sq.front + 1)% MAXS;	//���׳����ˣ����׼�1
		return (sq.d[sq.front]);
	}
	
}

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
int MERGEPASS(int S[],int T[])
{
	int low,mid,high,i;
	int w=0;		
	low=DEQUEUE();
	while(1)
	{
		mid = DEQUEUE();
		if(mid == -1)
		{
			for(i=low; i<n;i++)
				T[i]=S[i];
				w++;
				ENQUEUE(low);
				ENQUEUE(-1);
				return w;
		}
		high=DEQUEUE();
		if(high==-1)
		{
			high=n;
			MERGE(S,T,low,mid,high);
			w++;
			ENQUEUE(low);
			ENQUEUE(-1);
			return w;
		}
		MERGE(S,T,low,mid,high);
		w++;
		ENQUEUE(low);
		low=high;
	}
}

//��׼���׶Σ�������һ��ɨ��һ�߽��й鲢����
int MERGEPASS1(int S[],int T[])
{
	int low,mid,high,i;
	int w=0;
	low=0;
	while(1)
	{
		for(i=low+1;i<n;i++)
			if(SR[i]<SR[i-1])break;
			mid=i;
			if(mid==n)
			{
				for(i=low;i<n;i++)
					T[i]=S[i];
				w++;
				ENQUEUE(low);
				ENQUEUE(-1);
				return w;
			}
		for(i=mid+1;i<n;i++)
			if(SR[i]<SR[i-1])break;
			high=i;
			if(high==n)
			{
				MERGE(S,T,low,mid,high);
				w++;
				ENQUEUE(low);
				ENQUEUE(-1);
				return w;
			}
			MERGE(S,T,low,mid,high);
			w++;
			ENQUEUE(low);
			low=high;
	}
}

//����㷨
void MERGESORT()
{
	int i;							//
	sq.front = sq.rear = MAX-1;		//��ʼ���ն�
	MERGEPASS1(SR,TR);				//׼��������һ��ɨ�裬һ�߹鲢�����ɳ�ʼ������
	disp(TR);						//��ʾ��һ�ֹ鲢������Ľ��
	while(1)						//����������֮�䷴�����й鲢����
	{
		if(MERGEPASS(TR,SR)==1)	//�ٽ���һ�ֹ鲢��������ص�SR[]
			return ;			//������ֹ鲢ֻ����һ�Σ����������
		disp(SR);				//������ʾ���ֽ����������һ�ֹ鲢
		MERGEPASS(SR,TR);		//����һ�ֹ鲢�������TR[]
		disp(TR);				//��ʾ��һ�ֹ鲢������Ľ��	
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
		scanf("%d",&SR[i]);
	}
	disp(SR);			//��ʾ��δ�������������
	MERGESORT();		//���øĽ��Ĺ鲢������
	disp(SR);			//��ʾ�������������Ԫ������
}