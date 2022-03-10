#include <stdio.h>
#include <stdlib.h>

/* Definition of Int List */
typedef struct IntList   IL;   /* */
typedef struct IntList* PIL;   /* */

struct IntList {
   int h;
   PIL t;//IntList* 포인터
};

enum Bool{False,True};

PIL IL_empty;
int IL_head(PIL);      /* IL head            */
PIL IL_tail(PIL);      /* IL tail            */ 
PIL IL_cons(int, PIL); /* ::  IL construct   */
PIL IL_ins(Bool,int,PIL);//operator, int x, int list il; 
PIL isort (Bool (*gt)(int, int), PIL);
bool IL_is_empty(PIL);
bool is_empty(PIL);
Bool int_great_than(int, int);

void IL_print(PIL);

int main()
{
  /* Initialization for empty IL set and empty ILL set */
   
   if ((IL_empty=(PIL)malloc(sizeof(IL)))==NULL)
   {
      printf("No memory available!\n");
      exit(0);
   }
   
   /* This is just a simple version of defining a set. 
      You have to construct the code to input each set from the standard input. */

   /* Defining an empty set */
   IL_empty->h=0;
   IL_empty->t=NULL;

	/* insertion Sort */
	PIL l = NULL;
    int tmp=0;
    for(int i=0;i<5;i++){
        scanf("%d",&tmp);
        l = IL_cons(tmp,l);
    }
    //l = IL_cons(3,IL_cons(1,IL_cons(4,IL_cons(5,IL_cons(9,IL_cons(2,IL_cons(6, NULL))))))); 
	l = isort(&int_great_than,l);
	IL_print(l);
	
    return 0;
}

/*
fun ins gt (x,nil) = [x]
        | ins gt (x, y::ys) =
                if gt(x,y) then
                        y::ins gt (x,ys)
                else x::y::ys;
fun isort gt nil = nil
        | isort gt (x::xs) =
                ins gt (x, (isort gt xs));
isort (op >) [3,1,4,5,9,2,6];
*/

bool IL_is_empty(PIL l){
    if (l == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool is_empty(PIL l){
    if(l->t != NULL){
        return true;
    }
    else{
        return false;
    }
}

Bool int_great_than(int x, int y){
	if(x>y) return True;
	else return False;
}

PIL IL_ins(Bool (*gt)(int, int),int x,PIL l){
	int y;
	if(IL_is_empty(l))/*[]*/
	{
		return IL_cons(x,l);
	}
	else
	{
		if((*gt)(x, y=IL_head(l)))
		{
			return IL_cons(y, IL_ins(gt,x,IL_tail(l)));
		}
		else
		{
			return IL_cons(x,l);
		}
	}
}

PIL isort (Bool (*gt)(int, int), PIL l)
{
	if(!is_empty(l)){ /*!l->head = NULL*/
		return l;
	}
	else
	{
		IL_ins(gt, IL_head(l), isort(gt, IL_tail(l)));
	}
}

int IL_head(PIL intlist)       /* IL head            */
{
    return intlist->h;
}
PIL IL_tail(PIL intlist)       /* IL tail            */ 
{
    return intlist->t;//intlist와 연결된 intlist의 주소값을 반환
}
PIL IL_cons(int x, PIL intlist)          /* ::  IL construct   */
{
    PIL pintlist = (PIL)malloc(sizeof(IL));
    pintlist->t = intlist;
    pintlist->h = x;
    return pintlist;
}

void IL_print(PIL intlist)
{
    if(intlist == NULL){
        return;
    }
    else {
        if(intlist->h != 0){
            printf("%d ",intlist->h);
        }
        IL_print(intlist->t);
        return;
    }
}