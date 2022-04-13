#include <stdio.h>
#include <windows.h>
#define enemyhp 30000
#define enemyatk 300
#define enemydef 500
int TitanAnnihilation(int player[]);
int cheak_buff();
int cheak_debuff();
int cheak_enemyhp();
int cheak_youhp();
int zhanshi(int*,int*,int*,float*,float*);
int heimo(int*,float*,int*,float*,int*);
int baimo(int player[],float,float,float,float,float*,float*,float*,int*);
int shiren();
int boss();

int zhanshi(int *find,int *time_zs_1,int *time_zs_2,float *atk_rank,float *def_rank)
{   int use;
    printf("1.守护\n2.暴风斩\n3.原初的勇气\n使用 ");
    scanf("%d",&use);
    switch (use)
    {
    case 1:*find=1000;*time_zs_1=3;
        printf("做出了战斗姿势，吸引了敌方的仇恨\n");
        break;
    case 2:*atk_rank=1.2;
        printf("向前挥砍！\n");
        break;
    case 3:*def_rank=1.5;*time_zs_2=2;
        printf("做出了防御姿态\n");
        break;
    }
    return 0;
}

int heimo(int *hm_cen,float *atk_rank,int *find,float *dot,int *time)
{
    int use;
    printf("1.黑魔纹\n2.秽浊\n3.星火\n使用 ");
    scanf("%d",&use);
    switch (use)
    {
    case 1:(*hm_cen)++;
    printf("刻印夜之纹章，完成度%d层\n",*hm_cen);
        break;
    case 2:*atk_rank=3.0;
        *find+=1;
        printf("以太汇聚，在漆黑中爆发\n");
        break;
    case 3:*dot=0.3;
        *time=7;
        printf("黑天之火，璨璨星尘！\n");
        break;
    }
    return 0;
}

int baimo(int player[],float zs_hp,float hm_hp,float bm_hp,float sr_hp,float *bmhp,float *bmall,float *bmatk,int *t)
{
    int use,chose,i;
    printf("1.救疗\n2.医治\n3.法令");
    if(*t<0)
    printf("(准备就绪)");
    else
    printf("(cd:%d回合)",(*t)+1);
    printf("\n使用 ");
    scanf("%d",&use);
    
    switch (use)
    {
    case 1:
         for(i=0;i<3;i++)
         {
             printf("%d.",i+1);
         switch (player[i])
        {
        case 1:printf("战士 hp:%d\\2000\n",(int)zs_hp);
            break;
        case 2:printf("黑魔法师 hp:%d\\800\n",(int)hm_hp);
            break;
        case 3:printf("白魔法师 hp:%d\\800\n",(int)bm_hp);
            break;
        case 4:printf("吟游诗人 hp:%d\\1200\n",(int)sr_hp);
            break;
        }
        }
        printf("选择治疗目标\n");
        scanf("%d",&chose);
        printf("倾听元灵的告解\n");
        return chose;
        *bmhp=3.0;
        break;
    case 2:*bmall=0.8;
    printf("感受元灵的慰藉\n");
        break;
    case 3:
    if(*t<0)
    {
        printf("思考元灵的选择\n");
        *bmall=2.0;
        *bmatk=5.0;
        *t=4;
    }
    else
    printf("发动失败！\n");
        break;
    }
    return 0;
}
void main()
{
    int result;
    int teamn=0,n;
    int play[3]={0};
    int i=0;
    char chose;
    printf("组建你的三人小队！\n");
    printf("战士     --1\n");
    printf("黑魔法师 --2\n");
    printf("白魔法师 --3\n");
    printf("吟游诗人 --4\n");
    for(teamn=0;teamn<3;)
    {   printf("输入对应数字查看成员详情\n");
        scanf("%d",&n);
        if(n==play[0]||n==play[1]||n==play[2])//防止职业重复
        {
            printf("请勿选择重复职业\n");
            continue;
        }
    switch (n)                           //职业选择
    {
    case 1:
    {   printf("\n");
        printf("战士 ·无畏的担负者·\natk:100\ndef:500\nhp:2000\n");
        printf("技能组：\n1.守护[核心技能]：使敌方指向性技能以自身为目标，持续3回合\n2.暴风斩：对敌方单体造成相当于自身atk 120%%的伤害\n3.原初的勇气：两回合内将自身def提升至150%%\n");
        printf("是否选择战士?(Y)\n");
        getchar();
        scanf("%c",&chose);
        if(chose=='Y')
        {
            teamn++;                    //队员人数+1
            play[i++]=1;                //决定职业
        }
    }   
    continue;
    case 2:
    {   printf("\n");
        printf("黑魔法师 ·黑夜的探求者·\natk:300\ndef:100\nhp:800\n");
        printf("技能组：\n1.黑魔纹[核心技能]：获得一层atk提升200的buff，持续期间每次受到伤害减少一层\n2.秽浊：对敌方单体造成相当于自身atk 300%%的伤害，但提高自身仇恨\n3.星火：为敌方单体附加灼火，持续7回合，每回合受到相当于自身30%%atk的伤害\n被动技能；若上回合未受到伤害，本回合自身atk提升到150%%\n");
        printf("是否选择黑魔法师?(Y)\n");
        getchar();
        scanf("%c",&chose);
        if(chose=='Y')
        {
            teamn++;
           play[i++]=2;  
        }
    }
    continue;
    case 3:
    {   printf("\n");
        printf("白魔法师 ·白昼的聆听者·\natk:300\ndef:100\nhp:800\n");
        printf("技能组：\n1.救疗[核心技能]：回复指定队友相当于自身atk 300%%的hp\n2.医治：为己方全体回复相当于自身atk 80%%的hp\n3.法令：对己方全体回复相当于自身atk 200%%的hp，对对方全体造成相当于自身atk 5000%%的真实伤害，每5回合只能使用一次\n");
        printf("是否选择白魔法师?(Y)\n");
        getchar();
        scanf("%c",&chose);
        if(chose=='Y')
        {
            teamn++;
           play[i++]=3; 
        }
    }
    continue;
    case 4:
   {    printf("\n");
        printf("吟游诗人 ·传说的颂唱者·\natk:200\ndef:200\nhp:1200\n");
        printf("技能组：\n1.终末之诗[核心技能]：指定一个队友，使其下一次技能无视敌方防御\n2.苍穹之诗：使敌方单位def变为50%%，持续3回合\n3.红莲之诗：第一次造成相当于自身20%%atk的伤害，之后每次使用增加相当于自身40%%atk的伤害\n");
        printf("是否选择吟游诗人?(Y)\n");
        getchar();
        scanf("%c",&chose);
        if(chose=='Y')
        {
            teamn++;
           play[i++]=4;  
        }
    }
    continue;
    }
    }
    
    result=TitanAnnihilation(play);
    if(result==1)
    printf("WIN!!!\n");
    else
    printf("FALL~~\n");
    
}

int TitanAnnihilation(int player[])
{   
    int i;
    float enemy_hp=enemyhp,enemy_def=enemydef,enemy_atk=enemyatk;                                                              //变量行
    float zs_hp=2000,zs_def=500,zs_atk=100,find_zs=1,zs_hit;    
    float bm_hp=800,bm_def=100,bm_atk=300,find_bm=1,bm_hit;
    float hm_hp=800,hm_def=100,hm_atk=300,hm_hit;
    int find_hm=1,*p2=&find_hm,*p1=&find_zs,real_zs_def; 
    float sr_hp=1200,sr_def=200,sr_atk=200,find_sr=1;                                         //赋予初始属性  //find是仇恨值

    int time_zs_1=0,time_zs_2=0,*t_zs_1=&time_zs_1,*t_zs_2=&time_zs_2;                        //战士相关     //赋予战士buff倒计时
    float zs_atk_rank=0,zs_def_rank=1,*zs_atk_zz=&zs_atk_rank,*zs_def_zz=&zs_def_rank;

    float hm_atk_rank=0,real_hm_atk=0,*hm_atk_zz=&hm_atk_rank,hm_dot_atk_rank=0,*hm_dot=&hm_dot_atk_rank;   //黑魔相关 
    int heimowen=0,*hm_cen=&heimowen,time_hm=0,*t_hm=&time_hm;

    float bm_hps=0,*bm_hps_zz=&bm_hps,bm_all,*bm_all_zz=&bm_all,bm_atk_2,*bm_atk_zz=&bm_atk_2;              //白魔相关
    int bm_chose,bm_time=0,*bm_t=&bm_time;                                                                   
    printf("确认你的小队\n");
    for(i=0;i<3;i++)
    { 
        switch (player[i])
        {
        case 1:printf("战士 ");
            break;
        case 2:printf("黑魔法师 ");
            break;
        case 3:printf("白魔法师 ");
            break;
        case 4:printf("吟游诗人 ");
            break;
        }                                       
    }                                            //并输出职业选择结果
    printf("\n准备完成!\n\n\n");
    printf("  任务开始\n");
    printf("Mission Start!\n");
    printf("地灵族召唤出了蛮神泰坦！！！");

   while(1)
    {
        printf("泰坦 hp：%d\\30000\n\n",(int)enemy_hp);    
        for(i=0;i<3;i++)
    { 
        switch (player[i])
        {
        case 1:printf("战士 hp:%d\\2000\n",(int)zs_hp);
            break;
        case 2:printf("黑魔法师 hp:%d\\800\n",(int)hm_hp);
            break;
        case 3:printf("白魔法师 hp:%d\\800\n",(int)bm_hp);
            break;
        case 4:printf("吟游诗人 hp:%d\\1200\n",(int)sr_hp);
            break;
        }                                       
    }                                             //回合初始状态显示
   

    printf("-------你的回合-------");
    {//战士初始化
        time_zs_1--;time_zs_2--;                      //倒计时计1
        if(time_zs_1==0) find_zs=1;                   //守护倒计时结束时调回仇恨
        if(time_zs_2==0) zs_def_rank=1;               //原初的勇气结束时调回def
        zs_atk_rank=0;  real_zs_def=500;              //倍率初始化
    } 
    {//黑魔初始化
        hm_atk_rank=0;                                //倍率初始化
        time_hm--;                                    //倒计时计1
        if(time_hm==0) hm_dot_atk_rank=0;             //星火结束
    }                  
    {//白魔初始化
        bm_atk_2=0;                                   //攻击倍率初始化
        bm_all=0;                                     //群体治疗倍率初始化
        bm_hps=0;                                     //单体治疗倍率初始化
        bm_time--;                                    //倒计时计1
    }
    for(i=0;i<3;i++)
    { 
        switch (player[i])
        {
        case 1:printf("\n战士\n");zhanshi(p1,t_zs_1,t_zs_2,zs_atk_zz,zs_def_zz);    //战士出手
            zs_hit=zs_atk*zs_atk_rank;                                              //战士伤害
            real_zs_def=real_zs_def*zs_def_rank;                                    //战士真实防御
            if(zs_atk_rank!=0)
            {   if((zs_hit-enemy_def)>0)
                {enemy_hp-=zs_hit-enemy_def;                                        //战士破防伤害判定
                printf("战士造成了%d的伤害\n",(int)(zs_hit-enemy_def));}
                else
                {enemy_hp-=zs_hit*0.05;                                             //战士未破防伤害判定
                printf("未能破防，只造成了%d的伤害\n",(int)(zs_hit*0.05));}
            }
            break;
        case 2:printf("\n黑魔法师\n");heimo(hm_cen,hm_atk_zz,p2,hm_dot,t_hm);        //黑魔出手
            real_hm_atk=heimowen*200+hm_atk;                                        //黑魔真实攻击力
            hm_hit=real_hm_atk*(hm_atk_rank+hm_dot_atk_rank);                       //黑魔伤害
        if((hm_atk_rank+hm_dot_atk_rank)!=0)
        {   if((hm_hit-enemy_def)>0)
            {enemy_hp-=hm_hit-enemy_def;                                            //黑魔破防伤害判定
            printf("黑魔法师造成了%d的伤害\n",(int)(hm_hit-enemy_def));}
            else
            {
                enemy_hp-=hm_hit*0.05;                                              //黑魔未破防伤害判定
                printf("未能破防，只造成了%d的伤害\n",(int)(hm_hit*0.05));
            }
        }
            break;
        case 3:printf("\n白魔法师\n");bm_chose=baimo(player,zs_hp,hm_hp,bm_hp,sr_hp,bm_hps_zz,bm_all_zz,bm_atk_zz,bm_t);          //白魔出手
        if(bm_hps!=0)                                                               //救疗判定
        {
            switch (player[bm_chose-1])
        {
        case 1:zs_hp+=bm_hps*bm_atk;
            break;
        case 2:hm_hp+=bm_hps*bm_atk;
            break;
        case 3:bm_hp+=bm_hps*bm_atk;
            break;
        case 4:sr_hp+=bm_hps*bm_atk;
            break;
        }
        printf("治疗量：%d\n",(int)(bm_hps*bm_atk));
        }

        if(bm_all!=0)                                                               //医治和法令判定
        {
            {
            zs_hp+=bm_all*bm_atk;
            hm_hp+=bm_all*bm_atk;
            bm_hp+=bm_all*bm_atk;
            sr_hp+=bm_all*bm_atk;
            }
            printf("治疗量：%d\n",(int)(bm_all*bm_atk));
        }
        if(bm_atk_2!=0)
        {
            bm_hit=bm_atk*bm_atk_2;
            enemy_hp-=bm_hit;                                                       //白魔伤害判定
            printf("白魔法师造成了%d的真实伤害\n",(int)bm_hit);
        }
            break;
        case 4:printf("\n吟游诗人\n");
        {
            
        }
            break;

        }                                       
    }
    }
return 0;
}