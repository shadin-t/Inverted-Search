#include "invert.h"

int update_database(hash_table *arr)
{
    if(created == 1)//checking if database already created or not
    {
        printf("\nINFO: Database is already created , So Update is not possible\n");
        return FAILURE;
    }

    if(updated == 1)//checking if database already updated or not
    {
        printf("\nINFO: Database is already created, So Update is not possible\n");
        return FAILURE;
    }
    char file[30];
    int size;
    char ch , ch1;
    printf("\nEnter file to update : ");
    scanf("%s",file);
    if(strstr(file , ".txt") != NULL)
    {
        FILE *fp;
        fp = fopen(file,"r");   //open the file in read mode

        //check file exist or not
        if(fp == NULL)
        {
            printf("\nINFO : %s => File does not exist in current directory\n\n",file);
            return FAILURE ;
        }
        else
        {
            fseek(fp , 0 , SEEK_END);
            size = ftell(fp);
            //printf("size of file = %d\n",size);
            rewind(fp);
            
            //check if file empty or not
            if(size == 0)
            {
                printf("\nINFO : %s => File is Empty\n\n",file);
                return FAILURE ;
            }
            else
            {
                //get first character from file , check if it is # or not
                ch = fgetc(fp);
                if(ch == '#')
                {
                    
                    fseek(fp , 0 ,SEEK_END);
                    fseek(fp, -2, SEEK_END);
                    //printf("fp = %ld\n",ftell(fp));
                    ch1 = fgetc(fp);
                    rewind(fp);

                    //check last character is # or not
                    if(ch1 == '#')
                    {
                        //Declare variables
                        int index, filecount, wordcount;
                        char word[20], filename[20];
                        main_node *temp1, *tempt;
                        sub_node *temp2;

                        while (fscanf(fp, "#%d;%[^;];%d;", &index, word, &filecount) != EOF) //updating database into the table
                        {
                            //if no element in table
                            if (arr[index].link == NULL)
                            {
                                
                                temp1 = create_main_node();
                                arr[index].link = temp1;
                                temp1 -> filecount = filecount;
                                strcpy(temp1 -> word, word);

                                temp2 = temp1 -> sub_link;
                                fscanf(fp, "%[^;];%d;", filename, &wordcount);
                                temp2 -> wordcount = wordcount;
                                strcpy(temp2 ->file_name, filename);
                                
                                //loop to create subnode
                                for (int i = 0; i < filecount - 1; i++)
                                {
                                    fscanf(fp, "%[^;];%d;", filename, &wordcount);
                                    temp2 -> sublink = create_subnode();
                                    temp2 = temp2 -> sublink;
                                    temp2 -> wordcount = wordcount;
                                    strcpy(temp2 ->file_name, filename);
                                    
                                }
                            }
                            else
                            {
                                
                                temp1 = arr[index].link;
                                while (temp1 ->mainlink != NULL) 
                                {
                                    temp1 = temp1 -> mainlink;
                                }

                                temp1 -> mainlink = create_main_node();
                                temp1 = temp1 -> mainlink;
                                temp1 ->filecount = filecount;
                                strcpy(temp1 -> word, word);

                                temp2 = temp1 ->sub_link;
                                fscanf(fp, "%[^;];%d;", filename, &wordcount);
                                temp2 -> wordcount = wordcount;
                                strcpy(temp2 ->file_name, filename);
        
                                //loop to create subnode
                                for (int i = 0; i < filecount - 1; i++)
                                {
                                    fscanf(fp, "%[^;];%d;", filename, &wordcount);
                                    temp2 -> sublink = create_subnode();
                                    temp2 = temp2 -> sublink;
                                    temp2 -> wordcount = wordcount;
                                    strcpy(temp2 ->file_name, filename);
                                
                                }
                            }
                            fscanf(fp,"#\n"); //to next line

                        }

                        fclose(fp); //closing the file
                        
                    }
                    else
                    {
                        printf("\nINFO: The file doesn't have the database\n");
                        return FAILURE; 
                    }

                }
                else
                {
                    printf("\nINFO: The file doesn't have the database\n");
                    return FAILURE; 
                }
            }
        }
    }
    else
    {
        printf("\nINFO: Filename should be in .txt format\n");
        return FAILURE;
    }
    
    printf("\n\nINFO: Database Updated Successfully\n\n");

    //make global flag as 1 to ensure updated or not
    updated = 1 ;
    return SUCCESS ;
}