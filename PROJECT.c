#include <stdio.h>			//header files
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
// defining structures
struct deal
{
    int deal_code;
    char deal_name[100];
    float deal_price;
    int quantity;
};
struct employee
{
    int employee_ID;
    char employee_name[20];
    float employee_salary;
}e;
struct pass 
{
	char id[10];
	char password[10];
}p;
struct food
{
    int food_code;
    char food_name[20];
    float food_price;
    int quantity;
};
//prototype
int foodfun();
int foodadd();
int fooddisplay();
int fooddeelete();
int foodupdate();
int dealfun();
int time1();
int dealadd();
int dealdisplay();
int dealdeelet();
int dealupdate();
int employefun();
int employeadd();
int employedisplay();
int employeedeelete();
int employeeupdate();
int m_m(); 
int admin(int num);
int totalbill(float sum,float discount);
int cal();
int total();
int main_menu();
int home(int num);
int employeedata();

int num;		//global variable
// function calling and function definitions
int main()
{
	main_menu();
}
int main_menu()
{
    time1();
    int num;
    printf ("\n\t\t\t\t|| WElCOME TO RESTURANT ||");
    printf ("\n\n\n\t\t\t\t||\t1.ADMIN\t\t||\n\t\t\t\t||\t2.CUSTOMER\t||\n\t\t\t\t||\t0.Exit\t\t||");
    printf ("\n\t\t\tPress key to Process :");
    scanf ("%d",&num);
    home (num);
}
int home (int num)
{ 
	switch (num)
	{ 
    	case 1:
       	time1();
        printf ("\n\n\t\t\t\tWELCOME ADMIN\n");
        printf ("Please Enter Your ID Password to proceed\n");
        admin(num);
	    break;
		case 2:
	  	time1();
	    m_m();
		break;
	    case 0:
        system ("cls");
        exit(1);
	    default :
	    printf ("Please Enter correct key");
	}
}
int m_m()  // main menu screen
{
	time1();
	int n;
	printf("\t\t\t||\t\tWELCOME TO AAF FOODS\t\t||\n");
	printf("\n\t\t||\tPRESS 1 FOR FOOD MENU\t\t\t\t\t||\n");
	printf("\t\t||\tPRESS 2 FOR DEALS MENU\t\t\t\t\t||");
	printf("\n\t\t||\tPRESS 3 FOR EXIT \t\t\t\t\t||\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			time1();
		cal();
		break;
		case 2:
			time1();
		dealcal();
		break;
		case 3:
		main_menu();
		break;
		default:
		printf ("please enter correct key");
	    printf ("\npress any key to try again\n");
	    getch();
		m_m();
	}
}
int admin(int num)
{ 
struct pass p[5];
	char ch,pass1[15],username[10];
    int num1,i,t=0;
	char cp[10];
    printf ("\nUSERNAME:");
    scanf ("%s",username);
    printf  ("\nPassword:");
    while(1)
	{
		ch=getch();
		if(ch==13)
		{
			break;
		}
		else
		{
    	pass1[i]=ch;
        printf("*");
        i++;
        if(i>15)
        {
        	printf("\nlenght exceeded\n");
        	printf("press any key to return");
        	getch();
        	home(num);
		}
        
    	}
    }
    FILE *fp;
	fp=fopen("pass.txt","r");   
	i=0;
    while (!feof(fp))
    {  fscanf (fp,"%s %s\n",p[i].id,p[i].password);
		if (strcmp(pass1,p[i].password)==0&&strcmp(username,p[i].id)==0)   //condition for password verification
		{  
		t++; 
    	time1();
   		int n;
    	while(1)
    		{
	    		printf("\n\t\t\t||\tMAIN MENU\t||\n\n\n");
	    		printf("\t\t||\tFOR EMPLOYEE SERVICE PRESS 1:\t\t||\n\t\t||\tFOR CUSTOMER SERVICE PRESS 2:\t\t||\n\t\t||\tFOR DEALS SERVICE PRESS 3:\t\t||\n\t\t||\tTO CHECK PROFIT/LOSS PRESS 4:\t\t||\n\t\t||\tTO CHECK TOTAL ENCOME PRESS 5:\t\t||\n\t\t||\tTO REMOVE TOTAL ENCOME STORE PRESS 6:\t||\n\t\t||\tTO EXIT PRESS 7:\t\t\t||\n");
	    		scanf("%d",&n);
	    		switch(n)
	    		{
		    		case 1:
		    		//calling add function
		    		time1();
		        	employefun();
		        	break;
		    		case 2:
		    			time1();
		    		//calling  function
		        	foodfun();
		        	break;
			    	case 3:
			    		time1();
		    		//calling delete function
		        	dealfun();
		    		break;
		    		case 4:
		    			time1();
		    		//calling update function
		    		total1();
		    		break;
		   			case 5:
		   				time1();
		    		total();
		    		break;
		    		case 6:
		    			time1();
		    		removetotalincome();
		    		break;
		    		case 7:
		    		//to get out of the infinite loop
		    		//calling main menu function
		        	main_menu();
		        	break;
		        	default:
		        		time1();
		        	printf ("please enter correct key");
		       		printf ("\npress any key to try again");
		       		getch();
		       		admin(num);
	    		}
    		}
		}
	i++;
	}
	if(t==0)
	{
	printf("\nincorrect password\npress enter to try again");
	getch();
	admin(num);
	}

	fclose (fp);
}
//employee department
int employefun()
{
	int n;
	printf("\t\t||\tFOR ADDITION OF EMPLOYEE DATA PRESS 1:\t\t||\n\t\t||\tTO DISPLAY EMPLOYEE DATA PRESS 2:\t\t||\n\t\t||\tTO DELETE EMPLOYEE DATA PRESS 3:\t\t||\n\t\t||\tTO UPDATE EMPLOYEE DATA PRESS 4:\t\t||\n\t\t||");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
    	//calling add function
    	time1();
        employeadd();
        break;
    	case 2:
    	//calling display function
    	time1();
        employedisplay();
        break;
	    case 3:
	    	time1();
    	//calling delete function
        employeedeelete();
    	break;
    	case 4:
    		time1();
        employeeupdate();
   		break;
   		case 5:
    	admin(num);
    	break;
   		default:
   			time1();
   		printf ("please enter correct key");
       	printf ("\npress any key to try again");
       	getch();
       	employefun();
	}
}
//food department
int foodfun()
{
	int n;
	printf("\t\t||\tFOR ADDITION OF FOOD DATA PRESS 1:\t\t||\n\t\t||\tTO DISPLAY FOOD DATA PRESS 2:\t\t\t||\n\t\t||\tTO DELETE FOOD DATA PRESS 3:\t\t\t||\n\t\t||\tTO UPDATE FOOD DATA PRESS 4:\t\t||\n\t\t\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			time1();
    	//calling add function
        foodadd();
    	break;
    	case 2:
    		time1();
    	//calling display function
        fooddisplay();
    	break;
   		case 3:
   			time1();
    	//calling delete function
       	fooddeelete();
    	break;
    	case 4:
    		time1();
    	//calling update function
       	foodupdate();
    	break;
    	case 5:
    	admin(num);
    	break;
   		default:
   			time1();
        printf ("please enter correct key");
       	printf ("\npress any key to try again");
       	getch();
       	foodfun();
	}
}
//deal depertment
int dealfun()
{
	int n;
	printf("\t\t||\tFOR ADDITION OF DEALS DATA PRESS 1:\t||\n\t\t||\tTO DISPLAY DEALS DATA PRESS 2:\t\t||\n\t\t||\tTO DELETE DEALS PRESS 3:\t\t||\n\t\t||\tTO UPDATE DEALS PRESS 4:\t\t||\n\t\t||\tTO EXIT PRESS 5:\t\t\t||\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
    	//calling add function
    	time1();
        dealadd();
    	break;
    	case 2:
    		time1();
    	//calling display function
        dealdisplay();
    	break;
   		case 3:
   			time1();
    	//calling delete function
       	dealdeelete();
    	break;
    	case 4:
    		time1();
    	//calling update function
       	dealupdate();
    	break;
    	case 5:
    	admin(num);
    	break;
   		default:
   			time1();
        printf ("please enter correct key");
       	printf ("\npress any key to try again");
       	getch();
       	dealfun();
	}
}
int employeadd()
{
	int i,n;
	char sel;
    FILE *fp;
    fp=fopen("employe.dat","a");
    if(fp==NULL)
    {
        printf("there is no data\n");
        printf("press any key to exit");
        getch();
        admin(num);
    }
    else
		{
			while(1)
    		{
            	printf("input the employee ID: ");
            	scanf("%d",&e.employee_ID);
        	    fflush(stdin);
            	printf("input the employee name: ");
 	        	gets(e.employee_name);
    	        fflush(stdin);
        	    printf("input the employee salary: ");
        	    scanf("%f",&e.employee_salary);
            	//fwrite to write data in to the file
            	fwrite(&e,sizeof(e),1,fp);
            	printf("do you want to enter another data?(y/n)");
            	scanf(" %c",&sel);
            	fflush(stdin);
            	//to get out of inifinite loop
            	if (sel=='n')
                	{
                	    break;
                	}
    		}
		}
	fclose(fp);
	printf("\t\t|\t\t\t|");
	printf("\t\t|\tADDED SUCESSFULLY\t|");
    printf ("\npress any key to exit");
    getch();
    main();
    return 0;
}
//defining display function
int employedisplay()
{
	FILE *fp;
	fp=fopen("employe.dat","r");
	//fread to read data from the file
		printf("employee ID\temployee name\temployee salary\n");
	while(fread(&e,sizeof(e),1,fp)==1)
	{
	
		printf("%d\t\t%s\t\t%.2f\n",e.employee_ID,e.employee_name,e.employee_salary);
	}
	fclose(fp);
	printf("press any key to go to main menu:");
	getch();
	main();
	return 0;
}
//defining delete funtion
int employeedeelete()
{
	FILE *fp;
	FILE *fpr;
	int count=0,id;
	fp=fopen("employe.dat","r");
	fpr=fopen("extra.DAT","w");
	printf("enter the ID of employee you want to delete:");
	scanf("%d",&id);
	fflush(stdin);
	//reading data from the file
	while(fread(&e,sizeof(e),1,fp)==1)
	{
	    if(id==e.employee_ID)
		{
		printf("\nSUCESSFULLY DELETED\n");
		count=1;
		}
	     else
        {
           //writing data in to the file
		fwrite(&e,sizeof(e),1,fpr);
        }
	}
	if(count==0)
	{
		printf("\nID doesnot exist\n");
	}
	fclose(fpr);
	fclose(fp);
	//removing the original file
	remove("employe.dat");
	//renaming the extra dublicate file into original one
	rename("extra.DAT","employe.dat");
	printf("type any key to go to the main menu:");
	getch();
	main();
	return 0;
}
//function definition to update the file
int employeeupdate()
{
    FILE *fp;
	FILE *fpr;
	int count=0,id;
	fp=fopen("employe.dat","r");
	fpr=fopen("extra.DAT","w");
	printf("enter the ID you want to update:");
	scanf("%d",&id);
	fflush(stdin);
	//reading data from file
	while(fread(&e,sizeof(e),1,fp)==1)
	{
	if(id==e.employee_ID)
		{
            printf("input the employee record: ");
            scanf("%d",&e.employee_ID);
            fflush(stdin);
            printf("input the employee name: ");
            gets(e.employee_name);
            fflush(stdin);
            printf("input the employee price: ");
            scanf("%f",&e.employee_salary);
            fwrite(&e,sizeof(e),1,fpr);
            count=1;
		}
	else
        {
        	//updating the data
		fwrite(&e,sizeof(e),1,fpr);
        }
	}
	if(count==0)
	{
		printf("\nID does not exist\n");
	}
	fclose(fpr);
	fclose(fp);
	remove("employe.dat");
	rename("extra.DAT","employe.dat");
	printf("type any key to go to the main menu:");
	getch();
	main();
	return 0;
}

//definition of functions regarding food
int foodadd()
{
	struct food f[100];
 	int count=0;
	FILE *fpr;
	//opening file
	int i,n;
	char sel;
    FILE*fp;
    fp=fopen("food.txt","a");
    if(fp==NULL)
    {
        printf("file does not exist");
    }
    else
	{
    	for(i=0;i<100;i++)
		{
           	printf("input the food code: ");
           	scanf("%d",&f[i].food_code);
       	    fflush(stdin);
           	printf("input the food name: ");
         	gets(f[i].food_name);
   	        fflush(stdin);
            printf("input the food price: ");
       	    scanf("%f",&f[i].food_price);
       	    fflush(stdin);
       	      	printf("input the food quantity: ");
           	scanf("%d",&f[i].quantity);
       	    fflush(stdin);
           	//fwrite to write data in to the file
           	fprintf(fp,"%d %s %.2f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
           	fflush(stdin);
           	printf("do you want to enter another food?(y/n)");
           	scanf(" %c",&sel);
           	fflush(stdin);
           	if (sel=='n')
               	{
              	    break;
         	 	}
        }
   	}
   	fclose(fp);
	printf("\t\t|\t\t\t|");
	printf("\t\t|\tADDED SUCESSFULLY\t|");
    printf("\nenter any key to exit");
	getch();
	main();  
    return 0;
}
//defining display function
int fooddisplay()
{
	struct food f[100];
	int i;
	FILE *fp;
	fp=fopen("food.txt","r");
 	printf("FOOD CODE\tFOOD NAME\t\tFOOD PRICE\tFOOD QUANTITY\n");
	//fread to read data from the file
	for(i=0;!feof(fp);i++)
 	{
      	fscanf(fp,"%d\t\t%s\t\t%f\t\t%d\n",&f[i].food_code,f[i].food_name,&f[i].food_price,&f[i].quantity);
      	fflush(stdin);
		printf("%d\t\t%s\t\t%.2f\t\t%d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
		fflush(stdin);
 	}
	fclose(fp);
	printf("press any key to go to main menu:");
	getch();
	main();
	return 0;
}
//defining delete funtion
int fooddeelete()
{
	struct food f[100];
	int i=0;
	FILE *fp;
	FILE *fpr;
	int count=0,code;
	fp=fopen("food.txt","r");
	fpr=fopen("extra.txt","w");
	printf("enter the code of food you want to delete: ");
	scanf("%d",&code);
	fflush(stdin);
	//reading data from the file
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %f %d",&f[i].food_code,f[i].food_name,&f[i].food_price,&f[i].quantity);
		if(code==f[i].food_code)
		{
		printf("\nSUCESSFULLY DELETED\n");
		count=1;
		}
		else
        {
        	//writing data in to the file
		count=1;
			fprintf(fpr,"%d %s %f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
        }
        i++;
	}
	if(count==0)
	{
		printf("\nEnter a vaild code\n");
	}
	fclose(fpr);
	fclose(fp);
	//removing the original file
	remove("food.txt");
	//renaming the dublicate dublicate file into original one
	rename("extra.txt","food.txt");
	printf("type any key to go to the main menu:");
	getch();
	main();
	return 0;
}
//function defining to update the file
int foodupdate()
{
	int i,j;
	struct food f[100];
    FILE *fp;
	FILE *fpr;
	int count=0,code;
	fp=fopen("food.txt","r");
	fpr=fopen("dublicate.txt","w");
	printf("enter the code you want to update:");
	scanf("%d",&code);
	fflush(stdin);
	printf("What do you want to update?\nEnter '1'to update food id\nEnter '2'to update food name\nEnter '3'to update food price\nEnter '4'to update food quantity\n");
	scanf ("%d",&j);
	//reading data
	for(i=0;!feof(fp);i++)
	{
		fscanf(fp,"%d %s %f %d\n",&f[i].food_code,f[i].food_name,&f[i].food_price,&f[i].quantity);
		if(code==f[i].food_code)
		{    
		    if (j==1)
            {
			printf("input the food record: ");
            scanf("%d",&f[i].food_code);
            fflush(stdin);
             fprintf(fpr,"%d %s %.2f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);}
            else if (j==2)
            {
			printf("input the food name: ");
            scanf ("%s",f[i].food_name);
            fflush(stdin);
         	fprintf(fpr,"%d %s %.2f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
			}
			else if(j==3)
			{
            printf("input the food price: ");
            scanf("%f",&f[i].food_price);
         	fprintf(fpr,"%d %s %.2f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
			}
            else if(j==4)
            {
			printf("input the food quantity: ");
            scanf("%d",&f[i].quantity);
            fprintf(fpr,"%d %s %.2f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
			}
            count=1;
            continue;
    	}
		
		else
        {
        	//updating the data
			fprintf(fpr,"%d %s %.2f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
        }
	}
	if (count==0)
	{
		printf("\nfood does not exist\n");
	}
	fclose(fpr);
	fclose(fp);
	remove("food.txt");
	rename("dublicate.txt","food.txt");
	printf("type any key to go to the main menu:");
	getch();
	main();
	return 0;
}
int dealadd()
{
	struct deal d[100];
 	int count=0;
	FILE *fpr;
	//opening file
	int i,n;
	char sel;
    FILE *fp;
    fp=fopen("deal.txt","a+");
    if(fp==NULL)
    {
        printf("file does not exist");
    }
    else
	{
    	for(i=0;i<10;i++)
		{
           	printf("input the deal code: ");
           	scanf("%d",&d[i].deal_code);
       	    fflush(stdin);
           	printf("input the deal includes: ");
         	gets(d[i].deal_name);
   	        fflush(stdin);
            printf("input the deal price: ");
       	    scanf("%f",&d[i].deal_price);
       	    fflush(stdin);
       	    printf("input the deal quantity: ");
       	    scanf("%d",&d[i].quantity);
       	    fflush(stdin);
           	//fprintf to write data in to the file
           	fprintf(fp,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
           	fflush(stdin);
           	printf("do you want to enter another deal?(y/n)");
           	scanf(" %c",&sel);
           	fflush(stdin);
           	if (sel=='n')
           	{
           	    break;
         	}
        }
   	}
   	fclose(fp);
	printf("\t\t|\t\t\t|");
	printf("\t\t|\tADDED SUCESSFULLY\t|");
    printf("\npress any key to exit");
    getch();
    main();
    return 0;
}
//defining display function
int dealdisplay()
{
	struct deal d[100];
	int i;
	FILE *fp;
	fp=fopen("deal.txt","r");
 	
	//fread to read data from the file
	for(i=0;!feof(fp);i++)
 	{
      	fscanf(fp,"%d %s %f %d\n",&d[i].deal_code,d[i].deal_name,&d[i].deal_price,&d[i].quantity);
      	fflush(stdin);
		printf("%d\t\t%s\t\t%.2f\t\t%d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
		fflush(stdin);
 	}
	fclose(fp);
	printf("press any key to go to main menu:");
	getch();
	main();
	return 0;
}
//defining delete funtion
int dealdeelete()
{
	struct deal d[100];
	int i=0;
	FILE *fp;
	FILE *fpr;
	int count=0,code;
	fp=fopen("deal.txt","r");
	fpr=fopen("dublicate.txt","w");
	printf("enter the code of deal you want to delete:");
	scanf("%d",&code);
	fflush(stdin);
	//reading data from the file
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %f %d\n",&d[i].deal_code,d[i].deal_name,&d[i].deal_price,&d[i].quantity);
		if(code==d[i].deal_code)
		{
		printf("\nSUCESSFULLY DELETED\n");
		count=1;
		}
		else
        {
        	//writing data in to the file
		fprintf(fpr,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
        }
        i++;
	}
	if(count==0)
	{
		printf("\nEnter a vaild code\n");
	}
	fclose(fpr);
	fclose(fp);
	//removing the original file
	remove("deal.txt");
	//renaming the dublicate dublicate file into original one
	rename("dublicate.txt","deal.txt");
	printf("type any key to go to the main menu:");
	getch();
	main();
	return 0;
}
//function defining to update the file
int dealupdate()
{
	int i,j;
	struct deal d[100];
    FILE *fp;
	FILE *fpr;
	int count=0,code;
	fp=fopen("deal.txt","r");
	fpr=fopen("dublicate.txt","w");
	printf("enter the code you want to update:");
	scanf("%d",&code);
	fflush(stdin);
	printf("What do you want to update?\nEnter '1'to update deal id\nEnter '2'to update deal include\nEnter '3'to update deal price\nEnter '4'to update deal quantity\n");
	scanf ("%d",&j);
	//reading data
	for(i=0;!feof(fp);i++)
	{
		fscanf(fp,"%d %s %f %d\n",&d[i].deal_code,d[i].deal_name,&d[i].deal_price,&d[i].quantity);
		if(code==d[i].deal_code)
		{    
		    if (j==1)
            {
			printf("input the food record: ");
            scanf("%d",&d[i].deal_code);
            fflush(stdin);
            fprintf(fpr,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
			}
            else if (j==2)
            {
			printf("input the deal name: ");
            scanf("%s",d[i].deal_name);
            fflush(stdin);
         	fprintf(fpr,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
			}
			else if(j==3)
			{
            printf("input the deal price: ");
            scanf("%f",&d[i].deal_price);
         	fprintf(fpr,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
			}
            else if(j==4)
            {
			printf("input the deal quantity: ");
            scanf("%d",&d[i].quantity);
            fprintf(fpr,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
			}
            count=1;
            continue;
    	}
		else
        {
        	//updating the data
			fprintf(fpr,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
        }
	}
	if (count==0)
	{
		printf("\ndeal does not exist\n");
	}
	fclose(fpr);
	fclose(fp);
	remove("deal.txt");
	rename("dublicate.txt","deal.txt");
	printf("type any key to go to the main menu:");
	getch();
	main();
	return 0;
}
//food(to calculate sum,update file and store in file) 
int cal()
{ time1();
	struct food f[100];
	int n,quan,i,j=0,r,s=0,t=0,k;
	static float discount=0,sum=0;
	FILE *fp;
	FILE *fpr;
	FILE *fp1;
	fp=fopen("food.txt","r");
	fpr=fopen("totalencome.txt","a");
	fp1=fopen("food2.txt","w");
	printf("FOOD CODE\tFOOD NAME\t\tFOOD PRICE\tFOOD QUANTITY\n");
	for(i=0;!feof(fp);i++)
 	{     
      	fscanf(fp,"%d\t\t%s\t\t%f\t%d\n",&f[i].food_code,f[i].food_name,&f[i].food_price,&f[i].quantity);
		printf("%d\t\t%s\t\t%.2f\t\t%d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
		j++;
 	}
 	printf("enter key :");
 	scanf("%d",&n);
 	for(i=0;feof(fp);i++)
 	{ 
	 	if (n>j)
 		{
 		break;
 		}
 		else
		{
    		if (n==f[i].food_code)
			{   
		    t++;
			printf ("Enter Quantity:");
			scanf ("%d",&quan);
				if (quan<=f[i].quantity)
				{
				sum=sum+(f[i].food_price*quan);
					if(sum>=1000)
					{
					discount=sum-500;
					}
					else
					{
					discount=sum;
					}
					fprintf (fpr,"%.2f\n",sum);
					f[i].quantity=f[i].quantity-quan;
					fprintf (fp1,"%d %s %.2f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
					printf ("press 1 to reorder or 0 to proceed to billing:");
					scanf ("%d",&r);
					if (r==1)
					{ 
			   		for (k=i;k<j-1;k++)  
			      	fprintf (fp1,"%d %s %.2f %d\n",f[k+1].food_code,f[k+1].food_name,f[k+1].food_price,f[k+1].quantity);
					fclose (fp);
	        		fclose(fp1);
	        		fclose(fpr);
         			remove ("food.txt");
         			rename("food2.txt","food.txt");
					system ("cls");
					cal();
					}	
					else if (r==0)
					{
					for(k=i;k<j-1;k++)
					fprintf (fp1,"%d %s %.2f %d\n",f[k+1].food_code,f[k+1].food_name,f[k+1].food_price,f[k+1].quantity);
			  		break;
					}
				}
				else
				{
				printf ("\nout of stock");
				printf ("please consult with staff\n");
				printf ("press any key to exit");
				getch();
				main();
				}
			}
			else 
			{  
				fprintf (fp1,"%d %s %.2f %d\n",f[i].food_code,f[i].food_name,f[i].food_price,f[i].quantity);
				t=0;
			}
		}
 	}
 	if (t==s)
	{
 	printf ("enter right key");
 	printf ("\npress any key to return");
 	getch();
 	cal();
	}
	else
	{
	totalbill(sum,discount);
	sum=0;
	}
	fclose (fp);
	fclose(fp1);
	fclose(fpr);
	remove ("food.txt");
	rename("food2.txt","food.txt");
	printf("\npress any key to go to main menu");
	getch();
	main();
}
//food(to calculate sum,update file and store in file)
int dealcal()
{ time1();
	struct deal d[100];
	int n,quan,i,j=0,r,s=0,t=0,k;
	static float discount=0,sum=0;
	FILE *fp;
	FILE *fpr;
	FILE *fp1;
	fp=fopen("deal.txt","r");
	fpr=fopen("totalencome.txt","a");
	fp1=fopen("deal2.txt","w");
	printf("DEAL CODE\tDEAL INCLUDE\t\t\tDEAL PRICE\tDEAL QUANTITY\n");
	for(i=0;!feof(fp);i++)
 	{     
      	fscanf(fp,"%d\t\t%s\t\t%f\t%d\n",&d[i].deal_code,d[i].deal_name,&d[i].deal_price,&d[i].quantity);
		printf("%d\t\t%s\t%.2f\t\t%d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
		j++;
	}
 	printf("enter key :");
 	scanf("%d",&n);
 	for(i=0;feof(fp);i++)
 	{
	  	if (n>j)
 		{
 			break;
 		}
 		else
		{
    		if (n==d[i].deal_code)
			{   
		    t++;
			printf ("Enter Quantity:");
			scanf ("%d",&quan);
				if (quan<=d[i].quantity)
				{
				sum=sum+(d[i].deal_price*quan);
					if(sum>=1000)
					{
					discount=sum-500;
					}
					else
					{
					discount=sum;
					}
					fprintf (fpr,"%.2f\n",sum);
					d[i].quantity=d[i].quantity-quan;
					fprintf (fp1,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
					printf ("press 1 to reorder or 0 to proceed to billing");
					scanf ("%d",&r);
					if (r==1)
					{ 
			   		for (k=i;k<j-1;k++)  
			      	fprintf (fp1,"%d %s %.2f %d\n",d[k+1].deal_code,d[k+1].deal_name,d[k+1].deal_price,d[k+1].quantity);
					fclose (fp);
	        		fclose(fp1);
	        		fclose(fpr);
         			remove ("deal.txt");
         			rename("deal2.txt","deal.txt");
					system ("cls");
					dealcal();
					}
					else if (r==0)
					{
					for(k=i;k<j-1;k++)
					fprintf (fp1,"%d %s %.2f %d\n",d[k+1].deal_code,d[k+1].deal_name,d[k+1].deal_price,d[k+1].quantity);
			  		break;
					}
				}
				else
				{
				printf ("\nout of stock");
				printf ("please consult with staff\n");
				printf ("press any key to exit");
				getch();
				main();
				}
			}
			else 
			{  
				fprintf (fp1,"%d %s %.2f %d\n",d[i].deal_code,d[i].deal_name,d[i].deal_price,d[i].quantity);
				t=0;
			}
		}
 	}
 	if (t==s)
	{
 		printf ("enter right key");
 		printf ("\npress any key to return");
 		getch();
 		dealcal();
	}
	else
	{
		totalbill(sum,discount);
		sum=0;
	}
	fclose (fp);
	fclose(fp1);
	fclose(fpr);
	remove("deal.txt");
	rename("deal2.txt","deal.txt");
	printf("\npress any key to go to main menu");
	getch();
	main();
}
//to calculate total encome
int total()
{  
	time1();
	FILE *fp;
	int i;
	float total2=0,sum;
	fp=fopen("totalencome.txt","r");
	for(i=0;!feof(fp);i++)
	{
		fscanf(fp,"%f\n",&sum);
		fflush(stdin);
		total2=total2+sum;
	}
	fclose (fp);
	printf("\t|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\t||||||||||||| TOTAL INCOME= %.2f  |||||||||||||||||||||||\n",total2);
    printf("\t|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf ("press any key to exit");
	getch();
	admin(num);
}
//for total bill
int totalbill(float sum,float discount)
{
	time1();
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||\t\t\t\t YOUR BILL\t\t\t\t\t\t\t\t||\n");
    printf("||\t\t\t\t PLEASE PAY TO COUNTER\t\t\t\t\t\t\t||\n"); 
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||\t\t\t\t TOTAL BILL=%.2f\t\t\t\t\t\t\t||\n",sum);
    printf("||\t\t\t\t TOTAL BILL AFTER DISCOUNT=%.2f\t\t\t\t\t||\n",discount);
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	return 0;
}
//to calculate profit and loss
int total1()
{  	time1();
	float sum1=0,sum2,new1,new2;
	FILE *fp;
	int i;
	float total2=0,sum;
	fp=fopen("totalencome.txt","r");
	for(i=0;!feof(fp);i++)
	{
		fscanf(fp,"%f\n",&sum);
		fflush(stdin);
		total2=total2+sum;
	}
	fclose (fp);
	FILE *fpr;
	fpr=fopen("employe.dat","r+");
	while(fread(&e,sizeof(e),1,fp)==1)
	{
		sum1=sum1+e.employee_salary;
	}
	fclose (fpr);
	sum2=sum1+total2;
	printf ("your total income calculated by program by adding salary and income is\n\n\n\t\t\t\t%.2f\n\n",sum2);
	printf ("\nEnter total payment that is collected:");
	scanf ("%f",&new1);
	fflush(stdin);
	new2=new1-sum2;
	if (new2>0)
	{
		printf ("\nyou are in profit of %.2f\n",new2);
	}
	else if (new2<0)
	{
		printf ("\nyou are in loss\n");
	}
	else
	{
		printf ("\nno profit or loss\n");
	}
	printf ("press any key to exit");
	getch();
	admin(num);
}
//to update income file
int removetotalincome()
{time1();
	float sum=0;
	system ("CLS");
	remove("totalencome.txt");
	FILE *fp;
	fp=fopen("totalencome.txt","w");
	fprintf(fp,"%.2f",sum);
	fclose(fp);
	printf("SUCESSFULLY UPDATED\n");
	printf("press any key to exit:");
	getch();
	main();
}
//display time
int time1()
{   system ("cls");
	time_t currenttime;
    time (&currenttime);
    printf ("\t\t\t\t\t\t\t%s",ctime(&currenttime));
}
