#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defines */
#define ACCOUNT_QUANTITY 100

/* Typedef */
typedef struct account
{
  int accNr;
  char* firstName;
  char* lastName;
  float balance;
}account;

/* Local declaration */
void dispMeny(void);
void open_DB_file_and_store_in_struct_array(void);
void save_structArray_in_file(void* dataToSave_p, char* fileName);
account* createOneAcc(int accNr, char* firstName, char* lastName, float balance);
void printAccount(account* acc_p);
void create_new_account(struct account accounts[], int* numOfAccs_p);
void show_all_accounts(struct account accounts[], int num_accs);


/* Main program */
int main()
{
  int i;
  struct account accounts[ACCOUNT_QUANTITY];
  account* account_p = NULL;
  int num_accs = 0;

//This is for testing!!
  create_new_account(accounts, &num_accs);
  create_new_account(accounts, &num_accs);

  show_all_accounts(accounts, num_accs);

/*
  printf("\n***** Inside main(), after create_new_account() *****\n");
  printAccount(&accounts[0]);
  printf("\nnum_accs: %d\n", num_accs);

/*
  account_p = createOneAcc(1337, "Saqib", "Sarker", 9000);

  accounts[0] = *account_p;

  printAccount(account_p);

  account_p = NULL;

  printf("********************************************************\n");

  printAccount(&accounts[0]);

  char option;

  //open_DB_file_and_store_in_struct_array();
  while(1)
  {
    printf("***** Welcome to bank application *****\n");

    dispMeny();
    printf("Enter any option (1,2,3,4,5,6,7,8,9) to continue\n");

    option = getchar();
    switch(option)
    {
      case '1':
        //create_new_account(accounts, &num_accs);
        break;
      case '2':
        //show_all_accounts(accounts, &num_accs);
        break;
      case '3':
        //sort_accounts();
        break;
      case '4':
        //search_for_account();
        break;
      case '5':
        //change_balans_for_a_account();
        break;
      case '6':
        //remove_account();
        break;
      case '7':
        //show_statistics();
        break;
      case '8':
        //transfer();
        break;
      case '9':
        //save_structArray_in_file();
        return 0;
        break;
      default:
        system("clear");//Linux command
        printf("Enter any option (1,2,3,4,5,6,7,8,9) to continue\n");
        break;
    }
    system("clear");//Linux command
  }

*/
  return 0;
}

/* Local definition */
void dispMeny(void)
{
  printf("\n1 Add new account\n");
  printf("2 Show all accounts\n");
  printf("3 Sort accounts\n");
  printf("4 Search for a account\n");
  printf("5 Change balans for a account\n");
  printf("6 Remove a account\n");
  printf("7 Statistics\n");
  printf("8 Transfer\n");
  printf("9 End\n\n");
}


/**
* Load structs from file into internal struct-array
* File must be .txt
*
* If file does not exist, create one at the end of application with same name.
**/
void open_DB_file_and_store_in_struct_array(void)
{

}


/**
* Save internal struct in file.
* File must be .txt
*
* Save with same name open_DB_file_and_store_in_struct_array() opend
**/
void save_structArray_in_file(void* dataToSave_p, char* fileName)
{
  FILE *fp;

  fp = fopen( fileName , "w" );
  fwrite(dataToSave_p , sizeof(struct account) , sizeof(*dataToSave_p) , fp);

  fclose(fp);
}


void printAccount(struct account* acc_p)
{
  if(acc_p != NULL)
  {
    printf("AccNr: %d\n", acc_p->accNr);
    printf("Balance: %f\n", acc_p->balance);
    printf("FirstName: %s\n", acc_p->firstName);
    printf("LastName: %s\n", acc_p->lastName);
  }
  else
  {
    printf("\n\tThe pointer sent to printAccount() was NULL\n");
  }
}


account* createOneAcc(int accNr, char* firstName, char* lastName, float balance)
{
  //Allocate memory
  account* acc_p = malloc(sizeof(struct account));

  acc_p->accNr = accNr;
  acc_p->balance = balance;
  acc_p->firstName = strdup(firstName);
  acc_p->lastName = strdup(lastName);

  //printf("\n***** Inside createOneAcc(), before return acc_p *****\n");
  //printAccount(acc_p);
  return acc_p;
}


void create_new_account(struct account accounts[], int* numOfAccs_p)
{
  int accNr;
  char firstName[20];
  char lastName[20];
  float balance;

  printf("Enter account number: ");
  scanf("%d", &accNr);
  fflush(stdin); //Clear stdin buffer

  printf("Enter first name: ");
  scanf("%19s", firstName);
  fflush(stdin); //Clear stdin buffer

  printf("Enter last name: ");
  scanf("%19s", lastName);
  fflush(stdin); //Clear stdin buffer

  printf("Enter the balance on this account: ");
  scanf("%f", &balance);
  fflush(stdin); //Clear stdin buffer
/*
  //TESTING
  printf("\n*****Inside create_new_account(), after input from user*****\n");
  printf("\naccNr: %d", accNr);
  printf("\nfirstName: %s", firstName);
  printf("\nlastName: %s", lastName);
  printf("\nbalance: %f", balance);
*/

  account* acc_p = NULL;
  acc_p = createOneAcc(accNr, firstName, lastName, balance);
/*
  printf("\n***** Inside create_new_account(), after createOneAcc() call *****\n");
  printAccount(acc_p);

  accounts[0] = *acc_p;
  printf("\n***** Inside create_new_account(), after accounts[0] = *acc_p *****\n");
  printAccount(&accounts[0]);
*/

  if(acc_p != NULL)
  {
    //printf("\n***** Inside create_new_account(), inside if(acc_p != NULL) *****\n");
    //printf("\n\nnumAccs before adding: %d", *num_accs_p);
    accounts[*numOfAccs_p] = *acc_p;
    *numOfAccs_p += 1;
    //printf("\n\nnumAccs after adding: %d", *num_accs_p);
  }
}


void show_all_accounts(struct account accounts[], int num_accs)
{
  int i;
  for(i = 0; i < num_accs ; i++)
  {
    //printf("\n***** Inside show_all_accounts(), inside for-loop *****\n");
    printAccount(&accounts[i]);
  }
}
