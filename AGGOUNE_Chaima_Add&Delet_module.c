#include<stdio.h>
#include<stdlib.h>
								/* AGGOUNE Chaima Groupe 01 */
typedef struct module{
	char intitule[30];
	int conficient;
	struct module *next;
}module;

/*Creat The Liste*/
module* creatlist(int n){
	module *head=(module*) malloc(sizeof(module));
	if(head==NULL)
		printf("element not created ! ");
	else{	
		printf("enter the intitule number 1  : ");
		scanf("%s",&head->intitule);
		printf("enter the conficient number 1  : ");
		scanf("%d",&head->conficient);
		head->next=NULL;
		
		module *tmp=head;
		int i;
		for(i=2;i<=n;i++){ 
			/*creat new module */
			module *newmodule= (module*)malloc(sizeof(module));
			printf("enter the intitule number %d : ",i);
			scanf("%s",&newmodule->intitule);
			printf("enter the conficient number %d  : ",i);
			scanf("%d",&newmodule->conficient);
	 		newmodule->next=NULL;
			
			tmp->next=newmodule;
			tmp= tmp->next;
		}
		
	}
	return head;
	
	
}
/* Add Module In The Begining */
module* addBegin(module *head){
	module *newmodule= (module*)malloc(sizeof(module));
	if(head==NULL){//empty  linked list
		newmodule->next=NULL;
		head=newmodule;
		}
	else{// full linked list
		printf("enter the intitule number : ");
		scanf("%s",&newmodule->intitule);
		printf("enter the conficient number  : ");
		scanf("%d",&newmodule->conficient);
		newmodule ->next=head;
		head=newmodule;
	}		
	return head;

}

/* Add Module In The End */
module* addEnd( module *head){
	module *newmodule= (module*)malloc(sizeof(module));
	newmodule->next=NULL;
	if(head==NULL){// empty linked list
		head=newmodule;	// head=addBegin(head,d);
		}
	else{// full linked list
		printf("enter the intitule number : ");
		scanf("%s",&newmodule->intitule);
		printf("enter the conficient number  : ");
		scanf("%d",&newmodule->conficient);
		module *tmp=head;
		while(tmp->next!=NULL)
		{tmp=tmp->next;} 
		tmp->next=newmodule;
		}
	return head;

}
/* Add In Given Position */
module* addPosition(module *head){
	int reponse , pos , i=0 ;
    module *tmp;
	tmp = head; 
    module *newmodule = ( module*) malloc(sizeof(module));
    printf("\n How Do You Want To Add The Newmodule ?? ");
   printf("\n 1.befor position.");
	printf("\n 2.after position \n  ");
	printf("\n the reponse is :");
	scanf("%d",&reponse);
	switch (reponse){
		/*Add Befor Position */
		case 1 :
			printf("enter the position :");
			scanf("%d",&pos);
			while( tmp->next != NULL && i<=pos-1){
				tmp=tmp->next;
				i++;
			}
			break;
		/*Add After Position */
		case 2 :
		    printf("enter the position :");
			scanf("%d",&pos);
			while( tmp->next != NULL && i<=pos){
				tmp=tmp->next;
				i++;
			}
			break;
		default :
			printf("\n Invalid number ! \n");
			tmp=NULL;	
	}
	if(tmp==NULL) printf("\n  Invalid position or Invalid module \n");
	else {
		printf("enter the intitule number : ");
		scanf("%s",&newmodule->intitule);
		printf("enter the conficient number  : ");
		scanf("%d",&newmodule->conficient);
		newmodule->next=tmp->next;
		tmp->next = newmodule; 
	} 
	return head; 
}
/* Delet Module In The Begining */
module* deleteBegin(module *head){
	if(head==NULL)
	{	printf("YOUR LIST IS EMPTY");
		return head;
	}
	else{
		module *tmp=head;
		head=head->next;
		free(tmp);
		return head;
	}
	
}
/* Delet Module In The End */
module* deleteEnd(module* head){
	if(head==NULL)
	{	printf("YOUR LIST IS EMPTY");
		return head;
	}
	if(head->next==NULL)
	{	free(head);
		return NULL;
	}
	else{
		module *avantTmp, *tmp=head;
		while(tmp->next!=NULL){
			avantTmp=tmp;
			tmp=tmp->next;
		}
		free(tmp);
		avantTmp->next=NULL;
		return head;
	}
}
/* Delet In Given Position */
module* deletePosition(module *head){
  int i=1 , pos ;

  printf("\n How do you want to delete module ? ");
  printf("\nEnter the number of position :");
  scanf("%d",&pos);
  module *tmp,*avanttmp;
  tmp= head ;
  while(tmp!= NULL && i<=pos){
    avanttmp=tmp;
    tmp=tmp->next;
    i++;
  }
  avanttmp->next=tmp->next;
  free(tmp);
  
   return head;
}

/* Display The Liste */
void displaymodule( module*head){
	struct module *tmp = head;
	if(head == NULL){
		printf("list empty");
	}else {
		printf("\n  list of module\n");
		while (tmp != NULL) {
	        printf("intitule: %s, conficient: %d\n", tmp->intitule, tmp->conficient);
			tmp = tmp->next;
		}
	}
};
int main(){
	struct module *head;
	int N;
	printf("number of module N is :");
	scanf("%d",&N);
	char reponse_1 ,reponse_2 ;
	int pos_1 , pos_2 ;
	head = creatlist( N);
	displaymodule(head);
	do{
		printf("do you want to add a new couyrse (y,n) :");
		reponse_1 = getche();
		if(reponse_1 == 'y'|| reponse_1 =='Y'){
			printf("\nWhere you want to add it ?  ");
			printf("\n  1.In begin.");
			printf("\n  2.In a given position.");
			printf("\n  3.In end. ");
			printf("\n  reponse_1 is :");
			scanf("%d",&pos_1);
			switch (pos_1){
				case 1 :
					head = addBegin(head);
					break;
				case 2 :
					head = addPosition(head);
					break;
				case 3 : 
					head = addEnd(head);
					break;
				default:
					printf(" Invalid number ! \n");
			}
		}displaymodule(head);
	}while(reponse_1=='y' || reponse_1=='Y');
	do {
		printf("\n do you want to delet a module (y,n) :");
		reponse_2 = getche();
		if(reponse_2=='y' || reponse_2=='Y'){
			printf("\n Which module you want to delete it ? ");
			printf("\n  1.In begin .");
			printf("\n  2.In a given position.");
			printf("\n  3.In end. ");
			printf(" \n reponse_2 is :");
			scanf("%d",&pos_2);
			switch (pos_2){
				case 1 :
					head = deleteBegin(head);
					break;
				case 2 :
					head = deletePosition(head);
					break;
				case 3 :
					head = deleteEnd(head);
					break;
				default:
					printf(" Invalid number ! \n");
			}
	}displaymodule(head);
}while(reponse_2=='y' || reponse_2=='Y');

}
