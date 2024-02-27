#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "StrList.h"

void printMenu(){
    printf("Main Menu:\n");
    printf("1. Add strings to the list.\n");
    printf("2. Add a string at a specific index.\n");
    printf("3. Print the list.\n");
    printf("4. Print the length of the list.\n");
    printf("5. Print a string at a specific index.\n");
    printf("6. Print the total number of characters in the list.\n");
    printf("7. Enter a string and print its number of occurrences in the list.\n");
    printf("8. Enter a string and delete all its occurrences from the list.\n");
    printf("9. Enter an index and delete the corresponding element.\n");
    printf("10. Reverse the list.\n");
    printf("11. Delete the entire list.\n");
    printf("12. Sort the list lexicographically.\n");
    printf("13. Check if the list is sorted lexicographically.\n");
    printf("0. Exit the program.\n");
}

int main(){
    printMenu();
    int choice;
    StrList* list = StrList_alloc();
    while(true){
        scanf("%d",&choice);
        switch(choice){
            case 1: {
                if (list == NULL) {
                break;
                }
                int length;
                int counter;
                scanf("%d", &length);
                getchar();
                char* input = read_string();
                for(int i=0; i<strlen(input); i++){
                    if(input[i] == ' '){
                        counter++;
                    }
                }
                if(counter+1!=length){
                    break;
                }
                char* token = strtok(input, " \n");
                while (token != NULL) {
                  StrList_insertLast(list, token);
                   token = strtok(NULL, " \n");
                }
                free(token);
                free(input);
                break;
                }
            
            case 2:
                {

                    if (list == NULL){
                        break;
                    }
                    int index;
                    scanf("%d",&index);
                    char* input = read_string();
                    char* token = strtok(input, " \n");
                    while (token != NULL) {
                        StrList_insertAt(list, token, index);
                        token = strtok(NULL, " \n");
                    }
                    free(token);
                    free(input);
                    break;
                }
            case 3:
                {
                    if (list == NULL){
                        break;
                    }
                    StrList_print(list);
                    break;
                }
            case 4:
                {
                    if (list == NULL){
                        break;
                    }
                    printf("%ld\n",StrList_size(list));
                    break;
                }
            case 5:
                {
                    if (list == NULL){
                        break;
                    }
                    int index;
                    scanf("%d",&index);
                    StrList_printAt(list,index);
                    break;
                }
            case 6:
                {
                    if (list == NULL){
                        break;
                    }
                    printf("%d\n",StrList_printLen(list));
                    break;
                }
            case 7:
                {
                    if (list == NULL){
                        break;
                    }
                    char* input = read_string();
                    char* token = strtok(input, " \n");
                    while (token!= NULL) {
                        printf("%d\n",StrList_count(list,token));
                        token = strtok(NULL, " \n");
                    }
                    free(token);
                    free(input);
                    break;
                }
            case 8:
                {
                    if (list == NULL){
                        break;
                    }
                    char* input = read_string();
                    char* token = strtok(input, " \n");
                    while (token!= NULL) {
                        StrList_remove(list,token);
                        token = strtok(NULL, " \n");
                    }
                    free(token);
                    free(input);
                    break;
                }
            case 9:
                {
                    if (list == NULL){
                        break;
                    }
                    int index;
                    scanf("%d",&index);
                    StrList_removeAt(list,index);
                    StrList_print(list);
                    break;
                }
            case 10:
                {
                    if (list == NULL){
                        break;
                    }
                    StrList_reverse(list);
                    StrList_print(list);
                    break;
                }
            case 11:
                {
                    if (list == NULL){
                        break;
                    }
                    StrList_free(list);
                    break;
                }
            case 12:
                {
                    if (list == NULL){
                        break;
                    }
                    StrList_sort(list);
                    break;
                }
            case 13:
                {
                    if (list == NULL){
                        break;
                    }
                    if(StrList_isSorted(list) == 1){
                        printf("true\n");
                    }
                    else{
                        printf("false\n");
                    }
                    break;
                }
            case 0:
                free(list);
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}