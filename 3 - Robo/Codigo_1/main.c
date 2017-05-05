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

int s1=0, s2=0, s3=0; // sensores
int m1=0, m2=0; // motores

void readSensors(void); // função para ler os sensores, alterando as variaveis globais s1, s2 e s3, sem retornar nenhum valor, portanto.

void IA(void); // função de processamento dos dados

void driveMotors(void); // função de tomada de decisões

int main()
{
    while (1)
    {
    	readSensors();
    	
    	IA();
    	
    	driveMotors();
    	
    	Sleep(2500);
    }
}

void readSensors(void)
{
	srand(time(NULL));
	
	int distancia1, distancia2, distancia3;
	
	distancia1 = rand() % 400;
	if(distancia1<50) s1 = 1;
	else s1 = 0;
	
	distancia2 = rand() % 400;
	if(distancia2<50) s2 = 1;
	else s2 = 0;
	
	distancia3 = rand() % 400;
	if(distancia3<50) s3 = 1;
	else s3 = 0;
}

void IA(void) 
{
	if((s1==0) && (s2==0) && (s3==0))
    {
		m1=1;
        m2=1;
    }

    if((s1==0) && (s2==0) && (s3==1))
    {
        m1=1;
        m2=1;
    }

    if((s1==0) && (s2==1) && (s3==0))
    {
		m1=1;
        m2=1;
    }

    if((s1==0) && (s2==1) && (s3==1))
    {
        m1=1;
        m2=1;
    }

    if((s1==1) && (s2==0) && (s3==0))
    {
        m1=1;
    	m2=0;
    }

    if((s1==1) && (s2==1) && (s3==0))
    {
		m1=1;
        m2=0;
    }

    if((s1==0) && (s2==0) && (s3==1))
    {
        m1=0;
        m2=1;
    }

    if((s1==0) && (s2==1) && (s3==1))
    {
        m1=1;
        m2=0;
    }
	
}

void driveMotors(void)
{
	if((m1==1) && (m2==1)) printf("m1 = %d / m2 = %d (FRENTE)  \n", m1, m2);
	if((m1==1) && (m2==0)) printf("m1 = %d / m2 = %d (ESQUERDA) \n", m1, m2);
	if((m1==0) && (m2==1)) printf("m1 = %d / m2 = %d (DIREITA) \n", m1, m2);
}
