/*!
* \file main.c
*
* \author thnx1
* \date ���� 2018
*        �ֳ�3��o-d�ԣ�����Ҫ�����ǣ�
*      1 �ֱ����ÿ��o-d�Ե���Сֵ��
*      2 Ȼ����������С������ֵ
*       ��PSO�У�ֻ����ɵ�һ����
************************************************************************************************************
20180925 this is a branches  to test
Ŀ�꺯����������Ϊ�� x[i][j]cost[i][j]
(ref:http://t.cn/EPMAvy1)  pso�㷨���� ��Ѷ�����ĵ�
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
	cur_n = 0;           //��ǰ����
	RandInitofSwarm();             //��ʼ������Ⱥ			
	//lastGlobal = swarm.GBestIndex;
	// tempFitness = swarm.Particle[lastGlobal].Fitness;
	while (cur_n++ != ITE_N )//ֹͣ����Ϊ����ITE_N
	{
		UpdateofVandX();        //�ٶȺ�λ�ø���
		UpdatePandGbest();    //���¸�����ʷ���Ž�P��ȫ�����Ž�GBest
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