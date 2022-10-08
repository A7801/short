#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree_node
{
    int val;
    int size;
    struct tree_node* left;
    struct tree_node* right;
} node;

void enumerate(int* temp, node * head, int *c)
{
    if(head->left!=NULL) 
    enumerate(temp, head->left, c);
    else 
    return;
    temp[*c]= head->val;
    *c = *c + 1;
    if(head->right!=NULL)
    enumerate(temp, head->right, c);
    else
    return;
}

void deallo(node * head)
{
    if(head->left!=NULL)
    deallo(head->left);
    if(head->right!=NULL)
    deallo(head->right);
    free(head);
}
/*
void insert(int value, node*head)
{
    while(head->left!=NULL && head->right!=NULL)
    {
        if(value<= head->val && head->left!=NULL)
          head= head->left;
        else if (value> head->val && head->right!=NULL)
          head = head->right;
        else if(value<= head->val && head->left==NULL)
        {
            node *temp = (node *) malloc (sizeof(node));
            temp->size = 0;
            temp->val= value;
            temp->left = NULL;
            temp->right = NULL;
            if(head->right==NULL)
            
        }
    }
    while(head->left!=NULL || head->right!=NULL)
    {
        head->size = head->size +1;
        if(value<= head->val)
         { 
          if(head->left->size + 1 >= 0.75*(head->right->size) && head->right->size >= 0.75*(head->left->size+ 1))
            head= head->left;
          else
            {
                int temp[head->size];
                int c =0;
                temp[head->size -1] = value;
                enumerate(temp,head,&c);
                repair(temp,head);
                return;
            }
         }
        else (value> head->val)
        { 
          if(head->right->size + 1 >= 0.75*(head->left->size) && head->left->size >= 0.75*(head->right->size+ 1))
            head= head->right;
          else
            {
                int temp[head->size];
                int c =0;
                temp[head->size -1] = value;
                enumerate(temp,head,&c);
                repair(temp,head);
                return;
            }
         }
    }
    node *temp = (node *) malloc (sizeof(node));
    temp->size = 1;
    temp->val= value;
    temp->left = NULL;
    temp->right = NULL;
    if(head->left==NULL && head->right==NULL)
    {
        head->size = head->size +1;
        if(value<= head->val)
         head->left = temp;
        else
         head->right = temp;
    }
    else
    {
        head->size = head->size +1;
        int temp[head->size];
        int c =0;
        temp[head->size -1] = value;
        enumerate(temp,head,&c);
        repair(temp, head);
        return;
    }
}
*/

node* insert(int value, node*head, node* t)
{
    head->size = head->size + 1;
    if(value<= head->val)
    {
        if(t==NULL && head->size>3 && (head->left==NULL || head->right==NULL))
        t= head;
        else if(t==NULL && head->left->size + 1 >= 0.75*(head->right->size) && head->right->size >= 0.75*(head->left->size+ 1))
        t = head;
        if(head->left==NULL)
        {
            node *temp = (node *) malloc (sizeof(node));
            temp->size = 1;
            temp->val= value;
            temp->left = NULL;
            temp->right = NULL;
            head->left = temp;
            return t;
        }
        else
        insert(value, head->left, t);
    }
    else
    { 
        if(t==NULL && head->size>3 && (head->left==NULL || head->right==NULL))
         { t= head;}
        else if(t==NULL && (head->right->size + 1 >= 0.75*(head->left->size)) && (head->left->size >= 0.75*(head->right->size+ 1)))
         { t = head; }    
        
        printf("YES\n");
        if(head->right==NULL)
        {        
            node *temp = (node *) malloc (sizeof(node));
            temp->size = 1;
            temp->val= value;
            temp->left = NULL;
            temp->right = NULL;
            head->right = temp;
            return t;
        }
        else
        insert(value, head->right, t);
    }
}

int main()
{
    node *head = (node *) malloc (sizeof(node));
    head->size = 1;
    head->val= 1;
    head->left = NULL;
    head->right = NULL;
    node* x = NULL;
    node* y = NULL;
    for(int i = 2; i<=1e7; i++)
    {
        x = insert(i, head, NULL);
        printf("%d\n", head->val);
        if(x!=NULL)
        {
            //repair tree at x
            //deallo(x);
            ;
        }
    }

}