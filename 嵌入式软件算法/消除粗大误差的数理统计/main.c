#include <stdio.h>
#include <math.h>
#define MAX 200			//�������ֵ200

float d[MAX];		//�����������
int n;				//��ǰ��������
float ave;			//ƽ����
float s;			//����

float averg()
{
	int i;
	float sum;
	for(i=0,sum=0;i<n;i++)
		sum+=d[i];
	return sum/n;
}

float jfc()
{
	int i;
	float sum,c;
	for(i=0,sum=0;i<n;i++)
	{
		c=d[i]-ave;
		sum+=c*c;
	}
	return sqrt(sum/(n-1));
}

int del()
{
	int i,k;
	float low,high;
	low=ave-3*s;
	high=ave+3*s;
	k=0;								//��ʼ���޳���־
	for(i=0;i<n;i++)					
		if(d[i]<low || d[i]>high)		//���ֻ�����
		{
			if(i<n-1)					//����������������һ������
			{
				d[i]=d[n-1];		//�����һ�������������������
				i--;				//�˻�ǰһ��λ���Ա㴦���˸ոո��ǵ�����
			}
			n--;		//��ǰ��Ч������	��
			k=1;		//�����޳�������־
		}
		return k;	//�����޳���־
}

void main()
{
	int i;
	printf("\n\n���������������ĸ�����");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("�������%d������������ֵ��",i+1);
		scanf("%f",&d[i]);
	}
	getchar();
	while(1)
	{
		ave=averg();
		s=jfc();
		if(!del()) break;
	}
	printf("\n�޳������������ƽ��ֵ=%f\n",ave);
	printf("\n�޳�����������ľ�����=%f\n",s);
	getchar();
}