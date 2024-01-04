#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct dll{
	struct dll *prev;
	char name[10];
	int rn;
	float marks;
	struct dll *next;
}dll;
void add_end(dll **);
void add_begin(dll **);
void print(dll *);
int count(dll *);
void search(dll *);
void save_file(dll *);
void read(dll **);
void sort_data(dll *);
void main(){
	int op;
	dll *hp=0;
	while(1){
		printf("1) add_end 2) add_begin 3) print 4)count 5)delete_rn 6) search 7)save in file 8)read from file 9)sorting the data accoring to rollno");
		scanf("%d",&op);

		switch(op){
			case 1: add_end(&hp);
				break;
			case 2: add_begin(&hp);
				break;
			case 3:print(hp);	
			       break;
			case 4:  int cnt;
				 cnt=count(hp);
				 printf("count====%d\n",cnt);
				 break;
				 //			case 5: delete_rn(&hp);
				 //			         break;
			case 6: search(hp);
				break;
			case 7:save_file(hp);	
			       break;
			case 8: read(&hp);
				break;
			case 9: sort_data(hp);
				break;
		}
	}
}
void sort_data(dll* ptr)
{
	dll *p2,*p1,temp;
	int i,j,c=count(ptr);
	p1=ptr;
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-1-i;j++)
		{


			if(p1->rn>p2->rn)
			{

				temp.rn=p1->rn;
				strcpy(temp.name,p1->name);
				temp.marks=p1->marks;

				p1->rn=p2->rn;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;


				p2->rn=temp.rn;
				strcpy(p2->name,temp.name);
				p2->marks=temp.marks;

			}


			p2=p2->next;
		}


		p1=p1->next;
	}
}




void read(dll **ptr){
	FILE *fp=fopen("data","r");
	if(fp==0)
	{
		printf("file not opened\n");
		return;
	}
	dll *new;
	while(1){
		new=calloc(1,sizeof(dll));
		if(fscanf(fp,"%s %d %f",new->name,&new->rn,&new->marks)==-1)
			break;
		dll *last=*ptr;
		if(*ptr==0)
			*ptr=new;	
		else {
			last=*ptr;
			while(last->next)
				last=last->next; 
			last->next=new;
			new->prev=last;
		}
	}
}
void save_file(dll *ptr){
	FILE *fp=fopen("data","w+");
	if(fp==0)
	{
		printf("file not created\n");
		return;
	}
	while(ptr){
		fprintf(fp,"%s %d %f\n",ptr->name,ptr->rn,ptr->marks);
		ptr=ptr->next;
	}
	fclose(fp);
}
void search(dll *ptr){
	printf("enter the roll no to search\n");
	int rollno;
	scanf("%d",&rollno);
	while(ptr)
	{
		if(ptr->rn==rollno)
		{
			printf("%s %d %f\n",ptr->name,ptr->rn,ptr->marks);
			return;
		}
		ptr=ptr->next;
	}
}
int  count(dll *ptr){
	int c=0;
	while(ptr)
	{
		ptr=ptr->next;
		c++;
	}
	return c;
}
void print(dll *ptr)
{
	if(ptr==0)
	{
		printf("no records present\n");
		return;
	}

	while(ptr){
		printf("%s %d %f\n",ptr->name,ptr->rn,ptr->marks);
		ptr=ptr->next;
	}
}
void add_end(dll **ptr){
	dll *new=calloc(1,sizeof(dll));
	dll *last;
	printf("enter the name rollno and marks\n");
	scanf("%s %d %f",new->name,&new->rn,&new->marks);
	if(*ptr==0)
	{
		*ptr=new;
	}
	else {
		last=*ptr;
		while(last->next)
			last=last->next; 
		last->next=new;
		new->prev=last;
	}

}
void add_begin(dll **ptr){
	dll *new=calloc(1,sizeof(dll));
	printf("enter the name rollno and marks\n");
	scanf("%s %d %f",new->name,&new->rn,&new->marks);
	if(*ptr==0)
	{
		*ptr=new;
	}
	else {
		new->next=*ptr;
		(*ptr)->prev=new;
		*ptr=new;
	}
}
