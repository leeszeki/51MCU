/*********************************************************************************************************
*名称：led.h
*功能：外部引用到的数码管函数都在这个头文件中进行包含
创建时间：2019/7/4
修改时间：2019/7/4
作者：黄彦钊
*********************************************************************************************************/

#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <STC12C5A.H> 
#include "intrins.h"
#include "config.h"	 

void Display (uchar JNdata); //向hc595传送一个字节
void DisplayAddr(uchar i); //显示的数据

#endif