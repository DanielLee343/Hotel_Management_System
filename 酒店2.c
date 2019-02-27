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
//��ӭ����
void Welcome(void)
{
    printf("��ӭʹ�ñ��õ���Ϣ����ϵͳ!\n");
}
//��һ������
void printline(void)
{
    int i;
    for(i=0;i<27;i++)
        printf("*");
}

//������
void proc(void)
{
    printf("���ڼ��أ����Եȡ�����\n");
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

//1���鿴�õ���Ϣ
void ViewHotelInfo(void)
{
    int k;
    printline();
    printf("�鿴�ÿ���Ϣ");
    printline();
    printf("\n����Ϊ�Ƶ귿����Ϣ��\n�������� ����� �۸� �Ƿ�����ס\n");
    for(k=0;k<100;k++)
    {
        printf("%s\t%d\t%dԪ\t%s\n", hotelInfo[k].roomType, hotelInfo[k].roomNumber, hotelInfo[k].roomPrice, hotelInfo[k].vacantOrOccupied == 'y' ? "����":"����");
    }
    printf("��������������˵�:\n");
    getch();
    system("cls");
}
//2���鿴ĳһ������Ϣ
void ViewOneRoom(void)
{
    int i;
    int roomNumber;
    int index=-1;//������flag
    printline();
    printf("���ҷ���");
    printline();
    printf("\n������Ҫ���ҵķ���ţ�\n");
    scanf("%d",&roomNumber);
    for(i=0;i<100;i++)
    {
        if(hotelInfo[i].roomNumber==roomNumber)
        index=i;//���û�����ķ������������ݹ�����һ��ֻ����һ�µĲ������
    }
    if(index==-1)
        printf("������ķ���Ų����ڣ�\n");
    else
    {
        printf("�������� ����� ����۸� �Ƿ�����ס\n");
        printf("%s\t%d\t%dԪ\t%s\n", hotelInfo[index].roomType, hotelInfo[index].roomNumber, hotelInfo[index].roomPrice, hotelInfo[index].vacantOrOccupied == 'y' ? "����":"����");
    }
    printf("��������������˵�:\n");
    getch();
    system("cls");
}
//3.�鿴�ÿ���Ϣ
void ViewGuestInfo(void)
{
    int i;
    printline();
    printf("�鿴�ÿ���Ϣ");
    printline();
    if(guestInfo[0].roomNumber==0)
        printf("\nû���ÿ���ס��\n");
    else{
        printf("\n�������ÿ���Ϣ���ֱ�Ϊ��\n����\t���֤��\t�Ա�\t�����\n");
        for(i=0;i<hotelData.currentCount;i++)
        {
            printf("%s\t%s\t%s\t%d\n",guestInfo[i].Name,guestInfo[i].ID,guestInfo[i].Sex,guestInfo[i].roomNumber);
        }
    }
    printf("��������������˵�:\n");
    getch();
    system("cls");
}
//4.�鿴ĳһ�ÿ���Ϣ
void ViewOneGuest(void)
{
    char Name[10];
    int i;
    int j=-1;
    printline();
    printf("�鿴ĳһ������Ϣ");
    printline();
    if(guestInfo[0].roomNumber==0)
        printf("\nû���ÿ���Ϣ��\n");
    else{
        printf("\n������Ҫ���ҵ��ÿ�������\n");
        scanf("%s",Name);
        for(i=0;i<hotelData.currentCount;i++)
        {
            if(strcmp(guestInfo[i].Name,Name)==0)
            {
                j=i;
                break;
            }
        }
        if(j==-1)//��Ϣ������
        {
            printf("���ÿͲ����ڣ�\n");
        }
        else{
            printf("����Ϊ%s����Ϣ��\n",guestInfo[j].Name);
            printf("����\t���֤��\t�Ա�\t�����\n");
            printf("%s\t%s\t%s\t%d\n",guestInfo[j].Name,guestInfo[j].ID,guestInfo[j].Sex,guestInfo[j].roomNumber);
        }
    }
    printf("��������������˵�:\n");
    getch();
    system("cls");
}

//5���ÿ���ס

void GuestCheckIn(void)
{
    int i,j;
    int roomNumber;
    int day;
    int fee;
    printline();
    printf("�ÿ���ס");
    printline();
    if(hotelData.currentCount<hotelData.maxRoom)
    {
        printf("\n�������ÿ����������֤�ţ��Ա�\n");
        scanf("%s %s %s",guestInfo[hotelData.currentCount].Name,guestInfo[hotelData.currentCount].ID,guestInfo[hotelData.currentCount].Sex);
        printf("���ڵĿշ��������£�\n");

        for(i=0;i<100;i++)
        {
            if(hotelInfo[i].vacantOrOccupied=='n')
            {
                printf("%d ",hotelInfo[i].roomNumber);
            }
        }
        printf("\n��ѡ��Ҫ��ס�ķ����:\n");
        //���ÿ�ѡ��ķ�������Ϊ �����ˡ�
        scanf("%d",&guestInfo[hotelData.currentCount].roomNumber);//guestInfo�����currentCount����roomNumber
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

        printf("������Ҫ��ס������\n");
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
        printf("Ӧ���%dԪ\n",fee);
        printf("�Ǽǳɹ�����ӭ��ס��\n��Ϣ���£�\n\n");
        printf("����\t���֤��\t�Ա�\t�����\n");
        printf("%s\t%s\t%s\t%d\n",guestInfo[hotelData.currentCount].Name,guestInfo[hotelData.currentCount].ID,guestInfo[hotelData.currentCount].Sex,guestInfo[hotelData.currentCount].roomNumber);
        time_t now;
        struct tm *tm_now;
        time(&now);
        tm_now = localtime(&now) ;
        printf("�Ǽ�ʱ��: %d��%d��%d�� %d:%d:%d\n",tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
        hotelData.currentCount++;

    }
    else
        printf("��Ǹ������̫�ã��ͷ������ˡ�");
    printf("\n��������������˵�:\n");
    getch();
    system("cls");
}

//�ÿͻ���
void GuestChangeRoom(void)
{
    char Name[10];
    int i=0;
    int j=-1;
    char k[5];
    int roomNumber;
    printline();
    printf("�ÿͻ���");
    printline();
    if(guestInfo[0].roomNumber==0)
        printf("\nû���ÿ���Ϣ��\n");
    else{
    printf("\n�������ÿ͵�������\n");
    scanf("%s",Name);
    for(i=0;i<hotelData.currentCount;i++)
    {
        if(strcmp(guestInfo[i].Name,Name)==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1)//��Ϣ������
    {
        printf("���ÿͲ����ڣ�\n");
    }
    else{
        if(strcmp(guestInfo[j].Sex,"��")==0)
        strcpy(k,"����");
        if(strcmp(guestInfo[j].Sex,"Ů")==0)
        strcpy(k,"Ůʿ");
        printf("�𾴵�%s%s����Ŀǰ��ס�ķ�����%d��\n",guestInfo[j].Name,k,guestInfo[j].roomNumber);
        printf("���������еĿշ��䣺\n");
        for(i=0;i<100;i++)
        {
            if(hotelInfo[i].vacantOrOccupied=='n')
            {
                printf("%d ",hotelInfo[i].roomNumber);
            }
        }
        if(guestInfo[j].roomNumber>=101&&guestInfo[j].roomNumber<=120)
            printf("\n������Ҫ�������·��䣺(���ڷ���101~120֮��ѡ��)\n");
        if(guestInfo[j].roomNumber>=201&&guestInfo[j].roomNumber<=220)
            printf("\n������Ҫ�������·��䣺(���ڷ���201~220����301~320֮��ѡ��)\n");
        if(guestInfo[j].roomNumber>=301&&guestInfo[j].roomNumber<=320)
            printf("\n������Ҫ�������·��䣺(���ڷ���201~220����301~320֮��ѡ��)\n");
        if(guestInfo[j].roomNumber>=401&&guestInfo[j].roomNumber<=420)
            printf("\n������Ҫ�������·��䣺(���ڷ���401~420����501~520֮��ѡ��)\n");
        if(guestInfo[j].roomNumber>=501&&guestInfo[j].roomNumber<=520)
            printf("\n������Ҫ�������·��䣺(���ڷ���401~420����501~520֮��ѡ��)\n");
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
        printf("�����ɹ���\n");
    }
    }
    printf("��������������˵�:\n");
    getch();
    system("cls");
}


//�ÿ��˷�
void GuestCheckOut(void)
{
    char Name[10];
    int i=0;
    int j=-1;
    printline();
    printf("�ÿ��˷�");
    printline();
    if(guestInfo[0].roomNumber==0)
        printf("\nû���ÿ���Ϣ��\n");
    else{
    printf("\n�����ÿ͵Ǽ�����%d\n\n",hotelData.currentCount);
    printf("������Ҫ�˷��ÿ͵�������\n");
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
        printf("���ÿͲ����ڣ�\n");
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
        printf("%s�˷��ɹ���\n�˷�ʱ�䣺%d-%d-%d %d:%d:%d\n��ӭ�´ι��٣�\n\n",guestInfo[i].Name,tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
    }
    }
    printf("\n��������������˵�:\n");
    getch();
    system("cls");
}
//������
void main(void)
{
    proc();
    FILE *fp;
    int i;
    if((fp=fopen("Hotel Information2.txt","rb"))==NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        return;
    }
    for(i=0;i<100;i++)
    {
        fscanf(fp,"%s %d %d %c\n",hotelInfo[i].roomType,&hotelInfo[i].roomNumber,&hotelInfo[i].roomPrice,&hotelInfo[i].vacantOrOccupied);
    }
    fclose(fp);
    if((fp=fopen("Guest Information2.txt","rb"))==NULL)
    {
        printf("û���ÿ���ס��¼��\n");
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

        printf("�ܿͷ�����%d\n�ù����еǼ�����%d\n",hotelData.maxRoom,hotelData.currentCount);
    do{
        printline();
        printf("\n");
        Welcome();
        printf("��ѡ���ܣ�\n");
        printf(
               "1 �鿴�õ���Ϣ\n"
               "2 �鿴ĳһ������Ϣ\n"
               "3 �鿴�ÿ���Ϣ\n"
               "4 ����ĳһ�ÿ���Ϣ\n"
               "5 �ÿ���ס\n"
               "6 �ÿͻ���\n"
               "7 �ÿ��˷�\n"
               "8 ���沢�˳�\n");
        printline();
        printf("\n");
        scanf("%d",&i);
        if(i<1||i>8)
            printf("�����������\n");
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
                    printf("���ÿ���ס��Ϣ��\n");
                    fp=fopen("Guest Information2.txt","w");
                    fclose(fp);
                    getch();
                    system("cls");
                    exit(0);
                }
                else{
                    i=0;
                    printf("�ù����еǼ���Ϊ��%d\n",hotelData.currentCount);
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
