#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

struct login
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
} l;

void login(void);
void registration(void);
void traininfo(void);


void login(void)
{ 
    char username[30], password[20];
    FILE *log;
 
    log = fopen("login.txt", "r");
    if (log == NULL)
    {
        printf("Error at opening File!");
        exit(1);
    }


    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username: ");
    scanf("%s",username);
    printf("\nPassword: ");
    scanf("%s",password);
    while (fread(&l, sizeof(l), 1, log))
    {
        if (strcmp(l.username,username) == 0 && strcmp(l.password,password) == 0)
        {
            printf("\nSuccessful Login\n");
            traininfo();
            break;
        }
        else
        {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
            break;
        }
    }

    fclose(log);
    return;
}

void registration(void)
{
    FILE *log;
    log = fopen("login.txt", "w");
    if (log == NULL)
    {
        printf("Error at opening File!");
        exit(1);
    }

    struct login l;

    printf("\nWelcome to Railway Ticketing System Powered by IIIT UNA\n\n");
    printf("\nEnter First Name:\n");
    scanf("%s", l.fname);
    printf("\nEnter Surname:\n");
    scanf("%s", l.lname);

    printf("Thank you.\nNow please choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");

    printf("\nEnter Username:\n");
    scanf("%s", l.username);
    printf("\nEnter Password:\n");
    scanf("%s", l.password);

    fprintf(log, "%s\n%s\n%s\n%s", l.fname, l.lname, l.username, l.password);
    fclose(log);

    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
    getchar();
    system("clear");
    login();
}

typedef struct passenger_info
{
    char name[50];
    char gender[10];
    int age;
} passenger;

void traininfo(void)
{
    char from[50];
    char to[50];
    char date[16];
    int npassengers;

    FILE *fp;
    fp = fopen("traindetails.txt", "w");
    if (fp == NULL)
    {
        printf("Error at opening File!");
        exit(1);
    }
    fflush(stdin);
    printf("Enter the boarding station: ");
    fgets(from, 50, stdin);
    printf("Enter the destination station: ");
    fflush(stdin);
    fgets(to, 50, stdin);
    printf("Date of boarding (dd/mm/yyyy): ");
    fflush(stdin);
    fgets(date, 16, stdin);

    char train[10][100] = {"Rajdhani Express....................10 pm", "Humsafar Express....................2 pm",
                           "Sampark Kranti Express....................7 am", "Bundelkhand Express....................11 am", "Chetak Express....................5:30 pm",
                           "Garib Rath Express....................5 am", "Kavi Guru Express....................3 am", "Jan Shatabdi Express....................8 pm",
                           "Gatiman Express....................12:30 pm", "Vande Bharat Express....................3 pm"};

    srand(time(NULL));
   int num = (rand() % 10);
    // printf("%d\n", num);

    int i = 0;
    char train_name[100];
    while (train[num][i] != '\0')
    {
        train_name[i] = train[num][i];
        i++;
    }
    printf("%s",train_name);

    printf("\nEnter no.of passengers: ");
    scanf("%d", &npassengers);
    passenger arr[npassengers];

    for (int i = 1; i <= npassengers; i++)
    {
        printf("Enter The %dth Passenger Age: ", i);
        scanf("%d", &arr[i].age);
        printf("Enter The %dth Passenger Name: ", i);
        fflush(stdin);
        fgets(arr[i].name,50,stdin);
        printf("Enter The %dth Passenger Gender: ", i);
        fflush(stdin);
        fgets(arr[i].gender,10,stdin);
    }

    char coach[3][50] = {"AC coach", "Sleeper coach", "General coach"};
    char coach_type[50];
    int x;
    printf("Enter the choice of coach (AC/Sleeper/General)(0/1/2): ");
    scanf("%d", &x);
    int k = 0;
    if (x == 0)
    {
        while (coach[x][k] != '\0')
        {
            coach_type[k] = coach[x][k];
            k++;
        }
    }
    else if (x == 1)
    {
        while (coach[x][k] != '\0')
        {
            coach_type[k] = coach[x][k];
            k++;
        }
    }
    else if (x == 2)
    {
        while (coach[x][k] != '\0')
        {
            coach_type[k] = coach[x][k];
            k++;
        }
    }
    else
    {
        printf("Invalid Input");
    }
    printf("%s", coach_type);

    char class[3][50] = {"1st AC", "2nd AC", "3rd AC"};
    char coach_class[50];
    int y;
    if (x == 0)
    {
        printf("\nEnter choice of class(1st AC/2nd AC/3rd AC)(0/1/2): ");
        scanf("%d", &y);
        int j = 0;
        if (y == 0)
        {
            while (class[y][j] != '\0')
            {
                coach_class[j] = class[y][j];
                j++;
            }
        }
        else if (y == 1)
        {
            while (class[y][j] != '\0')
            {
                coach_class[j] = class[y][j];
                j++;
            }
        }
        else if (y == 2)
        {
            while (class[y][j] != '\0')
            {
                coach_class[j] = class[y][j];
                j++;
            }
        }
        else
        {
            printf("Invalid Input");
        }
    }
    printf("%s",coach_class);
    fclose(fp);
}

int main (void)
{
    int option;
    printf("----------------Welcome to Railway Ticketing System Powered by IIIT UNA-----------------\n\n");
    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d",&option);

    getchar();           // catching newline.

    if(option == 1)
        {
            system("clear");
            registration();
        }

    else if(option == 2)
        {
            system("clear");
            login();
        }
}
