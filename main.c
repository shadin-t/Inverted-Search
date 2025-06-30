/*  ----DOCUMENTATION----
    NAME : MOHAMMAD SHADIN
    DATE : 28-12-24
    DES  : INVERTED SEARCH (DS PROJECT)
*/
#include "invert.h"

//global variable
int created = 0 , updated = 0 ;

int main(int argc , char *argv[])
{
    hash_table arr[28];     //Declare hashtable
    filename *head = NULL ; 

    if(read_and_validate_CLA(argc , argv ,&head) == SUCCESS)
    {
        create_HT(arr , 28); 
        int option ;
        char c;
        while(1)
        {
            printf("\nSelect your choice among following operations :\n");
            printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\n\n");
            printf("Enter your choice :");
            scanf("%d",&option);

            switch(option)  //switch case to do operations
            {
                case 1 :
                    create_database(arr , &head);
                    break ;

                case 2 :
                    display_database(arr) ;
                    break ;

                case 3 :
                    update_database(arr );
                    break;

                case 4 :
                    search_word(arr);
                    break ;

                case 5 :
                    save_database(arr);
                    break ;

                default :
                    printf("Enter a valid option\n");
            }
            printf("\nDo you want to continue?\n");
            printf("Enter y/Y to continue or n/N to discontinue\n");
            scanf(" %c",&c);
            if(c == 'N' || c == 'n')
            {
                break ; //if n/N stop the loop and exit
            }
        }
    }
    else
    {
        printf("INFO : Files are not there \nCreate database is not possible\n");

    }
}