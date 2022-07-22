#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define  MAX_SIZE  100

struct Data readData();
void addNewTask();
void viewAllTask();
void editTask();
void deleteTask();
void deletedTasks();

struct Data {
    char task_name[MAX_SIZE][MAX_SIZE];
    int day[MAX_SIZE], month[MAX_SIZE], year[MAX_SIZE], due_date[MAX_SIZE];
};

int main() {
    int choice;
    printf("\n\n\t***********************************\n");
    printf("\t*PERSONAL TASK MANAGEMENT SYSTEM*\n");
    printf("\t***********************************");;

    while(1) {
        printf("\n\n\t\tMAIN MENU:\n\n");
        printf("\tADD NEW TASK\t\t[1]\n");
        printf("\tVIEW ALL TASKS\t\t[2]\n");
        printf("\tEDIT TASK\t\t[3]\n");
        printf("\tDELETE TASK\t\t[4]\n");
        printf("\tRECENTLY DELETED\t[5]\n");
        printf("\tEXIT PROGRAM\t\t[0]\n\n");

        printf("\tENTER OPTION: ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {
            case 1:
                addNewTask();
                break;
            case 2:
                viewAllTask();
                break;
            case 3:
                editTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                deletedTasks();
                break;
            case 0:
                printf("\tTHANK YOU FOR USING THE SYSTEM, HAVE A GOOD DAY!");
                getch();
                exit(0);

            default:
                printf("==========================INVALID INPUT=========================");
                break;
        }
        printf("\n===============PRESS ENTER KEY RETURN TO MAIN MENU===============\n\n");
        getch();
    }
}

void addNewTask() {
    int day, month, year;
    char task_name[MAX_SIZE];
    FILE  *fpointer = fopen("TaskFile.txt", "a");

    printf("\n\n\t\t***************************\n");
    printf("\t\t* WELCOME TO THE ADD MENU *");
    printf("\n\t\t***************************\n\n");
    printf("\t- ENTER NEW TASK NAME: ");
    scanf("%s", task_name);
    printf("\n\t- ENTER DUE DATE:[dd-mm-yyyy] ");
    printf("\n\tDAY:");
    scanf("%d", &day);
    printf("\n\tMONTH:");
    scanf("%d", &month);
    printf("\n\tYEAR:");
    scanf("%d", &year);
    printf("\n\n==================INFORMATION ADDED SUCCESSFULLY=================");
    fprintf(fpointer, "%s %d %d %d\n", task_name, day, month, year);
    fclose(fpointer);

}

void viewAllTask() {
    struct Data data = readData();
    int temporary1, temporary2, temporary3, temporary4, choice, index = 1;
    char temporary5[100];
    printf("\n\n\t\t***************************\n");
    printf("\t\t* WELCOME TO THE VIEW MENU *");
    printf("\n\t\t***************************\n\n");
    printf("\tSORT: \n");
    printf("\tASCENDING DATE\t\t[1]\n");
    printf("\tDESCENDING DATE\t\t[2]\n");
    printf("\tRECENTLY ADDED\t\t[3]\n");
    printf("\tALPHABETICAL ORDER\t[4]\n");



    printf("\n\tENTER OPTION: ");
    scanf("%d", &choice);
    printf("\n\n");

    switch (choice) {
        //1 = ascending order
        case 1:
            for (int i = 0; i < 100; i++) {
                for (int j = i + 1; j < 100; j++) {
                    if (data.due_date[i] != 0 && strcmp(data.task_name[i], "empty") != 0) {

                        if (data.due_date[i] > data.due_date[j]) {

                            temporary1 = data.day[i];
                            temporary2 = data.month[i];
                            temporary3 = data.year[i];
                            temporary4 = data.due_date[i];
                            strcpy(temporary5, data.task_name[i]);


                            data.day[i] = data.day[j];
                            data.month[i] = data.month[j];
                            data.year[i] = data.year[j];
                            data.due_date[i] = data.due_date[j];
                            strcpy(data.task_name[i], data.task_name[j]);

                            data.due_date[j] = temporary1;
                            data.day[j] = temporary1;
                            data.month[j] = temporary2;
                            data.year[j] = temporary3;
                            data.due_date[j] = temporary4;
                            strcpy(data.task_name[j], temporary5);
                        }
                    }
                }
            }
            printf("\n\n=============VIEWING TASKS IN ASCENDING DATE ORDER=============\n\n");
            printf("\tTASK NAME\t\t|\tDUE DATE (dd-mm-yyyy)\n");

            for (int i = 0; i < 100; i++) {
                if (strcmp(data.task_name[i], "empty") != 0) {
                    printf("%d.) %-28s|\t\t%d-%d-%d\n", index, data.task_name[i], data.day[i], data.month[i], data.year[i]);
                    index++;
                }
            }
            break;

            //descending order
        case 2:
            for (int i = 0; i < 100; i++) {
                for (int j = i + 1; j < 100; j++) {
                    if (data.due_date[i] != 0 && strcmp(data.task_name[i], "empty") != 0) {  //1 = descending order    !0 NOT WORKING
                        if (data.due_date[i] < data.due_date[j]) {
                            temporary1 = data.day[i];
                            temporary2 = data.month[i];
                            temporary3 = data.year[i];
                            temporary4 = data.due_date[i];
                            strcpy(temporary5, data.task_name[i]);


                            data.day[i] = data.day[j];
                            data.month[i] = data.month[j];
                            data.year[i] = data.year[j];
                            data.due_date[i] = data.due_date[j];
                            strcpy(data.task_name[i], data.task_name[j]);

                            data.due_date[j] = temporary1;
                            data.day[j] = temporary1;
                            data.month[j] = temporary2;
                            data.year[j] = temporary3;
                            data.due_date[j] = temporary4;
                            strcpy(data.task_name[j], temporary5);
                        }
                    }
                }
            }
            printf("\n\n=============VIEWING TASKS IN DESCENDING DATE ORDER=============\n\n");
            printf("\tTASK NAME\t\t|\tDUE DATE (dd-mm-yyyy)\n");

            for (int i = 0; i < 100; i++) {
                if (strcmp(data.task_name[i], "empty") != 0 && data.day[i] != 0) {
                    printf("%d.) %-28s|\t\t%d-%d-%d\n", index, data.task_name[i], data.day[i], data.month[i], data.year[i]);
                    index++;
                }
            }
            break;

            //Recently added order
        case 3:
            printf("\n\n=============VIEWING TASKS IN RECENTLY ADDED ORDER=============\n\n");
            printf("\tTASK NAME\t\t|\tDUE DATE (dd-mm-yyyy)\n");

            for (int i = 99; i >= 0; i--) {
                if (strcmp(data.task_name[i], "empty") != 0) {
                    printf("%d.) %-28s|\t\t%d-%d-%d\n", index, data.task_name[i], data.day[i], data.month[i], data.year[i]);
                    index++;
                }
            }
            break;

            //Alphabetical Order
        case 4:
            printf("\n\n=============VIEWING TASKS IN ALPHABETICAL ORDER=============\n\n");
            printf("\tTASK NAME\t\t|\tDUE DATE (dd-mm-yyyy)\n");
            for(int i = 0; i < 100; i++) {
                for(int j = i + 1; j < 100; j++) {
                    if (data.due_date[i] != 0 && strcmp(data.task_name[i], "empty") != 0) {

                        if (strcmp(data.task_name[i], data.task_name[j]) > 0) {
                            temporary1 = data.day[i];
                            temporary2 = data.month[i];
                            temporary3 = data.year[i];
                            temporary4 = data.due_date[i];
                            strcpy(temporary5, data.task_name[i]);


                            data.day[i] = data.day[j];
                            data.month[i] = data.month[j];
                            data.year[i] = data.year[j];
                            data.due_date[i] = data.due_date[j];
                            strcpy(data.task_name[i], data.task_name[j]);

                            data.due_date[j] = temporary1;
                            data.day[j] = temporary1;
                            data.month[j] = temporary2;
                            data.year[j] = temporary3;
                            data.due_date[j] = temporary4;
                            strcpy(data.task_name[j], temporary5);
                        }
                    }
                }
            }
            for (int i = 0; i < 100; i++) {
                if (strcmp(data.task_name[i], "empty") != 0 && data.day[i] != 0) {
                    printf("%d.) %-28s|\t\t%d-%d-%d\n", index, data.task_name[i], data.day[i], data.month[i], data.year[i]);
                    index++;
                }
            }
            break;

        default:
            printf("=========================INVALID INPUT=========================");
            break;
    }
}

void editTask() {
    struct Data data = readData();
    int len = 0, choice, index, flag = 1;
    FILE  *fpointer = fopen("TaskFile.txt", "w");

    printf("\n\n\t\t******************************\n");
    printf("\t\t* WELCOME TO THE EDITING MENU *");
    printf("\n\t\t******************************\n\n");
    printf("\n\tSELECT A TASK TO EDIT:\n\n");
    for (int i = 0; i < 100; i++) {
        if (strcmp(data.task_name[i], "empty") != 0) {
            printf("\t%s\t[%d]\n", data.task_name[i], i+1);
            len++;
        }
    }
    printf("\n\tENTER OPTION: ");
    scanf("%d", &choice);

    for (int i = 1; i <= len; i++) {
        if (choice == i) {
            index = i - 1;
            printf("\n\n\n\n================EDITING INFORMATION FOR (%s)================\n\n", data.task_name[index]);

            printf("\tEDIT TASK NAME\t[1]");
            printf("\n\tEDIT DUE DATE\t[2]");
            printf("\n\n\tENTER OPTION: ");


            scanf("%d", &choice);

            while(flag) {
                switch (choice) {
                    case 1:
                        printf("\nSET NEW TASK NAME: ");
                        scanf("%s", &data.task_name[index]);
                        flag = 0;
                        break;
                    case 2:
                        printf("\nSET NEW DUE DATE:[dd-mm-yyyy] ");
                        printf("\nDAY:");
                        scanf("%d", &data.day[index]);
                        printf("MONTH:");
                        scanf("%d", &data.month[index]);
                        printf("YEAR:");
                        scanf("%d", &data.year[index]);
                        flag = 0;
                        break;

                    default:
                        printf("=====================INVALID INPUT=====================\n");
                        getch();
                        break;
                }
            }
        }
    }
    for (int i = 0; i < len; i++) {
        fprintf(fpointer, "%s %d %d %d\n", data.task_name[i], data.day[i], data.month[i], data.year[i]);
    }
    printf("\n================INFORMATION CHANGED SUCCESSFULLY================");
    fclose(fpointer);
}

void deleteTask() {
    struct Data data = readData();
    int len = 0, choice;
    FILE  *fpointer = fopen("TaskFile.txt", "w");
    FILE  *fpointer1 = fopen("RecentlyDeleted.txt", "a");

    printf("\n\n\t\t******************************\n");
    printf("\t\t* WELCOME TO THE DELETE MENU *");
    printf("\n\t\t******************************\n\n");
    printf("\n\tSELECT A TASK TO DELETE:\n\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(data.task_name[i], "empty") != 0) {
            printf("\t%s\t[%d]\n", data.task_name[i], i+1);
            len++;
        }
    }
    printf("\n\tENTER OPTION: ");
    scanf("%d", &choice);

    for (int i = 1; i <= len; i++) {
        if (choice == i) {
            fprintf(fpointer1, "%s %d %d %d\n", data.task_name[i-1], data.day[i-1], data.month[i-1], data.year[i-1]);

            while(i<len){
                strcpy(data.task_name[i - 1], data.task_name[i]);
                data.day[i - 1] = data.day[i];
                data.month[i - 1] = data.month[i];
                data.year[i - 1] = data.year[i];
                i++;
            }

        }
    }

    len--; //to prevent printing "empty" 0 0 0 on txt file for the deleted element

    for (int i = 0; i < len; i++) {
        fprintf(fpointer, "%s %d %d %d\n", data.task_name[i], data.day[i], data.month[i], data.year[i]);
    }

    printf("\n\n=================INFORMATION DELETED SUCCESSFULLY=================");
    fclose(fpointer);
    fclose(fpointer1);
}

//return TaskName and due_date
struct Data readData() {
    int index = 0;

    FILE  *fpointer = fopen("TaskFile.txt", "r");
    struct Data data;

    for (int i = 0; i < 100; i++) {
        data.day[i] = 0;
        data.month[i] = 0;
        data.year[i] = 0;
        data.due_date[i] = 0;
        strcpy(data.task_name[i], "empty");
    }
    while (!feof(fpointer)) {
        fscanf(fpointer, "%s" "%d" "%d %d", &data.task_name[index], &data.day[index], &data.month[index], &data.year[index]); //first assumption POINTER due_date to convert from string to int or second assumption is that the code will not work without it
        data.due_date[index] = data.year[index] * 10000 + data.month[index] * 100 + data.day[index]; //yyyy0000 - mm00 - dd
        index++;
    }
    fclose(fpointer);
    return data;
}

void deletedTasks() {
    struct Data data1;
    int index = 0;
    for (int i = 0; i < 100; i++) {
        data1.day[i] = 0;
        data1.month[i] = 0;
        data1.year[i] = 0;
        data1.due_date[i] = 0;
        strcpy(data1.task_name[i], "empty");
    }
    FILE  *fpointer1 = fopen("RecentlyDeleted.txt", "r");
    printf("\n\n=====================RECENTLY DELETED TASKS=====================\n\n");
    while (!feof(fpointer1)) {
        fscanf(fpointer1, "%s" "%d" "%d %d", &data1.task_name[index], &data1.day[index], &data1.month[index],&data1.year[index]);
        if(strcmp(data1.task_name[index], "empty") != 0) {
            printf("\tTASK NAME\t\t|\tDUE DATE (dd-mm-yyyy)\n");
            printf("%d.) %-28s|\t\t%d-%d-%d\n", index + 1, data1.task_name[index], data1.day[index], data1.month[index],data1.year[index]);
            index++;
        }
    }
    fclose(fpointer1);
}
