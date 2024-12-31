#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
int i,j;

struct customer
{
	char name[50],address[55],username[20],password[15];
	float balance;
	long int acc_no;
	int day,month,year;
}c,user1;
int main()
{
	int choicelog,choicead,m,n,a,amt,d,mo,y,match=0;
	long int acno;
	char useradmin[]="admin",filename[20];
	char passadmin[]="admin123";
	char useradmin1[10],passadmin1[10],usernamec[15],passwordc[16],oldpass[16],newpass[16],ce,newpass1[16],updates[20],updatee[50],user[25],ch;
	FILE *fp,*fpp;
	struct customer c;
	while(1)
	{
		printf("\n\n\n\t****************************************************************************************************\n");
		printf("\t****************************************************************************************************\n");
		printf("\t****************************************************************************************************\n");
		printf("\t**********************************Welcome to Online banking System**********************************\n");
		printf("\t****************************************************************************************************\n");
		printf("\t****************************************************************************************************\n");
		printf("\t****************************************************************************************************\n");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tDeveloped by:\n\t\t\t\t\t\t\t\t\t\t\t\tJagadish Ghimire");
		printf("\n\t\t\t\t\t\t\t\t\t\t\t\tPabin Chalise");
		getch();
		system("cls");
	home:
		system("cls");
		printf("Choose:\n1. Run as Admin\n2. Run as Customer\n3. Exit\n\t\t");
		scanf("%d",&choicelog);
		system("cls");
		switch(choicelog)
		{
			case 1:
			log:
				system("cls");
				printf("\nEnter your details:\nUsername: ");
				fflush(stdin);
				gets(useradmin1);
				if(strcmp(useradmin,useradmin1)!=0)
				{
					printf("Username doesn't match.");
					getch();
					goto log;
				}
				else
				{
					
				
				printf("\nPassword: ");
				fflush(stdin);
				gets(passadmin1);
			/*	i=0;
				while((ch=_getch())!=13)
				{
					while((ch=_getch())!='BS')
					{
						passadmin1[i]=ch;
						i++;
						printf("*");
					}
				}
				passadmin1[i]='\0';				
				*/
				system("cls");
				if(strcmp(useradmin,useradmin1)==0)
				{
					if(strcmp(passadmin,passadmin1)==0)
					{
					main:
						system("cls");						
						printf("\nWhat do you want to do:\n1. Update customer details\n2. View customer detail\n3. Delete customer's detail\n4. Logout\n\t\t");
						scanf("%d",&a);
						system("cls");
						switch(a)
						{
							
							case 1:
								printf("\nEnter costumer's username to update details: ");
								fflush(stdin);
								gets(updates);
								
								fp=fopen(strcat(updates,".dat"),"r");
								fread(&c,sizeof(struct customer),1,fp);
								if(strcmp(updates,c.username)==0)
								{
									printf("\nCustomer's username doesn't match the record.");
									getch();
									system("cls");
									goto main;
									break;
								}
								else
								{								
									strcpy(filename,updates);
									system("cls");
									fp=fopen(strcat(updates,".dat"),"r");
									fpp=fopen("copyy.dat","w");
									printf("\nWhat to update:\n1. Name\n2. Address\n3. Date of Birth\n4. Main menu\n5. Home page\n\t\t");
									scanf("%d",&choicelog);
									system("cls");
									if(choicelog==1)
									{
										
										printf("Enter the new name:");
										scanf("%s",user1.name);
										fprintf(fp,"%ld %s %f %d %d %s %s %s %d\n",c.acc_no,c.address,c.balance,c.day,c.month,user1.name,c.password,c.username,c.year);
										system("cls");
										printf("Changes saved!");


										printf("\nEnter name: ");
										fflush(stdin);
										gets(updatee);
										if(strcmp(c.name,updatee)==0)
										{
											printf("New name is same as old one.");
										}
										else
										{
											printf("\nAre you sure to change? press Y/y to save.\n\t\t");
											scanf("%c",&ce);
											if(ce=='y' || ce=='Y')
											{	
											
	
											
											
												
												fp=fopen(strcat(filename,".dat"),"r");
												fread(&user1,sizeof(struct customer),1,fp);
												fclose(fp);
												fp=fopen(strcat(filename,".dat"),"w");
												fwrite(&c,sizeof(struct customer),1,fp);
												if(fwrite!=0)
												{
													printf("Name sucessfully updated.");
													getch();
												}
												fclose(fp);
											}
											
											goto main;
										}


										
									}	
									else if(choicelog==2)
									{
										
										printf("Enter the new address:");
										scanf("%s",user1.address);
										fprintf(fp,"%ld %s %f %d %d %s %s %s %d\n",c.acc_no,user1.address,c.balance,c.day,c.month,c.name,c.password,c.username,c.year);
										system("cls");
										printf("Changes saved!");

										
										printf("\nEnter address: ");
										fflush(stdin);
										gets(updatee);
										printf("\nAre you sure to change? press Y/y to save.\n\t\t");
										scanf("%c",&ce);
										if(ce=='y' || ce=='Y')
										{	
											fp=fopen(strcat(filename,".dat"),"r");
											fread(&user1,sizeof(struct customer),1,fp);
											fclose(fp);
											strcpy(c.address,updatee);
											fp=fopen(strcat(filename,".dat"),"w");
											fwrite(&c,sizeof(struct customer),1,fp);
											if(fwrite!=0)
											{
												printf("Address sucessfully updated.");
											}
											fclose(fp);
										}
										goto main;


									}				
									else if(choicelog==3)
									{
										
										printf("Enter the new Date of birth(DD/MM/YYYY):");
										scanf("%d%d%d",&user1.day,&user1.month,&user1.year);
										fprintf(fp,"%ld %s %f %d %d %s %s %s %d\n",c.acc_no,c.address,c.balance,user1.day,user1.month,c.name,c.password,c.username,user1.year);
										system("cls");
										printf("Changes saved!");

										
										printf("\nEnter date of birth(DD/MM/YYYY): ");
										scanf("%d%d%d",&c.day,&c.month,&c.year);
										
											fp=fopen(strcat(filename,".dat"),"w");
											fwrite(&c,sizeof(struct customer),1,fp);
											if(fwrite!=0)
											{
												printf("Date of birth sucessfully updated.");
												getch();
											}
								 			fclose(fp);


										}
									}
									fclose(fp);
									getch();
									system("cls");
									goto main;
								
							case 2:
								printf("\nEnter costumer's username to view details: ");
								fflush(stdin);
								gets(updates);
								strcpy(filename,updates);
								
									fp=fopen(strcat(filename,".dat"),"r");
									fread(&c,sizeof(struct customer),1,fp);
									if(fp==0)
									{
										printf("\nCustomer's data doesn't found.\n!!!Try Again.!!!");
										getch();
									}	
									else
									{					
										printf("\nName: %s\nAddress: %s\nDate of Birth: %d/%d/%d\nAccount Number: %ld\nBalance: %f\n",c.name,c.address,c.day,c.month,c.year,c.acc_no,c.balance);
										fclose(fp);
										getch();
										system("cls");
									}
									fclose(fp);
							
								goto main;
								break;		
							case 3:
								del:
								printf("Enter customer's username to delete record: ");
								fflush(stdin);
								gets(updates);
								strcpy(filename,updates);
								fp=fopen(strcat(filename,".dat"),"r");
								fread(&c,sizeof(struct customer),1,fp);
								
								if(fp==0)
								{
									printf("\nCustomer's data doesn't found.\n!!!Try Again.!!!");
									getch();
									system("cls");
									goto del;
								}
								else
								{	
									printf("\nAre you sure to change? press Y/y to delete.\n\t\t");
									scanf("%c",&ce);
									if(ce=='y' || ce=='Y')
									{
										strcpy(filename,updates);
										fp=fopen(strcat(filename,".dat"),"r");
										fread(&c,sizeof(struct customer),1,fp);
										fclose(fp);
										//strcpy(filename,updates);
										fp=fopen(strcat(filename,".dat"),"w");
														
										if(remove(updates)!=0)
										{
												strcpy(filename,updates);
											remove(strcat(filename,".dat"));
											fprintf(stderr,"Errno:%d\n",errno);
											perror("Error msg:");
										//	printf("Customer data deleted succesfully.");
											getch();
											system("cls");
										}
										else
										{
											strcpy(filename,updates);
											remove(strcat(filename,".dat"));
											printf("Customer data deleted succesfully.");
										//	printf("Something went wrong. Please! try again.");
											getch();
											system("cls");
										}
										fwrite(&c,sizeof(struct customer),1,fp);
										/*if(fwrite!=0)
										{
											printf("Customer's data deleted successfully");
											getch();
											system("cls");
										
										}*/
										fclose(fp);
									}
									
								}
								
								fclose(fp);
								goto main;
								break;
							case 4:
								goto home;
							default:
								("Invalid Input");
								getch();
								system("cls");
						}
					}
				}
				
				else
				{
					printf("\nYou entered wrong username or password.");
					getch();
					system("cls");
					goto log;
				}
				break;
			case 2:
				c.acc_no=0145654001;
				printf("Do you want to login or signup:\n1. LogIn\n2. SignUp:\n");
				scanf("%d",&choicelog);
				switch(choicelog)
				{
					case 1:
					login:
						printf("\nEnter your login details below:\nUsername: ");
						fflush(stdin);
						gets(usernamec);
						strcpy(filename,usernamec);
						fp=fopen(strcat(filename,".dat"),"r");
						fread(&c,sizeof(struct customer),1,fp);
						if(strcmp(usernamec,c.username)!=0)
						{
							printf("Username doesn't match the record");
							getch();
							goto login;
						}	
						printf("\nPassword: ");
						fflush(stdin);
						gets(passwordc);
						fclose(fp);
						if(strcmp(c.password,passwordc)==0)
						{
						meny:
							system("cls");
							printf("\nWhat do you want to do?\n1. Your details.\n2. Balance Inquiry.\n3. Withdrawl.\n4. Deposit.\n5. Online transfer\n6. Change password.\n7. Logout\n\t\t");
							scanf("%d",&a);
							switch(a)
							{
								case 1:
									printf("\nName: %s\nAddress: %s\nAccount number: %ld\nDate of Birth: %d/%d/%d\n",c.name,c.address,c.acc_no,c.day,c.month,c.year);
									getch();
									system("cls");
									goto meny;
									break;
								case 2:
									strcpy(filename,usernamec);
									fp=fopen(strcat(filename,".dat"),"r");
									fread(&user1,sizeof(struct customer),1,fp);
									fclose(fp);
									if((c.balance)>=500)
									{
										printf("\nActual balance : %.2f",c.balance);
										printf("\nAvailable balacne : %.2f",(c.balance-500));
										printf("\nInterest rate : 4.25 %");
										printf("\nAccured Interest : %.2f",((c.balance*4.25)/100)/12);
									}
									else
									{	
										printf("\nActual balance : %.2f",c.balance);
										printf("\nAvailable balance :0.00");
										printf("\nInterest  rate : 4.25 %");
										printf("\nAccured Interest : %.2f",((c.balance*4.25)/100)/12);
									}
								
									getch();
									system("cls");
									goto meny;
									break;
								case 3:
									strcpy(filename,usernamec);
									fp=fopen(strcat(filename,".dat"),"r");
									fread(&user1,sizeof(struct customer),1,fp);
									fclose(fp);
									printf("\nAmount to withdraw:\n");
									scanf("%d",&amt);
									if(c.balance>=amt)
									{
										c.balance-=amt;
									}
									else
									{
										printf("You don't have enough balance to withdraw.\n");
									}
									fp=fopen(strcat(filename,".dat"),"r");
									fread(&user1,sizeof(struct customer),1,fp);
									fclose(fp);
									fp=fopen(filename,"w");
									fwrite(&c,sizeof(struct customer),1,fp);
									fclose(fp);
									if(fwrite!=NULL)
									{
										printf("\nYou withdrew Rs.%d ",amt);
									}
									getch();
									system("cls");
									goto meny;
									break;
								case 4:
									strcpy(filename,usernamec);
									fp=fopen(strcat(filename,".dat"),"r");
									fread(&user1,sizeof(struct customer),1,fp);
									fclose(fp);
									printf("\nAmount to deposit:\n");
									scanf("%d",&amt);
									fp=fopen(filename,"w");
									c.balance+=amt;
									fwrite(&c,sizeof(struct customer),1,fp);
									fclose(fp);
									if(fwrite!=NULL)
									{
										printf("\nYou succesfully deposited Rs.%d",amt);
										getch();
									}
									system("cls");
									goto meny;
									break;
								case 5:
									system("cls");
									{
										printf("Enter username to transfer:\t");
										fflush(stdin);
										gets(useradmin1);
										printf("Enter amount to transfer:\t");
										scanf("%d",&amt);
										strcpy(filename,useradmin1);
										fp=fopen(strcat(filename,".dat"),"r");
										if(fp==NULL)
										{
											printf("Username is not registered.");
											getch();
											goto meny;
										}
										else
										{
											fread(&user1,sizeof(struct customer),1,fp);
										
										if(amt>=c.balance-500)
										{
											printf("Insufficient balance.");
											getch();
										}
										else
										{
											strcpy(filename,useradmin1);
											fp=fopen(strcat(filename,".dat"),"r");
											fread(&user1,sizeof(struct customer),1,fp);
											fclose(fp);
											if(fread!=NULL)
											{
												strcpy(filename,useradmin1);
												fp=fopen(strcat(filename,".dat"),"w");
												user1.balance+=amt;
												fwrite(&user1,sizeof(struct customer),1,fp);
												fclose(fp);
												
											}
											if(fwrite!=NULL)
											{
												printf("You have succesfully transfered Rs.%d to %s",amt,user1.username);
												getch();
												strcpy(filename,usernamec);
												fp=fopen(strcat(filename,".dat"),"w");
												c.balance-=amt;
												fwrite(&c,sizeof(struct customer),1,fp);
												fclose(fp);
											}
										}
										}
										fclose(fp);
										goto meny;
									}
									system("cls");
									printf("!!!!!!INVALID INPUT!!!!!!");
									getch();
									system("cls");
									goto meny;
								case 6:
								passs:
									printf("\nEnter old password: ");
									fflush(stdin);
									gets(oldpass);
									printf("Enter new password: ");
									fflush(stdin);
									gets(newpass);
									printf("Re-enter new password: ");
									fflush(stdin);
									gets(newpass1);
									fp=fopen(strcat(filename,".dat"),"r");
									fread(&c,sizeof(struct customer),1,fp);
									fclose(fp);
									if(strcmp(oldpass,c.password)!=0)					//Password shown wrong
									{
										printf("\nYou entered wrong password.");
										getch();
										system("cls");
									}
									else
									{
										if(strcmp(newpass,newpass1)==0)
										{	
											strcpy(filename,usernamec);
											fp=fopen(strcat(filename,".dat"),"w");
											strcpy(c.password,newpass1);
											fwrite(&c,sizeof(struct customer),1,fp);
											if(fwrite!=NULL)
											{
												printf("Password changed.");
												getch();
												system("cls");
												goto login;
											}
											fclose(fp);
											goto passs;
											getch();
										}
										else
										{
											printf("\nNew passwords doesn't match.'");
											getch();
											system("cls");
											goto passs;
										}
									}
									system("cls");
									goto meny;
									break;
								case 7:	
									goto home;
								default:
									printf("\nInvalid Input");
									getch();
									system("cls");
									goto meny;
							}
						}
						else
						{
							printf("\nYour username or password is incorrect.");				//Error while logging in
							getch();
							system("cls");
							goto login;
						}
					case 2:
						/*for(i=0;i<100;i++)
						{
							if(c.name==NULL)
							{
								m=i;
								break;
							}	
						}*/
						system("cls");
						printf("\nEnter your details for registration:\nName: ");
						fflush(stdin);
						gets(c.name);
						printf("\nAddress: ");
						fflush(stdin);
						gets(c.address);
						printf("\nDate of Birth(DD/MM/YYYY): ");
						fflush(stdin);
						scanf("%d%d%d",&c.day,&c.month,&c.year);
					ree:
						printf("\nUsername: ");
						fflush(stdin);
						gets(user);
						strcpy(filename,user);
						fp=fopen(strcat(filename,".dat"),"r");
						fread(&c,sizeof(struct customer),1,fp);
						if(fread!=NULL)
						{
							if(strcmp(c.username,user)!=0)
							{
								strcpy(c.username,user);
							}
							else
							{
								printf("Username already taken");
								getch();
								goto ree;
							}
						}
						
					re:
						printf("\nPassword: ");
						fflush(stdin);
						gets(c.password);
						if(strcmp(c.username,c.password)==0)
						{
							printf("Username and password mustn't match.");
							getch();
							goto re;
						}
						//for(i=0,m=0;user[i]="/0";i++)	{	m++;}	
						acno=01003245001;
						c.acc_no=acno+(m*127);
						fclose(fp);
						
						system("cls");
						strcpy(filename,user);
						fp=fopen(strcat(filename,".dat"),"w");
						fwrite(&c,sizeof(struct customer),1,fp);
						if(fwrite!=0)
							printf("\nAccount succesfully registered.");
							
						else
							printf("\nSomething went wrong, please try again.");
						
						fclose(fp);
						getch();
						system("cls");
						goto login;
						break;
					default:
						printf("\nInvalid Input");
						getch();
						system("cls");
				}
			case 3:
				exit(0);
			default:
				printf("\nInvalid Input");
				getch();
				system("cls");
				break;
			}
		}
		getch();
	}
}