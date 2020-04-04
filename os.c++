//DEVELOPED BY AKSHAT PAREEK		REG NO: 11811340  		ROLL NO: 31			SECTION: K18GE

//header files

#include<iostream>				//input output stream
#include<conio.h>				//console input output
#include<stdlib.h>				//standard library		
#include<string>

using namespace std;

struct process
{
	int pid;			//process id
	string pname;		//process name
	int at;				//arrival time
	int bt;				//burst time
	int cmpt;			//completion time
	int rbt;			//remaining burst time
}f[50],s[50],m[50];

//f denote faculty && s denote student

int n, quanta, fc=0, sc=0, mc=0;

instruction()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME";
	getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO";
	getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO THE";
	getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO THE WORLD";
	getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO THE WORLD OF";
	getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO THE WORLD OF OPERATING";
	getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO THE WORLD OF OPERATING SYSTEM";
	getch();
	system("cls");

	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO THE WORLD OF OPERATING SYSTEM\n\n\n\n"
		<<"	\t\t\t\t\tProject developed by Akshat Pareek\n"
		<<"	\t\t\t\t\tRegistration number: 11811340\n"
		<<"	\t\t\t\t\tRoll number: 31\n"
		<<"	\t\t\t\t\tSection: K18GE";
			
	getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\n  ";
	for(int i=0; i<140; i++)
	{
		cout<<"#";
	}
	
	cout<<"\n\n\n\t\t\t\tWelcome, please follow the instruction for proper functioning of this system..."
		  "\n\n\n"
		  "\t\t\t	1. Enter time in 2400 format eg, 10:30 am should be enter as 1030."
		  "\n"
		  "\t\t\t	2. Enter query arrival time in ascending order, i.e in real time arrival manner."
		  "\n"
		  "\t\t\t	3. You can come between 10:00 am to 12:00 pm only."
		  "\n"
		  "\t\t\t	4. All time units are in minutes."
		  "\n"
		  "\t\t\t	5. Please enter the right value of burst time so that CPU cann't be idle."
		  "\n"
		  "\t\t\t	6. Round Robin and Multilevel Queue are used in this program.			\n\n\n";
	
	cout<<"  ";
	for(int i=0;i<140;i++)
	{
		cout<<"#";
	}
	
	getch();
	system("cls");
	return 0;
}

void input()
{
	int t;
	char ch;
	
	cout<<"\n\nEnter total no of queries: ";				//no of queries
	cin>>n;
	
	if(n==0)
	{
		cout<<"No queries";
	}
	
	else
	{
		cout<<"\nEnter Quanta number for each process: ";				//total quantum number
		cin>>quanta;
		cout<<"\nEnter f for faculty and s for student: \n";
		
		for(int i=0; i<n; i++)
		{
			cout<<"\nJob Type(f/s): ";
			cin>>ch;
			
			if(ch=='f')
			{
				cout<<"Query ID: ";
				cin>>f[fc].pid;
				
				cout<<"Process Name: ";
				cin>>f[fc].pname;
				
				cout<<"Arrival Time: ";
				cin>>t;
				
				if(t<1000 || t>=1200)
				{
					cout<<"\nCome at another time between 10 am to 12pm";
					i=i-1;
					continue;
				}
				else
				{
					if(t>1059 && t<1200)
					{
						f[fc].at= t-1040;
					}
					
					else if(t>=1000 && t<1100)
					{
						f[fc].at= t-1000;
					}
				}
				
				cout<<"Burst time: ";
				cin>>f[fc].bt;
				
				f[fc].rbt=f[fc].bt;
				fc++;
			} 
			
			else if(ch=='s')
			{
				cout<<"Query ID: ";
				cin>>s[sc].pid;
				
				cout<<"Process Name: ";
				cin>>s[sc].pname;
				
				cout<<"Arrival Time: ";
				cin>>t;
				
				if(t<1000 || t>=1200)
				{
					cout<<"\nCome at another time between 10 am to 12pm";
					i=i-1;
					continue;
				}
				else
				{
					if(t>1059 && t<1200)
					{
						s[sc].at= t-1040;
					}
					
					else if(t>=1000 && t<1100)
					{
						s[sc].at= t-1000;
					}
				}
				
				cout<<"Burst time: ";
				cin>>s[sc].bt;
				
				s[sc].rbt=s[sc].bt;
				sc++;
			}
			else
			{
				cout<<"It is not a correct job type, please enter again...";
				i--;
				continue;
			}
		}
	}
}

void ready()				//this function is used to make process ready for system call
{
	int isc=0, ifc= 0;
	
	if(fc!=0  && sc!=0)
	{
		while(isc<sc && ifc<fc)
		{
			if(f[ifc].at == s[isc].at)
			{
				m[mc] = f[ifc];
				mc++;			
				ifc++;
				
				m[mc] = s[isc];
				mc++;
				isc++;
			}
			
			else if(f[ifc].at < s[isc].at)
			{
				m[mc]= f[ifc];
				mc++;
				ifc++;
			}
			
			else if(f[ifc].at > s[isc].at)
			{
				m[mc]= s[isc];
				mc++;
				isc++;
			}
		}
		if(mc != (fc+sc))
		{
			while(ifc!=fc)
			{
				m[mc] = f[ifc];
				mc++;
				ifc++;
			}
			
			while(isc!=sc)
			{
				m[mc] = s[isc];
				mc++;
				isc++;
			}
		}
	}
	
	else if(fc==0)
	{
		while(isc!=sc)
		{
			m[mc] = s[isc];
			mc++;
			isc++;
		}
	}
	
	else if(sc==0)
	{
		while(ifc!=fc)
		{
			m[mc] = f[ifc];
			mc++;
			ifc++;
		}
	}
	
	else 
	{
		cout<<"No jobs available...\n";
	}
}

void round_robin()					//whole work is done in this function by calling system call
{
	int time = m[0].at, mark=0, cc=0;
	
	while(cc!=mc)
	{
		for(int i=0; i<=mark; i++)
		{
			if(m[i].rbt > quanta)
			{
				time += quanta;
				m[i].rbt -= quanta;
			}
			else if(m[i].rbt <= quanta && m[i].rbt !=0)
			{
				time += m[i].rbt;
				m[i].rbt =0;
				m[i].cmpt = time;
				cc++;
			}
			else
			{	
				continue;
			}
		}
		
		int start = mark+1;
		
		for(int rc = start; rc < mc; rc++)
		{
			if(m[rc].at <= time)
			{
				mark++;
			}
		}
	}	
}

void printer()					//it summarize all work to the user as output
{
	int total=0; 
	double avg,sum=0;
	
	cout<<"\n\n\t\t\t\t\t\t**********SUMMARY FOR THE EXECUTION**********\n";
	cout<<"\n\t\tQuery ID\tProcess Name\tArrival Time\tBurst Time\tCompletion Time	\tTurn Around Time\tWaiting Time\n";
	cout<<"\t\t___________________________________________________________________________________________________________________________\n";
	
	for(int i=0; i<mc; i++)
	{
		if(m[i].at>59 && m[i].at<120)
		{				
			if(m[i].cmpt>59 && m[i].cmpt<120)
			{
				cout<<"\n\t\t  " << m[i].pid << "\t\t" << m[i].pname << "\t\t" << (m[i].at+1040) << "\t\t" << m[i].bt << "\t\t" << (m[i].cmpt+1040) << "	\t\t" << (m[i].cmpt-m[i].at) << "\t\t\t" << ((m[i].cmpt-m[i].at)- m[i].bt);
			}
			
			else if(m[i].cmpt>=120)
			{
				cout<<"\n\t\t  " << m[i].pid << "\t\t" << m[i].pname << "\t\t" << (m[i].at+1040) << "\t\t" << m[i].bt << "\t\t" << (m[i].cmpt+1080) << "	\t\t" << (m[i].cmpt-m[i].at) << "\t\t\t" << ((m[i].cmpt-m[i].at)- m[i].bt);
			}
		}
		else if(m[i].at>=0 && m[i].at<60)
		{
			if(m[i].cmpt>=0 && m[i].cmpt<60)
			{
				cout<<"\n\t\t  " << m[i].pid << "\t\t" << m[i].pname << "\t\t" << (m[i].at+1000) << "\t\t" << m[i].bt << "\t\t" << (m[i].cmpt+1000) << "	\t\t" << (m[i].cmpt-m[i].at) << "\t\t\t" << ((m[i].cmpt-m[i].at)- m[i].bt);
			}
			
			else if(m[i].cmpt>59 && m[i].cmpt<120)
			{
				cout<<"\n\t\t  " << m[i].pid << "\t\t" << m[i].pname << "\t\t" << (m[i].at+1000) << "\t\t" << m[i].bt << "\t\t" << (m[i].cmpt+1040) << "	\t\t" << (m[i].cmpt-m[i].at) << "\t\t\t" << ((m[i].cmpt-m[i].at)- m[i].bt);
			}
			
			else if(m[i].cmpt>=120)
			{
				cout<<"\n\t\t  " << m[i].pid << "\t\t" << m[i].pname << "\t\t" << (m[i].at+1000) << "\t\t" << m[i].bt << "\t\t" << (m[i].cmpt+1080) << "	\t\t" << (m[i].cmpt-m[i].at) << "\t\t\t" << ((m[i].cmpt-m[i].at)- m[i].bt);
			}
		}
		if(total<m[i].cmpt)
		{
			total= m[i].cmpt;
		}
		sum+= ((m[i].cmpt-m[i].at)-m[i].bt);
	}
	
	cout<<"\n\t\t___________________________________________________________________________________________________________________________\n";
		
	avg = sum/mc;
	cout<<"\n\nTotal time Spent for all queries: "<<total;
	cout<<"\nAverage query time: "<<avg;
	cout<<"\n\n\t\t\t\t**********Process Execution Complete**********";
}


int main()
{
	instruction();
	input();
	ready();
	round_robin();
		system("cls");
	printer();
}


