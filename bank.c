#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include <stdbool.h>
#include<dos.h>
struct date
{
	int dd,mm,yy;	
}; 
struct
{
	char fname[20],lname[20],mail[100],adres[10000],nation[100],typea[100];
	int age,depo,an;
	long long int pn;
	struct date dob;
	struct date time;
}add,update,rem,trans,check;
main()
{
	system("COLOR 10");
	int pass,password=1234,i=0,p;
	printf("\n\n\n\t\t\t\tBANK MANAGEMENT SYSTEM");
	printf("\n\t\t\t\t   USER LOGIN PORTAL");
	printf("\n\n\n\n\n\t\t\tEnter password to login to system: ");
	scanf("%d",&pass);
	if (pass==password)
	{
		printf("\n\n\nPassword Match!");
		printf("\nLOADING");
		while(i<7)
		{
			frdlay(100000000);
			printf(". ");
			i++;
		}
		frdlay(10000000);
		printf("\n\nPress any key to continue ");
		getch();
		system("cls");
		menu();
	}
	else
	{
		printf("\n\n\nWrong! Password (- o -!)");
		printf("\n\nTo retry press 1 or to exit press 0 ");
		scanf("%d",&p);
		if(p==1)
		{
			system("cls");
			main();
		}
		else if(p==0)
		{
			system("cls");
			exit(0);
		}
	}
}
frdlay(int j)
{
	int i,k;
	for(i=0;i<j;i++)
	{
		k=i;
	}
}
menu()
{
	int i;
	printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BANK SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\n\t\t\t[1] Create new Bank account");
	printf("\n\t\t\t[2] Remove existing account");
	printf("\n\t\t\t[3] Update account details");
	printf("\n\t\t\t[4] View your bank account details");
	printf("\n\t\t\t[5] Transaction");
	printf("\n\t\t\t[6] View members list");
	printf("\n\t\t\t[7] Exit");
	printf("\n\n\t\t---------------------------------------------------------------");
	printf("\n\n\tEnter your choice: ");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			system("cls");
			new_bank();
			break;
		case 2:
			system("cls");
			remove_acc();
			break;
		case 3:
			system("cls");
			upd_bank();
			break;
		case 4:
			system("cls");
			see_bank();
			break;
		case 5:
			system("cls");
			tran_bank();
			break;
		case 6:
			system("cls");
			view_bank();
			break;
		case 7:
			system("cls");
			exit(0);
		default:
			printf("\n\n\t\tWrong input!");
			frdlay(1000000000);
			system("cls");
			menu();
	}
}
tran_bank()
{
	int choice,f,t,test=0;
	FILE *oldf,*tran;
	oldf=fopen("record.txt","r");
	tran=fopen("new.txt","w");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 Transaction Window \xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\tEnter the account number: ");
	scanf("%d",&check.an);
	while(fscanf(oldf,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",&add.an,add.fname,add.lname,&add.time.dd,&add.time.mm,&add.time.yy,&add.dob.dd,&add.dob.mm,&add.dob.yy,&add.pn,add.mail,add.adres,&add.age,add.nation,&add.depo,add.typea)!=EOF)
	{
		if(check.an==add.an)
		{
			test=1;
			Transaction:
			printf("\n----------------------------------------------------------------");
			printf("\n\t[1] Withdraw\n\t[2] Deposit");
			printf("\n\tEnter your choice: ");
			scanf("%d",&t);
			if (t==1)
			{
				printf("\n----------------------------------------------------------------");
				printf("\n\tEnter the amount: ");
				scanf("%d",&trans.depo);
				add.depo-=trans.depo;
				fprintf(tran,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",add.an,add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,add.pn,add.mail,add.adres,add.age,add.nation,add.depo,add.typea);	
				printf("\n\tAmount has been Updated.");
			}
			else if(t==2)
			{
				printf("\n----------------------------------------------------------------");
				printf("\n\tEnter the amount: ");
				scanf("%d",&trans.depo);
				add.depo+=trans.depo;
				fprintf(tran,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",add.an,add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,add.pn,add.mail,add.adres,add.age,add.nation,add.depo,add.typea);	
				printf("\n\tAmount has been Updated.");
			}
			else
			{
				printf("\n\n\tWrong Input!");
				frdlay(1000000000);
				system("cls");
				goto Transaction;
			}
		}
		else
		{
			fprintf(tran,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",add.an,add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,add.pn,add.mail,add.adres,add.age,add.nation,add.depo,add.typea);		
		}
	}
	fclose(oldf);
	fclose(tran);
	remove("record.txt");
	rename("new.txt","record.txt");
	if(test=0)
	{
		printf("\n\n\tAccount number not matched!");
		check_Invalid:
		printf("\n\n\tPress 1 to main menu or 0 to exit: ");
		scanf("%d",&f);
		if(f==1)
		{
			system("cls");
			menu();
		}
		else if(f==0)
		{
			system("cls");
			exit(0);
		}
		else
		{
			printf("\n\n\tWrong input!");
			frdlay(1000000000);
			system("cls");
			goto check_Invalid;			
		}		
	}
	Invalid_num:
	printf("\n------------------------------------------------------------------");
	printf("\n\tPress 1 for Transaction or Press 0 to main menu or Press 9 to exit: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("cls");
		tran_bank();
	}
	else if(choice==0)
	{
		system("cls");
		menu();
	}
	else if(choice==9)
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("\n\n\tWrong input");
		frdlay(1000000000);
		system("cls");
		goto Invalid_num;
	}
}

see_bank()
{
	int choice,f,test=0;
	FILE *fp;
	fp=fopen("record.txt","r");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 VIEW WINDOW \xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\tEnter the account number: ");
	scanf("%d",&check.an);
	while(fscanf(fp,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",&add.an,add.fname,add.lname,&add.time.dd,&add.time.mm,&add.time.yy,&add.dob.dd,&add.dob.mm,&add.dob.yy,&add.pn,add.mail,add.adres,&add.age,add.nation,&add.depo,add.typea)!=EOF )
	{
		if(check.an==add.an)
		{
			printf("\n------------------------------------------------------------------");
			printf("\n\t1. Name: %s %s\n\t2. Opening date of account: %d/%d/%d\n\t3. D.0.B: %d/%d/%d\n\t4. Phone Number: %lld\n\t5. E-mail: %s\n\t6. Address: %s\n\t7. Age: %d\n\t8. Nationality: %s\n\t9. Amountin account: $%d\n\t10. Account type: %s",add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,add.pn,add.mail,add.adres,add.age,add.nation,add.depo,add.typea);
			test=1;
		}
	}
	fclose(fp);
	if(test==0)
	{
		printf("\n\n\tAccount number not matched!");
		check_Invalid:
		printf("\n\n\tPress 1 to main menu or 0 to exit: ");
		scanf("%d",&f);
		if(f==1)
		{
			system("cls");
			menu();
		}
		else if(f==0)
		{
			system("cls");
			exit(0);
		}
		else
		{
			printf("\n\n\tWrong input!");
			frdlay(1000000000);
			system("cls");
			goto check_Invalid;			
		}		
	}
	
	Invalid_num:
	printf("\n------------------------------------------------------------------");
	printf("\n\tPress 1 to View again or Press 0 to main menu or Press 9 to exit: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("cls");
		see_bank();
	}
	else if(choice==0)
	{
		system("cls");
		menu();
	}
	else if(choice==9)
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("\n\n\tWrong input");
		frdlay(1000000000);
		system("cls");
		goto Invalid_num;
	}
}
upd_bank()
{
	int choice,c,f,test=0;
	FILE *oldf,*upd;
	oldf=fopen("record.txt","r");
	upd=fopen("new.txt","w");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 Update details \xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\tEnter the account number: ");
	scanf("%d",&check.an);
	while(fscanf(oldf,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",&add.an,add.fname,add.lname,&add.time.dd,&add.time.mm,&add.time.yy,&add.dob.dd,&add.dob.mm,&add.dob.yy,&add.pn,add.mail,add.adres,&add.age,add.nation,&add.depo,add.typea)!=EOF)
	{
		if(check.an==add.an)
		{
			Index:
			test=1;
			printf("\n------------------------------------------------------------------");
			printf("\n\n\tEnter the Index of detail you wanted to update\n\t[1] Address\n\t[2] Phone number");
			printf("\n\tEnter your choice: ");
			scanf("%d",&c);
			printf("\n------------------------------------------------------------------");
			if(c==1)
			{
				printf("\n\tEnter new address: ");
				scanf(" %[^\n]s",update.adres);
				fprintf(upd,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",add.an,add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,add.pn,add.mail,update.adres,add.age,add.nation,add.depo,add.typea);	
			}
			else if(c==2)
			{
				printf("\n\tEnter new Phone number: ");
				scanf("%lld",&update.pn);
				fprintf(upd,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",add.an,add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,update.pn,add.mail,add.adres,add.age,add.nation,add.depo,add.typea);					
			}
			else
			{
				printf("\n\n\tWrong Index\n\tEnter valid Index");
				frdlay(1000000000);
				system("cls");
				goto Index;
			}
		}
		else
		{
			fprintf(upd,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",add.an,add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,add.pn,add.mail,add.adres,add.age,add.nation,add.depo,add.typea);	
		}	
	}
	printf("\n-------------------------------------------------------------------");
	printf("\n\tAccount has been updated.");
	fclose(oldf);
	fclose(upd);
	remove("record.txt");
	rename("new.txt","record.txt");
	if(test=0)
	{
		printf("\n\n\tAccount number not matched!");
		check_Invalid:
		printf("\n\n\tPress 1 to main menu or 0 to exit: ");
		scanf("%d",&f);
		if(f==1)
		{
			system("cls");
			menu();
		}
		else if(f==0)
		{
			system("cls");
			exit(0);
		}
		else
		{
			printf("\n\n\tWrong input!");
			frdlay(1000000000);
			system("cls");
			goto check_Invalid;			
		}		
	}
	Invalid_num:
	printf("\n------------------------------------------------------------------");
	printf("\n\tPress 1 to update again or Press 0 to main menu or Press 9 to exit: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("cls");
		upd_bank();
	}
	else if(choice==0)
	{
		system("cls");
		menu();
	}
	else if(choice==9)
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("\n\n\tWrong input");
		frdlay(1000000000);
		system("cls");
		goto Invalid_num;
	}
}
view_bank()
{
	int choice;
	FILE *open;
	open=fopen("record.txt","r");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 Member\'s List \xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\tAccount_Number\t\tName\t\tAge");
	while(fscanf(open,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",&add.an,add.fname,add.lname,&add.time.dd,&add.time.mm,&add.time.yy,&add.dob.dd,&add.dob.mm,&add.dob.yy,&add.pn,add.mail,add.adres,&add.age,add.nation,&add.depo,add.typea)!=EOF)
	{
		printf("\n\t\t%d\t\t\t%s %s\t%d",add.an,add.fname,add.lname,add.age);
	}
	fclose(open);
	invalid:
	printf("\n\n\n\tPress 1 to return to main menu or press 0 to exit: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("cls");
		menu();
	}
	else if(choice==0)
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("Invalid number");
		frdlay(1000000000);
		system("cls");
		goto invalid;
	}
}
remove_acc()
{
	int choice,f;
	FILE *oldf,*newf;
	oldf=fopen("record.txt","r");
	newf=fopen("new.txt","w");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 Remove Account \xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\tEnter Account number: ");
	scanf("%d",&check.an);
	while(fscanf(oldf,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",&add.an,add.fname,add.lname,&add.time.dd,&add.time.mm,&add.time.yy,&add.dob.dd,&add.dob.mm,&add.dob.yy,&add.pn,add.mail,add.adres,&add.age,add.nation,&add.depo,add.typea)!=EOF)
	{
		if(check.an!=add.an)
		{
			fprintf(newf,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",add.an,add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,add.pn,add.mail,add.adres,add.age,add.nation,add.depo,add.typea);	
		}
		else
		{
			printf("\n\n\t\tAccount has been Removed Successfully");
			frdlay(1000000000);
		}
	}
	if(check.an!=add.an)
	{
		printf("\n\n\tAccount number not matched!");
		check_Invalid:
		printf("\n\n\tPress 1 to main menu or 0 to exit: ");
		scanf("%d",&f);
		if(f==1)
		{
			system("cls");
			menu();
		}
		else if(f==0)
		{
			system("cls");
			exit(0);
		}
		else
		{
			printf("\n\n\tWrong input!");
			frdlay(1000000000);
			system("cls");
			goto check_Invalid;			
		}		
	}
	fclose(oldf);
	fclose(newf);
	remove("record.txt");
	rename("new.txt","record.txt");
	invalid:
	printf("\n\n\n\tPress 1 to return to main menu or press 0 to exit: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("cls");
		menu();
	}
	else if(choice==0)
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("Invalid number");
		frdlay(1000000000);
		system("cls");
		goto invalid;
	}
}
new_bank()
{
	int choice;
	FILE *fp;
	fp=fopen("record.txt","a+");
	system("cls");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2 Please enter your details \xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\tAccount number: ");
	scanf("%d",&check.an);
	while(fscanf(fp,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",&add.an,add.fname,add.lname,&add.time.dd,&add.time.mm,&add.time.yy,&add.dob.mm,&add.dob.mm,&add.dob.yy,&add.pn,add.mail,add.adres,&add.age,add.nation,&add.depo,add.typea)!=EOF)
	{
		if(check.an==add.an)
		{
			printf("\t\tAccount number, Alredy in use.");
			frdlay(1000000000);
			new_bank();	
		}
	}
	add.an=check.an;
	printf("\n\t\tFirst name: ");
	scanf("%s",add.fname);
	printf("\n\t\tLast name: ");
	scanf("%s",add.lname);
	printf("\n\t\tToday\'s date(dd/mm/yy): ");
	scanf("%d/%d/%d",&add.time.dd,&add.time.mm,&add.time.yy);
	printf("\n\t\tD.O.B{dd/mm/yy}: ");
	scanf("%d/%d/%d",&add.dob.dd,&add.dob.mm,&add.dob.yy);
	printf("\n\t\tPhone number: ");
	scanf("%lld",&add.pn);
	printf("\n\t\tE-mail: ");
	scanf("%s",add.mail);
	printf("\n\t\tAddress: ");
	scanf(" %[^\n]s",add.adres);
	printf("\n\t\tAge: ");
	scanf("%d",&add.age);
	printf("\n\t\tNationality: ");
	scanf("%s",add.nation);
	printf("\n\t\tAmount to deposit: $");
	scanf("%d",&add.depo);
	printf("\n\t\tAccount Type\n\t\t\t~Saving\n\t\t\t~Current");
	printf("\n\t\tEnter Account type: ");
	scanf("%s",add.typea);
	fprintf(fp,"%d %s %s %d/%d/%d %d/%d/%d %lld %s %s %d %s %d %s\n",add.an,add.fname,add.lname,add.time.dd,add.time.mm,add.time.yy,add.dob.dd,add.dob.mm,add.dob.yy,add.pn,add.mail,add.adres,add.age,add.nation,add.depo,add.typea);	
	fclose(fp);
	printf("\n\n\tNew Account has been created");
	invalid:
	printf("\n\tPress 1 to return to main menu or press 0 to exit: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("cls");
		menu();
	}
	else if(choice==0)
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("Invalid number");
		frdlay(1000000000);
		system("cls");
		goto invalid;
	}
}

