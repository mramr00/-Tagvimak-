#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isLeapYear(int year) {
    return (year%4==0&&year%100!=0)||(year%400==0);
}
int isLeapYear2(int y1,int y2){
    int result=0;
    for(int i=y1+1;i<=y2;i++){
        result+=isLeapYear(i)?1:0;
    }
    return result;
}
int NumberofDays(int year,int month,int day){
    int result=0;
    for(int y=1206;y<year;y++){
        result+=isLeapYear(y)?366:365;
    }
    for(int m=1;m<month;m++){
        if(m==1||m==2||m==3||m==4||m==5||m==6){
            result+=31;
        }
        if(m==7||m==8||m==9||m==10||m==11){
            result+=30;
        }
        if(m==12){
            result+=isLeapYear(year)?30:29;
        }
    }
    if(day==0){
        return result;
    }
    else if(day>0){
        return result+day-1;
    }
}
int NumberofDays2(int y1,int m1,int d1,int y2,int m2,int d2){
    int result=0;
    for(int i=y1+1;i<y2;i++){
        result+=isLeapYear(i)?366:365;
    }
    for(int j=m1+1;j<=12;j++){
        if(j==1||j==2||j==3||j==4||j==5||j==6){
            result+=31;
        }
        if(j==7||j==8||j==9||j==10||j==11){
            result+=30;
        }
        if(j==12){
            result+=isLeapYear(y1)?30:29;
        }
    }
    for(int z=1;z<m2;z++){
        if(z==1||z==2||z==3||z==4||z==5||z==6){
            result+=31;
        }
        if(z==7||z==8||z==9||z==10||z==11){
            result+=30;
        }
        if(z==12){
            result+=isLeapYear(y2)?30:29;
        }
    }
    result+=d2+30-d1;
    if(y1==y2){
        result-=365;
    }
    return result;
}
int WichDay(int days){
    if(days%7==2){
        return 1;
    }    if(days%7==3){
        return 2;
    }    if(days%7==4){
        return 3;
    }    if(days%7==5){
        return 4;
    }    if(days%7==6){
        return 5;
    }    if(days%7==0){
        return 6;
    }    if(days%7==1){
        return 7;
    }
}
int WichDay2(int days2){
    if(days2==1){
        printf("Saturday.");
    }if(days2==2){
        printf("Sunday.");
    }    if(days2==3){
        printf("Monday.");
    }    if(days2==4){
        printf("Tuesday.");
    }    if(days2==5){
        printf("Wednesday.");
    }    if(days2==6){
        printf("Thursday.");
    }    if(days2==7){
        printf("Friday.");
    }
}
int Age(int Days,int y1,int y2){
    int Days2,Days3,Days4;
    printf("%d days since your birthday.\nyour age is ",Days);
    Days-=isLeapYear2(y1,y2);
    Days2=Days;
    Days/=365;
    Days2%=365;
    Days3=Days2;
    Days3%=30;
    Days2/=30;
    printf("%d years and ",Days);
    printf("%d months and ",Days2);
    printf("%d days.\n",Days3);
}
int Calendar(int y,int m){
    int daysInMonth[]={0,31,31,31,31,31,31,30,30,30,30,30,29};
    char *monthNames[]={"","Farvardin","Ordibehesht","Khordad","Tir","Mordad","Shahrivar","Mehr","Aban","Azar","Dey","Bahman","Esfand"};
    if(WichDay(NumberofDays(y,m,0))==7){
        if(m<=6) {
            printf("\n     <<<%s>>>", monthNames[m]);
            printf("\nSA SU MO TU WE TH FR\n");
            printf("                  01\n");
            printf("02 03 04 05 06 07 08\n");
            printf("09 10 11 12 13 14 15\n");
            printf("16 17 18 19 20 21 22\n");
            printf("23 24 25 26 27 28 29\n");
            printf("30 31\n");
        }
        if(m>6){
            printf("\n     <<<%s>>>", monthNames[m]);
            printf("\nSA SU MO TU WE TH FR\n");
            printf("                  01\n");
            printf("02 03 04 05 06 07 08\n");
            printf("09 10 11 12 13 14 15\n");
            printf("16 17 18 19 20 21 22\n");
            printf("23 24 25 26 27 28 29\n");
            printf("30\n");
        }
    }
    else {
        printf("\n   <<<%s>>>\n", monthNames[m]);
        printf("SA SU MO TU WE TH FR\n");
        for (int z = 0; z < 3 * WichDay(NumberofDays(y, m, 0)) - 3; z++) {
            printf(" ");
        }
        int x = 1, a = WichDay(NumberofDays(y, m, 0)) - 1, b = 3 * WichDay(NumberofDays(y, m, 0)) - 2;
        for (int i = b; i <= 20; i++) {
            for (int j = a; j <= 6; j++) {
                if (x <= daysInMonth[m]) {
                    if (x > 9 && x < daysInMonth[m] + 1) {
                        printf("%d ", x);
                    } else if (x <= 9 && x < daysInMonth[m] + 1) {
                        printf("0%d ", x);
                    }
                } else {
                    break;
                }
                x++;
            }
            printf("\n");
            a = 0;
            if (x == daysInMonth[m] + 1) {
                break;
            }
        }
    }
}
int Conversion(int y,int m,int d){
    int Days=0,Days2,Days3,x;
    Days+=(y-1)*365+(m+4)*30+d+226899+2;
    char *monthnames[]={"","April","May","June","July","August","September","October","November","December","January","February","March"};
    Days2=Days;
    Days/=365;
    Days2%=365;
    Days3=Days2;
    Days3%=30;
    Days2/=30;
    if(Days2<10){
        x=Days2+3;
    }
    if(Days2>10){
        x=Days2-9;
    }
    if(x==0){
        x++;
    }
    printf("Gregorian date:\n");
    printf("%d ",Days);
    printf("%s(%d) ",monthnames[Days2],x);
    printf("%d \n",Days3);
    int Days4=0,Days5,Days6;
    char *monthnames2[]={"","Moharram","Safar","Rabiolaval","Rabiolsani","Jamadiolaval","Jamadiolsani","Rajab","Shaban","Ramazan","Shavval","Zigada","Zihaja",};
    Days4+=floor(y*365+m*30+d+10.875*y);
    Days5=Days4;
    Days4/=365;
    Days5%=365;
    Days6=Days5;
    Days6%=30;
    Days5/=30;
    printf("Lunar date:\n");
    printf("%d ",Days4+1);
    printf("%s(%d) ",monthnames2[Days5-1],Days5-1);
    printf("%d \n",Days6);
}
int MainMenu(){
    printf("********************\n");
    printf("Main Menu\n");
    printf("********************\n");
    printf("[0]Quit\n[1]Calendar\n[2]Age\n[3]Conversion\n");
    printf("********************\n");
}
int BacktoMenu(){
    printf("********************\n");
    printf("[0] back to menu\n");
    printf("********************\n");
}
int SolarMonth(int m){
    char *monthNames[]={"","Farvardin","Ordibehesht","Khordad","Tir","Mordad","Shahrivar","Mehr","Aban","Azar","Dey","Bahman","Esfand"};
    printf("%s(%d) ",monthNames[m],m);
}
int main(){
    int x;
    while(1){
        MainMenu();
        printf("select an option:");
        scanf("%d",&x);
        system("cls");
        if(x==0){
            system("cls");
            printf("Bye!");
            break;
        }
        if(x==1){
            int y,m;
            while(1) {
                BacktoMenu();
                printf("Year(1206-1498):");
                scanf("%d", &y);
                if(y==0){
                    system("cls");
                    break;
                }
                if(y<1206||y>1498){
                    system("cls");
                    printf("Invalid input!\n");
                    continue;
                }
                printf("Month(1-12):");
                scanf("%d", &m);
                if (m==0) {
                    system("cls");
                    break;
                }
                if(m<1||m>12){
                    system("cls");
                    printf("Invalid input!\n");
                    continue;
                }
                printf("********************");
                Calendar(y,m);
                printf("********************\n");
                system("pause");
                system("cls");
            }
        }
        if(x==2){
            int y1,m1,d1,y2,m2,d2;
            printf("Today's date:\n");
            printf("Year:");
            scanf("%d",&y2);
            printf("Month:");
            scanf("%d",&m2);
            printf("Day:");
            scanf("%d",&d2);
            system("cls");
            while(1){
                BacktoMenu();
                printf("Your birthday date:\n");
                printf("Year:");
                scanf("%d",&y1);
                if(y1==0){
                    system("cls");
                    break;
                }
                printf("Month:");
                scanf("%d",&m1);
                if(m1==0){
                    system("cls");
                    break;
                }
                printf("Day:");
                scanf("%d",&d1);
                if(d1==0){
                    system("cls");
                    break;
                }
                printf("********************\n");
                Age(NumberofDays2(y1,m1,d1,y2,m2,d2),y1,y2);
                printf("your birthday was ");
                WichDay2(WichDay(NumberofDays(y1,m1,d1)));
                printf("\nSolar date:\n");
                printf("%d ",y1);
                SolarMonth(m1);
                printf("%d\n",d1);
                Conversion(y1,m1,d1);
                printf("********************\n");
                system("pause");
                system("cls");
            }
        }
        if(x==3){
            int Y,M,D;
            while(1){
                BacktoMenu();
                printf("Enter Solar Date:\n");
                printf("Year:");
                scanf("%d",&Y);
                if(Y==0){
                    system("cls");
                    break;
                }
                printf("Month:");
                scanf("%d",&M);
                if(M==0){
                    system("cls");
                    break;
                }
                printf("Day:");
                scanf("%d",&D);
                if(D==0){
                    system("cls");
                    break;
                }
                printf("********************\n");
                Conversion(Y,M,D);
                printf("********************\n");
                system("pause");
                system("cls");
            }
        }
        else{
            system("cls");
            printf("********************\n");
            printf("Invalid input!\n");
        }
    }
    return 0;
}
