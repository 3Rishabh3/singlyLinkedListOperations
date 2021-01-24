#include <stdio.h>
#include <stdlib.h>

int count=0;
struct node{
    int data;
    struct node *next;
} *head,*tail,*temp,*temp2;


int showLinkedList(){
    temp=head;
    while (temp!=NULL){
        printf("%d   ",temp->data);
        temp=temp->next;
    }
    return 0;
}


int insertionAtBeg(int myData)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = myData;
    temp->next = NULL;

    if(head==NULL){
        head=temp;
        tail=temp;
    }

    else{
        temp->next = head;
        head = temp;
    }

    printf("\nElement added at beginning Successfully\n");
    return 0;
}


int insertionAtEnd(int myData)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = myData;
    temp->next = NULL;

    if(head==NULL){
        head=temp;
        tail=temp;
    }

    else{
        tail=head;
        while (tail->next!=NULL){
            tail=tail->next;
        };
        tail->next=temp;
        temp->next=NULL;
        tail=temp;
    }


    printf("\nElement added at end Successfully\n");
    return 0;
}


int insertionAtAnyPlace(int myData, int position)
{
    temp2=head;
    while(temp2!=NULL){
        temp2=temp2->next;
        count++;
    }


    if(position>=count || position==0 || position==count-1){
        printf("\nCan't insert at this position");
        printf("\nEnter here :");
        scanf("%d",&position);
        count=0;
        insertionAtAnyPlace(myData,position);
    }

    else {
        count=0;
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = myData;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp2 = head;
            for (int i = 0; i < position - 1; i++) {
                temp2 = temp2->next;
            }

            temp->next = temp2->next;
            temp2->next = temp;
        }


        printf("\nElement added at place %d", position);
        printf(" Successfully\n");
    }

    return 0;
}


int deletionAtBeg()
{
    temp2=head;
    if(head==NULL){
        printf("\nNode is empty");
    }

    else{
        head=head->next;
        free(temp2);
        printf("\nElement deleted at beginning Successfully\n");
    }

    return 0;
}


int deletionAtEnd()
{
    tail=head;
    if(tail==NULL){
        printf("\nNode is empty");
    }

    else{
        while(tail->next->next!=NULL){
            tail=tail->next;
        }
        printf("%d\n",tail->data);
        temp2=tail->next;
        tail->next=NULL;
        free(temp2);
        printf("\nElement deleted at end Successfully\n");
    }

    return 0;
}


int deletionAtAnyPlace(int position)
{
    temp2=head;
    while(temp2!=NULL){
        temp2=temp2->next;
        count++;
    }

    if(count<=2){
        printf("\nCan't delete\n");
        count=0;
    }


    else if(position>=count || position==0 || position==count-1){
        printf("\nCan't insert at this position");
        printf("\nEnter here :");
        scanf("%d",&position);
        count=0;
        deletionAtAnyPlace(position);
    }

    else{
        count=0;
        if (head == NULL) {
            printf("Node is empty");
        }
        else {
            temp2=head;
            for (int i = 0; i < position - 1; i++) {
                temp2 = temp2->next;
            }

            temp=temp2->next;
            temp2->next=temp2->next->next;
            free(temp);
            printf("\nElement deleted at place %d",position);
            printf(" Successfully\n");
        }
    }

    return 0;
}




int main() {

    char choice1='y';
    char choice2;
    int option;
    int myData;
    int position;

    mainMenu:
    printf("\n****** M A I N -- M E N U ******");
    printf("\n1.Insert Node");
    printf("\n2.Delete Node");
    printf("\n3.Exit Program");
    printf("\nEnter Option Here :");
    scanf("%d",&option);
    switch(option){
        case 1:
        insert:
            printf("\nWhere do you want to insert ?");
            printf("\n1.At the Beginning");
            printf("\n2.At the End");
            printf("\n3.At any Place except Beg. and End");
            printf("\n4.Main Menu");
            printf("\n5.Exit Program");
            printf("\nEnter Option Here :");
            scanf("%d",&option);
            switch(option){
                case 1:
                    printf("Enter data to insert at Beginning :");
                    scanf("%d",&myData);
                    insertionAtBeg(myData);
                    showLinkedList();
                    printf("\n1.Insert more items");
                    printf("\n2.Main Menu");
                    printf("\n3.Exit Program");
                    printf("\nEnter Option here :");
                    scanf("%d",&option);
                    if(option==1) goto insert;
                    else if(option == 2) goto mainMenu;
                    else{
                        printf("You exited successfully");
                        break;
                    }

                case 2:
                    printf("Enter data to insert at the End :");
                    scanf("%d",&myData);
                    insertionAtEnd(myData);
                    showLinkedList();
                    printf("\n1.Insert more items");
                    printf("\n2.Main Menu");
                    printf("\n3.Exit Program");
                    printf("\nEnter Option here :");
                    scanf("%d",&option);
                    if(option==1) goto insert;
                    else if(option == 2) goto mainMenu;
                    else{
                        printf("You exited successfully");
                        break;
                    }

                case 3:
                    printf("Enter data to insert at certain place :");
                    scanf("%d",&myData);
                    printf("\nPlease enter position Where do you want to insert data :");
                    scanf("%d",&position);
                    insertionAtAnyPlace(myData,position);
                    showLinkedList();
                    printf("\n1.Insert more items");
                    printf("\n2.Main Menu");
                    printf("\n3.Exit Program");
                    printf("\nEnter Option here :");
                    scanf("%d",&option);
                    if(option==1) goto insert;
                    else if(option == 2) goto mainMenu;
                    else{
                        printf("You exited successfully");
                        break;
                    }

                case 4: goto mainMenu;

                case 5:
                    printf("You exited successfully");
                    break;

                default:
                    printf("\nWrong option chosen, Wanna try once more to insert??");
                    printf("\nType Y or N here :");
                    scanf("%s",&choice2);
                    if(choice2=='Y' || choice2=='y') goto insert;
                    else goto mainMenu;
            }
            break;

        case 2:
        deleteOperation:
            printf("\nWhere do you want to Delete:");
            printf("\n1.At the Beginning");
            printf("\n2.At the End");
            printf("\n3.At any Place except Beg. and End");
            printf("\n4.Main Menu");
            printf("\n5.Exit Program");
            printf("\nEnter Option Here :");
            scanf("%d",&option);
            switch(option) {
                case 1:
                    deletionAtBeg();
                    showLinkedList();
                    printf("\n1.Delete more items");
                    printf("\n2.Main Menu");
                    printf("\n3.Exit Program");
                    printf("\nEnter Option here :");
                    scanf("%d", &option);
                    if (option == 1) goto deleteOperation;
                    else if(option == 2) goto mainMenu;
                    else{
                        printf("You exited successfully");
                        break;
                    }

                case 2:
                    deletionAtEnd();
                    showLinkedList();
                    printf("\n1.Delete more items");
                    printf("\n2.Main Menu");
                    printf("\n3.Exit Program Program");
                    printf("\nEnter Option here :");
                    scanf("%d", &option);
                    if (option == 1) goto deleteOperation;
                    else if(option == 2) goto mainMenu;
                    else{
                        printf("You exited successfully");
                        break;
                    }

                case 3:
                    printf("Please enter position Where do you want to Delete data :");
                    scanf("%d", &position);
                    deletionAtAnyPlace(position);
                    showLinkedList();
                    printf("\n1.Delete more items");
                    printf("\n2.Main Menu");
                    printf("\n3.Exit Program");
                    printf("\nEnter Option here :");
                    scanf("%d", &option);
                    if (option == 1) goto deleteOperation;
                    else if(option == 2) goto mainMenu;
                    else{
                        printf("You exited successfully");
                        break;
                    }

                case 4:
                    goto mainMenu;

                case 5:
                    printf("You exited successfully");
                    break;

                default:
                    printf("\nWrong option chosen, Wanna try once more to delete??");
                    printf("\nType Y or N here :");
                    scanf("%s", &choice2);
                    if (choice2 == 'Y' || choice2 == 'y') goto deleteOperation;
                    else goto mainMenu;
            }
            break;

        case 3:
            printf("You exited successfully");
            break;

        default:
            printf("\nWrong Choice entered, Please enter correct choice");
            goto mainMenu;
    }


    return 0;
}
