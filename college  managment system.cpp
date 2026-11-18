#include<iostream>
#include<string>
using namespace std;
struct student{
	int rollno;
	string name;
	char department;
	char course;
	int fees;
};
student s[100];
int total=0;
void addstudent(){
	if(total>=100){
		cout<<"student limit reached";
		return;	
	}
	cout<<"\nEnter your name:";
	cin.ignore();
	getline(cin,s[total].name);
	cout<<"\nEnter your roll number:";
	cin>>s[total].rollno;
	cout<<"\nEnter your department:";
	cin>>s[total].department;
	cout<<"\nEnter your course:";
	cin>>s[total].course;
	cout<<"\nEnter your fees:";
	cin>>s[total].fees;
	total++;
	cout<<"student added successfully.";
}
void searchstudent(){
	int rollno;
	int found=0;
	cout<<"Enter roll number to search:";
	cin>>rollno;
	for(int i=0;i<total; i++){
		if(s[i].rollno=rollno){
			found=1;
		}
		cout<<"\nstudent found:";
		cout<<"\n roll no:"<<s[i].rollno;
		cout<<"\n name:"<<s[i].name;
		cout<<"\n department:"<<s[i].department;
		cout<<"\n course:"<<s[i].course;
		cout<<"\n fees:"<<s[i].fees;
		break;
	}
	if(found==0){
		cout<<"\n student not found.";
	}
}
void deletestudent(){
	int roll, i, found =0;
	cout<<"\nEnter student's roll no to delete:";
	cin>>roll;
	for(i=0; i<total; i++){
		if(s[i].rollno==roll){
			found=1;
			for(int j=0; j<total; j++){
				s[j]=s[j+1];
			}
			total--;
			cout<<"\nStudent delete successfully.";
			break;
		}
	}
	if(found==0){
		cout<<"\nStudent not found.";
	}
}
void display(){
	if(total==0){
		cout<<"\n No student records available";
		return;
	}
	cout<<"\n.........All STUDENT RECORDS........";
	 for(int i = 0; i < total; i++)
    {
        cout << "\n\nRoll Number: " << s[i].rollno;
        cout << "\nName: " << s[i].name;
        cout << "\nCourse: " << s[i].course;
        cout << "\nFees: " << s[i].fees;
    }
}
int main(){
	int choice;
	do{
		cout<<"\n\n======================";
		cout<<"\n college management system";
		cout<<"\n =====================";
		cout<<"\n press 1 Add student:";
		cout<<"\n press 2 delete student:";
		cout<<"\n press 3 search student:";
		cout<<"\n press 4 display student:";
		cout<<"\n exit";
		cout<<"\n\n Enter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				addstudent(); break;
			case 2:
				searchstudent(); break;
			case 3:
				deletestudent(); break;
			case 4:
				display(); break;
			case 5:
				exit(0); break;
			default:
				cout<<"\n Invalid choice!";
		}
	}while(choice !=5);
	return 0;
}
