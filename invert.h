#ifndef INVERT_H
#define INVERT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1 

typedef struct main_node
{
    int filecount ;
    char word[30] ;
    struct sub_node *sub_link ;
    struct main_node *mainlink ;
    
}main_node;

typedef struct sub_node
{
    int wordcount ;
    char file_name[30] ;
    struct sub_node *sublink ;
}sub_node ;

typedef struct hash_table
{
    int key ;
    struct main_node *link;
}hash_table;

typedef struct filename
{
    char file_name[30] ;
    struct filename *link;
}filename;


extern int created , updated ;

//Function to print linked list
int print_list(filename *head) ;

/*Function to validate the command line argument*/
int read_and_validate_CLA(int argc ,char *argv[] , filename **head);

/*Function to create hash table*/
void create_HT(hash_table *HT, int size);

/*Function to create database*/
int create_database(hash_table *arr , filename **head);

/*Function to display database*/
int display_database(hash_table *arr );

/*Function to search word*/
int search_word(hash_table *arr) ;

/*Function to save database*/
int save_database(hash_table *arr);

/*function to update database*/
int update_database(hash_table *arr );

/*Function to find the index of the word*/
int find_index(char word);

/*Function to create subnode*/
sub_node *create_subnode() ;

/*Function to create Main node*/
main_node *create_main_node();

#endif