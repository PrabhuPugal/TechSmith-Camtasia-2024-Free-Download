// #include <stdio.h>
// #include <conio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdbool.h>

#define SIZE 100

struct DataItem 
{
    long int rollno;
    char data[16];   
    char key[16];
};

struct DataItem* hashArray[SIZE];
struct DataItem* item;

int hashCode(char* key) 
{
    return strlen(key) % SIZE;
}
void encrypt(char* pass)
{
    int key=strlen(pass);
    for(int i=0;i<key;i++)
        pass[i]=pass[i]-key;
}
struct DataItem *search(char* key) 
{
    int hashIndex = hashCode(key);  
        
    while(hashArray[hashIndex] != NULL) {
        
        if(!strcmp(hashArray[hashIndex]->key,key))
            return hashArray[hashIndex]; 
                
        ++hashIndex;
        hashIndex %= SIZE;
    }        
        
    return NULL;  
}

void insert(char* key,char* data,long int roll) 
{

    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));

    strcpy(item->data,data);  
    strcpy(item->key,key);
    item->rollno=roll;
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL ) 
    {
        ++hashIndex;
            
        hashIndex %= SIZE;
    }
        
    hashArray[hashIndex] = item;
}

struct DataItem* delete_hash(struct DataItem* item) 
{
    char* key;
    strcpy(key,item->key);

    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL) 
    {
        
        if(!strcmp(hashArray[hashIndex]->key,key)) 
        {
            struct DataItem* temp = hashArray[hashIndex]; 
                
            hashArray[hashIndex] = NULL; 
            return temp;
        }
            
        ++hashIndex;
            
        hashIndex %= SIZE;
    }      
        
    return NULL;        
}

void display() 
{
    int i = 0;
        
    for(i = 0; i<SIZE; i++) 
    {
        if(hashArray[i] != NULL)
            printf(" (%ld,%s,%s)",hashArray[i]->rollno,hashArray[i]->key,hashArray[i]->data);
        else
            printf(" ~~ ");
    }
        
    printf("\n");
}

int user_validate(char* user)
{
    item=search(user);
    if(item)
        return 1;
    else if(strlen(user)>=15)
        return -1;
    else
        return 0;
}

int no_of_digit(long int num)
{
    int n,nod=0;
    n=num;
    while(n!=0)
    {
        n/=10;
        nod++;
    }
    return nod;
}

int roll_validate(long int roll)
{
    for(int i = 0; i<SIZE; i++)
    {
        
        if(hashArray[i] != NULL)
        {
            if(roll==0)
                return 0;
            else if(hashArray[i]->rollno==roll)
                return 0;

            else if(no_of_digit(roll)>7)
                return 0;
        }
        
    }
    return 1;
}

char* get_pwd(char* password)
{
    int p=0;
    do{
        password[p]=getch();
        if(password[p]!='\r')
		{
            printf("*");
        }
        p++;
    }while(password[p-1]!='\r'&&p<=15);
    password[p-1]='\0';
    return password;
}

void writeinfile_hash()
{
	FILE *f;
    f=fopen("./bin/login_crentials.bin","wb");
	for(int i = 0; i<SIZE; i++)
    {
		fwrite(hashArray[i],sizeof(struct DataItem),1,f);
	}
	fclose(f);
}

void readfromfile_hash()
{
	FILE *f;
	struct DataItem *temp=(struct DataItem*)malloc(sizeof(struct DataItem));
	f=fopen("./bin/login_crentials.bin","rb");
	while(fread(temp,sizeof(struct DataItem),1,f))
	{
		insert(temp->key,temp->data,temp->rollno);
		temp=(struct DataItem*)malloc(sizeof(struct DataItem));
	}
	fclose(f);
}

// int main()
// {
//     // char user[16];
//     // char pass[16];

//     // strcpy(user,"Vignu");
//     // strcpy(pass,"VigNu");
//     // insert(user, pass);
    
//     // strcpy(user,"Sabaree");
//     // strcpy(pass,"saba");
//     // insert(user, pass);

//     // strcpy(user,"Kalai");
//     // strcpy(pass,"kala");
//     // insert(user, pass);

//     // strcpy(user,"KaLai");
//     // strcpy(pass,"kala");
//     // insert(user, pass);

//     // strcpy(user,"KAlai");
//     // strcpy(pass,"kala");
//     // insert(user, pass);

//     // strcpy(user,"KalAi");
//     // strcpy(pass,"kala");
//     // insert(user, pass);
//     readfromfile();
//     sign_up();
//     display();

//     int n=log_in();

//     printf("%d",n);
//     // insert(2, 70);
//     // insert(42, 80);
//     // insert(4, 25);
//     // insert(12, 44);
//     // insert(14, 32);
//     // insert(17, 11);
//     // insert(13, 78);
//     // insert(37, 97);

//     // display();
//     // item = search("KalAi");

//     // if(item != NULL)
//     //     printf("Element found: %s\n", item->data);
//     // else
//     //     printf("Element not found\n");

//     // _delete(item);
//     // display();
//     writeinfile();
//     // strcpy(user,"KalAi");
//     // strcpy(pass,"kala");
//     // insert(user, pass);

//     // display();
//     // item = search(37);

//     // if(item != NULL) {
//     //     printf("Element found: %d\n", item->data);
//     // } else {
//     //     printf("Element not found\n");
//     // }
// }