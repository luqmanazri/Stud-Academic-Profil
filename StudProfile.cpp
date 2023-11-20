#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//Class student
class Student{
	private:
		string name;
		int matric;
	public: 
		string getName()  { return name; }	
		int getMatric()  { return matric; }
		void setStudent(string n, int m)
		{
			name=n;
			matric=m;	
		}
		
		Student(){ }; //constructor
		~Student(){	};//alternate constructor
		Student(string n,int m);// desructor
				
		
};



class Session:public Student{ //class session
	private:
		string session;
		int sem;
	
	public:
	Session()//constructor
	{
		sem=0;
	}
	
	~Session()//destructor
	{
		sem=0;
	}
	
	Session(string ses,int s);
		void SetSession(string ses,int s)
		{
			session=ses;
			sem=s;
		}
	string getSession() { return session;}	
	int getSem() { return sem; }
	




};

class Academic:public Student{
	private:
		Session ob;//composition
		string code,result;
   		char type;
		double unit,grade;
		double totalGrade;

	public:
		string getCourse(){return code;} 
		char getType(){return type;}
		double getUnit(){return unit;}
		string getResult(){return result;}
		
		void setAcademic( string ses,int s,string c,char t,double u,string r)
		{
			code=c;
			type=t;
			unit=u;
			result=r;
		
			ob.SetSession(ses,s);
		}
		
		Academic()
		{
			unit=grade=totalGrade=0;
		}
		~Academic()
		{
			unit=grade=totalGrade=0;
		}
   		 Academic(string c,char t,double u,string r,double g,double ToGr);

		
		void setGrade(double g){grade=g;}
		void setTotalGr(double ToGr){totalGrade=ToGr;}

		double getGrade(){return grade;}
		double getTotalGr(){return totalGrade;}

		string Printsession(){return ob.getSession();}
		int Displaysem(){return ob.getSem();}

		friend double calcGPA(Academic &);//friend function
		
	

		
	
};
//function to assign GPA to grade
double calcGPA(Academic &cpt){
double g=0;
 	if (cpt.result=="A"||cpt.result=="a") 
	{g=4.00;}
	else if(cpt.result=="A-"||cpt.result=="a-") 
	{ g=3.67;}
	else if(cpt.result=="B+"||cpt.result=="b+")
	{g=3.33;}
	else if(cpt.result=="B"||cpt.result=="b")
	{g=3.00;}
	else if(cpt.result=="B-"||cpt.result=="b-")
	{g=2.67;}
    else if(cpt.result=="C+"||cpt.result=="c+")
	{g=2.33;}
	else if(cpt.result=="C"||cpt.result=="c")
	{g=2.00;}
	else if(cpt.result=="C-"||cpt.result=="c-")
	{g=1.67;}
	else if(cpt.result=="D+"||cpt.result=="d+")
	{g=1.33;}
	else if(cpt.result=="D"||cpt.result=="d")						 
	{g=1.00;}
	else if(cpt.result=="D-"||cpt.result=="d-")
	{g=0.67;}
	 else
		{g=0.00;}

return g;

}


int main()
{
	string name,ses,result,code;
	char type;
    int s,matric,ch,i;
	double g,unit,gp,ToGr,Totalunit,gpa;
	double cgpa=0,CGPAunit=0,tcgp=0;
	double t=80,u=17,m=20,e=15;
	double T=0,U=0,M=0,E=0;
	Academic ob[100];
	//menu
	cout<<"************************************************************"<< endl;
	cout<<"        WELCOME TO STUDENT ACADEMIC RESULT PROFILE" << endl;
	cout<<"************************************************************"<< endl;
	cout<< "MENU: " << endl;
	cout <<"1. Student Profile" << endl;
	cout<< "2. Academic Profile" << endl;
	cout <<"3. Exit" << endl;

	cout << "Enter your choice: " ;
	cin >> ch;
	cout << endl;
	
	switch(ch)
	{
		case 1: 
			system("cls");
			cout<<"Enter Your Name:";
			cin>>name;
			cout<<"Enter Your Matric Number :" ;
			cin>>matric;
			ob[0].setStudent(name,matric);
			system("cls");
			main();
			break;
	
		case 2:
		system("cls");
		for(int y=1;y<5;y++)// loop to input FOR 4 year
		{
		cout<<"-----------------------------------------------------------------------------"<<endl;
		cout<<"Academic Session of year "<< y <<" study: ";
		cin>>ses;
		cout<<"Enter your Semester:";
		cin>>s;
		cout<<"-----------------------------------------------------------------------------"<<endl;
		
			for(s;s<3;s++)// loop to input each sem (maximum 2 s in 1 year)
			{
		        
				int i=0;
				gpa=Totalunit=0;
				bool course=true;
				char c;
		        while(course)//while loop to add many courses
					{
		
					cout<<"Enter Your Course Code: ";
					cin >>code;
					cout<<"Enter Your Course Type: ";
					cin >>type;
					cout<<"Enter Your Course Unit: ";
					cin >>unit;
					cout<<"Enter Your Course Result: ";
					cin >>result;
					cout<<endl;
					 
					 g=calcGPA(ob[i]);
					 ob[i].setGrade(g);
					 ToGr=ob[i].getUnit()*ob[i].getGrade();
					 ob[i].setTotalGr(ToGr);
					 ob[i].setAcademic(ses,s,code,type,unit,result);
					 
		             cout<<"Add more Course ? Please Enter Y or N : ";
		             cin>>c;
		             cout<<endl;
		             
					 if(c=='N'||c=='n')	
					 
		             course=false;
					 else
					 i++;
					}
		
				
				cout<<"--------------------------------------------------------------------------"<<endl;
		        cout<<"|Sem "<<ob[i].Displaysem()<<" in Academic Session of year "<<ob[i].Printsession()<<endl;
				cout<<"--------------------------------------------------------------------------"<<endl;
				
					cout<<"Result : "<<endl;
					cout<<"|-----------|------------|---------|-----------------------|"<< endl;
					cout<<"|Course :   | Type:      | Credit: |         Result:       |"<<endl;
					cout<<"|-----------|------------|---------|-----------------------|"<< endl;
				for(i;i>=0;i--)
				{ 
				 	cout<<"|" <<ob[i].getCourse()<<"     |"<<ob[i].getType()<<"           |"<<ob[i].getUnit()<<"        |"<<ob[i].getResult()<<"                      |"<< endl;
					cout<<"|-----------|------------|---------|-----------------------|"<< endl<<endl;
					cout<<"Your Grade : "<<ob[i].getGrade()<<endl;
					cout<<"Your Total Grade: "<<ob[i].getTotalGr()<<endl;
					
					if(ob[i].getType()=='T'||ob[i].getType()=='t')
					{
					T=T+ob[i].getUnit();
					}
					else if(ob[i].getType()=='U'||ob[i].getType()=='u')
					{
					U=U+ob[i].getUnit();
					}
					else if(ob[i].getType()=='M'||ob[i].getType()=='m')
					{
					M=M+ob[i].getUnit();
					}
					else if(ob[i].getType()=='E'||ob[i].getType()=='e')
					{
					E=E+ob[i].getUnit();
					}
					gpa=gpa+ob[i].getTotalGr();
					Totalunit=Totalunit+ob[i].getUnit();
		
		
				}
				
				tcgp=tcgp+gpa;
				CGPAunit=CGPAunit+Totalunit;
				gpa=gpa/Totalunit;
				//display gpa
				cout<<"your GPA for this semester : "<<gpa;
				cout<<endl;
				cgpa=tcgp/CGPAunit;
				//display Cgpa
				cout<<"Your CGPA for this semester: "<<cgpa<<endl;
				//calculate remaining unit
				m=m-M;
				e=e-E;
				t=t-T;
				u=u-U;
				//display Unit by each Type
				cout<< "Here is Your Comulative Unit by each Type: "<<endl;
				cout<<"comulative unit for T-core : "<<T<<endl;
				cout<<"comulative unit for M-minor : "<<M<<endl;
				cout<<"comulative unit for E-optional : "<<E<<endl;
				cout<<"comulative unit for U-university : "<<U<<endl;
				//display remaining unit by each type
				cout<<"Here is Your Remaining Unit by each Type: "<<endl;
				cout<<"Remaining unit for T-core           : "<<t<<endl;
				cout<<"Remaining unit for M-minor          : "<<m<<endl;			
				cout<<"Remaining unit for E-optional       : "<<e<<endl<<endl<<endl;
				cout<<"Remaining unit for U-university     : "<<u<<endl;			

				
			}
		}
			main();
			break;
			
		case 3: 
			system("cls");
			break;
		
		default:
			system("cls");
		    cout <<"You have made a mistake, Please try again." << endl;
		    main();

	}
	
	return 0;
}



