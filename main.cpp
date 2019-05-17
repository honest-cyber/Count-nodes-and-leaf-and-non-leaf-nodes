#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* chap;
    struct node* rast;
};


unsigned int barg(struct node* node)
{
  if(node == NULL)
    return 0;
  if(node->chap == NULL && node->rast==NULL)
    return 1;
  else
    return barg(node->chap)+barg(node->rast);
}

unsigned int gheyrbarg (struct node* node)
{
  if(node == NULL)
    return 0;

    if(node->chap != NULL || node->rast!=NULL)
          return gheyrbarg(node->chap)+gheyrbarg(node->rast)+1;

}
int count(struct node *root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + count(root->chap) + count(root->rast);
    }
}


struct node* nodejadid(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->chap = NULL;
  node->rast = NULL;

  return(node);
}


int main()
{

  struct node *root = nodejadid(1);
  root->chap        = nodejadid(2);
  root->rast       = nodejadid(3);
  root->chap->chap  = nodejadid(4);
  root->chap->rast = nodejadid(5);
  root->rast->chap = nodejadid(6);
  root->rast->rast = nodejadid(7);
  root->rast->chap->chap = nodejadid(8);
  root->chap->chap->rast = nodejadid(9);



  printf("bargha  :%d", barg(root));
  printf("\ngheyr barg ha : %d", gheyrbarg(root));
  printf("\ntedad gere ha : %d \n",count(root));

  getchar();
  return 0;
}
