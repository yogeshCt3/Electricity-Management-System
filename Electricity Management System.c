#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char pswrd[]= "alterxc3000";
char z1=(char)186,z2=(char)187,z3=(char)188,z4=(char)200,z5=(char)201,z6=(char)205;
int i=0;
struct details{
	char name[50];
	char password[50];
	char age[3];
	char phone[11];
	char city[100];
	char state[100];
	char house_no[5];
	char Locality[50];
	char pin[7];
	float previous_unit;
	float new_unit;
	float total;
}x;
void _delete_a_user(char check_file[]){
	FILE *infile;
	fflush(stdin);
	system("cls");
	infile=fopen(check_file,"r");
	if(infile==NULL){
		printf("User Does not Exists");
		getch();
		main();
	}
	else{
		fclose(infile);
		int ret=remove(check_file);
		if(ret==0)
		printf("File deleted Successfully.");
		else 
		printf("Unable to delete file.");
		getch();
	}
	main();
}
void _show_the_bill(char check_file[],int arg){
	FILE *infile;
	system("cls");
	infile=fopen(check_file,"r");
	if(infile==NULL){
		printf("User Does not Exists");
		getch();
		main();
	}
	while(fread (&x, sizeof(struct details), 1, infile)){
	if(arg==0){
		char temp[50];
		printf("Enter your password: ");
		gets(temp);
		if(strcmp(temp,x.password)!=0)
		_show_the_bill(x.phone,0);
	}
	system("cls");
	printf("___________________Your Calculated Bill__________________");
	printf("\n\tName:           ");
	puts(x.name);
	printf("\tAge:            ");
	puts(x.age);
	printf("\tPhone number:   ");
	puts(x.phone);
	printf("\tHouse number:   ");
	puts(x.house_no);
	printf("\tLocality:       ");
	puts(x.Locality);  
	printf("\tPin Code:       ");
	puts(x.pin);
	printf("\tCity:           ");
	puts(x.city);
	printf("\tState:          ");
	puts(x.state);
	printf("\tPrevious unit:  ");
	printf("%.2f",x.previous_unit);
	printf("\n\tPresent unit:   ");
	printf("%.2f \n___________________________________________________________\n\tTotal units consumed: %.2f",x.new_unit,x.new_unit-x.previous_unit);
	printf("\n\n\tTotal Bill: %.2f",x.total);}
	fclose(infile);
	getch();
	main();
}
void _create_new_entry(){
	system("cls");
	printf("Enter Details: \n");
		FILE *outfile;
		fflush(stdin);
	printf("Name: ");
	gets(x.name);
	printf("Age: ");
	gets(x.age);
	printf("Phone number: ");
	gets(x.phone);
	printf("Enter Password: ");
	gets(x.password);
	outfile=fopen(x.phone,"w");
	printf("House number: ");
	gets(x.house_no);
	printf("Locality: ");
	gets(x.Locality);
	printf("Pin Code: ");
	gets(x.pin);
	printf("City: ");
	gets(x.city);
	printf("State: ");
	gets(x.state);
	printf("Previous unit: ");
	scanf("%f",&x.previous_unit);
	printf("Present unit: ");
	scanf("%f",&x.new_unit);
	float units,total_bill;
	units=x.new_unit-x.previous_unit;
	if(units <= 50)

            total_bill = units * 2.5;

    else if(units <= 100)

            total_bill = units * 3;

    else if(units <= 200)

           total_bill = units * 3.5;

     else if(units <= 300)

           total_bill = units * 4;

     else if(units <= 400)

           total_bill = units * 4.5;

     else if(units <= 500)

           total_bill = units * 4.75;

     else

           total_bill = units * 5;
           x.total=total_bill;
		if(outfile==NULL){
		printf("\nUnable to write in file.");
		getch();
		system("exit");
	}
		fwrite(&x,sizeof(struct details),1,outfile);
		fclose(outfile);
      _show_the_bill(x.phone,1);
	
}
int main(){
	system("cls");
	if(i==0){
	printf("----------------------ELECTRICITY BILLING SYSTEM-----------------------\n");
	printf("\nCalculating Charges.\n\n");
	printf("1. If Units consumed is between 0-50.\n    Charges are 2.5 per/- unit.\n");
	printf("\n3. If Units consumed is between 50-100.\n    Charges are 3.0 per/- unit.\n");
	printf("\n4. If Units consumed is between 100-200.\n    Charges are 3.5 per/- unit.\n");
	printf("\n5. If Units consumed is between 200-300.\n    Charges are 4.0 per/- unit.\n");
	printf("\n6. If Units consumed is between 300-400.\n    Charges are 4.5 per/- unit.\n");
	printf("\n7. If Units consumed is between 400-500.\n    Charges are 4.75 per/- unit.\n");
	printf("\n8. If Units consumed is above 500.\n    Charges are 5.0 per/- unit.\n");
	printf("\n\n\nPress any key to contiue...");
	getch();}
	i++;
	system("cls");
	printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",z5,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z2);
	printf("\t\t\t\t%cELECTRICITY BILLING%c\n",z1,z1);
	printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",z4,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z6,z3);

	printf("\n\t\t\t_______________Options______________\n\n");
	printf("\t\t\t\t1.New User\n\t\t\t\t2.View your Bill\n\n\t\t\t\t=>ADMINISTRATOR-OPTIONS\n\t\t\t\t  a.Delete a user\n\t\t\t\t  b.Search a user\n\n\t\t\t\t4.exit\n");
	char ch,data[50];
	printf("\n\t\t\t____________________________________\n\n");
	fflush(stdin);
	printf("\n\t\t\tEnter your Choice: ");
	scanf("%c",&ch);
	switch(ch){
		case '1':
			_create_new_entry();
			break;
		case '2':
			printf("Enter Phone number... ");
			fflush(stdin);
			gets(data);
			_show_the_bill(data,0);
			break;
		case 'a':printf("enter password: ");
				fflush(stdin);
				gets(data);
				if(strcmp(data,pswrd)==0){
					printf("enter user phone number: ");
					fflush(stdin);
					gets(data);
					_delete_a_user(data);
				}
				else
				main();
				break;
		case 'b':printf("enter password: ");
				fflush(stdin);
				gets(data);
				if(strcmp(data,pswrd)==0){
					printf("enter user phone number: ");
					fflush(stdin);
					gets(data);
					_show_the_bill(data,1);
				}else main();
				break;
		default:system("exit");
				
	}
	return 0;
}
