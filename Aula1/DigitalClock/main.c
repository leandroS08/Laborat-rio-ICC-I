#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    system("color 2");
    printf("C L O C K\n\n");

    int sec=0, min=0, hour=0;

    printf("Horario atual"); //introduz um horário inicial no qual o relógio programado começará
    printf("\nHora:");
    scanf("%d", &hour);
    while(hour<0||hour>=24)
    {
        printf("Invalido, digite novamente:");
        scanf("%d", &hour);
    }
    printf("Minuto:");
    scanf("%d", &min);
    while(min<0||min>=60)
    {
        printf("Invalido, digite novamente:");
        scanf("%d", &min);
    }
    printf("Segundo:");
    scanf("%d", &sec);
    while(sec<0||sec>=60)
    {
        printf("Invalido, digite novamente:");
        scanf("%d", &sec);
    }
    printf("\n\n");

    while(1)
    {
        printf("\r Horario: %2dh %2dmin %2ds", hour, min, sec);
        Sleep(1000);
        sec++;

        if(sec==60)
        {
            sec=0;
            min++;

            if(min==60)
            {
                min=0;
                hour++;

                if(hour==24)
                {
                    hour=0;
                }
            }
        }
    }


    system("pause");
    return 0;
}
