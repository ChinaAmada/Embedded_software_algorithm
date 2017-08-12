#include <stdio.h>
#define MAX 100
int R[MAX+1];			//R[1]��R[n]�洢������Ԫ�أ�R[0]��������
int n;

void disp(int S[]);

void QUICKSORT(int low,int high)
{
	int i,j;
	if(low>=high)	return;
	i=low;
	j=high;
	R[0]=R[i];
	while(i<j)
	{
		while(R[j]>=R[0] && i<j) j--;	//�ұߣ� �Ȼ�����j������
			if(i<j)	R[i++] = R[j];		//����������Ա�С�ڻ������������ŵ�����λ�ã�i���ұ���
		
		while(R[i]<R[0] && i<j) i++;	//��ߣ� �Ȼ���С��i������
			if(i<j) R[j--] = R[i];		//����Ȼ����󣬽�����ŵ�����λ�ã�j������
	}
	R[i] = R[0];	//�ѻ�����ֵ������
	disp(R);
	if(low<i-1)	QUICKSORT(low,i-1);		//����������������Ԫ�أ��ݹ����
	if(i+1<high) QUICKSORT(i+1,high);	//�ұ��������������Ԫ�أ��ݹ����
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
	QUICKSORT(1,n);
}