#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
ena struct Agwnas
kathe agwnas tha xei mesa thn ghpedouxo omada(char15), thn filoksenoumeni, ta goal tis ghpedouxou kai ta goal tis filoksenoumenis
rwtaw ton user posous agwnes exei paiksei stoixima 
ta vazw se pinaka agwnwn
se synartiseis:
gia kathe enan agwna na zitaw tis omades kai ta goal tis kathe omadas (gemisma)
display -> 1. paok vs aris 1-3
synolika goal -> 1. paok vs aris synolika goal: 4
pou na metraei to synolo goal olwn twn agwnwn
pou na vriskei ton mo twn goal olwn twn agwnwn
mo twn goal mono gia match me synolika goal>4
na metraei posa paixnidia o gipedouxos kerdise xwris na valei h alli omada goal
na zitaw mia omada kai na elegxw an einai gipedouxos kai na ektipwnw ton filoksenoumeno kai ta goal twn 2 
sorting asc ws pros ta goal twn gipedouxwn
display
na metrisw ta under 2.5 /over 2.5 me pointers
*/

struct Agwnas{
	char gip_om[15];
	char fil_om[15];
	int goal_gip;
	int goal_fil;
};

void gemisma(struct Agwnas agwnes_list[],int agwnes);
void display(struct Agwnas agwnes_list[],int agwnes);
void synolika_goal(struct Agwnas agwnes_list[],int agwnes);
void synolika_goal_olwn(struct Agwnas agwnes_list[],int agwnes);
void mo_goal_olwn(struct Agwnas agwnes_list[],int agwnes);
void mo_goal_panw_apo_4(struct Agwnas agwnes_list[],int agwnes);
void nikes_gip_no_goal(struct Agwnas agwnes_list[],int agwnes);
void searching(struct Agwnas agwnes_list[],int agwnes);
void sorting_asc(struct Agwnas agwnes_list[],int agwnes);
void over_under_pointers(struct Agwnas agwnes_list[],int agwnes,int *under,int *over);

int main() {
	int under=0;
	int over=0;
	int agwnes;
	printf("Posous agwnes exeis paiksei stoixima;\n");
	scanf("%i",&agwnes);
	struct Agwnas agwnes_list[agwnes];
	
	gemisma(agwnes_list,agwnes);
	display(agwnes_list,agwnes);
	synolika_goal(agwnes_list,agwnes);
	synolika_goal_olwn(agwnes_list,agwnes);
	mo_goal_olwn(agwnes_list,agwnes);
	mo_goal_panw_apo_4(agwnes_list,agwnes);
	nikes_gip_no_goal(agwnes_list,agwnes);
	searching(agwnes_list,agwnes);
	sorting_asc(agwnes_list,agwnes);
	display(agwnes_list,agwnes);
	over_under_pointers(agwnes_list,agwnes,&under,&over);

	printf("Over: %i, Under: %i",over,under);
	return 0;
}

void gemisma(struct Agwnas agwnes_list[],int agwnes){
	int i;
	int goal_gip;
	int goal_fil;
	char gip_om[15];
	char fil_om[15];
	for(i=0; i<agwnes; i++){
		printf("Dwse tin gipedouxo omada\n");
		scanf("%s",&gip_om);
		strcpy(agwnes_list[i].gip_om,gip_om);
		printf("Dwse ta goal tis gipedouxou omadas\n");
		scanf("%i",&goal_gip);
		agwnes_list[i].goal_gip=goal_gip;
		printf("Dwse tin filoksenoumeni omada\n");
		scanf("%s",&fil_om);
		strcpy(agwnes_list[i].fil_om,fil_om);
		printf("Dwse ta goal tis filoksenoumenis omadas\n");
		agwnes_list[i].goal_fil=goal_fil;
		scanf("%i",&goal_fil);
		agwnes_list[i].goal_fil=goal_fil;
		printf("\n\n");
	}
}

//display score
void display(struct Agwnas agwnes_list[],int agwnes){
	int i;
	printf("\n");
	for (i=0; i<agwnes; i++){
		printf("%i. %s vs %s %i-%i\n",i+1,agwnes_list[i].gip_om,agwnes_list[i].fil_om,agwnes_list[i].goal_gip,agwnes_list[i].goal_fil);
	}
	printf("\n");
}

//display synolika goal
void synolika_goal(struct Agwnas agwnes_list[],int agwnes){
	int i;
	int syn_goal=0;
	for (i=0; i<agwnes; i++){
		syn_goal=agwnes_list[i].goal_gip+agwnes_list[i].goal_fil;
		printf("%i. %s vs %s synolika goal: %i\n",i+1,agwnes_list[i].gip_om,agwnes_list[i].fil_om,syn_goal,syn_goal);
	}
	printf("\n");
}

//display synolo goal olwn twn agwnwn
void synolika_goal_olwn(struct Agwnas agwnes_list[],int agwnes){
	int i;
	int syn_goal=0;
	for (i=0; i<agwnes; i++){
		syn_goal += agwnes_list[i].goal_gip+agwnes_list[i].goal_fil;
	}
	printf("Ta synolika goal olwn twn agwnwn einai %i\n",syn_goal);
}

//mo goal olwn 
void mo_goal_olwn(struct Agwnas agwnes_list[],int agwnes){
	int i;
	double mo;
	int syn_goal=0;
	for (i=0; i<agwnes; i++){
		syn_goal += agwnes_list[i].goal_gip+agwnes_list[i].goal_fil;
	}
	if (agwnes==0){
		mo=0;
	}
	else{
		mo=(double)syn_goal/(2*agwnes);
	}
	printf("O mo olwn twn goal einai %.2f\n",mo);	
}

//mo twn goal mono gia match me synolika goal panw apo 4
void mo_goal_panw_apo_4(struct Agwnas agwnes_list[],int agwnes){
	int i,syn_goal;
	double mo;
	int sum=0;
	int count=0;
	for (i=0; i<agwnes; i++){
		syn_goal=agwnes_list[i].goal_gip+agwnes_list[i].goal_fil;
		if (syn_goal>4){
			sum+=syn_goal;
			count++;
		}
	}
	if (count==0){
		mo=0;
	}
	else{
		mo=(double)sum/count;	
	}
	printf("O mo twn goal mono gia ta match me synolika goal panw apo 4 einai %.2f\n",mo);
}

//nikes gipedouxou xwris na valei h alli omada goal
void nikes_gip_no_goal(struct Agwnas agwnes_list[],int agwnes){
	int i;
	int count=0;
	for (i=0; i<agwnes; i++){
		if (agwnes_list[i].goal_fil==0 && agwnes_list[i].goal_gip!=0){
			count++;
		}
	}
	printf("Oi nikes gipedouxou xwris na valei h alli omada goal einai %i\n",count);
}

//searching
void searching(struct Agwnas agwnes_list[],int agwnes){
	int i;
	int pos=-1;
	char omada[15];
	printf("Dwse mia omada gia na psakso\n");
	scanf("%s",&omada);
	//printf("Omada pou dothike : %s",omada);
	for (i=0; i<agwnes; i++){
		if (strcmp(omada,agwnes_list[i].gip_om)==0){
			printf("H omada htan gipedouxos epekse me %s kai to score htan %i-%i\n",agwnes_list[i].fil_om,agwnes_list[i].goal_gip,agwnes_list[i].goal_fil);
			pos=i;
		}
		else if (strcmp(omada,agwnes_list[i].fil_om)==0){
			printf("H omada htan filoksenoumeni epekse me %s kai to score htan %i-%i\n",agwnes_list[i].gip_om,agwnes_list[i].goal_gip,agwnes_list[i].goal_fil);
			pos=i;
		}	
	}
	if (pos==-1){
		printf("H omada den vrethike!!!\n");
	}
}

//sorting asc ws pros goal gipedouxwn
void sorting_asc(struct Agwnas agwnes_list[],int agwnes){
	int i,j;
	struct Agwnas temp;
	
	printf("\n");
	for (i=0; i<agwnes-1; i++){
		for (j=0; j<agwnes-i-1; j++){
			if (agwnes_list[j].goal_gip>agwnes_list[j+1].goal_gip){
				//swap goal gip
				temp=agwnes_list[j];
				agwnes_list[j]=agwnes_list[j+1];
				agwnes_list[j+1]=temp;
				
			}
		}
	}
} 

//over under me pointers
void over_under_pointers(struct Agwnas agwnes_list[],int agwnes,int *under,int *over){
	int i;
	int syn_goal;
	for (i=0; i<agwnes; i++){
		syn_goal=agwnes_list[i].goal_gip+agwnes_list[i].goal_fil;
		if (syn_goal>2.5){
			*over=*over+1;
		}
		else{
			*under=*under+1;
		}
	}
}

	

