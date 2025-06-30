#include "invert.h"

int search_word(hash_table *arr)
{
    char word[30];
    int index ;

    printf("\nEnter the word to search : ");
    scanf("%s",word);

    index = find_index(word[0]);

    //Checking if word is present or not
    while(arr[index].link != NULL)
    {
        if(strcmp(arr[index].link ->word , word) == 0 )
        {
            main_node *temp = arr[index].link;
            sub_node *temp2 = temp ->sub_link  ;
            printf("\n%s is present in %d files\n",temp ->word , temp ->filecount);
            while(temp2 != NULL)
            {
                printf("In %s %d times\n",temp2->file_name, temp2->wordcount);
                temp2 = temp2 ->sublink ;
            }
            printf("\n");
            break;
        }
        arr[index].link = arr[index].link ->mainlink ;
        
    }
    if(arr[index].link == NULL)
    {
        printf("\nINFO : Word is not found in the Database.\n");
        return FAILURE;
    }
    return SUCCESS ;
}

int save_database(hash_table *arr)
{
    char file[30];
    main_node *temp ;
    sub_node *temp1 ;
    
    printf("\nEnter the filename to save the data : ");
    scanf("%s",file);

    //saving the data to file
    if(strstr(file , ".txt") != NULL)
    {
        FILE *fp ;
        fp = fopen(file, "w"); //open file in write mode
        for(int i = 0 ; i < 28 ; i++)
        {
            if(arr[i].link != NULL)
            {
                temp = arr[i].link ;
                while(temp != NULL)
                {
                    temp1 = temp ->sub_link ;
                    //writing into the file
                    fprintf(fp , "#%d;%s;%d;",i ,temp ->word , temp ->filecount);
                    while(temp1 != NULL)
                    {
                        fprintf(fp , "%s;%d;",temp1 ->file_name , temp1 ->wordcount);
                        temp1 = temp1 -> sublink ;
                    }
                    fprintf(fp,"#\n");
                    temp = temp ->mainlink ;
                }
            }
        }
        fclose(fp); //closing the file
            
    }
    else
    {
        printf("\nINFO : Not a valid file extension , Pass the filename in .txt format.\n\n");
        return FAILURE ;
    }
    printf("\n\nINFO : Database Saved\n\n");
    return SUCCESS ;
}