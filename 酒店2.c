#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>

typedef struct GuestInfo{
char Name[10];
char ID[19];
char Sex[3];
int  roomNumber;
}GuestInfo;

GuestInfo guestInfo[100];

typedef struct HotelInfo{
char roomType[7];
int roomNumber;
int roomPrice;
char vacantOrOccupied;
}HotelInfo;

typedef struct HotelData{
int maxRoom ;
int currentCount;
}HotelData;

HotelData hotelData={100,0};

HotelInfo hotelInfo[100];

void proc();
void Welcome();
void printline();
void ViewHotelInfo();
void ViewOneRoom();
void ViewGuestInfo();
void ViewOneGuest();
void GuestCheckIn();
void GuestCheckOut();
void GuestChangeRoom();
void SaveGARInfo();
void SaveGuestInfo();
void SaveHotelInfo();
//欢迎标语
void Welcome(void)
{
    printf("欢迎使用本旅店信息管理系统!\n");
}
//来一点修饰
void printline(void)
{
    int i;
    for(i=0;i<27;i++)
        printf("*");
}

//进度条
void proc(void)
{
    printf("正在加载，请稍等。。。\n");
	int i = 0;
	for (i = 1; i <= 80; ++i)
	{
		printf("-");
	}
	fflush(stdout);
	for (i = 1; i <= 80; ++i)
	{
		printf("\b");
	}
	for (i = 1; i <= 80; ++i)
	{
		printf("*");
		fflush(stdout);
        Sleep(100);
	}
	printf("\n");
    system("cls");
}

//1：查看旅店信息
void ViewHotelInfo(void)
{
    int k;
    printline();
    printf("查看旅客信息");
    printline();
    printf("\n以下为酒店房间信息：\n房间类型 房间号 价格 是否有人住\n");
    for(k=0;k<100;k++)
    {
        printf("%s\t%d\t%d元\t%s\n", hotelInfo[k].roomType, hotelInfo[k].roomNumber, hotelInfo[k].roomPrice, hotelInfo[k].vacantOrOccupied == 'y' ? "有人":"无人");
    }
    printf("按任意键返回主菜单:\n");
    getch();
    system("cls");
}
//2：查看某一房间信息
void ViewOneRoom(void)
{
    int i;
    int roomNumber;
    int index=-1;//类似于flag
    printline();
    printf("查找房间");
    printline();
    printf("\n请输入要查找的房间号：\n");
    scanf("%d",&roomNumber);
    for(i=0;i<100;i++)
    {
        if(hotelInfo[i].roomNumber==roomNumber)
        index=i;//把用户输入的房间号与库存的数据关联在一起，只有是一致的才能输出
    }
    if(index==-1)
        printf("你输入的房间号不存在！\n");
    else
    {
        printf("房间类型 房间号 房间价格 是否有人住\n");
        printf("%s\t%d\t%d元\t%s\n", hotelInfo[index].roomType, hotelInfo[index].roomNumber, hotelInfo[index].roomPrice, hotelInfo[index].vacantOrOccupied == 'y' ? "有人":"无人");
    }
    printf("按任意键返回主菜单:\n");
    getch();
    system("cls");
}
//3.查看旅客信息
void ViewGuestInfo(void)
{
    int i;
    printline();
    printf("查看旅客信息");
    printline();
    if(guestInfo[0].roomNumber==0)
        printf("\n没有旅客入住！\n");
    else{
        printf("\n以下是旅客信息，分别为：\n姓名\t身份证号\t性别\t房间号\n");
        for(i=0;i<hotelData.currentCount;i++)
        {
            printf("%s\t%s\t%s\t%d\n",guestInfo[i].Name,guestInfo[i].ID,guestInfo[i].Sex,guestInfo[i].roomNumber);
        }
    }
    printf("按任意键返回主菜单:\n");
    getch();
    system("cls");
}
//4.查看某一旅客信息
void ViewOneGuest(void)
{
    char Name[10];
    int i;
    int j=-1;
    printline();
    printf("查看某一房间信息");
    printline();
    if(guestInfo[0].roomNumber==0)
        printf("\n没有旅客信息！\n");
    else{
        printf("\n请输入要查找的旅客姓名：\n");
        scanf("%s",Name);
        for(i=0;i<hotelData.currentCount;i++)
        {
            if(strcmp(guestInfo[i].Name,Name)==0)
            {
                j=i;
                break;
            }
        }
        if(j==-1)//消息树机制
        {
            printf("该旅客不存在！\n");
        }
        else{
            printf("以下为%s的信息：\n",guestInfo[j].Name);
            printf("姓名\t身份证号\t性别\t房间号\n");
            printf("%s\t%s\t%s\t%d\n",guestInfo[j].Name,guestInfo[j].ID,guestInfo[j].Sex,guestInfo[j].roomNumber);
        }
    }
    printf("按任意键返回主菜单:\n");
    getch();
    system("cls");
}

//5：旅客入住

void GuestCheckIn(void)
{
    int i,j;
    int roomNumber;
    int day;
    int fee;
    printline();
    printf("旅客入住");
    printline();
    if(hotelData.currentCount<hotelData.maxRoom)
    {
        printf("\n请输入旅客姓名，身份证号，性别\n");
        scanf("%s %s %s",guestInfo[hotelData.currentCount].Name,guestInfo[hotelData.currentCount].ID,guestInfo[hotelData.currentCount].Sex);
        printf("现在的空房间有以下：\n");

        for(i=0;i<100;i++)
        {
            if(hotelInfo[i].vacantOrOccupied=='n')
            {
                printf("%d ",hotelInfo[i].roomNumber);
            }
        }
        printf("\n请选择要入住的房间号:\n");
        //将旅客选择的房间设置为 “有人”
        scanf("%d",&guestInfo[hotelData.currentCount].roomNumber);//guestInfo里面第currentCount个的roomNumber
        switch(guestInfo[hotelData.currentCount].roomNumber/100)
        {
        case 1:
            hotelInfo[guestInfo[hotelData.currentCount].roomNumber-101].vacantOrOccupied='y';
            break;
        case 2:
            hotelInfo[guestInfo[hotelData.currentCount].roomNumber-181].vacantOrOccupied='y';
            break;
        case 3:
            hotelInfo[guestInfo[hotelData.currentCount].roomNumber-261].vacantOrOccupied='y';
            break;
        case 4:
            hotelInfo[guestInfo[hotelData.currentCount].roomNumber-341].vacantOrOccupied='y';
            break;
        case 5:
            hotelInfo[guestInfo[hotelData.currentCount].roomNumber-421].vacantOrOccupied='y';
            break;
        }

        printf("请输入要入住天数：\n");
        scanf("%d",&day);
        if(guestInfo[hotelData.currentCount].roomNumber>=101||guestInfo[hotelData.currentCount].roomNumber<=120)
            fee=day*80;
        if(guestInfo[hotelData.currentCount].roomNumber>=201||guestInfo[hotelData.currentCount].roomNumber<=220)
            fee=day*100;
        if(guestInfo[hotelData.currentCount].roomNumber>=301||guestInfo[hotelData.currentCount].roomNumber<=320)
            fee=day*100;
        if(guestInfo[hotelData.currentCount].roomNumber>=401||guestInfo[hotelData.currentCount].roomNumber<=420)
            fee=day*150;
        if(guestInfo[hotelData.currentCount].roomNumber>=501||guestInfo[hotelData.currentCount].roomNumber<=520)
            fee=day*150;
        printf("应付款：%d元\n",fee);
        printf("登记成功，欢迎入住！\n信息如下：\n\n");
        printf("姓名\t身份证号\t性别\t房间号\n");
        printf("%s\t%s\t%s\t%d\n",guestInfo[hotelData.currentCount].Name,guestInfo[hotelData.currentCount].ID,guestInfo[hotelData.currentCount].Sex,guestInfo[hotelData.currentCount].roomNumber);
        time_t now;
        struct tm *tm_now;
        time(&now);
        tm_now = localtime(&now) ;
        printf("登记时间: %d年%d月%d日 %d:%d:%d\n",tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
        hotelData.currentCount++;

    }
    else
        printf("抱歉，生意太好，客房都满了。");
    printf("\n按任意键返回主菜单:\n");
    getch();
    system("cls");
}

//旅客换房
void GuestChangeRoom(void)
{
    char Name[10];
    int i=0;
    int j=-1;
    char k[5];
    int roomNumber;
    printline();
    printf("旅客换房");
    printline();
    if(guestInfo[0].roomNumber==0)
        printf("\n没有旅客信息！\n");
    else{
    printf("\n请输入旅客的姓名：\n");
    scanf("%s",Name);
    for(i=0;i<hotelData.currentCount;i++)
    {
        if(strcmp(guestInfo[i].Name,Name)==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1)//消息树机制
    {
        printf("该旅客不存在！\n");
    }
    else{
        if(strcmp(guestInfo[j].Sex,"男")==0)
        strcpy(k,"先生");
        if(strcmp(guestInfo[j].Sex,"女")==0)
        strcpy(k,"女士");
        printf("尊敬的%s%s，您目前入住的房间是%d号\n",guestInfo[j].Name,k,guestInfo[j].roomNumber);
        printf("以下是所有的空房间：\n");
        for(i=0;i<100;i++)
        {
            if(hotelInfo[i].vacantOrOccupied=='n')
            {
                printf("%d ",hotelInfo[i].roomNumber);
            }
        }
        if(guestInfo[j].roomNumber>=101&&guestInfo[j].roomNumber<=120)
            printf("\n请输入要更换的新房间：(请在房间101~120之间选择)\n");
        if(guestInfo[j].roomNumber>=201&&guestInfo[j].roomNumber<=220)
            printf("\n请输入要更换的新房间：(请在房间201~220或者301~320之间选择)\n");
        if(guestInfo[j].roomNumber>=301&&guestInfo[j].roomNumber<=320)
            printf("\n请输入要更换的新房间：(请在房间201~220或者301~320之间选择)\n");
        if(guestInfo[j].roomNumber>=401&&guestInfo[j].roomNumber<=420)
            printf("\n请输入要更换的新房间：(请在房间401~420或者501~520之间选择)\n");
        if(guestInfo[j].roomNumber>=501&&guestInfo[j].roomNumber<=520)
            printf("\n请输入要更换的新房间：(请在房间401~420或者501~520之间选择)\n");
        scanf("%d",&roomNumber);
        for(i=0;i<100;i++){
            if(guestInfo[j].roomNumber==hotelInfo[i].roomNumber)
            {
                hotelInfo[i].vacantOrOccupied='n';
            }
            if(hotelInfo[i].roomNumber==roomNumber)
            {
                hotelInfo[i].vacantOrOccupied='y';
            }
        }
        guestInfo[j].roomNumber=roomNumber;
        printf("更换成功！\n");
    }
    }
    printf("按任意键返回主菜单:\n");
    getch();
    system("cls");
}


//旅客退房
void GuestCheckOut(void)
{
    char Name[10];
    int i=0;
    int j=-1;
    printline();
    printf("旅客退房");
    printline();
    if(guestInfo[0].roomNumber==0)
        printf("\n没有旅客信息！\n");
    else{
    printf("\n现有旅客登记数：%d\n\n",hotelData.currentCount);
    printf("请输入要退房旅客的姓名：\n");
    scanf("%s",Name);
    for(i=0;i<hotelData.currentCount;i++)
    {
        printf("%s",guestInfo[i].Name);
        if(strcmp(guestInfo[i].Name,Name) == 0)
            {
                j=i;
                break;
            }
    }
    if(j==-1)
        printf("该旅客不存在！\n");
    else{
        for(i=j;i<hotelData.currentCount-1;i++){
        strcpy(guestInfo[i].Name,guestInfo[i+1].Name);
        strcpy(guestInfo[i].ID,guestInfo[i+1].ID);
        strcpy(guestInfo[i].Sex,guestInfo[i+1].Sex);
        guestInfo[i].roomNumber=guestInfo[i+1].roomNumber;
        }

        for(i=0;i<100;i++){
            if(guestInfo[j].roomNumber==hotelInfo[i].roomNumber)
            {
                hotelInfo[i].vacantOrOccupied='n';
                break;
            }
        }
        hotelData.currentCount--;
        time_t now ;
        struct tm *tm_now ;
        time(&now) ;
        tm_now = localtime(&now) ;
        printf("%s退房成功！\n退房时间：%d-%d-%d %d:%d:%d\n欢迎下次光临！\n\n",guestInfo[i].Name,tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
    }
    }
    printf("\n按任意键返回主菜单:\n");
    getch();
    system("cls");
}
//主函数
void main(void)
{
    proc();
    FILE *fp;
    int i;
    if((fp=fopen("Hotel Information2.txt","rb"))==NULL)
    {
        printf("打开文件失败！\n");
        return;
    }
    for(i=0;i<100;i++)
    {
        fscanf(fp,"%s %d %d %c\n",hotelInfo[i].roomType,&hotelInfo[i].roomNumber,&hotelInfo[i].roomPrice,&hotelInfo[i].vacantOrOccupied);
    }
    fclose(fp);
    if((fp=fopen("Guest Information2.txt","rb"))==NULL)
    {
        printf("没有旅客入住记录！\n");
    }
    else
    {
        i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %s %d\n",guestInfo[i].Name,guestInfo[i].ID,guestInfo[i].Sex,&guestInfo[i].roomNumber);
            if(guestInfo[i].Name[0]=='\0')
            break;
            hotelData.currentCount++;
            i++;
        }
        fclose(fp);
    }

        printf("总客房数：%d\n旅馆现有登记数：%d\n",hotelData.maxRoom,hotelData.currentCount);
    do{
        printline();
        printf("\n");
        Welcome();
        printf("请选择功能：\n");
        printf(
               "1 查看旅店信息\n"
               "2 查看某一房间信息\n"
               "3 查看旅客信息\n"
               "4 查找某一旅客信息\n"
               "5 旅客入住\n"
               "6 旅客换房\n"
               "7 旅客退房\n"
               "8 保存并退出\n");
        printline();
        printf("\n");
        scanf("%d",&i);
        if(i<1||i>8)
            printf("你输入的有误！\n");
        else{
            switch(i){
            case 1:
                ViewHotelInfo();
                break;
            case 2:
                ViewOneRoom();
                break;
            case 3:
                ViewGuestInfo();
                break;
            case 4:
                ViewOneGuest();
                break;
            case 5:
                GuestCheckIn();
                break;
            case 6:
                GuestChangeRoom();
                break;
            case 7:
                GuestCheckOut();
                break;
            case 8:
                fp=fopen("Hotel Information2.txt","w");
                for(i=0;i<100;i++)
                {
                    fprintf(fp,"%s %d %d %c\n",hotelInfo[i].roomType,hotelInfo[i].roomNumber,hotelInfo[i].roomPrice,hotelInfo[i].vacantOrOccupied);
                }
                fclose(fp);
                if(hotelData.currentCount==0)
                {
                    printf("无旅客入住信息！\n");
                    fp=fopen("Guest Information2.txt","w");
                    fclose(fp);
                    getch();
                    system("cls");
                    exit(0);
                }
                else{
                    i=0;
                    printf("旅馆现有登记数为：%d\n",hotelData.currentCount);
                    fp=fopen("Guest Information2.txt","w");
                    for(i=0;i<hotelData.currentCount;i++)
                    {
                        fprintf(fp,"%s %s %s %d\n",guestInfo[i].Name,guestInfo[i].ID,guestInfo[i].Sex,guestInfo[i].roomNumber);
                    }
                    fclose(fp);
                    getch();
                    system("cls");
                    exit(0);
                }
            }
        }
    }while(1);
}
