// #include <stdio.h>
// #include <stdlib.h>

// #define SIZE 10

// // Node structure for linked list
// struct node {
//     int data;
//     struct node* next;
// };

// // Hash table (array of pointers)
// struct node* hashTable[SIZE];

// // Hash function
// int hashFunction(int key) {
//     return key % SIZE;
// }

// // Insert a key
// void insert(int key) {
//     int index = hashFunction(key);

//     struct node* newNode = (struct node*)malloc(sizeof(struct node));
//     newNode->data = key;
//     newNode->next = NULL;

//     // Insert at beginning of linked list
//     newNode->next = hashTable[index];
//     hashTable[index] = newNode;

//     printf("Key %d inserted at index %d\n", key, index);
// }

// // Search a key
// void search(int key) {
//     int index = hashFunction(key);
//     struct node* temp = hashTable[index];

//     while (temp != NULL) {
//         if (temp->data == key) {
//             printf("Key %d found at index %d\n", key, index);
//             return;
//         }
//         temp = temp->next;
//     }

//     printf("Key %d not found\n", key);
// }

// // Display hash table
// void display() {
//     for (int i = 0; i < SIZE; i++) {
//         struct node* temp = hashTable[i];
//         printf("Index %d: ", i);

//         while (temp != NULL) {
//             printf("%d -> ", temp->data);
//             temp = temp->next;
//         }

//         printf("NULL\n");
//     }
// }

// int main() {
//     int choice, key;

//     // Initialize hash table
//     for (int i = 0; i < SIZE; i++)
//         hashTable[i] = NULL;

//     while (1) {
//         printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter key: ");
//                 scanf("%d", &key);
//                 insert(key);
//                 break;

//             case 2:
//                 printf("Enter key to search: ");
//                 scanf("%d", &key);
//                 search(key);
//                 break;

//             case 3:
//                 display();
//                 break;

//             case 4:
//                 exit(0);

//             default:
//                 printf("Invalid choice\n");
//         }
//     }

//     return 0;
// }




#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * head[11], * temp = NULL, *p = NULL;

void insert (){
    int i, key;
    printf("Enter the value to insert :");
    scanf("%d",&key);
    
    i = key % 11;

    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->next = NULL;

    if(head[i] == NULL){
        head[i] = p;
    }
    else {
        temp = head[i];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
    }
}

void search(){
    int i, key;
    printf("Enter the value to search :");
    scanf("%d",&key);

    i = key % 11;   // ✅ FIX

    if(head[i] == NULL)
        printf("\nElement not Found");
    else {
        for(temp = head[i]; temp != NULL; temp = temp->next){
            if(temp->data == key){
                printf("\nElement found");
                return;
            }
        }
        printf("\nElement not Found");
    }
}

void display(){
    int i;
    for(i = 0; i < 11; i++){   // ✅ FIX
        printf("Index %d: ", i);

        if(head[i]==NULL)
            printf("NULL");
        else {
            for(temp = head[i]; temp != NULL; temp = temp->next){
                printf("%d -> ",temp->data);
            }
            printf("NULL");
        }
        printf("\n");
    }
}

int main(){
    int ch, q = 0;

    // ✅ Initialize
    for(int i = 0; i < 11; i++)
        head[i] = NULL;

    do{
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter Your choice :");
        scanf("%d",&ch);

        switch(ch){
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: q = 1; break;
            default: printf("Invalid choice");
        }
    }while(q==0);

    return 0;
}