#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash-table.c"
#include "heap.c"

void clr_scr()
{
    system("cls");
    printf("\t\t\t\t\tStudent Management System");
    printf("\n------------------------------------------------------------------------------------------------------");
}

int admin_login()
{
    char user[16];
    char pass[16];
    printf("\nEnter Your Username: ");
    fflush(stdin);
    gets(user);
    if(!strcmp("Admin",user))
    {
        printf("\nEnter your Password: ");
        fflush(stdin);
        strcpy(pass,get_pwd(pass));
        
        if(!strcmp("Admin@123",pass))
        {
            printf("\nLog in Successfull!");
            return 1;
        }
        else 
        {
            printf("\nPassword Wrong!");
            return 0;
        }
    }
    else
    {
        printf("\nUser Not Found");
        return 0;
    }
}
void admin()
{
    struct Student* ptr;
    while(!admin_login())
    {
        printf("\nTry Again!");
    }
    system("pause");
    clr_scr();
    while(1)
    {
        int n;
        long int num;
        printf("\nAdmin Menu");
        printf("\n1. Search a Student\n2. Display A Class\n3. Update Mark for A Student\n4. Update Marks for Class\n5. Display Marks of a Class\n6. Create a Student\n0.Quit\nEnter Your Choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                printf("\nEnter Roll Number: ");
                scanf("%ld",&num);
                ptr=search_heap(num);
                if(ptr==NULL)
                {
                    printf("\nRoll Number Not Found ");
                    break;
                }
                display_student_personal(ptr);
                display_student_marks(ptr);
                display_student_grade(ptr);
                break;
            
            case 2:
                display_class();
                break;

            case 3:
                printf("\nEnter Roll Number: ");
                scanf("%ld",&num);
                ptr=search_heap(num);
                if(ptr==NULL)
                {
                    printf("\nRoll Not Found ");
                    break;
                }
                student_update_mark(ptr);
                break;

            case 4:
                update_mark_class();
                break;
            
            case 5:
                display_mark_class();
                break;

            case 6:
                sign_up();
                printf("\nStudent Insertion Successfull!");
                break;

            case 0:
                return;
            
            default:
                break;
        }
        printf("\n\n\n");
        system("pause");
        clr_scr();
    }
}
void update_personal(struct Student* ptr)
{
    int n;
    while(1)
    {
        clr_scr();
        printf("\n\nUpdate Menu\n");
        printf("1. Name\n2. DOB\n3. Area\n4. City\n5. Pincode\n0. Exit\nEnter Your Choice: ");
        scanf("%d",&n);

        switch (n)
        {
            case 1:
                printf("\nOld Name: %s",ptr->name);
                printf("\nNew Name: ");
                fflush(stdin);
                gets(ptr->name);
                break;

            case 2:
                printf("\nDOB: %d/%d/%d",ptr->pers.d_day,ptr->pers.d_month,ptr->pers.d_year);
                printf("\nNew DOB: ");
                get_date(ptr);
                // ptr->pers->d_day=d.day;
                // ptr->pers->d_month=d.month;
                // ptr->pers->d_year=d.year;
                break;

            case 3:
                printf("\nArea: %s",ptr->pers.area);
                printf("\nNew Area: ");
                fflush(stdin);
                gets(ptr->pers.area);
                break;

            case 4:
                printf("\nCity: %s",ptr->pers.city);
                printf("\nNew City: ");
                fflush(stdin);
                gets(ptr->pers.city);
                break;

            case 5:
                printf("\nPincode: %d",ptr->pers.pincode);
                printf("\nNew Pincode: ");
                scanf("%d",&ptr->pers.pincode);
                break;

            case 0:
                return;
            default:
                break;
        }
        printf("\n\n\n");
        system("pause");
    }
}
void student()
{
    struct Student* cur;
    do
    {
        printf("\nStudent Log-in\n");
        cur=log_in();
    }while(!cur);
    printf("\n\n\n\nNote: Change Password if Log in for First Time!\n\n");
    system("pause");
    clr_scr();
    while(1)
    {
        int n,num;
        printf("\nStudent Menu");
        printf("\n1. My Personal Detials\n2. My Marks\n3. My Grade\n4. Change password\n5. Update Personal Details\n0.Quit\nEnter Your Choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                display_student_personal(cur);
                break;
            
            case 2:
                display_student_marks(cur); 
                break;

            case 3:
                display_student_grade(cur);
                break;

            case 4:
                change_password(cur);
                break;

            case 5:
                update_personal(cur);
                break;

            case 0:
                return;
            
            default:
                break;
        }
        printf("\n\n\n");
        system("pause");
        clr_scr();
    }
}

void main()
{
    readfromfile_hash();
    readfromfile_heap();
    // printArray(size);
    system("pause");
    while(1)
    {
        clr_scr();
        int n;
        printf("\nMenu");
        printf("\n1. Admin\n2. Student\n0.Quit\nEnter Your Choice: ");
        scanf("%d",&n);

        switch (n)
        {
            case 1:
                admin();
                break;
            case 2:
                student();
                break;
            case 0:
                writeinfile_hash();
                writeinfile_heap();
                return;    
            default:
                break;
        }
        printf("\n\n\n");
        system("pause");
    }
}
