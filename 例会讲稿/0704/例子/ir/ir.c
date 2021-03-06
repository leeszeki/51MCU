/*********************************************************************************************************
*名称：ir.c
*功能：红外模块包括的函数
创建时间：2019/XX/XX
修改时间：2019/6/5
作者：XXX
*********************************************************************************************************/

#include "ir.h"

U8 IRCOM[7] = {0};
U8 shuju[8]={0,1,2,3,4,5,6,7};   //储存数码管显示的值

/**************************************************************************
* 函数名称： IrInit()
* 功能：     红外初始化
******************************************************************************/
void IrInit()
{	
    IRIN=1;                    //I/O口初始化
	Delay_us(10);                 //延时
    IE=0x81;                 //允许总中断中断,使能 INT0 外部中断
	TCON=0x01;               //触发方式为脉冲负边沿触发
}

/**************************************************************************
* 函数名称： IR_IN()
* 功能：     红外值数据读取
******************************************************************************/
void IR_IN() interrupt 0 using 0
{
	U8 j,k,N=0;
	EX0 = 0;   
	Delay_us(15);
	if (IRIN==1) 
	{ 
		EX0 =1;
		return;
	} 
	                        //确认IR信号出现
	while (!IRIN)            //等IR变为高电平，跳过9ms的前导低电平信号。
		Delay_us(1);
	
	for (j=0;j<4;j++)         //收集四组数据
	{ 
	for (k=0;k<8;k++)        //每组数据有8位
	{
		while (IRIN)            //等 IR 变为低电平，跳过4.5ms的前导高电平信号。
		{Delay_us(1);}
		while (!IRIN)          //等 IR 变为高电平
		Delay_us(1);
		while (IRIN)           //计算IR高电平时长
		{
		Delay_us(1);
		N++;           
		if (N>=30)
		{ 
		EX0=1;
		return;
		}                  //0.14ms计数过长自动离开。
		}                        //高电平计数完毕                
		IRCOM[j]=IRCOM[j] >> 1;     //数据最高位补“0”
		if(N>=8)
		{
		IRCOM[j] = IRCOM[j] | 0x80;		  //数据最高位补“1”
		}  
		N=0;
		}
	}
	
	if(IRCOM[2]!=~IRCOM[3])
	{ 
		EX0=1;
		return; 
	}
	
	IRCOM[5]=IRCOM[2] & 0x0F;     //取键码的低四位
	IRCOM[6]=IRCOM[2] >> 4;       //右移4次，高四位变为低四位
	
	if(IRCOM[5]>9)
	{ 
		IRCOM[5]=IRCOM[5]+0x37;
	}
	else
	IRCOM[5]=IRCOM[5]+0x30;
    DisplayAddr(shuju[IRCOM[5]]);	
	EX0 = 1; 
}