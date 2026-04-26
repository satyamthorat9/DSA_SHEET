#include<stdio.h>
#include<malloc.h>
//node declaration
struct node {
    int data;
    struct node *right, *left;
};

//node creation
struct node *create(struct node *root){
    struct node *temp = NULL, *p = NULL;
    int i, n;
    printf("Enter How many values :");
    scanf("%d", &n);
    printf("Enter actual values :");
    for(i = 0; i < n; i++){
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->left = p->right =NULL;
        if(root == NULL){
            root = p;
        }
        else {
            temp = root;
            while(temp != NULL){
                if(p->data < temp->data){
                    if(temp->left == NULL){
                        temp->left = p;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else if(p->data > temp->data){
                    if(temp->right == NULL){
                        temp->right = p;
                        break;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
        }
    }
    return root;
}

//Inorder Trversing
void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

//Preorder Traversing
void preorder(struct node *root){
    if(root != NULL){
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//Postorder Traversing
void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

//search an element
int search(struct node *root, int x){
    struct node *temp = NULL;
    temp = root;
        if(x == temp->data){
            return 1;
        }
        else if(x < temp->data)
            search(temp->left, x);
        else if(x > temp->data)
            search(temp->right, x);
        else 
        return 0;
}

//Insert an Element
struct node *insert(struct node *root){
    struct node *temp = NULL, *p = NULL;
    int key;
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Element to insert : ");
    scanf("%d",&p->data);
    p->left = p->right = NULL;
    if(root == NULL){
        return p;
    }
    else
        temp = root;
    while(temp != NULL){
        if(p->data < temp->data){
            if(temp->left == NULL){
                temp->left = p;
                break;
            }
            else {
                temp=temp->left;
            }
        }
        else if(p->data > temp->data){
            if(temp->right == NULL){
                temp->right = p;
                break;
            }
            else {
                temp = temp->right;
            }
        }
        else {
            printf("Duplicate Values not allowed!");
            free(p);
            break;
        }
    }
    return root;
}

//Count total no of nodes
int countNode(struct node *root){
    static int c = 0;
    if(root == NULL){
        return 0;
    }
    else{
        countNode(root->left);
        c++;
        countNode(root->right);
    }
    return c;
}

//count Leaf node
int countLeaf(struct node *root){
    static int c = 0;
    if(root != NULL){
        countLeaf(root->left);

        if(root->left == NULL && root->right == NULL)
            c++;
        countLeaf(root->right);
    }
    return c;
}

//copy tree
struct node *treeCopy(struct node *root){
    struct node *p = NULL;
    if(root == NULL){
        return NULL;
    }
    else {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = root->data;
        p->left = treeCopy(root->left);
        p->right = treeCopy(root->right);
        return p;
    }
}

//mirror image
void mirror(struct node *root){
    struct node *p=NULL;
    if(root == NULL){
        return;
    }
    p = root->left;
    root->left = root->right;
    root->right = p;
    mirror(root->left);
    mirror(root->right);
}

//Compare two trees
int compareBST(struct node *t1, struct node *t2){
    if(t1 == NULL && t2 == NULL){
        return 1;
    }
    return((t1 && t2) && (t1->data == t2->data) && compareBST(t1->left, t2->left) && compareBST(t1->right, t2->right));
}


// **********************Graph**************************//








// slip 6 DBMS
CREATE OR REPLACE FUNCTION drivers_above_50(depot VARCHAR)
RETURNS VOID AS $$
DECLARE
    rec RECORD;
BEGIN
    FOR rec IN
        SELECT d.driver_name, d.d_age
        FROM driver d
        JOIN bus b ON d.driver_no = b.bus_no
        WHERE b.depot_name = depot AND d.d_age > 50
    LOOP
        RAISE NOTICE 'Name: %, Age: %', rec.driver_name, rec.d_age;
    END LOOP;
END;
$$ LANGUAGE plpgsql;

//slip 2
CREATE OR REPLACE FUNCTION total_persons(a_name VARCHAR)
RETURNS INT AS $$
DECLARE
    total INT;
BEGIN
    SELECT COUNT(*) INTO total
    FROM person p JOIN area a ON p.aname = a.aname
    WHERE a.aname = a_name;

    RETURN total;
END;
$$ LANGUAGE plpgsql;