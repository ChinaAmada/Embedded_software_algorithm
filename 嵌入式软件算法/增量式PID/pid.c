/************************************************
����ʽPID�㷨��ֱ�Ӽ�����������Ĵ�С
DOut= KP*dk + KI*ek + KD*(dk-dk-1)
************************************************/

float Set;				//�趨ֵ
float KP;				//��������
float KI;				//���ֳ���
float KD;				//΢�ֳ���
float LE;				//�ϴ����
float SE;				//�ۼ����
float LD;				//�ϴε�΢��ֵ

void pid(void)			//��Ҫ������ִ�д�������
{
	float now,E,DE,Dout;
	while(1)
	{
		now=sampleadc();	//�����õ����ƶ���ĵ�ǰֵ
		E=Set-now;			//���㵱ǰ���   
		DE=E-LE;			//��һ�̱仯���� D
		
		Dout=KP * DE			//P������
		   +KI * E			//I������
		   +KD * (DE-LE);	//D΢����
		CtrlOut(Dout);		//�����������ִ��
		LE=E;				//�������ֵ�����´μ���ʹ��
		LD=DE;
		delay_ms(500);		//��������500ms
	}
}