#include "invert.h"

int create_database(hash_table *arr , filename **head)
{
    if(created == 1)//checking if the database is created or not.
    {
        printf("\nINFO: Database is already created\n");
        return FAILURE;
    }
    FILE *fp ;
    char word[30];
    int index , flag = 0 ;
    filename *temp = *head;
    main_node *temp1 , *tempt ;
    
    while (temp != NULL)
    {
        fp = fopen(temp ->file_name ,"r"); //open the file in read mode
        while (fscanf(fp ,"%s", word) != EOF) // storing word by word from file
        {
            
            index = find_index(word[0]);  //find index of the word

             //creating mian nodes and subnodes
            if(arr[index].link == NULL)
            {
                temp1 = create_main_node();
                arr[index].link = temp1 ;
                strcpy(temp1 -> word , word);
                strcpy(temp1 ->sub_link ->file_name , temp ->file_name);
                temp1 ->filecount++ ;
                temp1 ->sub_link ->wordcount++ ;
                
            }
            else
            {
                flag = 0 ;
                temp1 = arr[index].link ;
                while(temp1  != NULL)
                {
                    
                    if(strcmp(temp1 ->word , word) == 0)
                    {
                        sub_node *temp2 = temp1 ->sub_link , *sec = NULL;
                        while(temp2 != NULL)
                        {
                            if(strcmp(temp2 ->file_name , temp ->file_name) == 0)
                            {
                                flag = 1 ;
                                temp2 ->wordcount++ ;
                                
                                break ;
                            }
                            sec = temp2 ;
                            temp2 = temp2 ->sublink ;
                        }
                        if (flag == 0)
                        {
                            if(sec != NULL)
                            {
                                sec ->sublink = create_subnode();
                                temp2 = sec ->sublink ;
                                temp1 ->filecount++ ;
                                
                            }
                            else
                            {
                                temp1 ->sub_link = create_subnode();
                                temp2 = temp1 ->sub_link ;
                                temp1 ->filecount++ ;
                            }
                            temp2 ->wordcount++ ;
                            strcpy(temp2 ->file_name , temp ->file_name);
                            flag = 1 ;
                            

                        }
                        break;
                    }
                    tempt = temp1 ;
                    temp1 = temp1 ->mainlink ;
                }
                if (flag == 0)
                {
                    tempt ->mainlink = create_main_node();
                    temp1 = tempt ->mainlink ;
                    temp1 ->filecount++ ;
                    strcpy(temp1 ->word , word);
                    strcpy(temp1 ->sub_link ->file_name , temp ->file_name);
                    temp1 ->sub_link ->wordcount++ ;
                    
                }
                    
            }
        }
        fclose(fp); //close the file
        
        temp = temp ->link ;  
    }
    created = 1 ; // make global flag as 1 , to know database is created
    printf("\nINFO : Successfull creation of database.\n\n");
    return SUCCESS ;
    
}
