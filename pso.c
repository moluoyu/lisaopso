#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "pso.h"
#include <memory.h>
/**
* \method
*
* \brief ͳ�Ƶ�ǰ��i������ѡ���j����·������£���ǰ����´ӵ�1������i���������Ѿ�ѡ��ͬһ����·�ĳ�������numofload
* ���ڼ��㵱ǰ��·�µ�·���������ʱ��Ϊ���۱�׼��
* \param
* \param
* \author thnx1
* \date ���� 2018
*/
//int numOfLoad1 = 0, numOfLoad2 = 0, numOfLoad3 = 0;????����������
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
* \brief ���㲻ͬ·���µ�·��ֵ������Ϊ��·�����г�ʱ�䣩
* ÿ��
* \param int in_x  �����x[i]�����i������ѡ��·�����
*�������ÿ������ѡ��·����ֵ��
* 4 ---100
* 2 ---010
* 1 ---001
* \author thnx1
* \date ���� 2018
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
//		* �����汾���������� * BPR�������㲻ͬ��ͨ�����µ�·�躯��         t=t0(1+a(q/c)^b)
//		*
//		*/
//	case 4:
//		if (particle->numOfLoad1 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);//ÿ1min������з�һ����
//			traffic = (double)totalNum / gapofTime;//���޸�Ϊbpr����
//			if (traffic >= 0 && traffic <= 0.2*capOfLoad1)// 1.2   ���ų����������ӣ�CostӦ��Խ��Խ��  Ƿ����
//			{
//				resOfC = 4.0;
//			}
//			else if (traffic > 0.2*capOfLoad1 && traffic <= 0.5*capOfLoad1)//    ��������
//			{
//				resOfC = 5.0;
//			}
//			else if (traffic > 0.5*capOfLoad1 && traffic <= capOfLoad1)//           ������
//			{
//				resOfC = 6.0;
//			}
//
//		}
//		else//�ʼʱ,���ڳ����Ƚ�С��û������·�躯��ֵ
//		{
//			resOfC = 4.0;
//		}
//		break;
//	case 2:
//		if (particle->numOfLoad2 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);
//			traffic = (double)totalNum / gapofTime;
//			if (traffic >= 0 && traffic <= 0.3*capOfLoad2)//3 ���ų����������ӣ�CostӦ��Խ��Խ�� Ƿ����
//			{
//				resOfC = 2.5;
//			}
//			else if (traffic > 0.3*capOfLoad2 && traffic <= 0.6*capOfLoad2)// 6 ��������
//			{
//				resOfC = 4.0;
//			}
//			else if (traffic > 0.6*capOfLoad2 && traffic <= capOfLoad2)//6-9������
//			{
//				resOfC = 6.0;
//			}
//		}
//		else//�ʼʱ,���ڳ����Ƚ�С��û������·�躯��ֵ
//		{
//			resOfC = 2.0;
//		}
//		break;
//	case 1:
//		if (particle->numOfLoad3 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);
//			traffic = (double)totalNum / gapofTime;
//			if (traffic >= 0 && traffic <= 0.2*capOfLoad3)//1.2  ���ų����������ӣ�CostӦ��Խ��Խ�� Ƿ����
//			{
//				resOfC = 1.0;
//			}
//			else if (traffic > 0.2*capOfLoad3 && traffic <= 0.6*capOfLoad3)//1.2-3.6  ��������
//			{
//				resOfC = 3.0;
//			}
//			else if (traffic > 0.6*capOfLoad3 && traffic <= capOfLoad3)//3.6-6������
//			{
//				resOfC = 5.0;
//			}
//		}
//		else//�ʼʱ,���ڳ����Ƚ�С��û������·�躯��ֵ,ֵ���󣬲���������Χ��
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
//		* �����汾���������� * BPR�������㲻ͬ��ͨ�����µ�·�躯��         t=t0(1+a(q/c)^b)
//		*
//		*/
//	case 4:
//		if (particle->numOfLoad1 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);//ÿ1min������з�һ����
//			traffic = (double)totalNum / gapofTime;//���޸�Ϊbpr����
//			if (traffic >= 0 && traffic <= 0.2*capOfLoad1)// 1.2   ���ų����������ӣ�CostӦ��Խ��Խ��  Ƿ����
//			{
//				resOfC = 4.0;
//			}
//			else if (traffic > 0.2*capOfLoad1 && traffic <= 0.5*capOfLoad1)//    ��������
//			{
//				resOfC = 5.0;
//			}
//			else if (traffic > 0.5*capOfLoad1 && traffic <= capOfLoad1)//           ������
//			{
//				resOfC = 6.0;
//			}
//
//		}
//		else//�ʼʱ,���ڳ����Ƚ�С��û������·�躯��ֵ
//		{
//			resOfC = 4.0;
//		}
//		break;
//	case 2:
//		if (particle->numOfLoad2 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);
//			traffic = (double)totalNum / gapofTime;
//			if (traffic >= 0 && traffic <= 0.3*capOfLoad2)//3 ���ų����������ӣ�CostӦ��Խ��Խ�� Ƿ����
//			{
//				resOfC = 2.5;
//			}
//			else if (traffic > 0.3*capOfLoad2 && traffic <= 0.6*capOfLoad2)// 6 ��������
//			{
//				resOfC = 4.0;
//			}
//			else if (traffic > 0.6*capOfLoad2 && traffic <= capOfLoad2)//6-9������
//			{
//				resOfC = 6.0;
//			}
//		}
//		else//�ʼʱ,���ڳ����Ƚ�С��û������·�躯��ֵ
//		{
//			resOfC = 2.0;
//		}
//		break;
//	case 1:
//		if (particle->numOfLoad3 > 1)
//		{
//			gapofTime = ((n - 1)*1.0);
//			traffic = (double)totalNum / gapofTime;
//			if (traffic >= 0 && traffic <= 0.2*capOfLoad3)//1.2  ���ų����������ӣ�CostӦ��Խ��Խ�� Ƿ����
//			{
//				resOfC = 1.0;
//			}
//			else if (traffic > 0.2*capOfLoad3 && traffic <= 0.6*capOfLoad3)//1.2-3.6  ��������
//			{
//				resOfC = 3.0;
//			}
//			else if (traffic > 0.6*capOfLoad3 && traffic <= capOfLoad3)//3.6-6������
//			{
//				resOfC = 5.0;
//			}
//		}
//		else//�ʼʱ,���ڳ����Ƚ�С��û������·�躯��ֵ,ֵ���󣬲���������Χ��
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

	//ÿ�μ���fitnessʱ��һ��Ҫ�ǵý������й��еı������㡣
	particle->load1Time = 0;
	particle->load2Time = 0;
	particle->load3Time = 0;
	//20181103 be water !!!my friend!,����д�������ӹ��б������㣬�㶼������������������
	particle->isNot1 = 0;
	particle->isNot2 = 0;
	particle->isNot3 = 0;

	//int resOfTime = 0;
	//ÿ�ε����󣬽�ÿ�����ӵ�numofLoad����ȫ�����㡣��Ȼ����� 
	// numofVehicle( )������������¼��㲻ͬʱ�ε�cost�����쳣ֵ
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
			//��ǰһ����ͬ·�������ټ��1min����
			if (particle->Vehicles[i].encodeLoad == particle->Vehicles[i - 1].encodeLoad)
			{
				particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime + 1;
			}
			else //��ǰһ������ͬ·
			{
				switch ((int)particle->Vehicles[i].encodeLoad)
				{
				case  4:
					if (particle->isNot1 != 1)//��һ��·û�г�
					{
						particle->isNot1 = 1;
						particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
					}
					else //��һ��·�г�
					{
						//�ҵ�ͬһ��·����һ�����ķ���ʱ�䣬Ҳ������load1Time
						//�����һ����Vehicles[i - 1]�ķ���ʱ��-load1Time >1min��������ȴ�ֱ�ӷ���
						if ((particle->Vehicles[i - 1].startTime - particle->load1Time) >= 1)
						{
							particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
						}
						else//���С��1min,�����������1min������
						{
							particle->Vehicles[i].startTime = particle->load1Time + 1;//
						}
					}
					break;
				case  2:
					if (particle->isNot2 != 1)//��2��·û�г�
					{
						particle->isNot2 = 1;
						particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
					}
					else //��2��·�г�
					{
						//�ҵ�ͬһ��·����һ�����ķ���ʱ�䣬Ҳ������load2Time
						//�����һ����Vehicles[i - 1]�ķ���ʱ��-load2Time >1min��������ȴ�ֱ�ӷ���
						if ((particle->Vehicles[i - 1].startTime - particle->load2Time) >= 1)
						{
							particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
						}
						else//���С��1min,�����������1min������
						{
							particle->Vehicles[i].startTime = particle->load2Time + 1;//
						}
					}
					break;
				case  1:
					if (particle->isNot3 != 1)//��3��·û�г�
					{
						particle->isNot3 = 1;
						particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
					}
					else //��3��·�г�
					{
						//�ҵ�ͬһ��·����һ�����ķ���ʱ�䣬Ҳ������load3Time
						//�����һ����Vehicles[i - 1]�ķ���ʱ��-load3Time >=1min��������ȴ�ֱ�ӷ���
						if ((particle->Vehicles[i - 1].startTime - particle->load3Time) >= 1)
						{
							particle->Vehicles[i].startTime = particle->Vehicles[i - 1].startTime;
						}
						else//���С��1min,�����������1min������
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
* \brief �������ÿ������ѡ��·����ֵ��
* 4 ---100
* 2 ---010
* 1 ---001
* \param
* \param
* \author thnx1
* \date ���� 2018
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

//Ŀǰ�����ڵ�·�����Ƚϸߣ�����һֱ��������������������������Բ����ǣ�
//int testParticle(struct PARTICLE * particle)
//{
//	int res=0,temp;
//	for (int i = 1; i < Dim+1; i++)
//	{
//		temp = numofVehicle(particle, i);//�����i����ѡ���j����·ʱ���ӵ�1��������i������ѡ�е�j��·�ĳ�������
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
//��ʼ����Ⱥ
void RandInitofSwarm(void)
{

	//ѧϰ����C1,C2
	swarm.C1 = 2.0;
	swarm.C2 = 2.0;
	swarm.GBestIndex = 1;
	for (int j = 1; j < Dim + 1; j++)
	{
		swarm.Xdown[j] = 1.0;    //ÿ������ѡ������СΪ1
		swarm.Xup[j] = 4.0;		// ÿ������ѡ�������Ϊ4
		swarm.Vmax[j] = 2.0;       //���ӷ����ٶ����ֵ
	}

	srand((unsigned)time(NULL));

	for (int i = 1; i < PNum + 1; i++)      //PNum ��Ⱥ��ģ���������Ӹ���
	{
		
		for (int j = 1; j < Dim + 1; j++)   //�趨ÿ������ÿ��ά���ϵ����λ��������ٶ�
		{
			//	swarm.Particle[i].X[j] = rand() / (double)RAND_MAX * (swarm.Xup[j] - swarm.Xdown[j]) + swarm.Xdown[j];
			swarm.Particle[i].Vehicles[j].encodeLoad= randomGenValue();		
			//-Xdown~Xup
			// swarm.Particle[i].V[j] = rand() / (double)RAND_MAX * swarm.Vmax[j] * 2 - swarm.Vmax[j];
			swarm.Particle[i].V[j] = randomGenSpeed();

			//-Vmax~Vmax
			//�趨�������ӵĵ�ǰ����ֵ��λ��
			swarm.Particle[i].PVehicles[j].encodeLoad = swarm.Particle[i].Vehicles[j].encodeLoad; 


		}
		//������Ӧ��֮ǰ�����ж����ӽ��Ƿ����
		//Ŀǰ�ĵ�·���������£���Ϊ���ټ��һminһ������������һֱ���㣬���ÿ��ǵ�·����
		// testParticle()����Ŀǰ�ò���
		swarm.Particle[i].Fitness = ComputAFitness(&swarm.Particle[i]);  //����ÿ�����ӵ���Ӧ��ֵ

	}


}

//update  V and X �����ٶȺ�λ��
void UpdateofVandX(void)
{
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 1; i < PNum + 1; i++)	//pNum��Ⱥ��С
	{
		//�ٶȸ��¹�ʽ����׼pso:    w*v[i] +c1xrand()x(pbest[i]-x[i])+c2xrand()x(gbest[i]-x[i])		
		//wΪ�������ӣ�ֵΪ�Ǹ���c1 c2Ϊѧϰ���ӣ�һ��Ϊ����Ч���ã���ȡΪ 2
		for (j = 1; j < Dim + 1; j++)
			swarm.Particle[i].V[j] = W_FUN * swarm.Particle[i].V[j] +
			rand() / (double)RAND_MAX * swarm.C1 * (swarm.Particle[i].PVehicles[j].encodeLoad - swarm.Particle[i].Vehicles[j].encodeLoad)	+rand() / (double)RAND_MAX * swarm.C2 * (swarm.gBestVehicles[j].encodeLoad - swarm.Particle[i].Vehicles[j].encodeLoad);
		for (j = 1; j < Dim + 1; j++)
		{
			if (swarm.Particle[i].V[j] > swarm.Vmax[j])  //���������ٶȷ�Χ
			{
				swarm.Particle[i].V[j] = swarm.Vmax[j];
			}
			if (swarm.Particle[i].V[j] < -swarm.Vmax[j])
			{
				swarm.Particle[i].V[j] = -swarm.Vmax[j];
			}
		}

		for (j = 1; j < Dim + 1; j++)     //����λ�ã�x(i+1)=x(i)+v(i)
		{
			swarm.Particle[i].Vehicles[j].encodeLoad += swarm.Particle[i].V[j];
			if (swarm.Particle[i].Vehicles[j].encodeLoad >= swarm.Xup[j])
				swarm.Particle[i].Vehicles[j].encodeLoad = swarm.Xup[j];
			if (swarm.Particle[i].Vehicles[j].encodeLoad <= swarm.Xdown[j])
				swarm.Particle[i].Vehicles[j].encodeLoad = swarm.Xdown[j];

			if (swarm.Particle[i].V[j] > 0)//�ٶȷ���Ϊ����
			{
				if (swarm.Particle[i].Vehicles[j].encodeLoad > 1 && swarm.Particle[i].Vehicles[j].encodeLoad < 2)
					swarm.Particle[i].Vehicles[j].encodeLoad = 2.0;
				if (swarm.Particle[i].Vehicles[j].encodeLoad > 2 && swarm.Particle[i].Vehicles[j].encodeLoad < 4)
					swarm.Particle[i].Vehicles[j].encodeLoad = 4.0;
			}
			if (swarm.Particle[i].V[j] < 0)              //�ٶȷ���Ϊ�ݼ�
			{
				if (swarm.Particle[i].Vehicles[j].encodeLoad > 1 && swarm.Particle[i].Vehicles[j].encodeLoad < 2)
					swarm.Particle[i].Vehicles[j].encodeLoad = 1.0;
				if (swarm.Particle[i].Vehicles[j].encodeLoad > 2 && swarm.Particle[i].Vehicles[j].encodeLoad < 4)
					swarm.Particle[i].Vehicles[j].encodeLoad = 2.0;
			}
		}
		/*********
		2017/7/26
		��Ϊ�����������д��룬����һ������
		**********/

		swarm.Particle[i].Fitness = ComputAFitness(&swarm.Particle[i]);  //���¼���ÿ�����ӵ���Ӧ��ֵ

	}

}

/*���¸��弫ֵP��ȫ�ּ�ֵGBest*/
void UpdatePandGbest(void)
{
	fp = fopen("output.txt", "a+");
	//update of P if the X is less than current P
	for (int i = 1; i < PNum + 1; i++)
	{

		if (swarm.Particle[i].Fitness < ComputAFitness(&swarm.Particle[i])) //���µ�ǰ��һ������pֵ
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
	//��ǰ���������������е�����ֵ

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