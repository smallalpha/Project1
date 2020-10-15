#include<stdio.h>
#include<string.h>
#include<math.h>
#define BURN_NUM 501
int BURN[2][BURN_NUM] = {0};
void compaper(double str1[],double str2[])//����Ѱ�������ۻ�ͨ�����ĵ�
{
	FILE* fp2;
	for (int i = 0; i < BURN_NUM; i++)
	{
		for (int j = 0; j < BURN_NUM; j++)
		{
			if (fabs((str1[i] - str2[j]) / str1[i])<0.01)
			{
				BURN[0][i] = i; BURN[1][i] = j;
				printf("��������ɹ�\n");
			}
			else
			{
				printf("%d,%d��������ʧ��\n",i,j);
			}
		}
	}
	fp2 = fopen("record.txt", "a");
	fprintf(fp2,"\n");
	for (int i = 0; i < BURN_NUM; i++)
	{
		if (BURN[0][i] == 0)
		{
			continue;
		}
		fprintf(fp2,"%d ",BURN[0][i]);
	}
	fprintf(fp2, "\n");
	for (int i = 0; i < BURN_NUM; i++)
	{
		if (BURN[1][i] == 0)
		{
			continue;
		}
		fprintf(fp2, "%d ", BURN[1][i]);
	}
	fprintf(fp2, "\n\n");
	fclose(fp2);
	fp2 = NULL;
}
int function1()
{
	//������������������ۻ�����ע������ͳ��
	//1.ͨ�����������ÿһ��ȼ�Ĳ�������ͨ��������/U235�ĺ������ܶ�
	//2.Ȼ�����ÿһ�����ۻ�����ͨ����Ȼ������Աȣ���������������ȼ�ĵ�

	FILE* fp;
	double U235_3[BURN_NUM] = {0};
	double U235_5[BURN_NUM] = { 0 };
	double Flux1[BURN_NUM] = { 0 };
	double Flux2[BURN_NUM], Flux3[BURN_NUM], Flux4[BURN_NUM], Flux5[BURN_NUM];
	double  Flux1_5[BURN_NUM],Flux2_5[BURN_NUM], Flux3_5[BURN_NUM], Flux4_5[BURN_NUM], Flux5_5[BURN_NUM];
	char ch[1000] = { 0 };
	char filename[100];
	int skin;
	double neutron_fluence3_1[BURN_NUM], neutron_fluence3_2[BURN_NUM], neutron_fluence3_3[BURN_NUM], neutron_fluence3_4[BURN_NUM], neutron_fluence3_5[BURN_NUM];
	double neutron_fluence5_1[BURN_NUM], neutron_fluence5_2[BURN_NUM], neutron_fluence5_3[BURN_NUM], neutron_fluence5_4[BURN_NUM], neutron_fluence5_5[BURN_NUM];
	
	//�����ļ�:���Ǽ���ɶ���ţ��Ǽ���ȼ�����/U235�ĺ������ܶ�
	fp=fopen("data.txt","r");
	ch[1] = fscanf(fp, "%s", ch);
	for (int i = 0; i < BURN_NUM; i++)
	{
		ch[1] = fscanf(fp, "%lf", &U235_3[i]);
		ch[1] = fscanf(fp, "%s", ch);
	}
	ch[1] = fscanf(fp,"%s",ch);
	for (int i = 0; i < BURN_NUM; i++)
	{
		ch[1] = fscanf(fp,"%lf",&U235_5[i]);
		ch[1] = fscanf(fp, "%s", ch);
	}
	fclose(fp);
	fp = NULL;

	//�Ҵ������ɶ���ţ�detͳ�Ƶ�����ͨ��
	//ͳ��3%�����ȵ�ȼ�ϵ�����ͨ��
	for (int i = 0; i < BURN_NUM; i++)
	{
		sprintf(filename,"inp3_det%d.m",i);
		fp = fopen(filename,"r");
		skin = 13;
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp,"%lf",&Flux1[i]);
		skin = 15;
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux2[i]);
		skin = 15;
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux3[i]);
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux4[i]);
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux5[i]);
		fclose(fp);
		fp = NULL;

	}
	//ͳ��5%�����ȵ�����ͨ��
	for (int i = 0; i < BURN_NUM; i++)
	{
		sprintf(filename, "inp5_det%d.m", i);
		fp = fopen(filename, "r");
		skin = 13;
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux1_5[i]);
		skin = 15;
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux2_5[i]);
		skin = 15;
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux3_5[i]);
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux4_5[i]);
		for (int k = 0; k < skin; k++)
		{
			ch[1] = fscanf(fp, "%s", ch);
		}
		ch[1] = fscanf(fp, "%lf", &Flux5_5[i]);
		fclose(fp);
		fp = NULL;
	}


	neutron_fluence3_1[0] = Flux1[0]; neutron_fluence3_2[0] = Flux2[0]; neutron_fluence3_3[0] = Flux3[0]; neutron_fluence3_4[0] = Flux4[0]; neutron_fluence3_5[0] = Flux5[0];
	neutron_fluence5_1[0] = Flux1_5[0]; neutron_fluence5_2[0] = Flux2_5[0]; neutron_fluence5_3[0] = Flux3_5[0]; neutron_fluence5_4[0] = Flux4_5[0]; neutron_fluence5_5[0] = Flux5_5[0];

	for (int i = 1; i < BURN_NUM; i++)
	{
		neutron_fluence3_1[i] = neutron_fluence3_1[i - 1] + Flux1[i];
		neutron_fluence3_2[i] = neutron_fluence3_2[i - 1] + Flux2[i];
		neutron_fluence3_3[i] = neutron_fluence3_3[i - 1] + Flux3[i];
		neutron_fluence3_4[i] = neutron_fluence3_4[i - 1] + Flux4[i];
		neutron_fluence3_5[i] = neutron_fluence3_5[i - 1] + Flux5[i];

		neutron_fluence5_1[i] = neutron_fluence5_1[i - 1] + Flux1_5[i];
		neutron_fluence5_2[i] = neutron_fluence5_2[i - 1] + Flux2_5[i];
		neutron_fluence5_3[i] = neutron_fluence5_3[i - 1] + Flux3_5[i];
		neutron_fluence5_4[i] = neutron_fluence5_4[i - 1] + Flux4_5[i];
		neutron_fluence5_5[i] = neutron_fluence5_5[i - 1] + Flux5_5[i];
	}
	fp=fopen("neutron_fluence.txt","a");
	fprintf(fp, "neutron_fluence3_1 neutron_fluence5_1 neutron_fluence3_2 neutron_fluence5_2 neutron_fluence3_3 neutron_fluence5_3 neutron_fluence3_4 neutron_fluence5_4 neutron_fluence3_5 neutron_fluence5_5\n");
	for (int i = 0; i < BURN_NUM; i++)
	{
		fprintf(fp, "%.6E\t|%.6E\t|%.6E\t|%.6E\t|%.6E\t|%.6E\t|%.6E\t|%.6E\t|%.6E\t|%.6E\t|\n", neutron_fluence3_1[i], neutron_fluence5_1[i], neutron_fluence3_2[i], neutron_fluence5_2[i], neutron_fluence3_3[i], neutron_fluence5_3[i], neutron_fluence3_4[i], neutron_fluence5_4[i], neutron_fluence3_5[i], neutron_fluence5_5[i]);

	}
	fclose(fp);
	fp = NULL;
	compaper(neutron_fluence3_1,neutron_fluence5_1);


	return 0;
}