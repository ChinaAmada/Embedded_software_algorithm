#include <stdio.h>
#define MAX 100
int R[MAX+1];			//R[1]��R[n]�洢������Ԫ�أ�R[0]��������
int n;

typedef struct
{
	int d[MAX];			//��������Ϊ���еĴ洢�ռ�
	int front,rear;		//ָʾ��ͷ����β
}SEQUEUE;
SEQUEUE sq;

void disp(int S[]);		//��������

int ENQUEUE(int x)		//˳��ѭ����������㷨
{
	if(sq.front == (sq.rear +1 ) % MAX)		//�ж��Ƿ����
		return NULL;
	else
	{
		sq.rear = (sq.rear+1) % MAX;	//��β��1
		sq.d[sq.rear] = x;			//����x
		return 1;
	}
}

int DEQUEUE()
{
	if(sq.front == sq.rear)		//�ж��Ƿ�ӿ�
		return NULL;
	else 
	{
		sq.front = (sq.front+1)% MAX;	//��ͷ��1
		return (sq.d[sq.front]);		//����1��Ԫ��
	}
}

void QUICKSORT()
{
	int i,j,l,r;
	sq.front = sq.rear =MAX-1;		//��ʼ���ն�
	ENQUEUE(1);						//�����������
	ENQUEUE(n);						//���������յ�
	while(1)
	{
		l=DEQUEUE();				//�����������
		r=DEQUEUE();				//���������յ�
		if(l == NULL)	return;		//û�д��������䣬�㷨����
		i=l;
		j=r;
		R[0] =R[i];
		while(i<j)
		{
			while(R[j]>=R[0] && i<j) j--;	//�ұߣ� �Ȼ�����j������
				if(i<j)	R[i++] = R[j];		//����������Ա�С�ڻ������������ŵ�����λ�ã�i���ұ���
			
			while(R[i]<R[0] && i<j) i++;	//��ߣ� �Ȼ���С��i������
				if(i<j) R[j--] = R[i];		//����Ȼ����󣬽�����ŵ�����λ�ã�j������
		}
		R[i] = R[0];	//�ѻ�����ֵ������
		disp(R);
		if(l<i-1)			//���С��������
		{
			ENQUEUE(l);		//С�������������
			ENQUEUE(i-1);	//С�����յ�������
		}
		if(i+1<r)			//�������������
		{
			ENQUEUE(i+1);	//���������������
			ENQUEUE(r);		//�������յ�������
		}
	}
}

void disp(int S[])
{
	int i;
	printf("\n");
	for(i=1;i<=n;i++)	printf("%d ",S[i]);
	printf("\n");
}

void main()
{
	int i;
	while(1)
	{
		printf("\n����Ԫ�ظ�����");
		scanf("%d",&n);
		if(n<=MAX) break;
		printf("\n�������ܳ���%d",MAX);
	}
	for(i=1;i<=n;i++)
	{
		printf("\n�����%d��Ԫ�ص�ֵ��",i);
		scanf("%d",&R[i]);
	}
	disp(R);
	QUICKSORT();
}