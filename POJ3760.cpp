#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string name[5]= {"dragon","ninja","iceman","lion","wolf"};
int red_built[5]= {2,3,4,1,0};
int blue_built[5]= {3,0,1,2,4};
int time1[300],time2[300];
int built1,built2;
int attack[5];
int life_power[5];
int bh1,bh2;
struct Worrior
{
    int life;
    int attack;
    int kind;
    int number;
};
struct Fight
{
    Worrior w[3];   //1 win
    int reward;
    int flag;
    int iswin;
    int first;
    int whe;
    int fj;
    int v1;
}f[300];
int fnt;
struct City
{
    int flag; //0 §ß§é 1 ¨l§­ 2 §ð¨h
    int life_power;
    int ist[3];
    Worrior w[3];
    int last;
} city[30];
struct Mov
{
    int belong;
    int number;
    int from;
    int to;
    int life_power;
    int attack;
    int kind;
} mov[200];
struct Arrive //1 ºì·½µ½´ï
{
    int kind;
    int life_power;
    int attack;
    int number;
} arr[3];
int isarr[3];
int cnt;
int cmp(Mov a,Mov b)
{
    if (a.to!=b.to)return a.to<b.to;
    else return a.belong<b.belong;
}
struct Lead_place
{
    int enemynum;
    int life_power;
    int now;
    int number;
};
Lead_place red,blue;
int num_worr;
int main()
{
    int m,n,i,cas,t,op,rednum,kk,bluenum,minute,hour;
  //  freopen("out.txt","w",stdout);
    scanf("%d",&op);
    cas=0;
    while (op--)
    {
        memset(time1,0,sizeof(time1));
        memset(time2,0,sizeof(time2));
        bh1=0;
        bh2=0;
        scanf("%d%d%d",&m,&n,&t);
        built1=0;
        built2=0;
        for (i=0; i<5; i++)
            scanf("%d",&life_power[i]);
        for (i=0; i<5; i++)
            scanf("%d",&attack[i]);
        printf("Case:%d\n",++cas);
        red.enemynum=0;
        red.life_power=m;
        blue.enemynum=0;
        blue.life_power=m;
        rednum=0;
        bluenum=0;
        for (i=1; i<=n; i++)
        {
            city[i].flag=-1;
            city[i].life_power=0;
            city[i].ist[1]=-1;
            city[i].ist[2]=-1;
            city[i].last=-1;
        }
        int hour=0;
        minute=0;
        while (hour*60+minute<=t)
        {

            if (red.life_power>=life_power[red_built[built1]])
            {
                bh1++;
                red.number=bh1;
                red.now=red_built[built1];
                red.life_power-=life_power[red_built[built1]];
                printf("%03d:%02d red",hour,minute);
                cout<<" "<<name[red_built[built1]]<<" ";
                printf("%d born\n",bh1);
                built1=(built1+1)%5;
            }
            else red.now=-1;
            if (blue.life_power>=life_power[blue_built[built2]])
            {
                bh2++;
                blue.number=bh2;
                blue.now=blue_built[built2];
                blue.life_power-=life_power[blue_built[built2]];
                printf("%03d:%02d blue",hour,minute);
                cout<<" "<<name[blue_built[built2]]<<" ";
                printf("%d born\n",bh2);
                built2=(built2+1)%5;
            }
            else blue.now=-1;
            minute+=10;
            if (hour*60+minute>t)break;
            if (city[n].ist[1]>0)
            {
                arr[1].kind=city[n].w[1].kind;
                arr[1].life_power=city[n].w[1].life;
                arr[1].attack=city[n].w[1].attack;
                if (arr[1].kind==2&&((n+1)%2==0))
                {
                    arr[1].life_power=max(arr[1].life_power-9,1);
                    arr[1].attack+=20;
                }
                arr[1].number=city[n].w[1].number;
                isarr[1]=1;
                city[n].ist[1]=-1;
            }
            else isarr[1]=-1;
            if (city[1].ist[2]>0)
            {
                arr[2].kind=city[1].w[2].kind;
                arr[2].life_power=city[1].w[2].life;
                arr[2].attack=city[1].w[2].attack;
                if (arr[2].kind==2&&((n+1)%2==0))
                {
                    arr[2].life_power=max(arr[2].life_power-9,1);
                    arr[2].attack+=20;
                }
                arr[2].number=city[1].w[2].number;
                isarr[2]=1;
                city[1].ist[2]=-1;
            }
            else isarr[2]=-1;
            cnt=0;
            for (i=n-1; i>=1; i--)
            {
                if (city[i].ist[1]>0)
                {
                    if (city[i].w[1].kind==2&&(i+1)%2==0)
                    {
                        city[i].w[1].attack+=20;
                        city[i].w[1].life=max(city[i].w[1].life-9,1);
                    }
                    city[i].ist[1]=-1;
                    city[i+1].ist[1]=1;
                    cnt++;
                    mov[cnt].belong=1;
                    mov[cnt].from=i;
                    mov[cnt].to=i+1;
                    mov[cnt].number=city[i].w[1].number;
                    mov[cnt].kind=city[i].w[1].kind;
                    mov[cnt].attack=city[i].w[1].attack;
                    mov[cnt].life_power=city[i].w[1].life;
                    mov[cnt].number=city[i].w[1].number;
                    city[i+1].w[1]=city[i].w[1];
                }
            }
            for (i=2; i<=n; i++)
            {
                if (city[i].ist[2]>0)
                {
                    if (city[i].w[2].kind==2&&(n-i+2)%2==0)
                    {
                        city[i].w[2].attack+=20;
                        city[i].w[2].life=max(city[i].w[2].life-9,1);
                    }
                    city[i].ist[2]=-1;
                    city[i-1].ist[2]=1;
                    cnt++;
                    mov[cnt].belong=2;
                    mov[cnt].from=i;
                    mov[cnt].to=i-1;
                    mov[cnt].number=city[i].w[2].number;
                    mov[cnt].kind=city[i].w[2].kind;
                    mov[cnt].attack=city[i].w[2].attack;
                    mov[cnt].life_power=city[i].w[2].life;
                    mov[cnt].number=city[i].w[2].number;
                    city[i-1].w[2]=city[i].w[2];
                }
            }
            int fff=0;
            if (isarr[2]>0)
            {
                isarr[2]=-1;
                printf("%03d:%02d blue ",hour,minute);
                cout<<name[arr[2].kind];
                printf(" %d reached red headquarter with %d elements and force %d\n",arr[2].number,arr[2].life_power,arr[2].attack);
                red.enemynum++;
            }
            if (red.enemynum==2)
            {
                printf("%03d:%02d red headquarter was taken\n",hour,minute);
                fff=1;
            }
            if (red.now!=-1)
            {

                city[1].ist[1]=1;
                city[1].w[1].life=life_power[red.now];
                city[1].w[1].attack=attack[red.now];
                city[1].w[1].kind=red.now;
                city[1].w[1].number=red.number;
                printf("%03d:%02d red ",hour,minute);
                cout<<name[red.now];
                printf(" %d marched to city 1 with %d elements and force %d\n",red.number,life_power[red.now],attack[red.now]);
                red.now=-1;
            }
            sort(mov+1,mov+cnt+1,cmp);
            for (i=1; i<=cnt; i++)
            {
                printf("%03d:%02d ",hour,minute);
                if (mov[i].belong==1)printf("red ");
                else printf("blue ");
                cout<<name[mov[i].kind];
                printf(" %d marched to city %d with %d elements and force %d\n",mov[i].number,mov[i].to,mov[i].life_power,mov[i].attack);
            }
            if (blue.now!=-1)
            {

                city[n].ist[2]=1;
                city[n].w[2].life=life_power[blue.now];
                city[n].w[2].attack=attack[blue.now];
                city[n].w[2].kind=blue.now;
                city[n].w[2].number=blue.number;
                printf("%03d:%02d blue ",hour,minute);
                cout<<name[blue.now];
                printf(" %d marched to city %d with %d elements and force %d\n",blue.number,n,life_power[blue.now],attack[blue.now]);
                blue.now=-1;
            }
            if (isarr[1]>0)
            {
                isarr[1]=-1;
                printf("%03d:%02d red ",hour,minute);
                cout<<name[arr[1].kind];
                printf(" %d reached blue headquarter with %d elements and force %d\n",arr[1].number,arr[1].life_power,arr[1].attack);
                blue.enemynum++;
            }

            if (blue.enemynum==2)
            {
                printf("%03d:%02d blue headquarter was taken\n",hour,minute);
                break;
            }
            if (fff==1)break;
            minute+=10;
            if (hour*60+minute>t)break;
            for (i=1; i<=n; i++)
                city[i].life_power+=10;
            minute+=10;
            if (hour*60+minute>t)break;
            for (i=1; i<=n; i++)
            {
                if (city[i].ist[1]==city[i].ist[2])continue;
                if (city[i].ist[1]==1)
                {
                    printf("%03d:%02d red ",hour,minute);
                    cout<<name[city[i].w[1].kind];
                    printf(" %d earned %d elements for his headquarter\n",city[i].w[1].number,city[i].life_power);
                    red.life_power+=city[i].life_power;
                    city[i].life_power=0;
                }
                else
                {
                    printf("%03d:%02d blue ",hour,minute);
                    cout<<name[city[i].w[2].kind];
                    printf(" %d earned %d elements for his headquarter\n",city[i].w[2].number,city[i].life_power);
                    blue.life_power+=city[i].life_power;
                    city[i].life_power=0;
                }
            }
            minute+=10;
            if (hour*60+minute>t)break;
            fnt=0;
            for (i=1; i<=n; i++)
            {
                if (city[i].ist[1]==1&&city[i].ist[2]==1)
                {
                    int v1=city[i].w[1].life;
                    int v2=city[i].w[2].life;
                    if (city[i].flag==1||(city[i].flag==-1&&i%2==1))  //red first
                    {
                        city[i].w[2].life-=city[i].w[1].attack;
                        if (city[i].w[2].life<=0)
                        {
                            city[i].ist[2]=-1;
                            fnt++;
                            f[fnt].fj=-1;
                            f[fnt].whe=i;
                            f[fnt].first=1;
                            f[fnt].reward=0;
                            f[fnt].w[1]=city[i].w[1];
                            f[fnt].w[2]=city[i].w[2];
                            f[fnt].iswin=1;
                            f[fnt].flag=-1;
                            if (city[i].flag!=1)
                            {
                                city[i].flag=-1;
                                if (city[i].last!=1)
                                    city[i].last=1;
                                else
                                {
                                    f[fnt].flag=1;
                                    city[i].flag=1;
                                }
                            }
                            time1[city[i].w[1].number]++;
                            if (city[i].w[1].kind==4&&time1[city[i].w[1].number]%2==0)
                            {
                                city[i].w[1].attack*=2;
                                city[i].w[1].life*=2;
                            }
                            if (city[i].w[2].kind==3)
                            {
                                city[i].w[1].life+=v2;
                            }
                        }
                        else
                        {
                            if (city[i].w[2].kind==1)
                            {
                                fnt++;
                                f[fnt].fj=-1;
                                f[fnt].whe=i;
                                f[fnt].first=1;
                                f[fnt].reward=0;
                                f[fnt].w[1]=city[i].w[1];
                                f[fnt].w[2]=city[i].w[2];
                                f[fnt].iswin=-1;
                                f[fnt].flag=-1;
                                city[i].last=-1;
                                continue;
                            }
                            else
                            {
                                int a1=city[i].w[2].attack/2;
                                city[i].w[1].life-=a1;
                                if (city[i].w[1].life<=0)
                                {
                                    fnt++;
                                    city[i].ist[1]=-1;

                                    f[fnt].fj=1;
                                    f[fnt].whe=i;
                                    f[fnt].first=1;
                                    f[fnt].reward=0;
                                    f[fnt].w[1]=city[i].w[1];
                                    f[fnt].w[2]=city[i].w[2];
                                    f[fnt].iswin=2;
                                    f[fnt].flag=-1;
                                    if (city[i].flag!=2)
                                    {
                                        city[i].flag=-1;
                                        if (city[i].last!=2)
                                            city[i].last=2;
                                        else
                                        {
                                            f[fnt].flag=2;
                                            city[i].flag=2;
                                        }
                                    }
                                    if (city[i].w[1].kind==3)
                                    {
                                        city[i].w[2].life+=v1;
                                    }
                                }
                                else
                                {
                                    fnt++;
                                    f[fnt].fj=1;
                                    f[fnt].whe=i;
                                    f[fnt].first=1;
                                    f[fnt].reward=0;
                                    f[fnt].w[1]=city[i].w[1];
                                    f[fnt].w[2]=city[i].w[2];
                                    f[fnt].iswin=-1;
                                    f[fnt].flag=-1;
                                    city[i].last=-1;
                                }
                            }
                        }
                    }
                    else
                    {
                        city[i].w[1].life-=city[i].w[2].attack;
                        if (city[i].w[1].life<=0)
                        {
                            city[i].ist[1]=-1;
                            fnt++;
                            f[fnt].fj=-1;
                            f[fnt].whe=i;
                            f[fnt].first=2;
                            f[fnt].reward=0;
                            f[fnt].w[1]=city[i].w[1];
                            f[fnt].w[2]=city[i].w[2];
                            f[fnt].iswin=2;
                            f[fnt].flag=-1;
                            if (city[i].flag!=2)
                            {

                                city[i].flag=-1;
                                if (city[i].last!=2)
                                    city[i].last=2;
                                else
                                {
                                    f[fnt].flag=2;
                                    city[i].flag=2;
                                }
                            }
                            time2[city[i].w[2].number]++;
                            if (city[i].w[2].kind==4&&time2[city[i].w[2].number]%2==0)
                            {
                                city[i].w[2].attack*=2;
                                city[i].w[2].life*=2;
                            }
                            if (city[i].w[1].kind==3)
                            {
                                city[i].w[2].life+=v1;
                            }
                        }
                        else
                        {
                            if (city[i].w[1].kind==1)
                            {
                                fnt++;
                                f[fnt].fj=-1;
                                f[fnt].whe=i;
                                f[fnt].first=2;
                                f[fnt].reward=0;
                                f[fnt].w[1]=city[i].w[1];
                                f[fnt].w[2]=city[i].w[2];
                                f[fnt].iswin=-1;
                                f[fnt].flag=-1;
                                city[i].last=-1;
                                continue;
                            }
                            else
                            {
                                int a1=city[i].w[1].attack/2;
                                city[i].w[2].life-=a1;
                                if (city[i].w[2].life<=0)
                                {
                                    city[i].ist[2]=-1;
                                    fnt++;
                                    f[fnt].fj=1;
                                    f[fnt].whe=i;
                                    f[fnt].first=2;
                                    f[fnt].reward=0;
                                    f[fnt].w[1]=city[i].w[1];
                                    f[fnt].w[2]=city[i].w[2];
                                    f[fnt].iswin=1;
                                    f[fnt].flag=-1;
                                    if (city[i].flag!=1)
                                    {

                                        city[i].flag=-1;
                                        if (city[i].last!=1)
                                            city[i].last=1;
                                        else
                                        {
                                            f[fnt].flag=1;
                                            city[i].flag=1;
                                        }
                                    }
                                    if (city[i].w[2].kind==3)
                                    {
                                        city[i].w[1].life+=v2;
                                    }
                                }
                                else
                                {
                                    fnt++;
                                    f[fnt].fj=1;
                                    f[fnt].whe=i;
                                    f[fnt].first=2;
                                    f[fnt].reward=0;
                                    f[fnt].w[1]=city[i].w[1];
                                    f[fnt].w[2]=city[i].w[2];
                                    f[fnt].iswin=-1;
                                    f[fnt].flag=-1;
                                    city[i].last=-1;
                                }
                            }
                        }
                    }
                }
            }
            for (i=fnt; i>=1; i--)
            {
                if (f[i].iswin==1)
                {
                    if (red.life_power>=8)
                    {
                        f[i].reward=8;
                        red.life_power-=8;
                        city[f[i].whe].w[1].life+=8;
                    }
                    else break;
                }
            }
            for (i=1; i<=fnt;i++)
            {
                if (f[i].iswin==2)
                {
                    if (blue.life_power>=8)
                    {
                        f[i].reward=8;
                        blue.life_power-=8;
                        city[f[i].whe].w[2].life+=8;
                    }
                    else break;
                }
            }
            for (i=1; i<=fnt; i++)
            {
                if (f[i].first==1)
                {
                    if (f[i].iswin==1)
                    {
                        printf("%03d:%02d red ",hour,minute);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d attacked blue ",f[i].w[1].number);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d in city %d with %d elements and force %d\n",f[i].w[2].number,f[i].whe,f[i].w[1].life,f[i].w[1].attack);
                        printf("%03d:%02d blue ",hour,minute);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d was killed in city %d\n",f[i].w[2].number,f[i].whe);
                        if (f[i].w[1].kind==0)
                        {
                            printf("%03d:%02d red dragon %d yelled in city %d\n",hour,minute,f[i].w[1].number,f[i].whe);
                        }
                        printf("%03d:%02d red ",hour,minute);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d earned %d elements for his headquarter\n",f[i].w[1].number,city[f[i].whe].life_power);
                        red.life_power+=city[f[i].whe].life_power;
                        city[f[i].whe].life_power=0;
                        if (f[i].flag==1)
                            printf("%03d:%02d red flag raised in city %d\n",hour,minute,f[i].whe);
                    }
                    else if (f[i].iswin==2)
                    {
                        printf("%03d:%02d red ",hour,minute);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d attacked blue ",f[i].w[1].number);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d in city %d with %d elements and force %d\n",f[i].w[2].number,f[i].whe,f[i].w[1].life+f[i].w[2].attack/2,f[i].w[1].attack);
                        printf("%03d:%02d blue ",hour,minute);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d fought back against red ",f[i].w[2].number);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d in city %d\n",f[i].w[1].number,f[i].whe);
                        printf("%03d:%02d red ",hour,minute);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d was killed in city %d\n",f[i].w[1].number,f[i].whe);
                        printf("%03d:%02d blue ",hour,minute);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d earned %d elements for his headquarter\n",f[i].w[2].number,city[f[i].whe].life_power);
                        blue.life_power+=city[f[i].whe].life_power;
                        city[f[i].whe].life_power=0;
                        if (f[i].flag==2)
                            printf("%03d:%02d blue flag raised in city %d\n",hour,minute,f[i].whe);
                    }
                    else
                    {
                        if (f[i].fj>0)kk=f[i].w[2].attack/2;else kk=0;
                        printf("%03d:%02d red ",hour,minute);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d attacked blue ",f[i].w[1].number);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d in city %d with %d elements and force %d\n",f[i].w[2].number,f[i].whe,f[i].w[1].life+kk,f[i].w[1].attack);
                        if (f[i].fj>0)
                        {
                            printf("%03d:%02d blue ",hour,minute);
                            cout<<name[f[i].w[2].kind];
                            printf(" %d fought back against red ",f[i].w[2].number);
                            cout<<name[f[i].w[1].kind];
                            printf(" %d in city %d\n",f[i].w[1].number,f[i].whe);
                        }
                        if (f[i].w[1].kind==0)
                        {
                            printf("%03d:%02d red dragon %d yelled in city %d\n",hour,minute,f[i].w[1].number,f[i].whe);
                        }
                    }
                }
                else
                {
                    if (f[i].iswin==2)
                    {
                        printf("%03d:%02d blue ",hour,minute);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d attacked red ",f[i].w[2].number);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d in city %d with %d elements and force %d\n",f[i].w[1].number,f[i].whe,f[i].w[2].life,f[i].w[2].attack);
                        printf("%03d:%02d red ",hour,minute);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d was killed in city %d\n",f[i].w[1].number,f[i].whe);
                        if (f[i].w[2].kind==0)
                        {
                            printf("%03d:%02d blue dragon %d yelled in city %d\n",hour,minute,f[i].w[2].number,f[i].whe);
                        }
                        printf("%03d:%02d blue ",hour,minute);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d earned %d elements for his headquarter\n",f[i].w[2].number,city[f[i].whe].life_power);
                        blue.life_power+=city[f[i].whe].life_power;
                        city[f[i].whe].life_power=0;
                        if (f[i].flag==2)
                            printf("%03d:%02d blue flag raised in city %d\n",hour,minute,f[i].whe);
                    }
                    else if (f[i].iswin==1)
                    {
                        printf("%03d:%02d blue ",hour,minute);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d attacked red ",f[i].w[2].number);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d in city %d with %d elements and force %d\n",f[i].w[1].number,f[i].whe,f[i].w[2].life+f[i].w[1].attack/2,f[i].w[2].attack);
                        printf("%03d:%02d red ",hour,minute);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d fought back against blue ",f[i].w[1].number);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d in city %d\n",f[i].w[2].number,f[i].whe);
                        printf("%03d:%02d blue ",hour,minute);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d was killed in city %d\n",f[i].w[2].number,f[i].whe);
                        printf("%03d:%02d red ",hour,minute);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d earned %d elements for his headquarter\n",f[i].w[1].number,city[f[i].whe].life_power);
                        red.life_power+=city[f[i].whe].life_power;
                        city[f[i].whe].life_power=0;
                        if (f[i].flag==1)
                            printf("%03d:%02d red flag raised in city %d\n",hour,minute,f[i].whe);
                    }
                    else
                    {
                        if (f[i].fj>0)kk=f[i].w[1].attack/2;else kk=0;
                        printf("%03d:%02d blue ",hour,minute);
                        cout<<name[f[i].w[2].kind];
                        printf(" %d attacked red ",f[i].w[2].number);
                        cout<<name[f[i].w[1].kind];
                        printf(" %d in city %d with %d elements and force %d\n",f[i].w[1].number,f[i].whe,f[i].w[2].life+kk,f[i].w[2].attack);
                        if (f[i].fj>0)
                        {
                            printf("%03d:%02d red ",hour,minute);
                            cout<<name[f[i].w[1].kind];
                            printf(" %d fought back against blue ",f[i].w[1].number);
                            cout<<name[f[i].w[2].kind];
                            printf(" %d in city %d\n",f[i].w[2].number,f[i].whe);
                        }
                         if (f[i].w[2].kind==0)
                        {
                            printf("%03d:%02d blue dragon %d yelled in city %d\n",hour,minute,f[i].w[2].number,f[i].whe);
                        }
                    }
                }

            }
            minute+=10;
            if (hour*60+minute>t)break;
            printf("%03d:%02d %d elements in red headquarter\n",hour,minute,red.life_power);
            printf("%03d:%02d %d elements in blue headquarter\n",hour,minute,blue.life_power);
            minute=0;
            hour++;
        }

    }
    return 0;
}
