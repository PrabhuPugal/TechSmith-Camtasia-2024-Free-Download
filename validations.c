// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<string.h>
// #include <dos.h>
#include <time.h>


char date[10];
void get_date(struct Student* node)
{
    
    //struct Date d;//=(struct Date*)malloc(sizeof(struct Date));
    int dd,mm,yy;
    scanf("%d/%d/%d",&dd,&mm,&yy);
    fflush(stdin);
    // gets(date);
    // dd=atoi(date[0])*10+atoi(date[1]);
    // mm=atoi(date[3])*10+atoi(date[4]);
    // yy=atoi(date[6])*1000+atoi(date[7])*100+atoi(date[8])*100+atoi(date[9])*100;
    
    
    if(yy>=1900 && yy<=2021)
    {
        if(yy==2022)
        {
        	if(mm>06)
        	{
        		printf("\nInvalid Date!!\n\nEnter Again:");
				get_date(node);
			}
		}
        if(mm>=1 && mm<=12)
        {
            
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                {
                	node->pers.d_day=dd;
                	node->pers.d_month=mm;
                	node->pers.d_year=yy;
                    return;
                	
                }
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                {
                	node->pers.d_day=dd;
                	node->pers.d_month=mm;
                	node->pers.d_year=yy;
                    return;
                	
                }
            else if((dd>=1 && dd<=28) && (mm==2))
                {
                	node->pers.d_day=dd;
                	node->pers.d_month=mm;
                	node->pers.d_year=yy;
                    return;
                	
                }
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                {
                	node->pers.d_day=dd;
                	node->pers.d_month=mm;
                	node->pers.d_year=yy;
                    return;
                	
                }
            else
                {
					printf("\nInvalid Date!!\n\nEnter Again:");
					get_date(node);
            	}
        }
        else
        {
            printf("\nInvalid Date!!\n\nEnter Again:");
            get_date(node);
        }
    }
    else
    {
        printf("\nInvalid Date!!\n\nEnter Again:");
        get_date(node);
    }
    // printf("%d/%d/%d",d.day,d.month,d.day);
    return;
}

int mark_validate()
{
    int num;
    scanf("%d",&num);
    if(num<0||num>100)
    {
        printf("\nInvalid Mark!!\n\nEnter Again:");
        mark_validate();
    }
    // return num;
}

// pincode, age,classid


int get_pincode()
{
    int pincode;
    scanf("%d",&pincode);
    if(pincode<=000000||pincode>999999)
    {
        printf("\nInvalid Pincode!!\nEnter Again:");
        get_pincode();
    }
    // return pincode;
}

int get_classid()
{
    int cls;
    scanf("%d",&cls);
    if(no_of_digit(cls)!=4)
    {
        printf("\nInvalid Class ID!!\nEnter Again:");
        return get_classid();
    }
    // printf("\nClass ID: %d\n",cls);
    return cls;
}

// int main()
// {
//     printf("%s",get_date());
// }