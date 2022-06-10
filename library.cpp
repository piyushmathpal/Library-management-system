#include<bits/stdc++.h>
using namespace std;
class book;
//char ch;
string press="Press enter to continue";
class student;
	fstream file1,file2,file3;
	
class book
{
	public:
		char bookid[10];
		char bookname[15];
		void dispbook();
		void dispavailablebook();
		void setbook();
		void showbooks();
		void createbook();
		
};
class student : public book
{
	char stuid[10];
	char stuname[15];
	public:
		void issuebook();
		void returnbook();
		void display_alls();
		void specificstudent();
		
		void show();
};
book ob;
student st;
void book::setbook(void)
{
	cout<<"Enter book ID: ";
	cin.getline(bookid,10);
	cout<<"Enter book Name: ";
	cin.getline(bookname,30);
	cout<<endl;
	
}
void book :: createbook()
{
	char ch;
	file1.open( "allbook.txt",ios::app);
	file2.open( "availablebook.txt",ios::app);
	do{
		cout<<endl;
		ob.setbook();
		
 		if (!file1.is_open()) {
        cout << "failed to open \n";
    	} else {
    	file1.write( (char*)&ob, sizeof(ob) );
    	file2.write((char*)&ob,sizeof(ob));
      	cout << "Book added successfully" << endl;
   		 }
   		 cout<<"Do you want to enter more Entries (y/n): ";
   		 cin>>ch;
   		 cin.ignore();
	}while(ch=='y'||ch=='Y');
	
	file1.close();
	file2.close();
	cout<<press;
	getchar();
	
	
}

void book::showbooks(void)
{
	cout<<"Book ID: "<<bookid<<endl;
	cout<<"Book Name: "<<bookname<<endl;

}
void book ::dispbook()
{
	system("CLS");
	
	file1.open( "allbook.txt", ios::in );

	if (!file1.is_open()) {
        cout << "failed to open "  << '\n';
    } 
	else {
		cout<<"\t\t All Books \t\t \n\n" ;
		while(file1.read( (char*)&ob, sizeof(ob) ))
		{
			ob.showbooks();
			cout<<endl<<endl;
		}
    }
    cout<<press;
    getchar();
    file1.close();
	
}
void book ::dispavailablebook()
{
	system("CLS");
	
	file1.open( "availablebook.txt", ios::in );

	if (!file1.is_open()) {
        cout << "failed to open " <<  '\n';
    } 
	else {
		cout<<"\t\t All Available Books \t\t \n\n" ;
		while(file1.read( (char*)&ob, sizeof(ob) ))
		{
			ob.showbooks();
			cout<<endl<<endl;
		}
    }
    file1.close();
    cout<<press;
    getchar();
	
}
	void student:: issuebook()
	{
		int flag =0;
	cout<<"Enter student ID: ";
	cin.getline(stuid,10);
	cout<<"Enter student Name: ";
	cin.getline(stuname,15);
	cout<<"Enter book ID: ";
	cin.getline(bookid,10);
	cout<<"Enter book Name: ";
	cin.getline(bookname,15);
	file2.open("temp.txt",ios::out);
	file1.open( "availablebook.txt", ios::in );
	
	if (!file1.is_open()) {
        cout << "failed to open " << '\n';
    } 
	else {
		while(file1.read( (char*)&ob, sizeof(ob )))
		{
			if(!(strcmp(ob.bookid,st.bookid)==0 ))
			{
				file2.write( (char*)&ob, sizeof(ob) );
			}
			else 
			{
			
			flag=1;
				
			}
		}
	}
	file1.close();
file2.close();
	
		remove("availablebook.txt");
		rename("temp.txt","availablebook.txt");
		if(flag==0)
		{
			cout<<"book not available"<<endl;
			getchar();
			cout<<press;
			return;
		}
    
	
 	file1.open( "issued.txt",ios::app);
 	if (!file1.is_open()) {
        cout << "failed to open " << '\n';
    } else {
    	file1.write( (char*)&st, sizeof(st) );
      	cout << "Isssued successfully" << endl;
    }
    file1.close();
	cout<<press;
    getchar();
		
	}
//	
void student::specificstudent()
{
	system("CLS");
	char check[10];
	cout<<"\t Enter student ID: ";
	cin.getline(check,10);
	cout<<endl<<endl;
	file1.open( "issued.txt", ios::in );

	if (!file1.is_open()) {
        cout << "failed to open " << '\n';
    } 
	else {
		while(file1.read( (char*)&st, sizeof(st) ))
		{
			if(strcmp(check,stuid)==0)
		{
				st.show();
			cout<<endl<<endl;
		}}
    }
//    getchar();
file1.close();
cout<<press;
	getchar();
	
}
//
	void student :: returnbook()
	{
		int flag=0;
	char dolo[10],doloo[10];
	cout<<"Enter student ID: ";
	cin.getline(doloo,10);
	cout<<"Enter book ID: ";
	
	cin.getline(dolo,10);
	file1.open( "issued.txt", ios::in );
	file2.open("temp.txt",ios::out);
	file3.open( "availablebook.txt", ios::app );
	
	if (!file1.is_open()) {
        cout << "failed to open " << '\n';
    } 
	else {
		while(file1.read( (char*)&st, sizeof(st) ))
		{
			if(!(strcmp(dolo,st.bookid)==0 &&strcmp(doloo,st.stuid)==0))
			{
				file2.write( (char*)&st, sizeof(st) );
			}
			else 
			{
				strcpy(ob.bookid,st.bookid);
				strcpy(ob.bookname,st.bookname);
				file3.write((char*)&ob,sizeof(ob));
				ob.showbooks();
				flag=1;
				
			}
		}
	}
file1.close();
file2.close();
file3.close();
		remove("issued.txt");
		rename("temp.txt","issued.txt");
		if(flag==0)
		{
			cout<<"Entry Not found"<<endl;
		}
    cout<<press;

	getchar();
	}
	
	void student :: show()
	{
	cout<<"Student ID: "<<stuid<<endl;
	cout<<"Student Name: "<<stuname<<endl;
	cout<<"Book ID: "<<bookid<<endl;
	cout<<"Book Name: "<<bookname<<endl;
		
	}
	void student::display_alls()
	{
//		system("CLS");
		file1.open( "issued.txt", ios::in );

	if (!file1.is_open()) {
        cout << "failed to open \n";
    } 
	else {
		while(file1.read( (char*)&st, sizeof(st) ))
		{
			st.show();
			cout<<endl<<endl;
		}
    }
//    getchar();
file1.close();
	getchar();
	}

void admin()
{
	system("CLS");
	int ch2;
	cout<<"\n\n\n\tADMINISTRATOR MENU";
	cout<<"\n\n\t1.DISPLAY ALL STUDENTS RECORD";
	cout<<"\n\n\t2.DISPLAY SPECIFIC STUDENT RECORD ";
	cout<<"\n\n\t3.CREATE BOOK ";
	cout<<"\n\n\t4.DISPLAY ALL BOOKS ";
	cout<<"\n\n\t5.DISPLAY AVAILABLE BOOK ";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch2;
	cin.ignore();
	switch(ch2)
	{
    		case 1: system("CLS");
			st.display_alls();
			break;
    		case 2:
	       		st.specificstudent();
	       		break;
			case 3: system("CLS");
			ob.createbook();
			break;
			case 4: 
		ob.dispbook();
		break;
		case 5:
			system("CLS");
			ob.dispavailablebook();
      		case 9:			   
			  break;
      		case 10: 

			  break;
     		case 11:
			 break;
      		default:cout<<"ENTER VALID";
   	}
   	
}
int main()
{

	char ch;
	do
	{
		system("CLS");
		cout<<"\n\n\t\t BIRLA INSTITUE OF APPLIED SCIENCES";
		cout<<"\n\n\tMAIN MENU";
		cout<<"\n\n\t01. BOOK ISSUE";
		cout<<"\n\n\t02. BOOK DEPOSIT";
	  	cout<<"\n\n\t03. ADMINISTRATOR MENU";
	  	cout<<"\n\n\t04. EXIT";
	  	cout<<"\n\n\tPlease Select Your Option (1-4) ";
	  	cin>>ch;
	  	cin.ignore();
	  	switch(ch)
	  	{
			case '1':system("CLS");
					st.issuebook();
				break;
		  	case '2':system("CLS");
		  			st.returnbook();
//			  book_deposit();
			    	 break;
		  	case '3':admin();
		
//			  admin_menu();
				 break;
		  	case '4':exit(0);
		  	default :cout<<"Enter Valid choice";
		  			cout<<"1";
		  	
		}
    	}while(ch!='4');
    	return 0;
}


