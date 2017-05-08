/*
	NOTAS DA AULA
	
	Um código de IA tem que possuir três regiões bem divididas:
	- ENTRADA: leitura de dados, no caso do robô, sensores
	- PROCESSAMENTO: uso dos dados na determinação de uma saída
	- SAIDA: decisões 

*/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct 
{
	int s1;
	int s2;
	int s3;
} SENSORS;

typedef struct
{
	int m1;
	int m2;
} MOTORS;

SENSORS readSensors(void); // função para ler os sensores

MOTORS IA(SENSORS Sensors); // função de processamento dos dados

void driveMotors(MOTORS Motors); // função de tomada de decisões

int main()
{
	SENSORS Robot_Sensors;
	MOTORS Robot_Motors;
	
    while (1)
    {
    	Robot_Sensors = readSensors();
    	
    	Robot_Motors = IA(Robot_Sensors);
    	
    	driveMotors(Robot_Motors);
    	
    	Sleep(2500);
    }
}

SENSORS readSensors(void)
{
	SENSORS Internal;
	
	int distancia1, distancia2, distancia3;
	
	srand((unsigned) time(NULL));
	
	distancia1 = rand() % 100;
	printf("%d\n", distancia1);
	if(distancia1<50) Internal.s1 = 1;
	else Internal.s1 = 0;

	distancia2 = rand() % 100;
	printf("%d\n", distancia1);
	if(distancia2<50) Internal.s2 = 1;
	else Internal.s2 = 0;

	distancia3 = rand() % 100;
	printf("%d\n", distancia1);
	if(distancia3<50) Internal.s3 = 1;
	else Internal.s3 = 0;
	
	return Internal;
}

MOTORS IA(SENSORS Sensors) 
{
	MOTORS Internal;
	
	if(Sensors.s1==0)
    {
		Internal.m1=1;
       	Internal.m2=1;
    }

    else
    {
	    if((Sensors.s2==0) && (Sensors.s3==0))
	    {
	        Internal.m1=1;
	    	Internal.m2=0;
	    }
	
	    if((Sensors.s2==1) && (Sensors.s3==0))
	    {
			Internal.m1=1;
	        Internal.m2=0;
	    }
	
	    if((Sensors.s2==0) && (Sensors.s3==1))
	    {
	        Internal.m1=0;
	        Internal.m2=1;
	    }
	
	    if((Sensors.s2==1) && (Sensors.s3==1))
	    {
	        Internal.m1=1;
	        Internal.m2=0;
	    }
	}
	
	return Internal;
}

void driveMotors(MOTORS Motors)
{
	if((Motors.m1==1) && (Motors.m2==1)) printf("m1 = %d / m2 = %d (FRENTE)  \n", Motors.m1, Motors.m2);
	if((Motors.m1==1) && (Motors.m2==0)) printf("m1 = %d / m2 = %d (ESQUERDA) \n", Motors.m1, Motors.m2);
	if((Motors.m1==0) && (Motors.m2==1)) printf("m1 = %d / m2 = %d (DIREITA) \n", Motors.m1, Motors.m2);
}
