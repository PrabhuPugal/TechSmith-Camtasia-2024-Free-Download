// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
#define SIZE 100
int size = 0;

// #include "hash-table.c"

void printArray(int size);

struct Mark
{
    int mark_1;
    int mark_2;
    int mark_3;
    int mark_4;
    int mark_5;
};
// struct Date
// {
//     int day;
//     int month;
//     int year;
// };
struct personal
{
    int d_day;
    int d_month;
    int d_year;
    int age;
    char area[40];
    char city[40];
    int pincode;
};

struct Student
{
    char name[30];
    long int rollno;
    struct Mark mark;
    struct personal pers;
    float average;
    char grade;
    int class_id;
};

#include "validations.c"

struct Student* stud[SIZE];
struct Student* curr;

void swap(struct Student *a,struct Student *b)
{
    struct Student temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && stud[l]->rollno > stud[largest]->rollno)
        largest = l;
        if (r < size && stud[r]->rollno > stud[largest]->rollno)
        largest = r;
        if (largest != i)
        {
        swap(stud[i], stud[largest]);
        heapify(size, largest);
        }
    }
}

void insert_heap(struct Student* newstud)
{
    if (size == 0)
    {
        stud[0] = newstud;
        size += 1;
    }
    else
    {
        stud[size] = newstud;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(size, i);
        }
    }
}
void deleteRoot(struct Student* num)
{
    fflush(stdin);
    delete_hash(search(num->name));
    int i;
    for (i = 0; i < size; i++)
    {
        if (num->rollno == stud[i]->rollno)
        break;
    }

    swap(stud[i], stud[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(size, i);
    }
    
}
void printArray(int size)
{
    for (int i = 0; i < size; ++i)
        printf("%ld-%s-%d-%f-%c-%d", stud[i]->rollno,stud[i]->name,stud[i]->pers.age,stud[i]->average,stud[i]->grade,stud[i]->class_id);
    printf("\n");
}

struct Student* search_heap(long int roll)
{
    for (int i = 0; i < size; ++i)
        if(stud[i]->rollno==roll)
        {
            return stud[i];            
        }
    return NULL;
}

void student_update_mark(struct Student* node)
{
    printf("Mark 1: ");
    node->mark.mark_1=mark_validate();

    printf("Mark 2: ");
    node->mark.mark_2=mark_validate();

    printf("Mark 3: ");
    node->mark.mark_3=mark_validate();

    printf("Mark 4: ");
    node->mark.mark_4=mark_validate();

    printf("Mark 5: ");
    node->mark.mark_5=mark_validate();

    node->average=(node->mark.mark_1+node->mark.mark_2+node->mark.mark_3+node->mark.mark_4+node->mark.mark_5)/5;
    node->grade=(node->average>90)?'O':node->average>80?'A':node->average>70?'C':node->average>60?'D':node->average>50?'E':'F';
}

struct Student* get_details(struct DataItem* ptr)
{
    struct Student* node=(struct Student*)malloc(sizeof(struct Student));
    // node->pers=(struct personal*)malloc(sizeof(struct personal));
    // node->mark=(struct Mark*)malloc(sizeof(struct Mark));
    node->rollno=ptr->rollno;

    strcpy(node->name,ptr->key);
    
    printf("\n\nDOB: ");
    // // node->pers->date=get_date();
    get_date(node);
    // node->pers->d_day=d.day;
    // node->pers->d_month=d.month;
    // node->pers->d_year=d.year;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    node->pers.age= (1900+tm->tm_year) - node->pers.d_year;

    printf("\nAge: %d",node->pers.age);

    printf("\nArea: ");
    fflush(stdin);
    gets(node->pers.area);

    printf("\nCity: ");
    fflush(stdin);
    gets(node->pers.city);

    printf("\nPincode: ");
    node->pers.pincode=get_pincode(); 

    printf("\nClass ID: ");
    node->class_id=get_classid();
    // printf("Class ID: %d",node->class_id);
    node->mark.mark_1=node->mark.mark_2=node->mark.mark_3=node->mark.mark_4=node->mark.mark_5=0;
    node->average=0;
    node->grade='-';
    return node;
}


void sign_up()
{
    char user[30];
    char pass[30];
    long int roll;
    printf("\nEnter Your Roll No: ");
    scanf("%ld",&roll);
    if(roll==0)
    {
        return;
    }
    if(roll_validate(roll)==1)
    {
        printf("\nEnter Username: ");
        fflush(stdin);
        gets(user);

        if(user_validate(user)==1)
        {
            printf("\nUser Already Exist!");
        }
        else if(user_validate(user)==-1)
        {
            printf("\nUser cannot have more than 15 characters!");
        }
        else
        {
            printf("\nEnter Password: ");
            fflush(stdin);
            strcpy(pass,get_pwd(pass));
            if(strlen(pass)>=15)
            {
                printf("\nPassword cannot have more than 15 characters!");
                return;
            }
            encrypt(pass);
            insert(user,pass,roll);
            // printf("\nSign up Sucessfull!");
            insert_heap(get_details(search(user)));
        }
    }
    else
        printf("\nInvalid Roll Number!");
}

struct Student* log_in()
{
    char user[16];
    char pass[16];


    printf("\nEnter Your Username: ");
    fflush(stdin);
    gets(user);
    item=search(user);

    if(item)
    {
        printf("\nEnter your Password: ");
        fflush(stdin);
        strcpy(pass,get_pwd(pass));
        encrypt(pass);
        if(!strcmp(item->data,pass))
        {
            printf("\nLog in Successfull!");
            return search_heap(item->rollno);
        }
        else 
        {
            printf("\nPassword Wrong!");
            return NULL;
        }
    }
    else
    {
        printf("\nUser Not Found");
        return NULL;
    }
}

void change_password(struct Student* cur)
{
    struct DataItem* ptr=search(cur->name);
    char pass1[16];
    char pass2[16];
    if(ptr)
    {
        printf("\nEnter your Password: ");
        fflush(stdin);
        strcpy(pass1,get_pwd(pass1));
        encrypt(pass1);
        if(!strcmp(item->data,pass1))
        {
            printf("\nEnter New Password: ");
            fflush(stdin);
            strcpy(pass1,get_pwd(pass1));
            encrypt(pass1);

            printf("\nEnter Once Again: ");
            fflush(stdin);
            strcpy(pass2,get_pwd(pass2));
            encrypt(pass2);

            if(!strcmp(pass1,pass2))
            {
                strcpy(ptr->data,pass1);
            }
            else
            {
                printf("\nPassword Mismatch!");
            }
        }
        else 
        {
            printf("\nPassword Wrong!");
            return;
        }
    }
    else
    {
        printf("\nUser Not Found");
        return;
    }
}

void display_class()
{
    int num,f=0;
    printf("\nEnter Class ID: ");
    scanf("%d",&num);
    printf("\nRoll\t\tName");
    for (int i = 0; i < size; ++i)
        if(stud[i]->class_id==num)
        {
            f=1;
            printf("\n%ld\t\t%s",stud[i]->rollno,stud[i]->name);
        }

    if(f==0)
        printf("\nNo Record Found");
}

void update_mark_class()
{
    int num,f=0;
    printf("\nEnter Class ID: ");
    scanf("%d",&num);
    for (int i = 0; i < size; ++i)
        if(stud[i]->class_id==num)
        {
            f=1;
            printf("\nEnter Marks For Student: %s\n\n",stud[i]->name);
            student_update_mark(stud[i]);
        }

    if(f==0)
        printf("\nNo Record Found");
}

void display_mark_class()
{
    int num,f=0;
    printf("\nEnter Class ID: ");
    scanf("%d",&num);
    printf("\nRoll\t\tName\t\tMark-1\t\tMark-2\t\tMark-3\t\tMark-4\t\tMark-5\t\tAverage\t\tGrade");
    for (int i = 0; i < size; ++i)
        if(stud[i]->class_id==num)
        {
            f=1;
            printf("\n%ld\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%f\t\t%c",stud[i]->rollno,stud[i]->name,stud[i]->mark.mark_1,stud[i]->mark.mark_2,stud[i]->mark.mark_3,stud[i]->mark.mark_4,stud[i]->mark.mark_5,stud[i]->average,stud[i]->grade);
        }
    if(f==0)
        printf("\nNo Record Found");
}

void display_student_personal(struct Student* ptr)
{
    printf("\nRoll: %ld",ptr->rollno);
    printf("\nName: %s",ptr->name);
    
    printf("\nDOB: %d/%d/%d",ptr->pers.d_day,ptr->pers.d_month,ptr->pers.d_year);
    printf("\nAge: %d",ptr->pers.age);
    printf("\nArea: %s",ptr->pers.area);
    printf("\nCity: %s",ptr->pers.city);
    printf("\nPincode: %d",ptr->pers.pincode);
}

void display_student_marks(struct Student* ptr)
{
    printf("\nMark-1: %d",ptr->mark.mark_1);
    printf("\nMark-2: %d",ptr->mark.mark_2);
    printf("\nMark-3: %d",ptr->mark.mark_3);
    printf("\nMark-4: %d",ptr->mark.mark_4);
    printf("\nMark-5: %d",ptr->mark.mark_5);
}

void display_student_grade(struct Student* ptr)
{
    printf("\nAvergae: %f",ptr->average);
    printf("\nGrade: %c",ptr->grade);
}

void writeinfile_heap()
{
	FILE *f;
    f=fopen("./bin/student_particulars.bin","wb");

	for(int i = 0; i<size; i++)
    {
		fwrite(stud[i],sizeof(struct Student),1,f);
        // printf("%d",stud[i]->pers.age);
	}
	fclose(f);
}

void readfromfile_heap()
{
	FILE *f;
	struct Student *temp=(struct Student*)malloc(sizeof(struct Student));
    // temp->pers=(struct personal*)malloc(sizeof(struct personal));
    // temp->mark=(struct Mark*)malloc(sizeof(struct Mark));
    // temp->pers->date=(struct Date*)malloc(sizeof(struct Date));
	f=fopen("./bin/student_particulars.bin","rb");
	while(fread(temp,sizeof(struct Student),1,f))
	{
		insert_heap(temp);
        // printf("%d/%d/%d",temp->pers->d_day,temp->pers->d_month,temp->pers->d_year);
		temp=(struct Student*)malloc(sizeof(struct Student));
        // temp->pers=(struct personal*)malloc(sizeof(struct personal));
        // temp->mark=(struct Mark*)malloc(sizeof(struct Mark));
        // temp->pers->date=(struct Date*)malloc(sizeof(struct Date));
	}
	fclose(f);
}

// int main()
// {
//     readfromfile_hash();
//     readfromfile_heap();
    // sign_up();
    // display();
    // printArray(size);

    // deleteRoot(search_heap(1018));
    // printf("Max-Heap array: ");
    // printArray(size);
    // sign_up();
    // display();
    // printArray(size);
    // curr=log_in();
    // printf("\n%d-%s",curr->rollno,curr->name);
    // display_class();
//     display_personal(curr);
//     writeinfile_hash();
//     writeinfile_heap();
// }


// personal details - any one of the tree 
// class view from admin side