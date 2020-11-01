#include <stdio.h>
#include <stdlib.h>

struct BstNode{
    int val;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* getNewNode(int data){
    struct BstNode* temp = (struct BstNode*)malloc(sizeof(struct BstNode));
    temp->val=data;
    temp->left = temp->right = NULL;
    return temp;
}

struct BstNode* insert(struct BstNode* root, int data){
    if (root == NULL){
        root = getNewNode(data);
    }
    else if (data < root->val){
        root->left = insert(root->left,data);
    }
    else if (data > root->val){
        root->right=insert(root->right,data);
    }
    return root;
}

int search(struct BstNode* root, int data){
    if (root == NULL){
        return 0;
    }
    else if (root->val==data){
        return 1;
    }
    else if (data < root->val){
        return(search(root->left,data));
    }
    else{
        return(search(root->right,data));
    }
}

struct BstNode* minVal(struct BstNode* root){
    while(root->left != NULL){
        root = root->left;
    }
    return(root);
}

int maxVal(struct BstNode* root){
    while(root->right != NULL){
        root = root->right;
    }
    return(root->val);
}

struct BstNode* delete(struct BstNode* root, int data){
    if(root==NULL){
        return root;
    }
    else if(data < root->val){
        root->left = delete(root->left,data);
    }
    else if(data > root->val){
        root->right = delete(root->right,data);
    }
    else{ //Value Found!!
        // Condition one
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //Condition two
        else if (root->left == NULL){
            struct BstNode* temp = root;
            root = root->right;
            free (temp);
        }
        else if (root->right == NULL){
            struct BstNode* temp = root;
            root=root->left;
            free (temp);
        }
        //Condition three
        else{
            struct BstNode* temp = minVal(root);
            root->val = temp->val;
            root->right = delete(root->right, temp->val);
        }
    }
    return root;
}

void inorder(struct BstNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->val);
        inorder(root->right);
    }
}

void postorder(struct BstNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->val);
    }
}

void preorder(struct BstNode *root)
{
    if (root != NULL)
    {
        printf("%d \n", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct BstNode* root = NULL;
    root = insert(root,15);
    insert(root,27); insert(root,10); insert(root,9);insert(root,13);
    insert(root,12); insert(root,81);insert(root,26);insert(root,23);
    insert(root,21); insert(root,83);
    inorder(root);
    printf("--------------------------------------------------------\n");
    postorder(root);
    printf("--------------------------------------------------------\n");
    delete(root,83);
    preorder(root);
    if(search(root,27)){
        printf("Yes it is present\n");
    }
    else{
        printf("No it is not here\n");
    }
    struct BstNode* temp = minVal(root);
    printf("Min Value %d \n", temp->val);
    printf("Max Value %d", maxVal(root));
    return 0;
}
