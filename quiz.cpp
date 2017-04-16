/* 
 * File:   main.cpp
 * Author: Nikesh
 *
 * Created on September 17, 2016, 1:33 AM
 */

#include <cstdlib>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<math.h>
#include<sstream>
#include <string>
#include <ctime>
#include <stdio.h>
using namespace std;
fstream file;
string temp1;
int ctr;
int sno;
int lengt;
/*
 * 
 */
class List

{
	public:
		typedef struct node
		{
			int counter;
			string word;
			node* next;
		}* nodeptr;
		nodeptr head;
		nodeptr curr;
		nodeptr temp;
		
	List()
	{
	 	head=NULL;
		curr=NULL;
		temp=NULL;
		
	}	
	string ReadString(ifstream &file)
	{
    char buf[1024];
    file.getline(&(buf[0]), 1024, '\t');
    return string(buf);
	}

	void createlist(string wordd, string counterr)            // ++++++++++++++++++++++++++++++++++++++++
	{	
		sno=0;
		ifstream iFile1(wordd);
		ifstream iFile2(counterr);
    	//while (iFile1.eof()==NULL&&iFile2.eof()==NULL)
    	while(true)
		{
    		sno++;
    		string addword;
    		int ctr;
    		iFile1 >> addword;
    		iFile2 >> ctr;
    		nodeptr n = new node;
			n->word=addword;
			n->next=NULL;
			n->counter=ctr;
			if(iFile1.eof()) break;
    		if(head!=NULL)
			{
				curr = head;
				
				while(curr->next!=NULL)
				{
					curr=curr->next;
				}
				curr->next=n;
			}
			else
			{
				head=n;
			}
                }
	}
        
        
        void createlist2(string wordd)            // ++++++++++++++++++++++++++++++++++++++++
	{	
		sno=0;
		ifstream iFile1(wordd);
    	while(true)
		{
    		sno++;
    		string addword;
    		iFile1 >> addword;
    		nodeptr n = new node;
			n->word=addword;
			n->next=NULL;
			if(iFile1.eof()) break;
    		if(head!=NULL)
			{
				curr = head;
				
				while(curr->next!=NULL)
				{
					curr=curr->next;
				}
				curr->next=n;
			}
			else
			{
				head=n;
			}
                }
	}
        
        
        void dispList()
	{
		curr=head;
		sno=1;
		while(curr!=NULL)
		{
			cout<<sno<<"\t"<<curr->counter<<"\t"<<curr->word<<endl;
			curr=curr->next;
			sno++;
		}
		cout<<"\n";
	}
        
        void dispList2()
	{
		curr=head;
		sno=1;
		while(curr!=NULL)
		{
			cout<<sno<<"\t"<<curr->word<<endl;
			curr=curr->next;
			sno++;
		}
		cout<<"\n";
	}
	
	void leng()
	{
		lengt=0;
		curr=head;
		while(curr->next!=NULL)
		{
			curr=curr->next;
			lengt++;
		}	
	}
        
        
	void update_known(string dest_known)
	{
		nodeptr p = new node;
		p=head;
		string var1=p->word;
		ofstream outputFile;
		outputFile.open(dest_known);
		while(p!=NULL)
		{
			if(p->counter>0)
		    {
			    var1=p->word;
				outputFile << var1<<endl;
				p=p->next;
			}
			else
			{
				p=p->next;
			}
		}
		
		outputFile.close();
	}
	void update_unknown(string dest_unknown)
	{
		nodeptr p = new node;
		p=head;
		string var1=p->word;
		ofstream outputFile;
		outputFile.open(dest_unknown);
		while(p!=NULL)
		{
			if(p->counter<0)
		    {
			    var1=p->word;
				outputFile << var1<<endl;
				p=p->next;
			}
			else
			{
				p=p->next;
			}
		}
		
		outputFile.close();
	}
	void update_unseen(string dest_unseen)
	{
		nodeptr p = new node;
		p=head;
		string var1=p->word;
		ofstream outputFile;
		outputFile.open(dest_unseen);
		while(p!=NULL)
		{
			if(p->counter==0)
		    {
			    var1=p->word;
				outputFile << var1<<endl;
				p=p->next;
			}
			else
			{
				p=p->next;
			}
		}
		
		outputFile.close();
	}
        
        
        void overrite(string wordd, string counterr, string dest_known, string dest_unknown, string dest_unseen)
	{
		nodeptr p = new node;
		p=head;
		string var1=p->word;
		int var2=p->counter;
		ofstream outputFile1;
		ofstream outputFile2;
		
		outputFile1.open(wordd);
		outputFile2.open(counterr);
		
		while(p!=NULL)
	    {
	    var1=p->word;
		var2=p->counter;
		outputFile1 << var1<<endl;
		outputFile2 << var2<<endl;
		
		p=p->next;
		}
		outputFile1.close();
		outputFile2.close();
		update_known(dest_known);
		update_unknown(dest_unknown);
		update_unseen(dest_unseen);
	}
        
        
        void sort(string wordd, string counterr, string dest_known, string dest_unknown, string dest_unseen)
		{
			
			for(curr=head;curr->next!=NULL;curr=curr->next)
			{
				for(temp=curr->next;temp!=NULL;temp=temp->next)
				{
					if(curr->counter>temp->counter)
					{
						temp1 = curr->word;
						ctr=curr->counter;
						curr->word = temp->word;
						curr->counter=temp->counter;
						temp->word = temp1;
						temp->counter=ctr;
					}
				}
			}
		   overrite(wordd,counterr,dest_known,dest_unknown,dest_unseen);
		}
        
        
        
	
	
	
	
	
	
	void reset(string wordd, string counterr, string dest_known, string dest_unknown, string dest_unseen)
	{
		curr=head;
		while(curr!=NULL)
		{
			curr->counter=0;
			curr=curr->next;
		}
		cout<<"All counter successfully reset :-> \n";
		overrite(wordd,counterr,dest_known,dest_unknown,dest_unseen);
	}
        
	

	
	
	void quiz_switch()
	{
            srand ( time(NULL) );
		int ch2;
		cout<<"Enter a choice for Quiz : "<<endl;
		cout<<"1 -> Quiz from All Words "<<endl;
		cout<<"2 -> Quiz from Barrons Words "<<endl;
                cout<<"3 -> Quiz from Princeton Words "<<endl;
		cout<<"4 -> Quiz from Magoosh All Words "<<endl;
		cout<<"5 -> Quiz from Magoosh Common Words "<<endl;
                cout<<"6 -> Quiz from Magoosh Basic Words "<<endl;
                cout<<"7 -> Quiz from Magoosh Advanced Words "<<endl;
                cout<<"8 -> Quiz from Custom Words "<<endl;
		cout<<"9 -> Exit "<<endl;
		cin >> ch2;
		switch(ch2)
		{
			case 1:
                            
                            createlist("words.txt","countr.txt");
                            leng();
			    quiz("words.txt","countr.txt","known.txt","unknown.txt","unseen.txt");
				break;
			case 2:
                            createlist("words_lists/barrons/barronwords.txt","words_lists/barrons/barronwords_counter.txt");
                            leng();
                            quiz("words_lists/barrons/barronwords.txt","words_lists/barrons/barronwords_counter.txt","words_lists/barrons/barrons_known.txt","words_lists/barrons/barrons_unknown.txt","words_lists/barrons/barrons_unseen.txt");
				break;
			case 3:
                            createlist("words_lists/princeton/princetonwords.txt","words_lists/princeton/princetonwords_counter.txt");
                            leng();
                            quiz("words_lists/princeton/princetonwords.txt","words_lists/princeton/princetonwords_counter.txt","words_lists/princeton/princeton_known.txt","words_lists/princeton/princeton_unknown.txt","words_lists/princeton/princeton_unseen.txt");
				break;
			case 4:
                            createlist("words_lists/magoosh/magooshwords.txt","words_lists/magoosh/magooshwords_counter.txt");
                            leng();
                            quiz("words_lists/magoosh/magooshwords.txt","words_lists/magoosh/magooshwords_counter.txt","words_lists/magoosh/magoosh_known.txt","words_lists/magoosh/magoosh_unknown.txt","words_lists/magoosh/magoosh_unseen.txt");
				break;
			case 5:
                            createlist("words_lists/magoosh_common/magooshwords_Common.txt","words_lists/magoosh_common/magooshwords_Common_counter.txt");
                            leng();
                            quiz("words_lists/magoosh_common/magooshwords_Common.txt","words_lists/magoosh_common/magooshwords_Common_counter.txt","words_lists/magoosh_common/m_c_known.txt","words_lists/magoosh_common/m_c_unknown.txt","words_lists/magoosh_common/m_c_unseen.txt");
				break;
                        case 6:
                            createlist("words_lists/magoosh_basic/magooshwords_Basic.txt","words_lists/magoosh_basic/magooshwords_Basic_counter.txt");
                            leng();
                            quiz("words_lists/magoosh_basic/magooshwords_Basic.txt","words_lists/magoosh_basic/magooshwords_Basic_counter.txt","words_lists/magoosh_basic/m_b_known.txt","words_lists/magoosh_basic/m_b_unknown.txt","words_lists/magoosh_basic/m_b_unseen.txt");
				break;
                        case 7:
                            createlist("words_lists/magoosh_advanced/magooshwords_Advanced.txt","words_lists/magoosh_advanced/magooshwords_Advanced_counter.txt");
                            leng();
                            quiz("words_lists/magoosh_advanced/magooshwords_Advanced.txt","words_lists/magoosh_advanced/magooshwords_Advanced_counter.txt","words_lists/magoosh_advanced/m_a_known.txt","words_lists/magoosh_advanced/m_a_unknown.txt","words_lists/magoosh_advanced/m_a_unseen.txt");
				break;
                    case 8:
                          createlist("words_lists/custom/customwords.txt","words_lists/custom/customwords_counter.txt");
                          leng();
                          quiz("words_lists/custom/customwords.txt","words_lists/custom/customwords_counter.txt","words_lists/custom/c_known.txt","words_lists/custom/c_unknown.txt","words_lists/custom/c_unseen.txt");
				break;  
                        case 9:
                            return;
				break;       
                        
		}	
		
	}
       
        void clear_linked_list()
        {
            head=NULL;
            curr=NULL;
        }
        void dispList_switch()
        {
            float ch3;
		cout<<"Enter a choice for Displaying List : "<<endl;
		cout<<"1 -> List of All Words "<<endl;
                cout<<"\t1.1 -> List of known words"<<endl;
                cout<<"\t1.2 -> List of unknown words"<<endl;
                cout<<"\t1.3 -> List of unseen words"<<endl;
		cout<<"2 -> List of Barrons Words "<<endl;
                cout<<"\t2.1 -> List of known words"<<endl;
                cout<<"\t2.2 -> List of unknown words"<<endl;
                cout<<"\t2.3 -> List of unseen words"<<endl;
                cout<<"3 -> List of Princeton Words "<<endl;
                cout<<"\t3.1 -> List of known words"<<endl;
                cout<<"\t3.2 -> List of unknown words"<<endl;
                cout<<"\t3.3 -> List of unseen words"<<endl;
		cout<<"4 -> List of Magoosh All Words "<<endl;
                cout<<"\t4.1 -> List of known words"<<endl;
                cout<<"\t4.2 -> List of unknown words"<<endl;
                cout<<"\t4.3 -> List of unseen words"<<endl;
		cout<<"5 -> List of Magoosh Common Words "<<endl;
                cout<<"\t5.1 -> List of known words"<<endl;
                cout<<"\t5.2 -> List of unknown words"<<endl;
                cout<<"\t5.3 -> List of unseen words"<<endl;
                cout<<"6 -> List of Magoosh Basic Words "<<endl;
                cout<<"\t6.1 -> List of known words"<<endl;
                cout<<"\t6.2 -> List of unknown words"<<endl;
                cout<<"\t6.3 -> List of unseen words"<<endl;
                cout<<"7 -> List of Magoosh Advanced Words "<<endl;
                cout<<"\t7.1 -> List of known words"<<endl;
                cout<<"\t7.2 -> List of unknown words"<<endl;
                cout<<"\t7.3 -> List of unseen words"<<endl;
		cout<<"8 -> List of Custom Words "<<endl;
                cout<<"\t8.1 -> List of known words"<<endl;
                cout<<"\t8.2 -> List of unknown words"<<endl;
                cout<<"\t8.3 -> List of unseen words"<<endl;
                cout<<"9 -> Exit "<<endl<<endl;
		cin >> ch3;
                        if(ch3==1)
                        {
                            createlist("words.txt","countr.txt");
                            dispList();
                            clear_linked_list();
                        }
                                else if(ch3==1.1f)
                                {
                                createlist2("known.txt");
                                dispList2();
                                clear_linked_list();   
                                }
                                else if(ch3==1.2f)
                                {
                                createlist2("unknown.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==1.3f)
                                {
                                createlist2("unseen.txt");
                                dispList2();
                                clear_linked_list();
                                }
                else if(ch3==2)
                        {
                            createlist("words_lists/barrons/barronwords.txt","words_lists/barrons/barronwords_counter.txt");
                            dispList();
                            clear_linked_list();
                        }
                                else if(ch3==2.1f)
                                {
                                createlist2("words_lists/barrons/barrons_known.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==2.2f)
                                {
                                createlist2("words_lists/barrons/barrons_unknown.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==2.3f)
                                {
                                createlist2("words_lists/barrons/barrons_unseen.txt");
                                dispList2();
                                clear_linked_list();
                                }
                else if(ch3==3)
                        {
                            createlist("words_lists/princeton/princetonwords.txt","words_lists/princeton/princetonwords_counter.txt");
                            dispList();
                            clear_linked_list();
                        }
                                else if(ch3==3.1f)
                                {
                                createlist2("words_lists/princeton/princeton_known.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==3.2f)
                                {
                                createlist2("words_lists/princeton/princeton_unknown.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==3.3f)
                                {
                                createlist2("words_lists/princeton/princeton_unseen.txt");
                                dispList2();
                                clear_linked_list();
                                }
                else if(ch3==4)
                        {
                            createlist("words_lists/magoosh/magooshwords.txt","words_lists/magoosh/magooshwords_counter.txt");
                            dispList();
                            clear_linked_list();
                        }
                                else if(ch3==4.1f)
                                {
                                createlist2("words_lists/magoosh/magoosh_known.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==4.2f)
                                {
                                createlist2("words_lists/magoosh/magoosh_unknown.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==4.3f)
                                {
                                createlist2("words_lists/magoosh/magoosh_unseen.txt");
                                dispList2();
                                clear_linked_list();
                                }
                else if(ch3==5)
                        {
                            createlist("words_lists/magoosh_common/magooshwords_Common.txt","words_lists/magoosh_common/magooshwords_Common_counter.txt");
                            dispList();
                            clear_linked_list();
                        }
                                else if(ch3==5.1f)
                                {
                                createlist2("words_lists/magoosh_common/m_c_known.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==5.2f)
                                {
                                createlist2("words_lists/magoosh_common/m_c_unknown.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==5.3f)
                                {
                                createlist2("words_lists/magoosh_common/m_c_unseen.txt");
                                dispList2();
                                clear_linked_list();
                                }
                else if(ch3==6)
                        {
                            createlist("words_lists/magoosh_basic/magooshwords_Basic.txt","words_lists/magoosh_basic/magooshwords_Basic_counter.txt");
                            dispList(); 
                            clear_linked_list();
                        }
                                else if(ch3==6.1f)
                                {
                                createlist2("words_lists/magoosh_basic/m_b_known.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==6.2f)
                                {
                                createlist2("words_lists/magoosh_basic/m_b_unknown.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==6.3f)
                                {
                                createlist2("words_lists/magoosh_basic/m_b_unseen.txt");
                                dispList2();
                                clear_linked_list();
                                }
                else if(ch3==7)
                        {
                            createlist("words_lists/magoosh_advanced/magooshwords_Advanced.txt","words_lists/magoosh_advanced/magooshwords_Advanced_counter.txt");
                            dispList();
                            clear_linked_list();
                        }
                                else if(ch3==7.1f)
                                {
                                createlist2("words_lists/magoosh_advanced/m_a_known.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==7.2f)
                                {
                                createlist2("words_lists/magoosh_advanced/m_a_unknown.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==7.3f)
                                {
                                createlist2("words_lists/magoosh_advanced/m_a_unseen.txt");
                                dispList2();
                                clear_linked_list();
                                }
                else if(ch3==8)
                        {
                            createlist("words_lists/custom/customwords.txt","words_lists/custom/customwords_counter.txt");
                            dispList();
                            clear_linked_list();
                        }
                                else if(ch3==7.1f)
                                {
                                createlist2("words_lists/custom/c_known.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==7.2f)
                                {
                                createlist2("words_lists/custom/c_unknown.txt");
                                dispList2();
                                clear_linked_list();
                                }
                                else if(ch3==7.3f)
                                {
                                createlist2("words_lists/custom/c_unseen.txt");
                                dispList2();
                                clear_linked_list();
                                }
                else if(ch3==9)
                        {
                    return;
                        }
           
        }
        
        
        void reset_switch()
        {
            int ch3;
		cout<<"Enter a choice for resetting the  List : "<<endl;
		cout<<"1 -> Reset List of All Words "<<endl;
		cout<<"2 -> Reset List of Barrons Words "<<endl;
                cout<<"3 -> Reset List of Princeton Words "<<endl;
		cout<<"4 -> Reset List of Magoosh All Words "<<endl;
		cout<<"5 -> Reset List of Magoosh Common Words "<<endl;
                cout<<"6 -> Reset List of Magoosh Basic Words "<<endl;
                cout<<"7 -> Reset List of Magoosh Advanced Words "<<endl;
                cout<<"8 -> Reset List of Custom Words "<<endl;
		cout<<"9 -> Exit "<<endl;
		cin >> ch3;
		switch(ch3)
		{
                    case 1:
                            createlist("words.txt","countr.txt");
                            reset("words.txt","countr.txt","known.txt","unknown.txt","unseen.txt");
                            clear_linked_list();
                            break;
                    case 2:
                            createlist("words_lists/barrons/barronwords.txt","words_lists/barrons/barronwords_counter.txt");
                            reset("words_lists/barrons/barronwords.txt","words_lists/barrons/barronwords_counter.txt","words_lists/barrons/barrons_known.txt","words_lists/barrons/barrons_unknown.txt","words_lists/barrons/barrons_unseen.txt");
                            clear_linked_list();    
                            break;
                    case 3:
                            createlist("words_lists/princeton/princetonwords.txt","words_lists/princeton/princetonwords_counter.txt");
                            reset("words_lists/princeton/princetonwords.txt","words_lists/princeton/princetonwords_counter.txt","words_lists/princeton/princeton_known.txt","words_lists/princeton/princeton_unknown.txt","words_lists/princeton/princeton_unseen.txt");
                            clear_linked_list();	
                            break;
                    case 4:
                            createlist("words_lists/magoosh/magooshwords.txt","words_lists/magoosh/magooshwords_counter.txt");
                            reset("words_lists/magoosh/magooshwords.txt","words_lists/magoosh/magooshwords_counter.txt","words_lists/magoosh/magoosh_known.txt","words_lists/magoosh/magoosh_unknown.txt","words_lists/magoosh/magoosh_unseen.txt");
                            clear_linked_list();
                            break;
                    case 5:
                            createlist("words_lists/magoosh_common/magooshwords_Common.txt","words_lists/magoosh_common/magooshwords_Common_counter.txt");
                            reset("words_lists/magoosh_common/magooshwords_Common.txt","words_lists/magoosh_common/magooshwords_Common_counter.txt","words_lists/magoosh_common/m_c_known.txt","words_lists/magoosh_common/m_c_unknown.txt","words_lists/magoosh_common/m_c_unseen.txt");
                            clear_linked_list();
                            break;
                    case 6:
                            createlist("words_lists/magoosh_basic/magooshwords_Basic.txt","words_lists/magoosh_basic/magooshwords_Basic_counter.txt");
                            reset("words_lists/magoosh_basic/magooshwords_Basic.txt","words_lists/magoosh_basic/magooshwords_Basic_counter.txt","words_lists/magoosh_basic/m_b_known.txt","words_lists/magoosh_basic/m_b_unknown.txt","words_lists/magoosh_basic/m_b_unseen.txt");
				break;
                    case 7:
                            createlist("words_lists/magoosh_advanced/magooshwords_Advanced.txt","words_lists/magoosh_advanced/magooshwords_Advanced_counter.txt");
                            reset("words_lists/magoosh_advanced/magooshwords_Advanced.txt","words_lists/magoosh_advanced/magooshwords_Advanced_counter.txt","words_lists/magoosh_advanced/m_a_known.txt","words_lists/magoosh_advanced/m_a_unknown.txt","words_lists/magoosh_advanced/m_a_unseen.txt");
                            clear_linked_list();
                            break;
                    case 8:
                           createlist("words_lists/custom/customwords.txt","words_lists/custom/customwords_counter.txt");
                            reset("words_lists/custom/customwords.txt","words_lists/custom/customwords_counter.txt","words_lists/custom/c_known.txt","words_lists/custom/c_unknown.txt","words_lists/custom/c_unseen.txt");
                            clear_linked_list();
                            break;        
                    case 9:
                        return;
				break;       
                }
        }
	void quiz(string wordd, string counterr, string dest_known, string dest_unknown, string dest_unseen)
	{
		int num = rand() % lengt;
		curr=head;
		char ch;
			for(int i=0;i<num;i++)
			{
				curr=curr->next;
			}
			if(curr->counter<=0)
				{
					cout<<curr->word;
					cout<<"\t";
					cin>>ch;
					if(ch=='y'||ch=='Y')
					{
						curr->counter = curr->counter+1;
                                                
					}
					else if(ch=='n'||ch=='N')
					{
						curr->counter = curr->counter-1;
                                                if(curr->counter<=-5)
                                                {
                                                    curr->counter=-5;
                                                }
					}
					else if(ch=='x'||ch=='X')
					{
                                            return;
					}
					sort(wordd,counterr,dest_known,dest_unknown,dest_unseen);
					num=rand()%lengt;
					quiz(wordd,counterr,dest_known,dest_unknown,dest_unseen);
                                        
                                }
				else
				{
					num=rand()%lengt;
					quiz(wordd,counterr,dest_known,dest_unknown,dest_unseen);
				}	
			
	}
		
};

	int main(int argc, char** argv)
	{
            List obj;
            int ch;
	while(1)
	{
		cout <<"\n1.Quiz  2.Display 3.Reset all counters 4.Exit\n\nEnter ur choice : ";
                cin >> ch;
		switch(ch)
		{
			case 1:
				obj.quiz_switch();
                                obj.clear_linked_list();
				break;
			case 2:
				obj.dispList_switch();
				break;
			case 3:
				obj.reset_switch();
				break;
			case 4:
				exit(1);
				break;
		}
	}
            
	return 0;
		
	}
