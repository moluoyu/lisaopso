#pragma once
#ifndef _PSO_H_
#define _PSO_H_
//不同路径的最大车流量                             
#define  capOfLoad1   10   //pcu/h No.4 号道路   1500pcu/h=25puc/min (设计速度25km/h) 考虑现有车流量，只留下
#define  capOfLoad2   26    //pcu/h No.2 号道路 
#define  capOfLoad3   25   //pcu/h No.1 号道路  1600pcu/h =26pcu/min   (设计速度35km/h)

/**
* \method
* 每个维度代表一辆车辆的选择结果,000 我们用十进制来表示车辆的选择道路 大型客车折换系数2.5 
* 比如：选择第一条道路则为  100 -->对应的十进制  4
* 比如：选择第二条道路则为  010 -->对应的十进制  2
* 比如：选择第三条道路则为  001 -->对应的十进制  1
*
*/
#define NumofVehicle 4 //目前车辆总数
#define Dim NumofVehicle //粒子维度 
#define PNum 2    //种群规模        由于每辆车有3种可能 所以一共有3^种解
#define ITE_N  3	 //最大迭代次数
int cur_n;			//当前迭代次数
int lastGlobal;  // 上一次迭代中种群中的最优值
double curGlobal;   // 本次迭代中种群中的最优值
					/*惯性权重函数*/
#define W_MAX 1.4
#define W_MIN	0.4
//#define W_FUN	(W_MAX-W_MIN)*(ITE_N-cur_n)/ITE_N+W_MIN// apso 权重系数w,为线性变化的
					/*个体和种群结构体*/
#define W_FUN  0.729
struct VEHICLE
{
	int startTime; //每辆车的发车时间/  以min为单位
	double encodeLoad; //道路编码

} ;
struct PARTICLE
{
	//double X[Dim + 1];   //粒子当前位置
	struct VEHICLE Vehicles[Dim + 1];
	struct VEHICLE PVehicles[Dim + 1]; 	 //粒子当前最优值的位置
	double V[Dim + 1];   //粒子当前速度
	double Fitness;      //粒子当前适应度
	int isNot1; //判断第1条路上是否有车,等于1为有车，0为无车
	int isNot2; //判断第2条路上是否有车,等于1为有车，0为无车
	int isNot3; //判断第3条路上是否有车,等于1为有车，0为无车
	int load1Time; //记录第1条道上目前最后一辆车的发车时间
	int load2Time; //记录第2条道路目前上最后一辆车发车时间
	int load3Time; //记录第3条道路上目前上最后一辆车发车时间
   //int numOfLoad1;
  //int	 numOfLoad2;
  //int	numOfLoad3;
} particle; 


struct SWARM
{
	struct PARTICLE Particle[PNum + 1];
	int GBestIndex;            //群体最优值索引
	struct VEHICLE gBestVehicles[Dim + 1];
	//double GBestV[Dim + 1];          //群体最优值坐标
	double C1;                  //学习因子
	double C2;
	double Xup[Dim + 1];            //位置上下限
	double Xdown[Dim + 1];
	double Vmax[Dim + 1];           //速度最大值
} swarm;

void RandInitofSwarm(void);
void UpdateofVandX(void);
void UpdatePandGbest(void);

#endif
