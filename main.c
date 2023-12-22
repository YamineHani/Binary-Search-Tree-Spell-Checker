#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//done
typedef struct node node;
struct node{
    char *word;
    node *left,*right;
};
node *NewNode(char*st){
    node*n= malloc(sizeof (node));
    n->left=n->right=NULL;
    n->word= malloc(strlen(st)+1);
    strcpy(n->word,st);
    return n;
}
void scan(node*root);
node *InsertNode(node *root, char *st){
    if(!root) return NewNode(st);
     if(strcasecmp(root->word,st)>0) root->left= InsertNode(root->left,st);
     else root->right= InsertNode(root->right,st);
    return root;
}
int height(node*root){
    if(!root) return -1;
    else{
        int right= height(root->right);
        int left = height(root->left);
        return right>left?(right+1):(left+1);
    }
}
void readFile(char *fileName){
    int i=0;
    FILE *f=fopen(fileName,"r");
    if(!f){
        printf("ERROR READING FILE %s\n",fileName);
        exit(1);
    }
    node*m=NULL;
    while(!feof(f)){
        char str[300];
        fscanf(f,"%s",str);
        i++;
        m=InsertNode(m,str);
    }
    fclose(f);
    printf("FILE LOADED SUCCESSFULLY\n");
    printf("SIZE = %d\n",i);
    printf("HEIGHT = %d\n", height(m));
    scan(m);
}

node *search(node*root,char*key ){
    if(root->right==NULL && root->left==NULL)
        return root;
    if(!root|| strcasecmp(root->word,key)==0)
        return root;
     if(strcasecmp(root->word,key)>0 && root->left)
        return search(root->left,key);
    if(strcasecmp(root->word,key)<0 && root->right)
        return search(root->right,key);
    return root;

}
node *findMin(node*root){
    if(root&&root->left)
        return findMin(root->left);
    return root;
}
node *findMax(node*root){
    if(root&&root->right)
        return findMax(root->right);
    return root;
}

node *successor(node*root,char*key){
    if(!root)
        return NULL;
    node *successor=NULL;
    node * n=root;
    while (n&& strcasecmp(n->word,key)!=0){
        if(strcasecmp(n->word,key)>0)
        {successor=n; n=n->left;}
        else
            n=n->right;
    }
    if(!n)
        return NULL;
    if(n&&n->right)
        successor= findMin(n->right);
    return successor;
}
node *predeccessor(node*root,char*key){
    if(!root)
        return NULL;
    node *pre=NULL;
    node * n=root;
    while (n&& strcasecmp(n->word,key)!=0){
        if(strcasecmp(n->word,key)<0)
        {pre=n; n=n->right;}
        else
            n=n->left;
    }
    if(!n)
        return NULL;
    if(n&&n->left)
        pre= findMax(n->left);
    return pre;
}

void scan(node*root){
    printf("ENTER A SENTENCE\n");
    char st[400];
    gets(st);
    char *tok= strtok(st," ");
    while (tok){
        node*n=NULL;
        n=search(root,tok);
        if(strcasecmp(n->word,tok)==0)
            printf("%s - CORRECT\n",tok);
        else{

            node*s=NULL;
            s=successor(root,n->word);
            node*p=NULL;
            p=predeccessor(root,n->word);
            printf("%s - INCORRECT, SUGGESTIONS : %s %s %s\n",tok,n->word,s->word,p->word);
        }

        tok= strtok(NULL," ");
    }
}


int main() {
    readFile("EN-US-Dictionary.txt");
    return 0;
}
