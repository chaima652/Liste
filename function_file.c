#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int tete;
	int Queue;
	int taille;
	int file[50];
}myfile;

int estvide(myfile f){
	if(f.Queue==f.tete)
		return 1;
	else
		return 0;
}

int estpleinne(myfile f){
	if(f.Queue==f.taille)
		return 1;
	else
		return 0;
}

void enfiler(myfile *f, int v){
	f->file[f->Queue]=v;
	f->Queue++;
}

int defiler(myfile*f){
	return f->file[f->tete++];
	
}

int main(){
	myfile f;
	int v;
	printf("donne taille de file : ");
	scanf("%d",&f.taille);
	f.Queue=f.tete=0;
	while(!estpleinne(f)){
		printf("donne valeur v : ");
		scanf("%d",&v);
		enfiler(&f,v);
	}
	while(!estvide(f)){
		v=defiler(&f);
		printf("%d \n",v);
	}
}