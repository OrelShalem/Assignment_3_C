#include "StrList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    char* _data;
    struct _Node * _next;
} Node;


typedef struct _StrList{
    Node* _head;
    size_t _size;
}StrList;

Node* Node_alloc(char* data,
				 Node* next) {
                    Node* node = (Node*)malloc(sizeof(Node));
                    node->_data = data;
                    node->_next = next;
                    return node;
}

void Node_free(Node* node) {
    free(node->_data);
    free(node);
}

StrList* StrList_alloc(){
    StrList* list = (StrList*)malloc(sizeof(StrList));
    list->_head = NULL;
    list->_size = 0;
    return list;
}


void StrList_free(StrList* StrList){
    Node* p1 = StrList->_head;
    Node* p2 = NULL;
    while(p1!= NULL){
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    StrList ->_head = NULL;
    StrList->_size = 0;
    return;
}

size_t StrList_size(const StrList* StrList){
    return StrList ->_size;
}

void StrList_insertLast(StrList* StrList,
					  const char* data){
                        Node* newNode = Node_alloc(strdup(data),NULL);
                        if (newNode == NULL)
                        {
                            return;
                        }

                        Node* current = StrList -> _head;
                        if (current == NULL)
                        {
                            StrList ->_head = newNode;
                        }
                        else{
                            while (current ->_next != NULL)
                            {
                                current= current ->_next;
                            }
                            current ->_next = newNode;
                        }
                        StrList ->_size++;
                      }
/*
* Inserts an element at given index
*/
void StrList_insertAt(StrList* StrList,
	const char* data,int index){
        Node* newNode = Node_alloc(strdup(data),NULL);
        if (newNode == NULL)
        {
            return;
        }

        Node* current = StrList -> _head;
        if (current == NULL)
        {
            StrList ->_head = newNode;
        }
        else if (index == 0)
        {
            newNode -> _next = current;
            StrList -> _head = newNode;
        }
        else{
            int i = 0;
            while (i < index - 1)
            {
                current= current ->_next;
                i++;
            }
            newNode ->_next = current ->_next;
            current ->_next = newNode;
        }
        StrList ->_size++;
                        
    }

    char* StrList_firstData(const StrList* StrList){
        return StrList -> _head ->_data;
    }

    void StrList_print(const StrList* StrList){
        const Node* current = StrList -> _head;
        while (current)
        {
            printf("%s",current->_data);
            if (current-> _next == NULL)
            {
                break;
            }
            printf(" ");
            current = current -> _next;
        }
        printf("\n");
    }

    void StrList_printAt(const StrList* Strlist,int index){
        if (index < 0 || Strlist -> _size < index)
        {
            return;
        }
        const Node* current = Strlist -> _head;
        int counter = 0;
        while (counter < index)
        {
            current = current -> _next;
            counter++;
        }
        printf("%s\n", current->_data);
    }

    /*
    * Return the amount of chars in the list.
    */
    int StrList_printLen(const StrList* Strlist){
        int len = 0;
        const Node* current = Strlist -> _head;
        while (current)
        {
            len += strlen(current->_data);
            if (current-> _next == NULL)
            {
                break;
            }
            current = current -> _next;
        }
        return len;
    }

    /*
    Given a string, return the number of times it exists in the list.
    */
   int StrList_count(StrList* StrList, const char* data){
        int count = 0;
        const Node* current = StrList -> _head;
        while (current)
        {
        if (strcmp(current->_data,data) == 0)
            {
            count++;
            }
        current = current -> _next;
        }
        return count;
   }
    /*
	Given a string and a list, remove all the appearences of this string in the list.
    */
    void StrList_remove(StrList* StrList, const char* data){
        Node* current = StrList -> _head;
        Node* prev = NULL;
        while (current){
            if (strcmp(current->_data,data) == 0){
                if (prev == NULL){
                    StrList -> _head = current -> _next;
                }
                else{
                    prev -> _next = current -> _next;
                }
                StrList -> _size--;
                Node_free(current);
                current = StrList -> _head;
            }
            else{
                prev = current;
                current = current -> _next;
            }
        }

    }

    void StrList_removeAt(StrList* StrList, int index){
         if (index < 0 || StrList -> _size < index)
        {
            return;
        }
        if (index == 0)
        {
            StrList -> _head = StrList -> _head -> _next;
            return;
        }
        
        Node* current = StrList -> _head;
        int counter = 0;
        while (counter < index - 1){
            current = current -> _next;
            counter++;
        }
        Node* previous = current;
        current = current -> _next;
        previous -> _next = current -> _next;
        StrList -> _size--;
        Node_free(current);
    }

    int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
        if (StrList1 -> _size!= StrList2 -> _size)
        {
            return 0;
        }
        Node* current1 = StrList1 -> _head;
        Node* current2 = StrList2 -> _head;
        while (current1){
            if(current1 -> _data!= current2 -> _data){
                return 0;
            }
            current1 = current1 -> _next;
            current2 = current2 -> _next;
        }
        return 1;
    }

    StrList* StrList_clone(const StrList* Strlist){
        StrList* newList = StrList_alloc();
        if (newList == NULL)
        {
            return NULL;
        }
        const Node* current = Strlist -> _head;
        while (current)
        {
            StrList_insertLast(newList,current -> _data);
            current = current -> _next;
        }
        return newList;
    }

    void StrList_reverse( StrList* StrList){
    Node* current = StrList -> _head; // current is the pointer to the current node
    Node* previous = NULL; // previous is the pointer to the previous node

    while (current) {
        Node* next = current -> _next; // next is the pointer to the next node
        current -> _next = previous; // switch the next and previous pointers
        previous = current; // update the previous pointer
        current = next; // move to the next node
    }

    StrList -> _head = previous; // update the head pointer to point to the new head of the reversed list
}

    /*
    * Sort the given list in lexicographical order 
    */
    void StrList_sort(StrList* StrList) {
        if (StrList == NULL || StrList->_head == NULL || StrList->_head->_next == NULL) {
            return; // Handle empty or single-element lists
        }

        int swapped;
        Node* current;
        Node* pre = NULL;

        /* Checking for empty list */
        if (StrList->_head == NULL)
            return;

        do {
            swapped = 0;
            current = StrList->_head;

        while (current->_next != pre) {
            if (strcmp(current->_data, current->_next->_data) > 0) { 
                char* temp = current->_data;
                current->_data = current->_next->_data;
                current->_next->_data = temp;
                swapped = 1;
            }
            current = current->_next;
        }
        pre = current;
        }
        while (swapped);

    }


    /*
    * Checks if the given list is sorted in lexicographical order
    * returns 1 for sorted,   0 otherwise
    */
    int StrList_isSorted(StrList* StrList){
        if (StrList == NULL || StrList->_head == NULL || StrList->_head->_next == NULL) {
            return 1;
        }

        Node* current = StrList->_head;
        while (current) {
            Node* next = current->_next;
            if(next == NULL) {
                return 1;
            }
            if (strcmp(current->_data, next->_data) > 0) {
                return 0;
            }
            current = next;
        }
        return 1;
    }

    char* read_string() {
    char* input = NULL;
    size_t len;

    // Get input from user
    if (getline(&input, &len, stdin) == -1) {
        printf("Failed to read input.\n");
        free(input);
        return NULL;
    }

    // Remove trailing newline from the string
    input[strcspn(input, "\n")] = '\0';

    return input;
}




    