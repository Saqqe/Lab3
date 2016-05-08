#include <stdio.h>
#include <stdlib.h>

/* Defines */
#define ACCOUNT_QUANTITY 100

/* Local declaration */
void dispMeny(void);
void open_DB_file_and_store_in_struct_array(void);
void save_structArray_in_file(void);


//TODO: might need to change to "typdef"
struct Account_information
{
  int accNr;
  char firstName[15];
  char lastName[15];
  float balance;
};


/* Main program */
int main()
{
  struct Account_information account[ACCOUNT_QUANTITY];
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
        //create_new_account();
        break;
      case '2':
        //show_all_accounts();
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
void save_structArray_in_file(void)
{

}
