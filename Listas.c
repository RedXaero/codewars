#include <stdio.h>
#include <stdlib.h>


struct nodo {
    char data;
    struct nodo *ptrNext;
};
//A la antigua, como buen señor
typedef struct nodo node_t;
typedef node_t *ListNodePtr;

void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char val);
void deleteNode(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
void printList(ListNodePtr currentPtr );


int main() {

    /*
    char command[50];
    strcpy(command,"ls -l");
    system(command);
     */


    //*** Abstract Data Types ***

    ListNodePtr head = NULL; //Inicialmente no hay nodos
    int choise = 0;
    char item = '\0';

    /* display the menu */
    printf("Enter your choise\n"
           "    1 to insert an element into the list in alphabetial order.\n"
           "    2 to insert an element at the end of the list.\n"
           "    3 to insert an element at the beginning of the list.\n"
           "    4 to delete an element from the list.\n"
           "    5 to delete an element from the beginning of the list.\n"
           "    6 to end\n");
    printf(":: ");
    scanf("%d%*c", &choise);


    /*The loop*/
    while(choise != 6){
        switch (choise) {
            case 1:{
                printf("Enter a character: ");
                scanf("%c", &item);
                insert(&head, item);
                printList(head);
            }break;

            case 2:{
                printf("Enter a character: ");
                scanf("%c", &item);
                insertAtEnd(&head, item);
                printList(head);
            }break;

            case 3:{
                printf("Enter a character: ");
                scanf("%c", &item);
                insertAtBeginning(&head, item);
                printList(head);
            }break;

            case 4:{
                printf("Enter character to be deleted: ");
                scanf("%c", &item);
                deleteNode(&head, item);
            }break;

            case 5:{
                deleteAtBeginning(&head);
                printList(head);
            }break;

            default:{
                printf("Invalid choise");
            }break;
        }
        printf("Enter your choise\n"
               "    1 to insert an element into the list in alphabetial order.\n"
               "    2 to insert an element at the end of the list.\n"
               "    3 to insert an element at the beginning of the list.\n"
               "    4 to delete an element from the list.\n"
               "    5 to delete an element from the beginning of the list.\n"
               "    6 to end\n");
        printf(":: ");
        scanf("%d%*c", &choise);
    }

    return 0;
}

void insert(ListNodePtr *head, char value){
    ListNodePtr newNode = malloc(sizeof(node_t));
    ListNodePtr ptrCurrent, ptrPrev;

    ptrCurrent = *head;
    newNode->data = value;
    if( *head == NULL){
        *head = newNode;
        newNode->ptrNext = NULL;
    }
    else{

        while(ptrCurrent != NULL && value > ptrCurrent->data){
            ptrPrev = ptrCurrent;
            ptrCurrent = ptrPrev->ptrNext;
        }
        newNode->ptrNext = ptrPrev->ptrNext;
        ptrPrev->ptrNext = newNode;
    }
}


void insertAtEnd(ListNodePtr *head, char value){
    ListNodePtr current = *head;

    if(current != NULL){
        while(current->ptrNext != NULL){
            current = current->ptrNext;
        }

        current->ptrNext = malloc(sizeof (node_t));
        current->ptrNext->data = value;
        current->ptrNext->ptrNext = NULL;
    }
    else{
        current = malloc(sizeof(node_t));
        current->data = value;
        current->ptrNext = NULL;
        *head = current;
    }
}



void insertAtBeginning(ListNodePtr *head, char val){

    ListNodePtr new_Node = malloc(sizeof (node_t));

    new_Node->data = val;
    new_Node->ptrNext = *head;
    *head = new_Node;

}


void deleteNode(ListNodePtr *head, char value){

    if(*head == NULL){
        printf("Nothing to delete!\n");
    }
    else{
        ListNodePtr ptrCurrent, ptrPrev;
        ptrCurrent = *head;
        while(ptrCurrent != NULL && value != ptrCurrent->data){
            ptrPrev = ptrCurrent;
            ptrCurrent = ptrPrev->ptrNext;
        }
        if(ptrCurrent == NULL)
            printf(" %c not found!", value);
        else{
            if(ptrCurrent == *head){
                printf("%c deleted", ptrCurrent->data);
                free(*head);
            }
            else{
                ptrPrev->ptrNext = ptrCurrent->ptrNext;
                printf("%c found and deleted!\n",ptrCurrent->data);
                free(ptrCurrent);
            }
        }
    }
}

void deleteAtBeginning(ListNodePtr *head){
    if(*head == NULL){
        printf("Nothing to delete!\n");
    }
    else{
        ListNodePtr aux = *head;
        *head = (*head)->ptrNext;
        printf("the first value %c has been deleted!\n", aux->data);
        free(aux);
    }
}

void printList(ListNodePtr currentPtr ){
    if(currentPtr == NULL)
        printf("The list is empty!\n");
    else{
        printf("Head\n");
        printf(" |\n");
        printf(" %c\n", 25);

        while (currentPtr != NULL){
            printf(" %c --> ", currentPtr->data);
            currentPtr = currentPtr->ptrNext;
        }
        printf("NULL\n");
    }
}