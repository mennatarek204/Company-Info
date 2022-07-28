#include<stdio.h>
#include<stdlib.h>
typedef struct company{
    int id;
    float salary;
}Company[100];

void read(Company employees){
	int i,n;
	printf("Enter number of employees: ");
		scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("ID #%d: ",(i+1));
		scanf("%d",&employees[i].id);
		printf("salary #%d: ",(i+1));
		scanf("%f",&employees[i].salary);
		printf("\n");
	}
}

void sort(Company employees){
    int i,j;
    float temp=0.0;
    for(i=0;i<50;i++){
        for(j=0;j<49;j++)
            if(employees[j].salary<=employees[j+1].salary){
                temp=employees[j+1].salary;
                employees[j+1].salary=employees[j].salary;
                employees[j].salary=temp;
            }
    }
}

void find(Company employees){
    int i;
    float n;
    printf("To find salaries that exceed >> ");
        scanf("%f",&n);
    for(i=0;i<100;i++){
        if(employees[i].salary>n)
            printf("ID#%d of salary %.1f exceeds %.1f\n",employees[i].id,employees[i].salary,n);
    }

}

void payraise(Company employees){
    int i,n,temp[50]={0};
    float per,percentage,pay;
    printf("Enter number of employees you want to give pay raise: ");
        scanf("%d",&n);
    printf("Enter IDs to be pay raised: ");
        for(i=1;i<=n;i++)
            scanf("%d",&temp[i]);
    printf("Enter %% of pay raise: ");
        scanf("%f",&per);
    percentage=per/100;
        for(i=1;i<=n;i++){
            pay=employees[i].salary+(employees[i].salary*percentage);
            printf("ID#%d pay raise = %.1f\n",(i+1),pay);
        }
}

void print_salaries(Company employees){
	int i,j;
	printf("\n________________________________________________________________________________________________\n");
	printf("Salaries:-\n");
	for(j=0;j<100;j++){
		if(employees[j].salary!=0)
		printf("Salary #%d: %.1f\t",(j+1),employees[j].salary);
	}
 printf("\n________________________________________________________________________________________________\n");
}

int main(){
    Company employees[100]={0};
	read(employees);
	sort(employees);
	find(employees);
	payraise(employees);
	print_salaries(employees);
	return 0;
}
