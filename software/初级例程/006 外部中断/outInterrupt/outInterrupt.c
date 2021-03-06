/*********************************************************************************************************
*名称：outInterrupt.h
*功能：外部中断函数
创建时间：2019/7/4
修改时间：2019/7/4
作者：黄彦钊
*********************************************************************************************************/
#include "outInterrupt.h"	
#include "led/led.h"
	
/*******************************************************************************
* 函 数 名         : IntInit
* 函数功能		   : 设置外部中断
*******************************************************************************/ 
void init()
{												 
	EA  = 1;						 //打开总中断	 

	IT0 = 1;					 //设置外部中断0为下降沿触发方式
	EX0 = 1;					 //允许外部中断0中断
	IT1 = 1;					 //设置外部中断1为下降沿触发方式
	EX1 = 1;					 //允许外部中断1中断
}

/*******************************************************************************
* 函 数 名         : time0
* 函数功能		   : 外部中断0对应的服务程序
		      		 中断0由按键key1控制触发
*******************************************************************************/ 

void time0() interrupt 0
{			 
     led1();
}
/*******************************************************************************
* 函 数 名         : time1
* 函数功能		   : 外部中断1对应的服务程序
		      		 中断1由按键key2控制触发       
*******************************************************************************/ 
void time1() interrupt 2
{
     led2();
}
