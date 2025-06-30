#include "invert.h"

int display_database(hash_table *arr)
{
    int i , j , flag = 0;
    main_node *temp1  ;
    sub_node *temp2 ;

    //Display the database in table form
    printf("%-8s %-15s %-17s %-16s %-8s\n\n","Index","Word","File Count","File Name","Word Count");
    for(i = 0 ; i < 28 ; i++)
    {
        if(arr[i].link != NULL)
        {
            temp1 = arr[i].link ;
            
            while(temp1 != NULL)
            {
                temp2 = temp1 ->sub_link ;
                    printf("%-10d",i);
                    printf("%-18s",temp1 ->word);
                    printf("%-15d",temp1 ->filecount);
                    flag = 0 ;
                    while(temp2 != NULL)
                    {
                        if(flag == 1)
                        {
                            printf("%-10s %-18s %-13s","","","");
                        }
                        printf("%-20s",temp2 ->file_name);
                        printf("%-10d\n",temp2 ->wordcount);
                        flag = 1 ;
                        temp2 = temp2 ->sublink ;
                    }
                    printf("\n");
                    
                temp1 = temp1 ->mainlink ;
                
            }
            
        }
    }
    return SUCCESS ;
}