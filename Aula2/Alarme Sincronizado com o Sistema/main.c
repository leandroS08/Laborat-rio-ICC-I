#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main()
{
    system("color 2");
    printf("A L A R M E\n\n");


    int alarme_sec=0, alarme_min=0, alarme_hour=0;

    printf("Horario do alarme"); //le o horario do alarme
    printf("\nHora:");
    scanf("%d", &alarme_hour);
    while(alarme_hour<0||alarme_hour>=24)
    {
        printf("Invalido, digite novamente:");
        scanf("%d", &alarme_hour);
    }
    printf("Minuto:");
    scanf("%d", &alarme_min);
    while(alarme_min<0||alarme_min>=60)
    {
        printf("Invalido, digite novamente:");
        scanf("%d", &alarme_min);
    }
    printf("Segundo:");
    scanf("%d", &alarme_sec);
     while(alarme_sec<0||alarme_sec>=60)
    {
        printf("Invalido, digite novamente:");
        scanf("%d", &alarme_sec);
    }
    printf("\n\n");


    int sec=0, min=0, hour=0;

    struct tm *local;
    time_t t;
    t= time(NULL);
    local=localtime(&t);

    sec=local->tm_sec;
    min=local->tm_min;
    hour=local->tm_hour;


    while(1)
    {
        printf("\r Horario: %2dh %2dmin %2ds", hour, min, sec);

        if((hour==alarme_hour)&&(min==alarme_min)&&(sec==alarme_sec))
        {
            printf("\n *****A L A R M E******\n\n");
            PlaySound("despertador.wav", NULL, SND_ASYNC);
        }

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


