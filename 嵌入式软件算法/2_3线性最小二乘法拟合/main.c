#include <stdio.h>
#define MAX 20				//�궨�ڵ���������ֵ
int n;						//ʵ�ʱ궨�ڵ����
float x[MAX];				//��¼�궨�ڵ��ADת�����
float y[MAX];				//��¼�궨�ڵ���¶�
float a[2];					//���������ϵ�����ϵ��

void lsline()		//��������㷨
{
	float ave_x,ave_y,sumx2,sumxy;	//�������
	int i;
	ave_x=ave_y=sumx2=sumxy=0;		//��ʼ��
	for(i=0;i<n;i++)
	{
		ave_x+=x[i];		//����xi���ۼ�ֵ
		ave_y+=y[i];		//����yi���ۼ�ֵ
	}
	ave_x=ave_x/n;		//����xi��ƽ��ֵ
	ave_y=ave_y/n;		//����yi��ƽ��ֵ
	for(i=0;i<n;i++)
	{
		sumx2 += (x[i]-ave_x)*(x[i]-ave_x);		//sumx2Ϊxi�ķ����ۼ�ֵ
		sumxy += (y[i]-ave_x)*(x[i]-ave_x);		//xy
	}
	a[1] = sumxy/sumx2;		//�ȼ���ֱ�߷��̵�һ����ϵ��a1
	a[0] = ave_y-a[1]*ave_x;	//�ټ���ֱ�߷��̵ĳ�ϵ����a0
}

int main()
{
	int i ;
	printf("\n����궨�ڵ�ĸ�����");
	scanf("%d",&n);
	for(i=0;i<n;i++)	//����n���궨�ڵ������
	{
		printf("�����%d���궨�ڵ��ADת��ֵ��",i+1);
		scanf("%f",&x[i]);
		printf("�����%d���궨�ڵ���¶�ֵ��",i+1);
		scanf("%f",&y[i]);
	}
	getchar();
	lsline();		//������������㷨
	printf("\n������Ϸ���ʽΪ��y=%fx",a[1]);
	if(a[0]<0) printf("%f",a[0]);
	else printf(" + %f",a[0]);
	getchar();
}