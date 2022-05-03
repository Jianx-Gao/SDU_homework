#ifndef __UART_H_
#define __UART_H_

#include <intrins.h>					// �����ͷ�ļ���,��ʹ��_nop_�⺯��
#include "delay.h"		        // ��ʱ����ͷ�ļ�
#include <string.h>           // �����ͷ�ļ���,��ʹ��strstr�⺯��

extern void U1SendString(uint8 *s);
extern void U1SendData(uint8 ch);
extern void UartInit(void);

#endif
