#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "pso.h"
#include <memory.h>
/**
* \method
*
* \brief 统计当前第i辆车在选择第j条道路的情况下，当前情况下从第1辆到第i辆，所有已经选择同一条道路的车辆总数numofload
* 用于计算当前道路下的路阻情况（以时间为评价标准）
* \param
* \param
* \author thnx1
* \date 九月 2018
*/
//int numOfLoad1 = 0, numOfLoad2 = 0, numOfLoad3 = 0;????还是有问题
//int numofVehicle(struct PARTICLE* particle, int n)
//{
//	int num = 0;
//	int resOfV = 0;
//	//	int tempNum1 = 0, tempNum2 = 0, tempNum3 = 0;
//	//printf("%d,%d,%d\n", particle->numOfLoad1, particle->numOfLoad2, particle->numOfLoad3);
//	if (4 == (int)particle->Vehicles[n].encodeLoad)
//	{
//
//		//tempNum1++;
//		particle->numOfLoad1++;
//		resOfV = particle->numOfLoad1;
//	}
//	if (2 == (int)particle->Vehicles[n].encodeLoad)
//	{
//
//		//tempNum2++;
//		particle->numOfLoad2++;
//		resOfV = particle->numOfLoad2;
//	}
//	if (1 == (int)particle->Vehicles[n].encodeLoad)
//	{
//
//		//tempNum3++;
//		particle->numOfLoad3++;
//		resOfV = particle->numOfLoad3;
//	}
//	return resOfV;
//}
/**
* \method
*
* \brief 计算不同路径下的路阻值（这里为：路径的行程时间）
* 每条
* \param int in_x  传入的x[i]代表第i辆车的选择路径结果
*随机生成每辆车的选择路径的值，
* 4 ---100
* 2 ---010
* 1 ---001
* \author thnx1
* \date 九月 2018
*/
//double countCost(struct PARTICLE* particle, int n)
//{
//	double traffic = 0.0;
//	double costTime = 0.0;
//	double gapofTime = 0.0;
//	double resOfC = 0.0;
//	int  totalNum = numofVehicle(particle, n);
//	switch ((int)particle->X[n])
//	{
//		/**
//		* \brief
//		* 后续版本（待做）： * BPR函数计算不同交通流量下的路阻函数         t=t0(1+a(q/c)^b)
//		*
//		*/
//	case 4:
//		if (particle->numOfLoad1 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);//每1min间隔进行发一辆车
//			traffic = (double)totalNum / gapofTime;//待修改为bpr函数
//			if (traffic >= 0 && traffic <= 0.2*capOfLoad1)// 1.2   随着车流量的增加，Cost应该越来越大  欠饱和
//			{
//				resOfC = 4.0;
//			}
//			else if (traffic > 0.2*capOfLoad1 && traffic <= 0.5*capOfLoad1)//    正常饱和
//			{
//				resOfC = 5.0;
//			}
//			else if (traffic > 0.5*capOfLoad1 && traffic <= capOfLoad1)//           过饱和
//			{
//				resOfC = 6.0;
//			}
//
//		}
//		else//最开始时,由于车流比较小，没法计算路阻函数值
//		{
//			resOfC = 4.0;
//		}
//		break;
//	case 2:
//		if (particle->numOfLoad2 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);
//			traffic = (double)totalNum / gapofTime;
//			if (traffic >= 0 && traffic <= 0.3*capOfLoad2)//3 随着车流量的增加，Cost应该越来越大 欠饱和
//			{
//				resOfC = 2.5;
//			}
//			else if (traffic > 0.3*capOfLoad2 && traffic <= 0.6*capOfLoad2)// 6 正常饱和
//			{
//				resOfC = 4.0;
//			}
//			else if (traffic > 0.6*capOfLoad2 && traffic <= capOfLoad2)//6-9过饱和
//			{
//				resOfC = 6.0;
//			}
//		}
//		else//最开始时,由于车流比较小，没法计算路阻函数值
//		{
//			resOfC = 2.0;
//		}
//		break;
//	case 1:
//		if (particle->numOfLoad3 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);
//			traffic = (double)totalNum / gapofTime;
//			if (traffic >= 0 && traffic <= 0.2*capOfLoad3)//1.2  随着车流量的增加，Cost应该越来越大 欠饱和
//			{
//				resOfC = 1.0;
//			}
//			else if (traffic > 0.2*capOfLoad3 && traffic <= 0.6*capOfLoad3)//1.2-3.6  正常饱和
//			{
//				resOfC = 3.0;
//			}
//			else if (traffic > 0.6*capOfLoad3 && traffic <= capOfLoad3)//3.6-6过饱和
//			{
//				resOfC = 5.0;
//			}
//		}
//		else//最开始时,由于车流比较小，没法计算路阻函数值,值过大，不在上述范围内
//		{
//			resOfC = 1.0;
//		}
//		break;
//	}
//	return resOfC;
//}


//double countCost2(struct PARTICLE* particle, int n)
//{
//	double traffic = 0.0;
//	double costTime = 0.0;
//	double gapofTime = 0.0;
//	double resOfC = 0.0;
//	int  totalNum = numofVehicle(particle, n);
//	switch ((int)particle->X[n])
//	{
//		/**
//		* \brief
//		* 后续版本（待做）： * BPR函数计算不同交通流量下的路阻函数         t=t0(1+a(q/c)^b)
//		*
//		*/
//	case 4:
//		if (particle->numOfLoad1 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);//每1min间隔进行发一辆车
//			traffic = (double)totalNum / gapofTime;//待修改为bpr函数
//			if (traffic >= 0 && traffic <= 0.2*capOfLoad1)// 1.2   随着车流量的增加，Cost应该越来越大  欠饱和
//			{
//				resOfC = 4.0;
//			}
//			else if (traffic > 0.2*capOfLoad1 && traffic <= 0.5*capOfLoad1)//    正常饱和
//			{
//				resOfC = 5.0;
//			}
//			else if (traffic > 0.5*capOfLoad1 && traffic <= capOfLoad1)//           过饱和
//			{
//				resOfC = 6.0;
//			}
//
//		}
//		else//最开始时,由于车流比较小，没法计算路阻函数值
//		{
//			resOfC = 4.0;
//		}
//		break;
//	case 2:
//		if (particle->numOfLoad2 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);
//			traffic = (double)totalNum / gapofTime;
//			if (traffic >= 0 && traffic <= 0.3*capOfLoad2)//3 随着车流量的增加，Cost应该越来越大 欠饱和
//			{
//				resOfC = 2.5;
//			}
//			else if (traffic > 0.3*capOfLoad2 && traffic <= 0.6*capOfLoad2)// 6 正常饱和
//			{
//				resOfC = 4.0;
//			}
//			else if (traffic > 0.6*capOfLoad2 && traffic <= capOfLoad2)//6-9过饱和
//			{
//				resOfC = 6.0;
//			}
//		}
//		else//最开始时,由于车流比较小，没法计算路阻函数值
//		{
//			resOfC = 2.0;
//		}
//		break;
//	case 1:
//		if (particle->numOfLoad3 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);
//			traffic = (double)totalNum / gapofTime;
//			if (traffic >= 0 && traffic <= 0.2*capOfLoad3)//1.2  随着车流量的增加，Cost应该越来越大 欠饱和
//			{
//				resOfC = 1.0;
//			}
//			else if (traffic > 0.2*capOfLoad3 && traffic <= 0.6*capOfLoad3)//1.2-3.6  正常饱和
//			{
//				resOfC = 3.0;
//			}
//			else if (traffic > 0.6*capOfLoad3 && traffic <= capOfLoad3)//3.6-6过饱和
//			{
//				resOfC = 5.0;
//			}
//		}
//		else//最开始时,由于车流比较小，没法计算路阻函数值,值过大，不在上述范围内
//		{
//			resOfC = 1.0;
//		}
//		break;
//	}
//	return resOfC;
//}



extern int tempGbest[ITE_N + 1];
FILE * fp;
int  ComputAFitness(struct PARTICLE* particle) //
{

	//每次计算fitness时，一定要记得将粒子中共有的变量清零。
	particle->load1Time = 0;
	particle->load2Time = 0;
	particle->load3Time = 0;
	//20181103 be water !!!my friend!,上面写的你粒子共有变量清零，你都不看喵！！！！！！
	particle->isNot1 = 0;
	particle->isNot2 = 0;
	particle->isNot3 = 0;

	//int resOfTime = 0;
	//每次迭代后，将每个粒子的numofLoad属性全部归零。不然后面的 
	// numofVehicle( )函数会出错，导致计算不同时段的cost出现异常值
	//particle->numOfLoad1 = 0;
	//particle->numOfLoad2 = 0;
	//particle->numOfLoad3 = 0;
	for (int i = 1; i < Dim + 1; i++)
	{
		//to do code 
		if (1 == i)
		{
			particle->Vehicles[i].startTime = 0;
		}
		else
		{
			//与前一辆车同路，则至少间隔1min发车
			if (particle->Vehicles[i].encodeLoad == particle->Vehicles[i - 1].encodeLoad)
			{
				particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime + 1;
			}
			else //与前一辆车不同路
			{
				switch ((int)particle->Vehicles[i].encodeLoad)
				{
				case  4:
					if (particle->isNot1 != 1)//第一条路没有车
					{
						particle->isNot1 = 1;
						particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
					}
					else //第一条路有车
					{
						//找到同一条路的上一辆车的发车时间，也就是是load1Time
						//如果上一辆车Vehicles[i - 1]的发车时间-load1Time >1min，则无需等待直接发车
						if ((particle->Vehicles[i - 1].startTime - particle->load1Time) >= 1)
						{
							particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
						}
						else//如果小于1min,则必须满足间隔1min的条件
						{
							particle->Vehicles[i].startTime = particle->load1Time + 1;//
						}
					}
					break;
				case  2:
					if (particle->isNot2 != 1)//第2条路没有车
					{
						particle->isNot2 = 1;
						particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
					}
					else //第2条路有车
					{
						//找到同一条路的上一辆车的发车时间，也就是是load2Time
						//如果上一辆车Vehicles[i - 1]的发车时间-load2Time >1min，则无需等待直接发车
						if ((particle->Vehicles[i - 1].startTime - particle->load2Time) >= 1)
						{
							particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
						}
						else//如果小于1min,则必须满足间隔1min的条件
						{
							particle->Vehicles[i].startTime = particle->load2Time + 1;//
						}
					}
					break;
				case  1:
					if (particle->isNot3 != 1)//第3条路没有车
					{
						particle->isNot3 = 1;
						particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
					}
					else //第3条路有车
					{
						//找到同一条路的上一辆车的发车时间，也就是是load3Time
						//如果上一辆车Vehicles[i - 1]的发车时间-load3Time >=1min，则无需等待直接发车
						if ((particle->Vehicles[i - 1].startTime - particle->load3Time) >= 1)
						{
							particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
						}
						else//如果小于1min,则必须满足间隔1min的条件
						{
							particle->Vehicles[i].startTime = particle->load3Time + 1;//
						}
					}
					break;
				}

			}
			
		}

		switch ((int)particle->Vehicles[i].encodeLoad)
		{
		case  4:
			if (particle->isNot1 != 1)
			{
				particle->isNot1 = 1;
			}
			break;
		case  2:
			if (particle->isNot2 != 1)
			{
				particle->isNot2 = 1;
			}
			break;
		case  1:
			if (particle->isNot3 != 1)
			{
				particle->isNot3 = 1;
			}
			break;
		}
		switch ((int)particle->Vehicles[i].encodeLoad)
		{
		case  4:
			particle->load1Time = particle->Vehicles[i].startTime;
			break;
		case  2:
			particle->load2Time = particle->Vehicles[i].startTime;
			break;
		case  1:
			particle->load3Time = particle->Vehicles[i].startTime;
			break;
		}
	}

	for (int j = 1; j < Dim + 1; j++)
	{
		particle->PVehicles[j].startTime = particle->Vehicles[j].startTime;
		//particle->PVehicles[j].encodeLoad = particle->Vehicles[j].encodeLoad;

	}

	return particle->Vehicles[Dim].startTime;
}

/**
* \method
*
* \brief 随机生成每辆车的选择路径的值，
* 4 ---100
* 2 ---010
* 1 ---001
* \param
* \param
* \author thnx1
* \date 九月 2018
*/
double randomGenValue()
{
	int a = rand() % 3 + 1;
	double temp = 0;
	switch (a)
	{
	case 1:
		temp = 1.0;
		break;
	case 2:
		temp = 2.0;
		break;
	case 3:
		temp = 4.0;
		break;
	}
	return  temp;
}
double randomGenSpeed()   
{

	int a = rand() % 2 + 1;
	double temp = 0.0;
	switch (a)
	{
	case 1:
		temp = 1.0;
		break;
	case 2:
		temp = 2.0;
		break;
	}
	return  temp;
}

//目前，由于道路容量比较高，所以一直到不到饱和容量，这个函数可以不考虑；
//int testParticle(struct PARTICLE * particle)
//{
//	int res=0,temp;
//	for (int i = 1; i < Dim+1; i++)
//	{
//		temp = numofVehicle(particle, i);//计算第i辆车选择第j条道路时，从第1辆车到第i辆车中选中第j条路的车辆数。
//		switch (particle->Vehicles[i].encodeLoad)
//		{
//		case 4:
//			temp / (particle->Vehicles[i].startTime - );
//			if (>= capOfLoad1)
//			{
//			}
//			break;
//		case 2:
//			break;
//		case 1:
//			break;
//		}
//		
//
//	}
//	return
//}
//初始化种群
void RandInitofSwarm(void)
{

	//学习因子C1,C2
	swarm.C1 = 2.0;
	swarm.C2 = 2.0;
	swarm.GBestIndex = 1;
	for (int j = 1; j < Dim + 1; j++)
	{
		swarm.Xdown[j] = 1.0;    //每辆车的选择结果最小为1
		swarm.Xup[j] = 4.0;		// 每辆车的选择结果最大为4
		swarm.Vmax[j] = 2.0;       //粒子飞翔速度最大值
	}

	srand((unsigned)time(NULL));

	for (int i = 1; i < PNum + 1; i++)      //PNum 总群规模，即是粒子个数
	{
		
		for (int j = 1; j < Dim + 1; j++)   //设定每个粒子每个维度上的随机位置与随机速度
		{
			//	swarm.Particle[i].X[j] = rand() / (double)RAND_MAX * (swarm.Xup[j] - swarm.Xdown[j]) + swarm.Xdown[j];
			swarm.Particle[i].Vehicles[j].encodeLoad= randomGenValue();		
			//-Xdown~Xup
			// swarm.Particle[i].V[j] = rand() / (double)RAND_MAX * swarm.Vmax[j] * 2 - swarm.Vmax[j];
			swarm.Particle[i].V[j] = randomGenSpeed();

			//-Vmax~Vmax
			//设定初代粒子的当前最优值的位置
			swarm.Particle[i].PVehicles[j].encodeLoad = swarm.Particle[i].Vehicles[j].encodeLoad; 


		}
		//计算适应度之前，先判断粒子解是否合理
		//目前的道路容量设置下，因为至少间隔一min一辆。所以条件一直满足，不用考虑道路容量
		// testParticle()函数目前用不着
		swarm.Particle[i].Fitness = ComputAFitness(&swarm.Particle[i]);  //计算每个粒子的适应度值

	}


}

//update  V and X 更新速度和位置
void UpdateofVandX(void)
{
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 1; i < PNum + 1; i++)	//pNum种群大小
	{
		//速度更新公式：标准pso:    w*v[i] +c1xrand()x(pbest[i]-x[i])+c2xrand()x(gbest[i]-x[i])		
		//w为惯性因子，值为非负，c1 c2为学习因子，一般为常数效果好，常取为 2
		for (j = 1; j < Dim + 1; j++)
			swarm.Particle[i].V[j] = W_FUN * swarm.Particle[i].V[j] +
			rand() / (double)RAND_MAX * swarm.C1 * (swarm.Particle[i].PVehicles[j].encodeLoad - swarm.Particle[i].Vehicles[j].encodeLoad)	+rand() / (double)RAND_MAX * swarm.C2 * (swarm.gBestVehicles[j].encodeLoad - swarm.Particle[i].Vehicles[j].encodeLoad);
		for (j = 1; j < Dim + 1; j++)
		{
			if (swarm.Particle[i].V[j] > swarm.Vmax[j])  //控制粒子速度范围
			{
				swarm.Particle[i].V[j] = swarm.Vmax[j];
			}
			if (swarm.Particle[i].V[j] < -swarm.Vmax[j])
			{
				swarm.Particle[i].V[j] = -swarm.Vmax[j];
			}
		}

		for (j = 1; j < Dim + 1; j++)     //更新位置：x(i+1)=x(i)+v(i)
		{
			swarm.Particle[i].Vehicles[j].encodeLoad += swarm.Particle[i].V[j];
			if (swarm.Particle[i].Vehicles[j].encodeLoad >= swarm.Xup[j])
				swarm.Particle[i].Vehicles[j].encodeLoad = swarm.Xup[j];
			if (swarm.Particle[i].Vehicles[j].encodeLoad <= swarm.Xdown[j])
				swarm.Particle[i].Vehicles[j].encodeLoad = swarm.Xdown[j];

			if (swarm.Particle[i].V[j] > 0)//速度方向为递增
			{
				if (swarm.Particle[i].Vehicles[j].encodeLoad > 1 && swarm.Particle[i].Vehicles[j].encodeLoad < 2)
					swarm.Particle[i].Vehicles[j].encodeLoad = 2.0;
				if (swarm.Particle[i].Vehicles[j].encodeLoad > 2 && swarm.Particle[i].Vehicles[j].encodeLoad < 4)
					swarm.Particle[i].Vehicles[j].encodeLoad = 4.0;
			}
			if (swarm.Particle[i].V[j] < 0)              //速度方向为递减
			{
				if (swarm.Particle[i].Vehicles[j].encodeLoad > 1 && swarm.Particle[i].Vehicles[j].encodeLoad < 2)
					swarm.Particle[i].Vehicles[j].encodeLoad = 1.0;
				if (swarm.Particle[i].Vehicles[j].encodeLoad > 2 && swarm.Particle[i].Vehicles[j].encodeLoad < 4)
					swarm.Particle[i].Vehicles[j].encodeLoad = 2.0;
			}
		}
		/*********
		2017/7/26
		因为少了下面这行代码，找了一个晚上
		**********/

		swarm.Particle[i].Fitness = ComputAFitness(&swarm.Particle[i]);  //重新计算每个粒子的适应度值

	}

}

/*更新个体极值P和全局极值GBest*/
void UpdatePandGbest(void)
{
	fp = fopen("output.txt", "a+");
	//update of P if the X is less than current P
	for (int i = 1; i < PNum + 1; i++)
	{

		if (swarm.Particle[i].Fitness < ComputAFitness(&swarm.Particle[i])) //更新当前这一代个体p值
		{
			for (int j = 1; j < Dim + 1; j++)
			{
				swarm.Particle[i].PVehicles[j].encodeLoad = swarm.Particle[i].Vehicles[j].encodeLoad;
				swarm.Particle[i].PVehicles[j].startTime = swarm.Particle[i].Vehicles[j].startTime;

			}
		}
	}

	//update of GBest
	// 
	//当前代数中所有粒子中的最优值

	for (int i = 1; i < PNum + 1; i++)
	{

		if (ComputAFitness(&swarm.Particle[i]) <
			ComputAFitness(&swarm.Particle[swarm.GBestIndex]))//swarm.Particle[swarm.GBestIndex].P
		{
			swarm.GBestIndex = i;
		}

	}


	for (int j = 1; j < Dim + 1; j++)
	{
		swarm.gBestVehicles[j].encodeLoad = swarm.Particle[swarm.GBestIndex].PVehicles[j].encodeLoad;
		swarm.gBestVehicles[j].startTime = swarm.Particle[swarm.GBestIndex].PVehicles[j].startTime;

	}
	/*fprintf(fp, "The %dth iteraction.\n", cur_n);
	fprintf(fp, "GBestIndex:%d \n", swarm.GBestIndex);

	fprintf(fp,"STime:\n");
	for (int j = 1; j < Dim + 1; j++)
	{

		fprintf(fp, "%d,", swarm.gBestVehicles[j].startTime);
	}
	fprintf(fp, "\nGBest:\n");
	for (int j = 1; j < Dim + 1; j++)
	{
		fprintf(fp, "%.0f,", swarm.gBestVehicles[j].encodeLoad);
	}
	fprintf(fp, "\n");*/
	double fitness = ComputAFitness(&swarm.Particle[swarm.GBestIndex]);
	tempGbest[cur_n]=fitness;
	fprintf(fp,"Fitness of GBest: %.1f \n\n", fitness);

	printf("The %dth iteraction.\n", cur_n);
	printf("GBestIndex:%d \n", swarm.GBestIndex);
	printf("STime:\n");
	for (int j = 1; j < Dim + 1; j++)
	{
		printf("%d,", swarm.gBestVehicles[j].startTime);
	}
	printf("\nGBest:");
	for (int j = 1; j < Dim + 1; j++)
	{
		printf("%.0f,", swarm.gBestVehicles[j].encodeLoad);
	}
	printf("Fitness of GBest: %.1f \n\n", fitness);
	//fclose(fp);
}