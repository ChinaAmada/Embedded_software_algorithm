#include <stdio.h>

#define a 0.03125	//�˲�ϵ��
float samp;			//�˲��㷨����Ч���

void tasksampctrl(void)
{
	float _new;
	samp=sample_adc();		//��ʼ��
	delay_ms(500);			//��ʱ500ms
	while(1)
	{
		_new=sample_adc();	//�µĲ�������
		samp= A*_new+(1-A)*samp;
		delay_ms(500);
	}
}
