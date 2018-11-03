/*!
* \file main.c
*
* \author thnx1
* \date 九月 2018
*        分成3个o-d对，我们要做的是：
*      1 分别求出每个o-d对的最小值，
*      2 然后求三个最小里的最大值
*       此PSO中，只是完成第一步，
************************************************************************************************************
20180925 this is a branches  to test
目标函数进行修正为： x[i][j]cost[i][j]
(ref:http://t.cn/EPMAvy1)  pso算法编码 腾讯在线文档
**********************************************************************************************************/
#include "pso.h"
#include "stdio.h"
extern double ComputAFitness(struct PARTICLE* particle);
//int tempcur[ITE_N];
int  tempGbest[ITE_N+1];
int main(int argc, const char *argv[])
{
	/*double tempFitness;
	int temp1=1;*/
	cur_n = 0;           //当前代数
	RandInitofSwarm();             //初始化粒子群			
	//lastGlobal = swarm.GBestIndex;
	// tempFitness = swarm.Particle[lastGlobal].Fitness;
	while (cur_n++ != ITE_N )//停止条件为代数ITE_N
	{
		UpdateofVandX();        //速度和位置更新
		UpdatePandGbest();    //更新个体历史最优解P和全局最优解GBest
	//	tempGbest[cur_n] = ComputAFitness(&swarm.Particle[swarm.GBestIndex]);

	//	if (tempFitness>ComputAFitness(&swarm.Particle[swarm.GBestIndex])) //
		//{
	//		lastGlobal = swarm.GBestIndex;
	//		temp1 = cur_n;
	//		tempFitness = swarm.Particle[lastGlobal].Fitness;
		//	for (int i = 1; i < Dim + 1; i++)
		//	{
		//		swarm.Particle[0].Vehicles[i].encodeLoad = swarm.Particle[lastGlobal].Vehicles[i].encodeLoad;
		//	}
		//}



	}
	for(int i=1;i<=ITE_N;i++)
	{
		printf("%d\t%d\n", i, tempGbest[i]);
	}
	int temp1 = tempGbest[1];
	int tempnum = 1;
	for (int i = 1; i <= ITE_N; i++)
	{
		if (temp1>tempGbest[i])
		{
			temp1 = tempGbest[i];
			tempnum = i;
		}
	}
	printf("%d %d\n", tempnum, temp1);


	return 0;
}