#include<stdio.h>
#include<stdlib.h>


typedef struct{
	int somme;
	int taille;
	int pile[50];
}mypile;

int estvide(mypile p){
	if(p.somme==0)
		return 1;
	else 
		return 0;
}

int estpleinne(mypile p){
	if(p.somme==p.taille)
		return 1;
	else 
		return 0;
}

void empiler(mypile * p,int v){
	p->pile[p->somme]=v;
	p->somme++;
}
 
int depiler(mypile*p){
	p->somme=p->somme-1;
	return p->pile[p->somme];
}

int main(){
	mypile p1; 
	int n;
	printf("donne la valeur de pile : ");
	scanf("%d",&p1.taille);
	p1.somme=0;
	while(!estpleinne(p1)){
		printf("donne un valeur n : ");
		scanf("%d",&n);
		empiler(&p1,n);
	}
	while(!estvide(p1)){
		printf("\n%d",depiler(&p1));
	}
}