#include<stdio.h>
#include<malloc.h>
#include"btree.h"
int main(){
    int i, n, ch, q=0, key, k, c;
    struct node *root = NULL,*t1 = NULL, *t2 = NULL;
    do{
        printf("\n\tMenu\n");
        printf("1.create\n2.Inorder Traversing\n3.Preorder Traversing\n4.Postorder Traversing\n5.Search\n6.Insert\n7.Count Total Nodes\n8.Count Leaf nodes\n9.Copy Tree\n10.Mirror image\n11.create t1\n12.create t2\n13.CompareBST\n15.Exit\n");
        printf("Enter  Your choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1: root = create(root);
            break;
            case 2:inorder(root);
            break;
            case 3:preorder(root);
            break;
            case 4:postorder(root);
            break;
            case 5:printf("\nEnter Value to search : ");
                scanf("%d",&key);
                k = search(root, key);
                if(k == 1){
                    printf("Element  Found!\n");
                }
                else{
                    printf("Element Not found!\n");
                }
                break;
            case 6:root = insert(root);
            break;
            case 7:c = countNode(root);
                    printf("\n%d elements\n",c);
                break;
                case 8:c = countLeaf(root);
                printf("%d Leaf Elements!\n",c);
                break;
            case 9:root = treeCopy(root);
                inorder(root);
                break;
            case 10: mirror(root);
                inorder(root);
                break;
            case 11:t1 = create(t1);
            break;
            case 12:t2 = create(t2);
            break;
            case 13:k = compareBST(t1, t2);
                if(k == 1){
                    printf("Two trees are equal\n");
                }
                else{
                    printf("Two trees are not equal\n");
                }
                break;
            case 15:q=1;
            break;
        }
    }while(q!=1);
    return 0;
}