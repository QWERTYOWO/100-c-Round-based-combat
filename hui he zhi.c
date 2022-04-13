#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define enemyhp 30000
#define enemyatk 300
#define enemydef 500
int TitanAnnihilation(int player[]);
int zhanshi(int*,int*,int*,float*,float*);
int heimo(int*,float*,int*,float*,int*);
int baimo(int player[],float,float,float,float,float*,float*,float*,int*);
int shiren(int*,float*,float*,float*,int*);

int zhanshi(int *find,int *time_zs_1,int *time_zs_2,float *atk_rank,float *def_rank)
{   int use;
    printf("1.守护\n2.暴风斩\n3.原初的勇气\n使用 ");
    scanf("%d",&use);
    switch (use)
    {
    case 1:*find=1000;*time_zs_1=2;//提升仇恨，计时3
        printf("做出了战斗姿势，吸引了敌方的仇恨\n");
        break;
    case 2:*atk_rank=1.2;//获得攻击倍率
        printf("向前挥砍！\n");
        break;
    case 3:*def_rank=1.5;*time_zs_2=1;//获得防御倍率，计时2
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
    case 1:(*hm_cen)++;//黑魔纹层数+1
    printf("刻印夜之纹章，完成度%d层\n",*hm_cen);
        break;
    case 2:*atk_rank=3.0;//获得攻击倍率
        *find+=1;//仇恨+1
        printf("以太汇聚，在漆黑中爆发\n");
        if(*hm_cen>0)
        (*hm_cen)--;//消耗一层黑魔纹
        break;
    case 3:*dot=0.7;//获得dot伤害倍率
        *time=6;//dot计时7
        if(*hm_cen>0)
        (*hm_cen)--;//消耗一层黑魔纹
        printf("黑天之火，璨璨星尘！\n");
        break;
    }
    return 0;
}

int baimo(int player[],float zs_hp,float hm_hp,float bm_hp,float sr_hp,float *bmhp,float *bmall,float *bmatk,int *t)
{
    int use,chose,i;
    printf("1.救疗\n2.医治\n3.法令");
    if(*t<0)//向玩家展示cd
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
         switch (player[i])//向玩家展示当前目标序号及目标生命值
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
        printf("\n倾听元灵的告解\n");
        return chose;//返回选择目标
        *bmhp=3.0;//获得治疗倍率
        break;
    case 2:*bmall=0.8;//获得治疗倍率
    printf("\n--感受元灵的慰藉--\n");
        break;
    case 3:
    if(*t<0)
    {
        printf("\n--思考元灵的选择--\n");
        *bmall=2.0;//获得治疗倍率
        *bmatk=5.0;//获得攻击倍率
        *t=4;//获得cd，计时5
    }
    else
    printf("发动失败！\n");
        break;
    }
    return 0;
}

int shiren(int *t,float *sr_buff,float *sr_debuff,float *sr_atk,int *sr_use)
{
    int use;
    printf("1.终末之诗");
    if(*t<0)//向玩家展示cd
    printf("(准备就绪)");
    else
    printf("(cd:%d回合)",(*t)+1);
    printf("\n2.苍穹之诗\n3.红莲之诗\n使用");
    scanf("%d",&use);
    switch (use)
    {
    case 1:if(*t<0)
        {
            printf("\n且看终末之局，巴哈姆特，卫月坠星\n");
            *sr_buff=2.0;//获得激励倍率
            *t=1;//cd 2回合
        }
        else
        {
            printf("释放失败\n");
            break;
        }
        break;
    case 2:*sr_debuff=0.5;//获得削弱倍率
        printf("\n且看苍穹之上，尼德霍格，禁城龙诗\n");
        break;
    case 3:*sr_atk+=0.2;//逐渐提高伤害倍率
            *sr_use=1;//判定是不是用技能
        printf("\n且看帝国之领，阿拉米格，红莲奔袭\n");
        break;
    }
    return 0;
    
}

void main()
{   SetConsoleOutputCP(65001);
    int result;
    int teamn=0,n;
    int play[3]={0};
    int i=0;
    char chose;
   Sleep(500); printf("组建你的三人小队！\n");
  Sleep(500);  printf("战士     --1\n");
   Sleep(500); printf("黑魔法师 --2\n");
   Sleep(500); printf("白魔法师 --3\n");
    Sleep(500);printf("吟游诗人 --4\n");
    for(teamn=0;teamn<3;)
    {   printf("输入对应数字查看成员详情\n");
        printf("注:职业选择顺序会影响出手顺序！\n");
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
        Sleep(500);printf("技能组：\n1.守护[核心技能]：使敌方指向性技能以自身为目标，持续3回合\n2.暴风斩：对敌方单体造成相当于自身atk 120%%的伤害\n3.原初的勇气：两回合内将自身def提升至150%%\n4.天赋：仅一次，受到致死伤害时将hp回复至50%%\n");
       Sleep(500); printf("是否选择战士?(Y)\n");
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
       Sleep(500);printf("技能组：\n1.黑魔纹[核心技能]：获得一层atk提升100的buff，持续期间每次受到伤害减少一层\n2.秽浊：消耗一层黑魔纹，对敌方单体造成相当于自身atk 300%%的伤害，提高自身仇恨\n3.星火：消耗一层黑魔纹，为敌方单体附加灼火，持续7回合，每回合受到相当于自身70%%atk的伤害\n天赋；若上回合未受到伤害，黑魔纹层数+1，否则-1\n");
       Sleep(500); printf("是否选择黑魔法师?(Y)\n");
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
       Sleep(500); printf("技能组：\n1.救疗[核心技能]：回复指定队友相当于自身atk 300%%的hp\n2.医治：为己方全体回复相当于自身atk 80%%的hp\n3.法令：对己方全体回复相当于自身atk 200%%的hp，对对方全体造成相当于自身atk 500%%的真实伤害，每5回合只能使用一次\n天赋：治疗量的10%%转换为对敌方全体的真实伤害\n");
        Sleep(500);printf("是否选择白魔法师?(Y)\n");
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
      Sleep(500);  printf("技能组：\n1.终末之诗[核心技能]：全体友方单位获得激励效果，下一次使用攻击或治疗技能的最终效果翻倍，冷却时间2回合，可叠加\n2.苍穹之诗：直到下回合结束，使敌方单位def变为40%%，技能结束时敌方单位def回归原值\n3.红莲之诗：第一次造成相当于自身20%%atk的伤害，之后每次使用增加相当于自身40%%atk的伤害\n天赋：当自己为唯一存活的友方角色时，提升自身100%%攻击\n");
       Sleep(500); printf("是否选择吟游诗人?(Y)\n");
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
    if(result==1)//结果展示
    printf("\nWIN!!!\n");
    else
    printf("\nFALL~~\n");
    system("pause");
}

int TitanAnnihilation(int player[])
{   
    int i;//控制变量
    int dead_zs=1,dead_bm=1,dead_hm=1,dead_sr=1;                                              //死亡函数(为1时判定角色死亡)
    float enemy_hp=enemyhp,enemy_def=enemydef,enemy_atk=enemyatk;                             //boss基础属性变量
    float zs_hp=2000,zs_def=300,zs_atk=100,zs_hit;                                            //战士基础属性变量
    float bm_hp=800,bm_def=100,bm_atk=300,bm_hit; int find_bm=1;                                  //白魔基础属性及仇恨变量
    float hm_hp=800,hm_def=100,hm_atk=300,hm_hit;                                             //黑魔基础属性变量
    int find_hm=1,*p2=&find_hm,find_zs=1,*p1=&find_zs,real_zs_def;                            //黑魔和战士仇恨变量
    float sr_hp=1200,sr_def=200,sr_atk=200,find_sr=1;                                         //诗人基础属性及仇恨变量
    float zsmax=2000,bmmax=800,hmmax=800,srmax=1200;                                          //血量上限

    int time_zs_1=0,time_zs_2=0,*t_zs_1=&time_zs_1,*t_zs_2=&time_zs_2;                        //战士倒计时
    float zs_atk_rank=0,zs_def_rank=1,*zs_atk_zz=&zs_atk_rank,*zs_def_zz=&zs_def_rank;        //战士伤害和防御倍率
    int zs_fh=1;

    float hm_atk_rank=0,real_hm_atk=0,*hm_atk_zz=&hm_atk_rank,hm_dot_atk_rank=0,*hm_dot=&hm_dot_atk_rank;   //黑魔伤害倍率
    int heimowen=0,*hm_cen=&heimowen,time_hm=0,*t_hm=&time_hm;                                              //黑魔纹变量及黑魔倒计时
    int hitor=0;                                                                                            //判断是否被打(没被打为0)

    float bm_hps=0,*bm_hps_zz=&bm_hps,bm_all,*bm_all_zz=&bm_all,bm_atk_2,*bm_atk_zz=&bm_atk_2;            //白魔治疗倍率及攻击倍率
    int bm_chose,bm_time=0,*bm_t=&bm_time;                                                                //白魔目标选择，技能cd倒计时   
    float hps_totol=0;                                                                                    //白魔总治疗量

    float sr_atk_rank=0,sr_debuff_rank=0,sr_buff_rank=0,*sr_atk_zz=&sr_atk_rank,*sr_debuff=&sr_debuff_rank,*sr_buff=&sr_buff_rank;//诗人的伤害，buff，debuff
    int sr_cd=0,*sr_cd_zz=&sr_cd,sr_use=0,*sr_use_zz=&sr_use,sr_t=0;                                     //诗人技能cd及是否释放技能判定
    int sr_sr_buff=0,zs_sr_buff=0,bm_sr_buff=0,hm_sr_buff=0;                                                //诗人buff计次
    int sr_j=0;                                                                                         //诗人天赋计数

    float enemy_real_def=enemy_def;
    int boss_use=0,maxfind,max=-100;                                                                                     //boss技能相关
    time_t t1;
    time_t t2;
    long delay;
    char d[10];
    char str[6]={0};
    int j;//boss机制变量
    int boss_t=0;//boss行动延迟
    srand(time(NULL));
    printf("确认你的小队\n");
    for(i=0;i<3;i++)
    { 
        switch (player[i])
        {
        case 1:printf("战士 ");dead_zs=0;//令其死亡函数为0，即存活
            break;
        case 2:printf("黑魔法师 ");dead_hm=0;
            break;
        case 3:printf("白魔法师 ");dead_bm=0;
            break;
        case 4:printf("吟游诗人 ");dead_sr=0;
            break;
        }                                       
    }                                            //并输出职业选择结果
    printf("\n准备完成!\n\n\n");
    printf("  任务开始\n");
    printf("Mission Start!\n");
    printf("地灵族召唤出了蛮神泰坦！！！\n\n");

   while(1)
    {
        printf("泰坦 hp：%d\\30000\n\n",(int)enemy_hp);    //每回合展示一次双方状态
        for(i=0;i<3;i++)
    { 
        switch (player[i])
        {
        case 1:if(dead_zs==0) printf("战士 hp:%d\\2000\n",(int)zs_hp);
            break;
        case 2:if(dead_hm==0) printf("黑魔法师 hp:%d\\800\n",(int)hm_hp);
            break;
        case 3:if(dead_bm==0) printf("白魔法师 hp:%d\\800\n",(int)bm_hp);
            break;
        case 4:if(dead_sr==0) printf("吟游诗人 hp:%d\\1200\n",(int)sr_hp);
            break;
        }
        
    }                                             //回合初始状态显示
   

    printf("\n\n-------你的回合-------\n\n");
    {//战士初始化
        time_zs_1--;time_zs_2--;                      //倒计时计1
        if(time_zs_1==0) find_zs=1;                   //守护倒计时结束时调回仇恨
        if(time_zs_2==0) zs_def_rank=1;               //原初的勇气结束时调回def
        zs_atk_rank=0;  real_zs_def=500;              //倍率初始化
    } 
    {//黑魔初始化
        if(dead_hm==0)
       { hm_atk_rank=0;                                //倍率初始化
        time_hm--;                                    //倒计时计1
        if(time_hm==0) hm_dot_atk_rank=0;             //星火结束
        if(heimowen<0) heimowen=0;                    //黑魔纹层数不为负数
        if(hitor==0) heimowen++;else if(heimowen!=0) heimowen--;      //黑魔天赋判定
        printf("黑魔法师天赋发动，黑魔纹完成度%d层\n",heimowen);
        hitor=0;}//被打判定清空
    }                  
    {//白魔初始化
        bm_atk_2=0;                                   //攻击倍率初始化
        bm_all=0;                                     //群体治疗倍率初始化
        bm_hps=0;                                     //单体治疗倍率初始化
        hps_totol=0;                                  //总治疗量初始化
        bm_time--;                                    //倒计时计1
        bm_atk=300;                                   //诗人buff初始化
        max=-100;
    }
    {//诗人初始化
        sr_cd--;
        sr_use=0;                                     //不放攻击技能
        sr_debuff_rank=0;                             //削弱属性清空
        if(sr_t<=0) enemy_real_def=enemy_def;         //敌方防御恢复
        sr_buff_rank=0;                               //技能结束
        if(sr_j==0&&dead_bm==1&&dead_hm==1&&dead_zs==1&&dead_sr==0)
        {
            sr_atk=2000;sr_j++;
            printf("传承之诗！\n");
        }
        else sr_atk=200;                               //诗人天赋触发
    }
    for(i=0;i<3;i++)
    { 
        switch (player[i])
        {
        case 1:if(dead_zs==1) break;                                                //判定战士存活
            printf("\n战士\n");zhanshi(p1,t_zs_1,t_zs_2,zs_atk_zz,zs_def_zz);        //战士出手
            zs_hit=zs_atk*zs_atk_rank;                                              //战士伤害
            real_zs_def=real_zs_def*zs_def_rank;                                    //战士真实防御
            if(zs_atk_rank!=0)
            {   if(zs_sr_buff>0)//诗人buff加成
                {zs_sr_buff-=1;//诗人buff-1
                    if((zs_hit-enemy_real_def)>0)
                {enemy_hp-= 2 *zs_hit-enemy_real_def;                                        //战士破防伤害判定*2
                printf("战士造成了%d的伤害\n",(int)( 2 *zs_hit-enemy_real_def));}
                else
                {enemy_hp-=zs_hit*0.05;                                             //战士未破防伤害判定*2
                printf("未能破防，只造成了%d的伤害\n",(int)(zs_hit*0.05));
                }}
                else if((zs_hit-enemy_real_def)>0)
                {enemy_hp-=zs_hit-enemy_real_def;                                        //战士破防伤害判定
                printf("战士造成了%d的伤害\n",(int)(zs_hit-enemy_real_def));}
                else
                {enemy_hp-=zs_hit*0.05;                                             //战士未破防伤害判定
                printf("未能破防，只造成了%d的伤害\n",(int)(zs_hit*0.05));}
            }
            if(enemy_hp<=0) return 1;                                               //胜利判定
            break;

        case 2:if(dead_hm==1) break;                                                //判定黑魔存活
            printf("\n黑魔法师\n");heimo(hm_cen,hm_atk_zz,p2,hm_dot,t_hm);           //黑魔出手
            if(heimowen<0) heimowen=0;                                              //黑魔纹不为负数
            real_hm_atk=heimowen*100+hm_atk;                                        //黑魔真实攻击力
            hm_hit=real_hm_atk*(hm_atk_rank+hm_dot_atk_rank);                       //黑魔伤害
        if((hm_atk_rank+hm_dot_atk_rank)!=0)
        {   if(hm_sr_buff>0)//诗人buff
            {
                hm_sr_buff-=1;//诗人buff-1
                 if((hm_hit-enemy_real_def)>0)
            {enemy_hp-=2*hm_hit-enemy_real_def;                                            //2*黑魔破防伤害判定
            printf("黑魔法师造成了%d的伤害\n",(int)(2*hm_hit-enemy_real_def));}
            else
            {
                enemy_hp-=2*hm_hit*0.05;                                              //2*黑魔未破防伤害判定
                printf("未能破防，只造成了%d的伤害\n",(int)(2*hm_hit*0.05));
            }
            }
            else if((hm_hit-enemy_real_def)>0)
            {enemy_hp-=hm_hit-enemy_real_def;                                            //黑魔破防伤害判定
            printf("黑魔法师造成了%d的伤害\n",(int)(hm_hit-enemy_real_def));}
            else
            {
                enemy_hp-=hm_hit*0.05;                                              //黑魔未破防伤害判定
                printf("未能破防，只造成了%d的伤害\n",(int)(hm_hit*0.05));
            }
        }
            if(enemy_hp<=0) return 1;                                               //胜利判定
            break;

        case 3:if(dead_bm==1) break;                                                //判定白魔存活
        printf("\n白魔法师\n");bm_chose=baimo(player,zs_hp,hm_hp,bm_hp,sr_hp,bm_hps_zz,bm_all_zz,bm_atk_zz,bm_t);          //白魔出手
        if(bm_hps!=0)                                                               //救疗判定
        {if(bm_sr_buff>0){bm_sr_buff--;bm_atk*=2;}                                  //如果buff存在，治疗量翻倍
            switch (player[bm_chose-1])//选择目标
        {
        case 1:if(dead_zs==1)//判断治疗对象是否已经死亡
        {
            printf("治疗失败，目标已退场\n");
            break;
        }
        zs_hp+=bm_hps*bm_atk;hps_totol=bm_hps*bm_atk;//治疗，并计入总治疗量
            break;
        case 2:if(dead_hm==1)
        {
            printf("治疗失败，目标已退场\n");
            break;
        }
        hm_hp+=bm_hps*bm_atk;hps_totol=bm_hps*bm_atk;
            break;
        case 3:if(dead_bm==1)
        {
            printf("治疗失败，目标已退场\n");
            break;
        }
        bm_hp+=bm_hps*bm_atk;hps_totol=bm_hps*bm_atk;
            break;
        case 4:if(dead_sr==1)
        {
            printf("治疗失败，目标已退场\n");
            break;
        }
        sr_hp+=bm_hps*bm_atk;hps_totol=bm_hps*bm_atk;
            break;
        }
        printf("治疗量：%d\n",(int)(hps_totol));
        }

        if(bm_all!=0)                                                               //医治和法令判定
        {
            {if(bm_sr_buff>0){bm_sr_buff--;bm_all*=2;}                               //如果buff存在，治疗量翻倍
            if(dead_zs==0) {zs_hp+=bm_all*bm_atk;hps_totol+=bm_all*bm_atk;}         //治疗存活对象，并计入总治疗量
            if(dead_hm==0) {hm_hp+=bm_all*bm_atk;hps_totol+=bm_all*bm_atk;}
            if(dead_bm==0) {bm_hp+=bm_all*bm_atk;hps_totol+=bm_all*bm_atk;}
            if(dead_sr==0) {sr_hp+=bm_all*bm_atk;hps_totol+=bm_all*bm_atk;}
            }
            printf("治疗量：%d\n",(int)(hps_totol));
        }
        if(bm_atk_2!=0)
        {   
            bm_hit=bm_atk*bm_atk_2;
            enemy_hp-=bm_hit;                                                       //白魔伤害判定
            printf("白魔法师造成了%d的真实伤害\n",(int)bm_hit);
            
        }  if(hps_totol!=0)
        {
             enemy_hp-=hps_totol*0.1;
            printf("天赋触发！白魔法师造成了%d的真实伤害\n",(int)(hps_totol*0.1));
            }
           if(sr_hp>srmax)sr_hp=srmax;
            if(zs_hp>zsmax)zs_hp=zsmax;
            if(hm_hp>hmmax)hm_hp=hmmax;
            if(bm_hp>bmmax)bm_hp=bmmax;                                             //生命上限判定
            if(enemy_hp<=0) return 1;                                               //胜利判定
            break;
        case 4:if(dead_sr==1) break;                                                //判定诗人存活
        printf("\n吟游诗人\n");shiren(sr_cd_zz,sr_buff,sr_debuff,sr_atk_zz,sr_use_zz);
        {
            if(sr_debuff_rank!=0) {enemy_real_def*=sr_debuff_rank;sr_t=2;}                   //诗人减防判定
            if(sr_use==1)
            {   if(sr_sr_buff>0){sr_sr_buff--;sr_atk*=2;}//如果buff存在伤害翻倍
                if((sr_atk*sr_atk_rank)>enemy_real_def)
                {
                    enemy_hp-=sr_atk*sr_atk_rank-enemy_real_def; 
                    printf("吟游诗人造成了%d的伤害\n",(int)(sr_atk*sr_atk_rank-enemy_real_def));  //诗人破防伤害
                }
                else
                {
                    enemy_hp-=sr_atk*sr_atk_rank*0.05;
                    printf("未破防，吟游诗人造成了%d的伤害\n",(int)(sr_atk*sr_atk_rank));  //诗人未破防伤害
                }
            } 
            if(sr_buff_rank!=0)
            {
                zs_sr_buff+=1;bm_sr_buff+=1;sr_sr_buff+=1;hm_sr_buff+=1;//叠一层buff        
            }
            for(i=0;i<3;i++)//诗人buff层数展示
    { 
        switch (player[i])
        {
        case 1:printf("战士 终末之叹:%d层\n",zs_sr_buff);
            break;
        case 2:printf("黑魔法师 终末之叹:%d层\n",hm_sr_buff);
            break;
        case 3:printf("白魔法师 终末之叹:%d层\n",bm_sr_buff);
            break;
        case 4:printf("吟游诗人 终末之叹:%d层\n",sr_sr_buff);
            break;
        }
    }
            sr_t--;
            if(enemy_hp<=0) return 1;//胜利判定
            break;
        }                                       
    }
    }
    printf("\n\n-------敌方回合-------\n\n");
    if(boss_t==1){printf("核心受损，泰坦无法行动了！\n");boss_t--;continue;}
    boss_use=rand()%10+1;//boss随机使用技能
    if(boss_use>=1&&boss_use<=6)//一技能单体伤害
    {
        printf("泰坦对前方发动冲锋\n");
        if(dead_bm==0) {maxfind=3;max=find_bm;}         //按仇恨索敌
        if(dead_hm==0)if(find_hm>=max){maxfind=2;max=find_hm;}
        if(dead_zs==0)if(find_zs>=max){maxfind=1;max=find_zs;}
        if(dead_sr==0)if(find_sr>max){maxfind=4;max=find_sr;}
        switch (maxfind)
        {
        case 1:printf("冲向了战士，造成了%d的伤害！\n",(int)(enemy_atk*4-real_zs_def));
        zs_hp-=enemy_atk*2.2-real_zs_def;
            break;
        case 2:printf("冲向了黑魔法师，造成了%d的伤害！\n",(int)(enemy_atk*2.2-hm_def));
        hm_hp-=enemy_atk*2.2-hm_def;hitor++;//黑魔天赋
            break;
        case 3:printf("冲向了白魔法师，造成了%d的伤害！\n",(int)(enemy_atk*2.2-bm_def));
        bm_hp-=enemy_atk*2.2-bm_def;
            break;
        case 4:printf("冲向了吟游诗人，造成了%d的伤害！\n",(int)(enemy_atk*2.2-sr_def));
        sr_hp-=enemy_atk*2.2-sr_def;
            break;
        }
    }
    else if(boss_use>6&&boss_use<=9)
    {
        printf("泰坦高高跃起砸向大地！\n");
        for(i=0;i<3;i++)
    { 
        switch (player[i])
        {
        case 1:if(dead_zs==1) break;// 二技能群体伤害
        if((enemy_atk*0.8-real_zs_def)>0)
        {printf("战士受到了%d的伤害\n",(int)(enemy_atk*0.8-real_zs_def));
        zs_hp-=enemy_atk*0.8-real_zs_def;}//破防
        else{
            printf("未能动摇战士的坚城!战士受到了%d的伤害\n",(int)(enemy_atk*0.1));
            zs_hp-=enemy_atk*0.1;//未破防
        }
            break;

        case 2:if(dead_hm==1) break;hitor++;//黑魔天赋
        if((enemy_atk*0.8-hm_def)>0)
        {printf("黑魔法师受到了%d的伤害\n",(int)(enemy_atk*0.8-hm_def));
        hm_hp-=enemy_atk*0.8-hm_def;}//破防
        else{
            printf("未能动摇黑魔法师的道路!黑魔法师受到了%d的伤害\n",(int)(enemy_atk*0.1));
            hm_hp-=enemy_atk*0.1;//未破防
        }
            break;
        case 3:if(dead_bm==1) break;
        if((enemy_atk*0.8-bm_def)>0)
        {printf("白魔法师受到了%d的伤害\n",(int)(enemy_atk*0.8-bm_def));
        bm_hp-=enemy_atk*0.8-bm_def;}//破防
        else{
            printf("未能动摇白魔法师的决心!白魔法师受到了%d的伤害\n",(int)(enemy_atk*0.1));
            bm_hp-=enemy_atk*0.1;//未破防
            break;}

        case 4:if(dead_sr==1) break;
        if((enemy_atk*0.8-sr_def)>0)
        {printf("吟游诗人受到了%d的伤害\n",(int)(enemy_atk*0.8-sr_def));
        sr_hp-=enemy_atk*0.8-sr_def;}//破防
        else{
            printf("未能停滞吟游诗人的歌颂!吟游诗人受到了%d的伤害\n",(int)(enemy_atk*0.1));
            sr_hp-=enemy_atk*0.1;//未破防
            }
            break;
        
        }
        }
        }
        else if(boss_use==10)//三技能机制伤害
{
    printf("泰坦核心显露\n");
    for(j=0;j<4;j++)
    {
    str[j]=rand()%('z'-'a'+1)+'a';
    }
    printf("！即将进行一次高额伤害判定 ！\n");
    printf("请迅速输入对应字符来防御接下来的攻击\n");
    Sleep(1000);
    printf("3\n");
    Sleep(1000);
    printf("2\n");
    Sleep(1000);
    printf("1\n");
    Sleep(1000);
    printf("输入%s\n",str);
    t1=time(NULL);
    scanf("%s",&d);
    t2=time(NULL);
    delay=t2-t1;
    if(strcmp(d,str)==0)
    {
        if(delay<3)
            {
                printf("完美弹反！\n");
                printf("核心破坏，泰坦下回合无法行动了！\n");
                boss_t=1;
            }
        else if(delay<5&&delay>=3)
            {printf("防御成功！\n");}
        else {
            printf("防御失败！\n");
            printf("全队受到了高额伤害！\n");
            bm_hp-=500;
            hm_hp-=500;
            sr_hp-=500;
            zs_hp-=800;
            hitor++;
        }
        
    }
    else {
        printf("受到猛击！\n");
        printf("全队受到了巨额伤害！\n");
        bm_hp-=600;
        hm_hp-=600;
        sr_hp-=600;
        zs_hp-=1000;
    }


}
if(bm_hp<=0&&dead_bm==0){printf("白魔法师体力不支，倒下了！\n");dead_bm=1;}
if(zs_hp<=0&&zs_fh==1){printf("战斗续行！\n");zs_fh--;zs_hp=zsmax/2;}
if(zs_hp<=0&&zs_fh==0&&dead_zs==0){printf("战士体力不支，倒下了！");dead_zs=1;}
if(hm_hp<=0&&dead_hm==0){printf("黑魔法师体力不支，倒下了！\n");dead_hm=1;}
if(sr_hp<=0&&dead_sr==0){printf("吟游诗人体力不支，倒下了！\n");dead_sr=1;}
if(dead_bm==1&&dead_hm==1&&dead_zs==1&&dead_sr==1) return 0;
    }
return 0;
    
 }