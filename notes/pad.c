#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

// C file Handling
// File C opperations, create new file , opening, reading, writing & closing

//GOAL make a note pad program wunning on windows

// Steps to proccessing a File
//1. declear a fIle pointer variable
//2. open a file using fopen()
//3. proccess the file using the suitable function
//4. closing the file using fclose()

// file input output functions
// fopen(), fclose(), putc(), putw(), getc(), getw(), fprintf(), fscanf(), fgets(), fputs(), feof()
int main(void)
{
    FILE *fp;
    char answer[10];
    char winput[300];
    char ainput[300];


    printf("write or append?\n");
    scanf("%9s", answer);

    getchar();

    if (strcmp(answer,"write") == 0)
    {
        fp = fopen("filename.txt","w");
        if(fp == NULL)
        {
            printf("error opening the file");
            return 1;
        }
        printf("Input: ");
        fgets(winput, sizeof(winput), stdin);
        fputs(winput,fp);
    }

    else if (strcmp(answer,"append") == 0)
    {
        fp = fopen("filename.txt","a");
        if (fp == NULL)
        {
            printf("error opening the file");
            return 2;
        }
        printf("Input: ");
        fgets(ainput, sizeof(ainput), stdin);
        fputs(ainput,fp);
    }
    else
    {
        printf("invalid input\n");
        return 23;
    }



    fclose(fp);
    return 0;
}


// int main(void)
// {
//     for ()
//     printf("Create new file?\n");
//     scanf("%d", &x);
//     if (x == "yes" && 'y')
//     {

//     }
//     printf("What do you want to do (read/write FILE)?: \n");
//     scanf("%d", &decision);

//     if (decision == "read" && 'r')
//     {

//     }

//     else (decision == "write" && 'w')
//     {
//         FILE *file = fopen("practice.txt", 'r');
//         if (file != NULL)
//         {
//             fwrite()
//         }
//     }
// }
