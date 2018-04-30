#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MaxOyuncu 250
#define MaxTur 10
#define ROWS 250
#define COLS 5

void agilesirala(int , int ,int, int  [ROWS][COLS], int );
void agilesiralaTers(int , int ,int, int  [ROWS][COLS], int );

int main()
{
    system("color 17");
    system("title Bireysel Satranc Turnuvasi Yonetim Sistemi v1.0 BETA");

    int LNO,ELO,UKD,turSay;
    int OyuncuSAY=0;

    int siralamaTablosu[250][5]= {{0}};
    int i,j;

    for(i=0; i<250; i++)
        for(j=0; j<5; j++)
            siralamaTablosu[i][j]=-1;


    int x=0,y=0;

    printf("Oyuncunun lisans numarasini giriniz (bitirmek icin 0 ya da negatif giriniz):\n");
    scanf("%d",&LNO);

    if(LNO<1)
    {
        printf("Ilk oyuncunun lisans numarasi 1 den kucuk olamaz\n");
        do
        {
            printf("Oyuncunun lisans numarasini giriniz (bitirmek icin 0 ya da negatif giriniz):\n");
            scanf("%d",&LNO);
        }
        while(LNO<1);
    }

    do
    {

        siralamaTablosu[x][3]=LNO;
        y++;

        printf("Oyuncunun ELO sunu giriniz (en az 1000, yoksa 0):\n");
        scanf("%d",&ELO);

        if(ELO < 1000 && ELO!=0)
        {
            do
            {
                printf("Oyuncunun ELO sunu giriniz (en az 1000, yoksa 0):\n");
                scanf("%d",&ELO);
            }
            while (ELO < 1000 && ELO!=0);
        }

        siralamaTablosu[x][1]=ELO;
        y++;

        printf("Oyuncunun UKD sini giriniz (en az 1000, yoksa 0):\n");
        scanf("%d",&UKD);

        if(UKD < 1000 && UKD!=0)
        {
            do
            {
                printf("Oyuncunun UKD sini giriniz (en az 1000, yoksa 0):\n");
                scanf("%d",&UKD);
            }
            while (UKD < 1000  && UKD!=0);
        }

        siralamaTablosu[x][2]=UKD;
        siralamaTablosu[x][0]=0;
        x++;
        y=0;

        printf("Oyuncunun lisans numarasini giriniz (bitirmek icin 0 ya da negatif giriniz):\n");
        scanf("%d",&LNO);

        OyuncuSAY++;

        for (i=0; i<OyuncuSAY; i++)
        {
            if(siralamaTablosu[i][3]== LNO)
            {
                do
                {
                    printf("Bu lisans numarasina sahip baska bir oyuncu vardir\nLutgen baska bir LNO giriniz:\n");
                    scanf("%d",&LNO);

                    i=0;
                }
                while(siralamaTablosu[i][3]== LNO);
            }

        }


    }
    while(LNO > 0);


    agilesirala(0,OyuncuSAY,OyuncuSAY,siralamaTablosu,0);


    for(i=0; i<OyuncuSAY; i++)
    {
        if(siralamaTablosu[i][0]==siralamaTablosu[i+1][0])
        {
            int k=i;
            int elsay=1;
            while(1)
            {
                elsay++;

                if(siralamaTablosu[k][0]!=siralamaTablosu[k+1][0])
                    break;
                k++;
            }
            agilesirala(i,k,elsay,siralamaTablosu,1);
        }

    }


    for(i=0; i<OyuncuSAY; i++)
    {
        if(siralamaTablosu[i][1]==siralamaTablosu[i+1][1])
        {
            int k=i;
            int elsay=1;
            while(1)
            {
                elsay++;

                if(siralamaTablosu[k][1]!=siralamaTablosu[k+1][1])
                    break;
                k++;
            }
            agilesirala(i,k,elsay,siralamaTablosu,2);
        }

    }

    for(i=0; i<OyuncuSAY; i++)
    {
        if(siralamaTablosu[i][2]==siralamaTablosu[i+1][2])
        {
            int k=i;
            int elsay=1;
            while(1)
            {
                elsay++;

                if(siralamaTablosu[k][2]!=siralamaTablosu[k+1][2])
                    break;
                k++;
            }
            agilesirala(i,k,elsay,siralamaTablosu,3);
        }

    }

    for(i=0; i<OyuncuSAY; i++)
        siralamaTablosu[i][4]=i+1;


    x=0,j;

    printf("--------------------------------------------------------------------------------\n");
    printf("Baslangic Siralamasi:\n\n");
    printf("BSNo \t LNo \t ELO \t UKD\n");
    printf("---- \t ----- \t ----- \t -----\n");


    for(i=0; i<OyuncuSAY; i++)
    {

        printf(" %d \t ",siralamaTablosu[i][4]);
        printf(" %d \t ",siralamaTablosu[i][3]);
        printf(" %d \t ",siralamaTablosu[i][1]);
        printf(" %d \t ",siralamaTablosu[i][2]);

        printf("\n");
    }


    int renk;
    char basRenk;




    do
    {
        printf("Baslangic siralamasina gore ilk oyuncunun ilk turdaki rengini giriniz (b/s):\n");
        fflush(stdin);
        basRenk=getchar();

        if (basRenk == 'b')
            siralamaTablosu[0][5]==1;
        else if(basRenk == 's')
            siralamaTablosu[0][5]==2;

    }
    while(basRenk!= 'b'&& basRenk!= 's' );




    printf("Tur sayisini girin\n");
    scanf("%d",&turSay);

    /*int minTur;
    minTur=(int)ceil(log2(turSay));
    printf("%dtur",(int)ceil(log2(OyuncuSAY)));

    printf("\n%d mintur",minTur);
    printf("\n%d tursay",turSay);*/

    if(turSay<(int)ceil(log2(OyuncuSAY)) || turSay>10)
        {
            do
            {
                printf("Tur sayisi %d den kucuk 10 dan buyuk olamaz\n",(int)ceil(log2(OyuncuSAY)));
                scanf("%d",&turSay);

            }
            while(turSay<(int)ceil(log2(OyuncuSAY)) || turSay>10);

        }


    int s;
    for(s=0; s<turSay; s++)

    {




        if(OyuncuSAY %2 == 0)               ////////////////////
        {
            printf("--------------------------------------------------------------------------------\n");
            j=0;

            printf("%d.Tur Eslendirme Listesi:\n\n",i+1);

            printf("\t\tBeyazlar Siyahlar\n\n");
            printf("MNo \t BSNo \t LNo \t Puan - Puan \t LNo \t BSNo\n");
            printf("---- \t ----  \t-----  \t ----   ----\t ----- \t ----\n");

            do
            {
                printf("%d \t %d \t %d \t %d \t %d \t %d \t %d\n",j+1,siralamaTablosu[j][4],siralamaTablosu[j][3],siralamaTablosu[j][0],siralamaTablosu[j+1][0],siralamaTablosu[j+1][3],siralamaTablosu[j+1][4]);
                fflush(stdin);
                j+=2;
            }
            while(siralamaTablosu[j][3]!=-1);
        }
        else
        {
            int gecicioyuncuSay=OyuncuSAY-1;

            printf("--------------------------------------------------------------------------------\n");


            printf("%d.Tur Eslendirme Listesi:\n\n",i+1);

            printf("\t\tBeyazlar Siyahlar\n\n");
            printf("MNo \t BSNo \t LNo \t Puan - Puan \t LNo \t BSNo\n");
            printf("---- \t ----  \t-----  \t ----   ----\t ----- \t ----\n");

            int k;
            for(k=0; k<(int)(gecicioyuncuSay/2); k++)
            {
                printf("%d \t %d \t %d \t %.2f \t %.2f \t %d \t %d\n",k+1,siralamaTablosu[k][4],siralamaTablosu[k][3],(float)(siralamaTablosu[k][0]/2),(float)(siralamaTablosu[k+1][0]/2),siralamaTablosu[k+1][3],siralamaTablosu[k+1][4]);

            }

            printf("%d \t %d \t %d \t %d              BYE\n", k+1,siralamaTablosu[k][4],siralamaTablosu[k][3],siralamaTablosu[k][0]);
            if(siralamaTablosu[k][0]==-1)
                siralamaTablosu[k][0]=1;
            else
                siralamaTablosu[k][0]++;

        }


        int macSonucu,tekcift;

        if (OyuncuSAY%2==0) tekcift=OyuncuSAY;
        else tekcift=OyuncuSAY-1 ;

        int masaTur=1;

        for(i=0; i<tekcift; i+=2)
        {




            printf("%d. turda %d. masada oynanan macin sonucunu giriniz (0-5):\n",s+1,masaTur);
            scanf("%d",&macSonucu);

            if(macSonucu<0 || macSonucu>5)
            {
                do
                {
                    printf("oynanan macin sonucunu giriniz (0-5):\n");
                    scanf("%d",&macSonucu);

                }
                while(macSonucu<0 || macSonucu>5);

            }

            // beraberlige 1  galibiyete 2
            if (macSonucu == 0 )
            {
                siralamaTablosu[i][0]+=1;
                siralamaTablosu[i+1][0]+=1;

            }
            else if (macSonucu == 1 || macSonucu == 3 )
            {
                if(siralamaTablosu[i][5]==1)
                {
                    siralamaTablosu[i][0]+=2;
                }
                else
                    siralamaTablosu[i+1][0]+=2;


            }
            else if (macSonucu ==2 || macSonucu == 4 )
            {
                if(siralamaTablosu[i][5]==2)
                {
                    siralamaTablosu[i][0]+=2;
                }
                else
                    siralamaTablosu[i+1][0]+=2;

            }
            else if (macSonucu == 5 )
            {

            }




            masaTur++;
        }


        agilesirala(0,OyuncuSAY,OyuncuSAY,siralamaTablosu,0);


        for(i=0; i<OyuncuSAY; i++)
        {
            if(siralamaTablosu[i][0]==siralamaTablosu[i+1][0])
            {
                int k=i;
                int elsay=1;
                while(1)
                {
                    elsay++;

                    if(siralamaTablosu[k][0]!=siralamaTablosu[k+1][0])
                        break;
                    k++;
                }
                agilesirala(i,k,elsay,siralamaTablosu,1);
            }

        }


        for(i=0; i<OyuncuSAY; i++)
        {
            if(siralamaTablosu[i][1]==siralamaTablosu[i+1][1])
            {
                int k=i;
                int elsay=1;
                while(1)
                {
                    elsay++;

                    if(siralamaTablosu[k][1]!=siralamaTablosu[k+1][1])
                        break;
                    k++;
                }
                agilesirala(i,k,elsay,siralamaTablosu,2);
            }

        }

        for(i=0; i<OyuncuSAY; i++)
        {
            if(siralamaTablosu[i][2]==siralamaTablosu[i+1][2])
            {
                int k=i;
                int elsay=1;
                while(1)
                {
                    elsay++;

                    if(siralamaTablosu[k][2]!=siralamaTablosu[k+1][2])
                        break;
                    k++;
                }
                agilesirala(i,k,elsay,siralamaTablosu,3);
            }

        }
        ////////


    }












    return 0;
}


void agilesirala(int nerden, int nereye, int elsay, int dizi [ROWS][COLS], int neyegore)
{

    int gecici []= {0,0,0,0,0};
    int i,j;
    for(i=nerden; i<elsay-1; i++)
    {

        for (j=nerden; j<elsay-1-i; j++)
        {

            if(dizi[j][neyegore]<dizi[j+1][neyegore])
            {
                gecici[0]=dizi[j+1][0];
                gecici[1]=dizi[j+1][1];
                gecici[2]=dizi[j+1][2];
                gecici[3]=dizi[j+1][3];
                gecici[4]=dizi[j+1][4];

                dizi[j+1][0]=dizi[j][0];
                dizi[j+1][1]=dizi[j][1];
                dizi[j+1][2]=dizi[j][2];
                dizi[j+1][3]=dizi[j][3];
                dizi[j+1][4]=dizi[j][4];

                dizi[j][0]=gecici[0];
                dizi[j][1]=gecici[1];
                dizi[j][2]=gecici[2];
                dizi[j][3]=gecici[3];
                dizi[j][4]=gecici[4];

            }
        }
    }
}

void agilesiralaTers(int nerden, int nereye, int elsay, int dizi [ROWS][COLS], int neyegore)
{

    int gecici []= {0,0,0,0,0};
    int i,j;
    for(i=nerden; i<elsay-1; i++)
    {

        for (j=nerden; j<elsay-1-i; j++)
        {

            if(dizi[j][neyegore]>dizi[j+1][neyegore])
            {
                gecici[0]=dizi[j+1][0];
                gecici[1]=dizi[j+1][1];
                gecici[2]=dizi[j+1][2];
                gecici[3]=dizi[j+1][3];
                gecici[4]=dizi[j+1][4];

                dizi[j+1][0]=dizi[j][0];
                dizi[j+1][1]=dizi[j][1];
                dizi[j+1][2]=dizi[j][2];
                dizi[j+1][3]=dizi[j][3];
                dizi[j+1][4]=dizi[j][4];

                dizi[j][0]=gecici[0];
                dizi[j][1]=gecici[1];
                dizi[j][2]=gecici[2];
                dizi[j][3]=gecici[3];
                dizi[j][4]=gecici[4];

            }
        }
    }
}

