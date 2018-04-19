#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

typedef struct{
	int item[MAX];
	int top;
}Pilha;

typedef struct{
	int item[MAX];
	int calda;
}Lista;

int popf(Lista *l){
	return l->item[l->calda];
}

int pop(Pilha *p){
	return p->item[p->top];
}

int push(Pilha *p,int v){
	p->top++;
	p->item[p->top]=v;
}

int verif(int v[],Lista *l,int n,Pilha *p){
	int i,c=0;
	p->top=-1;
	l->calda=0;
	for(i=0;i<n;i++){
		while(1){
			if(v[i]==popf(l)){
				l->calda++;
				c++;
				break;
			}
			else {
				if(v[i]==pop(p)){
					p->top--;
					c++;
					break;
				}
				else if(l->calda <n){
					push(p,l->item[l->calda]);
					l->calda++;
					continue;
				}
				break;
			}
		}
	}
	if(c==n){
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int i,n;
	Pilha p1;
	Lista l;
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		do{
			int v[n];
			for(i=0;i<n;i++){
				l.item[i]=i+1;
				scanf("%d",&v[i]);
				if(v[0]==0){
					break;
				}
			}
			if(v[0]==0){
				printf("\n");
				break;
				}
			else if(verif(v,&l,n,&p1)  ){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
			
		}while(1);
	}
	return 0;
}
