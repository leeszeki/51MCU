/******************************************************
 	该程序用于呼吸灯					
	模块0的PWM输出管脚为P1.3 模块1的PWM输出管脚为1.4
	此程序用的是P1.3口作为PWM输出
	修改时间：2019年7月27日							
	作者：曾思茹									
******************************************************/  

/**************************
* 函数名：main
* 功能：主函数
**************************/												 
void main()
{
    Init_PWM();//初始化PWM
	while(1)
	{
		PWM_change(); //改变占空比从而改变输出电压
	}
}