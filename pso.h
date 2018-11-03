#pragma once
#ifndef _PSO_H_
#define _PSO_H_
//��ͬ·�����������                             
#define  capOfLoad1   10   //pcu/h No.4 �ŵ�·   1500pcu/h=25puc/min (����ٶ�25km/h) �������г�������ֻ����
#define  capOfLoad2   26    //pcu/h No.2 �ŵ�· 
#define  capOfLoad3   25   //pcu/h No.1 �ŵ�·  1600pcu/h =26pcu/min   (����ٶ�35km/h)

/**
* \method
* ÿ��ά�ȴ���һ��������ѡ����,000 ������ʮ��������ʾ������ѡ���· ���Ϳͳ��ۻ�ϵ��2.5 
* ���磺ѡ���һ����·��Ϊ  100 -->��Ӧ��ʮ����  4
* ���磺ѡ��ڶ�����·��Ϊ  010 -->��Ӧ��ʮ����  2
* ���磺ѡ���������·��Ϊ  001 -->��Ӧ��ʮ����  1
*
*/
#define NumofVehicle 4 //Ŀǰ��������
#define Dim NumofVehicle //����ά�� 
#define PNum 2    //��Ⱥ��ģ        ����ÿ������3�ֿ��� ����һ����3^�ֽ�
#define ITE_N  3	 //����������
int cur_n;			//��ǰ��������
int lastGlobal;  // ��һ�ε�������Ⱥ�е�����ֵ
double curGlobal;   // ���ε�������Ⱥ�е�����ֵ
					/*����Ȩ�غ���*/
#define W_MAX 1.4
#define W_MIN	0.4
//#define W_FUN	(W_MAX-W_MIN)*(ITE_N-cur_n)/ITE_N+W_MIN// apso Ȩ��ϵ��w,Ϊ���Ա仯��
					/*�������Ⱥ�ṹ��*/
#define W_FUN  0.729
struct VEHICLE
{
	int startTime; //ÿ�����ķ���ʱ��/  ��minΪ��λ
	double encodeLoad; //��·����

} ;
struct PARTICLE
{
	//double X[Dim + 1];   //���ӵ�ǰλ��
	struct VEHICLE Vehicles[Dim + 1];
	struct VEHICLE PVehicles[Dim + 1]; 	 //���ӵ�ǰ����ֵ��λ��
	double V[Dim + 1];   //���ӵ�ǰ�ٶ�
	double Fitness;      //���ӵ�ǰ��Ӧ��
	int isNot1; //�жϵ�1��·���Ƿ��г�,����1Ϊ�г���0Ϊ�޳�
	int isNot2; //�жϵ�2��·���Ƿ��г�,����1Ϊ�г���0Ϊ�޳�
	int isNot3; //�жϵ�3��·���Ƿ��г�,����1Ϊ�г���0Ϊ�޳�
	int load1Time; //��¼��1������Ŀǰ���һ�����ķ���ʱ��
	int load2Time; //��¼��2����·Ŀǰ�����һ��������ʱ��
	int load3Time; //��¼��3����·��Ŀǰ�����һ��������ʱ��
   //int numOfLoad1;
  //int	 numOfLoad2;
  //int	numOfLoad3;
} particle; 


struct SWARM
{
	struct PARTICLE Particle[PNum + 1];
	int GBestIndex;            //Ⱥ������ֵ����
	struct VEHICLE gBestVehicles[Dim + 1];
	//double GBestV[Dim + 1];          //Ⱥ������ֵ����
	double C1;                  //ѧϰ����
	double C2;
	double Xup[Dim + 1];            //λ��������
	double Xdown[Dim + 1];
	double Vmax[Dim + 1];           //�ٶ����ֵ
} swarm;

void RandInitofSwarm(void);
void UpdateofVandX(void);
void UpdatePandGbest(void);

#endif
