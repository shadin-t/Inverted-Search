#include "invert.h"


int print_list(filename *head)
{
	if (head == NULL)
	{
		printf("\nINFO : List is empty\n");
        return FAILURE ;
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> file_name);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
    return SUCCESS;
}
int read_and_validate_CLA(int argc ,char *argv[] , filename **head)
{
    int i , size ;
    if(argc > 1)  //Check if files are given or not
    {
        for( i = 1 ; i < argc ; i++)
        {
            if((strstr(argv[i], ".txt")) != NULL) //Check if extension is .txt or not
            {
                FILE *file = fopen(argv[i] , "r");
                if(file == NULL) //Check file exist or not
                {
                    printf("\nINFO : %s => File does not exist in current directory\n",argv[i]);
                    
                }
                else
                {
                    fseek(file , 0 , SEEK_END);
                    size = ftell(file);
                    fclose(file);
                    //printf("size of file = %d\n",size);
                    if(size == 0)  //check file is empty or not
                    {
                        printf("\nINFO : %s => File is Empty\n",argv[i]);
                        
                    }
                    else
                    {
                        filename *temp = *head  ;
                        int flag = 0 ;
                        while(temp  != NULL)
                        {
                            if(strcmp(temp->file_name , argv[i]) == 0)
                            {
                                flag = 1 ;  //if same file name given more than once flag becomes 1
                                break ;       
                            }
                            temp = temp -> link ;
                        }
                        if(flag == 0)  //creating linked list
                        {
                            filename *new = malloc(sizeof(filename));
                            if(new == NULL)
                            {
                                printf("Failure in creating node\n");
                            }
                            strcpy(new -> file_name , argv[i]) ;
                            new -> link = NULL ;
                            
                            if((*head) == NULL)
                            {
                                *head = new ;
                            }
                            else
                            {
                                temp = *head ;
                                while(temp -> link != NULL)
                                {
                                    temp = temp -> link ;
                                }
                                temp -> link = new ;
                            }
                            printf("\nINFO: %s => Added to the list\n", argv[i]);
                        }
                        else  // if flag is 1 file already exists
                        {
                            printf("\nINFO: %s => File already exists in the list. Not adding again.\n", argv[i]);
                        
                        }
                        
                    }
                }
            }
            else
            {
                printf("\nINFO : %s => This file is not a .txt file\n",argv[i]);
                
            }
        }
        
        //print linked list
        if(print_list(*head) == FAILURE)
        {
            return FAILURE ;
        } 
        printf("\n\nINFO : Successfull : inserting file name into file linked list\n\n");
        return SUCCESS ;
    }
    else
    {
        printf("\nInfo : Insufficient Arguments\nPlease pass arguments like a.out <txt file>\n");
        return FAILURE;
    }
}
void create_HT(hash_table *HT, int size)
{
    int i ;
    for(i = 0 ; i < size ; i++)
    {
        HT[i].key = i ;
        HT[i].link = NULL ;
    }
}
int find_index(char word)
{
    if(word >= 'A' && word <= 'Z')
    {
        return (word - 65) ;
    }
    else if(word >= 'a' && word <= 'z')
    {
        return (word - 97) ;
    }
    else if (word >= '0' && word <= '9')
    {
        return 26 ; 
    }
    else
    {
        return 27 ;
    }
}

sub_node *create_subnode()
{
    /* Creating subnode and make link NULL and count 0*/
    sub_node * new = malloc(sizeof(sub_node));

    new -> wordcount = 0 ;
    new ->sublink = NULL ;

    return new;
}

main_node *create_main_node()
{
    /* Creating mainnode and make link NULL and count 0 and for sublink call create subnode function*/

    main_node *new = malloc(sizeof(main_node));

    new -> filecount = 0 ;
    
    new -> mainlink = NULL ;

    new -> sub_link = create_subnode();

    return new;

}