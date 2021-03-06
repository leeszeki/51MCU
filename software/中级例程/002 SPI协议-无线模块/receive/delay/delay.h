/*********************************************************************************************************
*名称：delay.h
*功能：外部所用到的延迟功能函数声明
创建时间：2019/7/8
修改时间：2019/7/8
作者：黄彦钊
*********************************************************************************************************/
#ifndef _DELAY_H_
#define _DELAY_H_	  
#include "config.h"

void delay_ms(uint n);
void delay_us(uint n);
void nop(uint n);

#endif