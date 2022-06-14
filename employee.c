#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
EMPLOYEE* list_of_employees=NULL;

void printEmployee(EMPLOYEE e){
    printf("%s%s%s","Name: ",e.name,", ");
    printf("%s%d\n","ID: ",e.id);
    if(e.payments==NULL){
      printf("No Payments..\n");
    }else{
      printf("--------------------\n");
      printf("Date              Amount\n");
      printf("----              ------\n");
      while(e.payments != NULL){
        printf("%s%s",e.payments->date,"        ");
        printf("%.6f\n",e.payments->amount);
        e.payments = e.payments->next;
      }
      
    }
}



void addEmployee(int e_id, char* e_name){
    EMPLOYEE *e = malloc(sizeof(EMPLOYEE));
    e->id = e_id;
    e->name = (char *)malloc(sizeof(char)*100);
    strcpy(e->name,e_name);
    e->next = list_of_employees;
    list_of_employees = e;
    
}

void printEmployees(){
    EMPLOYEE* p=list_of_employees;
    if(p==NULL){
      printf("The list is empty.");
    }
    while(p!=NULL){
        printEmployee(*p);
        printf("==================================\n");
        p=p->next;
    }
    
}

int addPayment(int e_id, char* p_date, float p_amount){
    int check =0;
    EMPLOYEE* p=list_of_employees;
    
    PAYMENT * pay = malloc(sizeof(PAYMENT));
    pay->amount = p_amount;
    pay->date = (char *)malloc(sizeof(char)*100);
    strcpy(pay->date,p_date);
    
    while(p!=NULL){
      if(p->id==e_id){
        pay->next = p->payments;
        p->payments = pay;
        return 1;
        
      }else{
        if(p->next!=NULL){
          p=p->next;
        }
      }
    }
    return check;
}

int deleteEmployee(int e_id, char* e_name){
    EMPLOYEE* p=list_of_employees;
    if(list_of_employees->id==e_id){ 
        list_of_employees=list_of_employees->next;
        free(p);
        p=NULL;
        return 1;
    }else{
        EMPLOYEE* current=list_of_employees;
        EMPLOYEE* previous=current;
        while((current!=NULL)&&(current->id!=e_id)){
          previous=current;
          current=current->next;
        }
        if(current!=NULL){
          previous->next=current->next;
          free(current);
          current=NULL;
          return 1;
        }else{
          return 0;
        }
    }
}
