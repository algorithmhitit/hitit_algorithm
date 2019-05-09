#include <stdio.h>
#include <stdlib.h>

/* Definition of Int List */
typedef struct IntList   IL;   /* */
typedef struct IntList* PIL;   /* */

struct IntList {
   int h;
   PIL t;//IntList* 포인터
};

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
PIL IL_empty;
int IL_head(PIL);      /* IL head            */
PIL IL_tail(PIL);      /* IL tail            */ 
PIL IL_cons(int, PIL); /* ::  IL construct   */
PIL IL_ins(op,int,PIL);//operator, int x, int list il; 
PIL isort (bool (*gt)(int, int), PIL l);

void IL_print(PIL);

/* Definition of Int List List */
typedef struct IntListList   ILL;   /* */
typedef struct IntListList* PILL;   /* */

struct IntListList {
   PIL   h;
   PILL t;
};

PILL ILL_empty;  	              
PIL  ILL_head(PILL);    /* ILL head            */
PILL ILL_tail(PILL);        /* ILL tail            */ 
PILL ILL_cons(PIL,  PILL);  /* ::  ILL Construct  건설하다,구성하다 */
PILL ILL_conc(PILL, PILL);  /* @   ILL Concatenate 사슬같이 잇다, 연쇄시키다. */

void ILL_print(PILL);

/*
fun ins gt (x,nil) = [x]
        | ins gt (x, y::ys) =
                if gt(x,y) then
                        y::ins gt (x,ys)
                else x::y::ys;
*/
PIL IL_ins(bool (*gt)(int, int),int x,PIL l){
	int y;
	if(IL_is_empty(l))/*[]*/
	{
		return IL_cons(x,l);
	}
	else
	{
		if((*gt)(x, y=IL_head(l)))
		{
			return IL_cons(y, ins(gt,x,IL_tail(l)));
		}
		else
		{
			return IL_cons(x,1);
		}
	}
}

PIL isort (bool (*gt)(int, int), PIL l)
{
	if(!is_empty(l)){
		return l;
	}
	else
	{
		ins(gt, IL_head(l), isort(gt, IL_tail));
	}
}

Enum Bool{False,True};

Bool int_great_than(int x, int y)
{
	if(x>y) return True;
	else reutnr False;
}

PILL pre(int x, PILL ll) 
{
   if (!ll)	return NULL;
   else	return ILL_cons(IL_cons(x,ILL_head(ll)),pre(x,ILL_tail(ll)));
}

/* 
  fun pre(x,nil) = nil
   |  pre(x,L::Ls) = (x::L)::pre(x,Ls); 
*/

PILL pow_n(PIL l) 
{
   PILL ps = NULL;
   if (!l)
      return ILL_cons(IL_empty, NULL);
   else 
   {
       ps = pow_n(IL_tail(l));
       return ILL_conc(ps, pre(IL_head(l),ps));   
   }
}

/* 
  fun pow_n([]) = [[]]
   |  pow_n(x::xs) =
       let
          val ps = pow_n(xs);
       in
          ps @ pre(x, ps)
       end;
*/
int main()
{
   PIL   set = NULL;
   PILL pset = NULL;

   /* Initialization for empty IL set and empty ILL set */
   
   if ((IL_empty=(PIL)malloc(sizeof(IL)))==NULL)
   {
      printf("No memory available!\n");
      exit(0);
   }
  
   /* Construct the set of {1, 2, 3} */
   set = IL_cons(1, IL_cons(2, IL_cons(3, NULL))); 
   
   /* This is just a simple version of defining a set. 
      You have to construct the code to input each set from the standard input. */

   /* Defining an empty set */
   IL_empty->h=0;
   IL_empty->t=NULL;
   
   /* Generate the power set of {1, 2, 3} */
   pset = pow_n(set);

   /* Output the power set */
   ILL_print(pset);

	/* insertion Sort */
	PIL l;
	l = isort (&int_great_than,IL_cons(3,IL_cons(1,IL_cons(4,IL_cons(5,IL_cons(9,IL_cons(2,IL_cons(6, NULL)))))));
	IL_print(l);
	//isort�� ���� �Է¹޴� �Լ��� ���� �ʿ�. 
    return 0;
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

PIL  ILL_head(PILL pill)    /* ILL head            */
{
    return pill->h;
}
PILL ILL_tail(PILL pill)         /* ILL tail            */ 
{
    return pill->t;
}
PILL ILL_cons(PIL pil,  PILL pill)   /* ::  ILL Construct  건설하다,구성하다 */
{
    PILL pintlistlist = (PILL)malloc(sizeof(PIL));
    pintlistlist->h = pil;
    pintlistlist->t = pill;
    return pintlistlist;
}
PILL ILL_conc(PILL pillx, PILL pilly)  /* @   ILL Concatenate 사슬같이 잇다, 연쇄시키다. */
{
    PILL tmp = pillx;
    while(tmp->t){
        tmp = tmp->t;
    }
    tmp->t = pilly;
    return pillx;
}
void ILL_print(PILL pill)
{
    PILL tmp = pill;
    printf("[");
    while(tmp){
        printf("[");
        IL_print(tmp->h);
        printf("]");
        tmp = tmp->t;
    }
    printf("]\n");
}
