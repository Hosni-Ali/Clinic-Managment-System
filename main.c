#include<stdio.h>             
#include<stdlib.h>
#include"std_types.h"




struct record
{
	u8 id;
	u8 name[8];
	u8 gender;
	u8 age;
	u8 res ;
	struct record *nextptr;
};
 
 struct record *head = NULL;
 struct record *tail = NULL;

 void add_new_record(void);
 u8 search_by_id(u8 key);
 void edit_record(void);
 void view_by_id(u8 id);
 void available_slots(void);
 //void reserve_slot(u8 reqid, u8 reschoose);
 void cancel_reserve_slot(void);
 void view_reserve_slots(void);


 
 
 
 void main(void)
{
    u16 modenum,adminpassword,i,adminchoose,userchoose,backtoadmin,backtouser,backtomainpage,iduserview,cancel=0;
do
{	
    printf("for admin login mode please enter number 1\nfor user login mode please enter number 2\n");
    printf("------------------------------------------------\n");
    scanf("%d",&modenum);
    if (modenum == 1)
    {
        
        for(i=0;i<3;i++)
        {
            printf("password:");
            scanf("%d",&adminpassword);
            if(adminpassword==1234)
               {
                   break;
               }
            else
               {
                   if(i==2)
                   continue;
                  printf("incorect password,please try agian\n");
               }
        }
            if(adminpassword==1234)
            {
				do
				{
				
				
				
                printf("welcome in clanic management system admin mode\n");
                printf("------------------------------------------------\n");     //code of admin mode will be in this condition
				printf("please press 1 for Adding new patient record\n"); 
				printf("please press 2 for Edit patient record\n");
				printf("please press 3 for Reserve a slot with the doctor\n");
				printf("please press 4 for Cancel reservation with the doctor\n");
				printf("please press 5 for exit\n");
				printf("------------------------------------------------\n");
				scanf("%d",&adminchoose);
				
				
				switch(adminchoose)
				{
					case 1 : 
					
					            
	                                 add_new_record();
		                             
	 
	                               
					                 break;
					
					
					
					
					case 2 :
					
					            
	                                 edit_record();
		                             
	 
	                               
					                 break;
					
					
					
					
					
					case 3 :
					
					
					                 available_slots();
								     
								     printf("\n===================================\n");
								
								     break;
					
					
					
					case 4 :    
					
					                 cancel_reserve_slot();
								     printf("slot canceled successfully\n");
								     printf("\n===================================\n");
								     
								     break;
					
					
					
					
					case 5 : 
					
					
					                 printf("thank you\n");
								     break;
					
					
					default :
					                 printf("wrong choose\n");
								     break;
				}
				
				printf("\n===================================\n");
				printf("press one for back to admin page ----press two for exit\n");
				scanf("%d",&backtoadmin);
				
                }while(backtoadmin==1);
            }
            else
            {
                printf("no more trials thank you\n");
            }
    }        
    else if(modenum==2)
    {
        
		do
		{
			
			
			
			printf("welcome in clanic management system user mode\n");                     //code of user mode will be in this condition
            printf("------------------------------------------------\n");
			printf("please press 1 for view patient record\n"); 
		    printf("please press 2 for View today reservations\n");
		    printf("please press 3 for exit\n");
		    printf("------------------------------------------------\n");
		    scanf("%d",&userchoose);
				
				
				switch(userchoose)
				{
					  case 1 :     
					              
								  
								  printf("please enter the ID\n");
								  scanf("%d",&iduserview);
								  view_by_id(iduserview);
								  
								  break;
					
					
					
					  case 2 :
					  
					  
					              view_reserve_slots();
						          printf("------------------------------------------------\n");
								  break;
					
					
					
					  case 3 :
					  
					  
					              printf("thank you\n");
								  break;
					
					
					  
					  default:  
					  
					               printf("wrong choose\n");
								   break;
					
					
				}	
			
			    printf("\n===================================\n");
				printf("press one for back to user page ----press two for exit\n");
				scanf("%d",&backtouser);
				
		}while(backtouser==1);
    }
    else
    {
        printf("incorect number,please try agian later\n");            //still not decide whether i will add trials or not 
    }
	
	printf("press one for back to main page ----press two for exit\n");
	scanf("%d",&backtomainpage);
	
}while(backtomainpage == 1);   
}



// adding new record // adding new record // adding new record // adding new record // adding new record// adding new record


void add_new_record(void)              
{
	u8 i,key,exist;
	struct record *ptr;
	ptr = (struct record*)malloc(sizeof(struct record));
	ptr->res=0;
	
	printf("please enter patient ID:");
	scanf("%d",&(ptr->id));
	
	key = ptr->id;
	
	
	exist = search_by_id(key);
	
	if (exist>0)
	{
		printf("The ID is already exist\n");
		free(ptr);
	}
	else 
	{
	    printf("\nplease enter patient name:");
	    for(i=0;i<8;i++)
		{
			scanf("%c",&(ptr->name[i]));
		}
	
	    printf("gender: for male press 0 -- for female press 1\n");
	    scanf("%d",&(ptr->gender));
	
	    printf("please enter the patient age:");
	    scanf("%d",&(ptr->age));
	
	    printf("patient record added successfully\n");
	
	    if(head==NULL)
	       {
		     head = ptr;
		     tail = ptr;
		     ptr->nextptr = NULL ;
	       }
	    else
	       {
		     tail->nextptr = ptr;
		     tail = ptr;
		     tail->nextptr = NULL;
	       }
	}	
}

// searching by id // searching by id // searching by id // searching by id // searching by id // searching by id // searching by id 

u8 search_by_id(u8 key)                                
{
	u8 find=0;
	struct record * sptr;
	sptr = head;
	while(sptr!=NULL)
	{
		if(sptr->id == key)
		{
			find++;
			
			
		}
		sptr = sptr->nextptr;
	}
	return find;
} 


// edit by id // edit by id  // edit by id  // edit by id // edit by id // edit by id  // edit by id  // edit by id  // edit by id  // edit by id 


void edit_record(void)
{
	u16 idsearch,i,count=0;
	struct record * ptredit;
	ptredit = head;
	printf("please enter the ID:");
	scanf("%d",&idsearch);
	while(ptredit!=NULL)
	{
		
		
		if(ptredit->id == idsearch)
		    {
				        count++;
			            printf("please edit patient ID:");
	                    scanf("%d",&(ptredit->id));
	            
	                    printf("\nplease edit patient name:");
	                    for(i=0;i<8;i++)
		                   {
			                  scanf("%c",&(ptredit->name[i]));
		                   }
	
	                    printf("gender: for male press 0 -- for female press 1\n");
	                    scanf("%d",&(ptredit->gender));
	
	                    printf("please edit the patient age:");
	                    scanf("%d",&(ptredit->age));
	
	                    printf("patient record edited successfully\n");
						break;
	               
		    }
	        
			ptredit = ptredit->nextptr;
		   
		
	
	}
	
	if(count == 0)
	    {
		printf("incorrect ID,thank you\n");
     	}
	
	
	
}



// view by id  // view by id  // view by id  // view by id  // view by id  // view by id  // view by id  // view by id


void view_by_id(u8 id)
{
	struct record * ptrview;
	u8 i=0 , count;
	ptrview=head;
	while(ptrview!=NULL)
	{
		if(ptrview->id==id)
		{
			printf("ID: %d \n",ptrview->id);
			printf("name: ");
			for(i=0;i<8;i++)
			{
				printf("%c",ptrview->name[i]);
			}
			if(ptrview->gender == 0 )
			{
				printf("\ngender: Male\n");
				
			}
			else
			{
				printf("\ngender: female\n");
			}
			printf("age: %d \n",ptrview->age);
			
			count++;
			break;
		}
		else
		{
			ptrview=ptrview->nextptr;
		}
    }
	if(count==0)
	{
		printf("wrong ID\n");
	}


}



//available_slots view    //available_slots view  //available_slots view //available_slots view  //available_slots view  //available_slots view  



void available_slots(void)                                
{
	u8 reschoose , reqid , counta=0 , countb=0 , countc=0 , countd=0 , counte=0 ;
	struct record * avaptr;
	struct record * resptr;
	avaptr = head;
	while(avaptr!=NULL)
	{
		printf("%d\n",avaptr->res);
		if(avaptr->res == 1)
		{
			counta++;
		}
		else if(avaptr->res == 2)
		{
			countb++;
		}
		else if(avaptr->res == 3)
		{
			countc++;
		}
		else if(avaptr->res == 4)
		{
			countd++;
		}
		else if(avaptr->res == 5)
		{
			counte++;
		}
		avaptr = avaptr->nextptr;
	}
	
	printf("%d-%d-%d-%d-%d\n",counta,countb,countc,countd,counte);
	if(counta==0)
	{
		printf("from 2 pm to 2:30 pm is available\n");
		printf("click one to reserve it\n");
		printf("\n===================================\n");
	}
	if(countb==0)
	{
		printf("from 2:30 pm to 3 pm is available\n");
		printf("click two to reserve it\n");
		printf("\n===================================\n");
	}
	if(countc==0)
	{
		printf("from 3 pm to 3:30 pm is available\n");
		printf("click three to reserve it\n");
		printf("\n===================================\n");
	}
	if(countd==0)
	{
		printf("from 3:30 pm to 4 pm is available\n");
		printf("click four to reserve it\n");
		printf("\n===================================\n");
	}
	if(counte==0)
	{
		printf("from 4 pm to 4:30 pm is available\n");
		printf("click five to reserve it\n");
		printf("\n===================================\n");
	}
	
	if((counta != 0)&&(countb != 0)&&(countc != 0)&&(countd != 0)&&(counte != 0))
	{
		printf("no reservation available\n");
		printf("\n===================================\n");
	}
	else
	{	
	printf("please enter number of reversation\n");
	scanf("%d",&reschoose);
	printf("please enter the ID\n");
	scanf("%d",&reqid);
	
	 //reserve_slot(u8 reqid, u8 reschoose)
	
	resptr = head;
	while(resptr!=NULL)
	{
		if(resptr->id == reqid)
		{
			resptr->res = reschoose;
				
		}
		resptr = resptr->nextptr;
	}
	printf("slot reserved successfully\n");
	}

} 



//reserve_slot //reserve_slot  //reserve_slot  //reserve_slot  //reserve_slot  //reserve_slot 
 
 
 
 


/*void reserve_slot(u8 reqid, u8 reschoose)
{
	
	struct record * resptr;
	resptr = head;
	while(resptr!=NULL)
	{
		if(resptr->id == reqid)
		{
			resptr->res=reschoose;
				
		}
		resptr = resptr->nextptr;
	}
	
} */




//cancel_reserve_slot  //cancel_reserve_slot   //cancel_reserve_slot  //cancel_reserve_slot  //cancel_reserve_slot


void cancel_reserve_slot(void)
{
	struct record * ptr;
	u8 cancelid,count=0 ;
	printf("please enter the ID\n");
	scanf("%d",&cancelid);
	ptr = head ;
	while(ptr!=NULL)
	{
		if(ptr->id == cancelid)
		{
			ptr->res=0;
			count++;
				
		}
		ptr = ptr->nextptr;
	}
	
	if(count==0)
	{
		printf("wrong ID\n");
	}
}


//view_reserve_slot    //view_reserve_slot   //view_reserve_slot    //view_reserve_slot     //view_reserve_slot 

void view_reserve_slots(void)
{
	u8  counta=0 , countb=0 , countc=0 , countd=0 , counte=0 ;
	
	struct record * viewptr;
	viewptr = head;
	while(viewptr!=NULL)
	{
		if(viewptr->res==1)
		{
			printf("ID:%d\n",viewptr->id);
			printf("from 2 pm to 2:30 pm\n");
			counta++;
		
		}
		else if(viewptr->res==2)
		{
			printf("ID:%d\n",viewptr->id);
			printf("from 2:30 pm to 3 pm\n");
			countb++;
		}
		else if(viewptr->res==3)
		{
			printf("ID:%d\n",viewptr->id);
			printf("from 3 pm to 3:30 pm\n");
			countc++;
		}
		else if(viewptr->res==4)
		{
			printf("ID:%d\n",viewptr->id);
			printf("from 3:30 pm to 4 pm\n");
			countd++;
		}
		if(viewptr->res==5)
		{
			printf("ID:%d\n",viewptr->id);
			printf("from 4 pm to 4:30 pm\n");
			counte++;
		}
		viewptr = viewptr->nextptr;
	}
	if((counta == 0)&&(countb == 0)&&(countc == 0)&&(countd == 0)&&(counte == 0))
	{
		printf("no reservation today\n");
		printf("\n===================================\n");
	}
}