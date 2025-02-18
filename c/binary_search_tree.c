#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (!x) {
        printf("Insufficient memory");
        exit(0);
    }
    return x;
}

void preorder(NODE root) {
    if (root) {
        printf("%d\t", root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void postorder(NODE root) {
    if (root) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t", root->info);
    }
}

void inorder(NODE root) {
    if (root) {
        inorder(root->llink);
        printf("%d\t", root->info);
        inorder(root->rlink);
    }
}

NODE insert(int item, NODE root) {
    NODE temp = getnode();
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    if (!root) return temp;
    
    NODE prev = NULL, cur = root;
    while (cur) {
        prev = cur;
        cur = (item < cur->info) ? cur->llink : cur->rlink;
    }
    if (item < prev->info) prev->llink = temp;
    else prev->rlink = temp;
    
    return root;
}

NODE search(int item, NODE root) {
    while (root) {
        if (item == root->info) return root;
        root = (item < root->info) ? root->llink : root->rlink;
    }
    return NULL;
}

int main() {
    int item, ch, n;
    NODE root = NULL;
    
    while (1) {
        printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the number of items: ");
                scanf("%d", &n);
                printf("Enter the items to be inserted: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &item);
                    root = insert(item, root);
                }
                break;
            case 2:
                if (root) {
                    printf("Preorder traversal: ");
                    preorder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 3:
                if (root) {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 4:
                if (root) {
                    printf("Postorder traversal: ");
                    postorder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 5:
                printf("Enter the item to be searched: ");
                scanf("%d", &item);
                if (search(item, root)) {
                    printf("Item found\n");
                } else {
                    printf("Item not found\n");
                }
                break;
            default:
                printf("Exiting...\n");
                return 0;
        }
    }
}
