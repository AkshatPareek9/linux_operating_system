//DEVELOPED BY AKSHAT PAREEK		REG NO: 11811340  		ROLL NO: 31			SECTION: K18GE

//header files

#include<stdio.h>		//define the printf and scanf function

struct process
{
	int pid;			//process id
	char pname;			//process name
	int at;				//arrival time
	int bt;				//burst time
	int cmpt;			//completion time
	int rbt;			//remaining burst time
}f[50],s[50],m[50];

//f denote faculty && s denote student

int n, quanta, fc=0, sc=0, mc=0;

instruction()
{
	int i;
	printf("\n\tWELCOME TO THE WORLD OF OPERATING SYSTEM\n\tProject developed by Akshat Pareek\n\tRegistration number: 11811340\n\tRoll number: 31\n\tSection: K18GE\n\n");
	for(i=0; i<100; i++)
	{
		printf("#");
	}
	printf("\n\tWelcome, please follow the instruction for proper functioning of this system...");
	printf("\n	1. Enter time in 2400 format eg, 10:30 am should be enter as 1030.");
	printf("\n	2. Enter query arrival time in ascending order, i.e in real time arrival manner.");
	printf("\n	3. You can come between 10:00 am to 12:00 pm only.");
	printf("\n	4. All time units are in minutes.");
	printf("\n	5. Please enter the right value of burst time so that CPU cann't be idle.");
	printf("\n	6. Round Robin and Multilevel Queue are used in this program.\n");
	for(i=0;i<100;i++)
	{
		printf("#");
	}
	return 0;
}

void input()
{
	int t,i;
	char ch;
	printf("\n\nEnter total no of queries: ");				//no of queries
	scanf("%d",&n);
	
	if(n==0)
	{
		printf("No queries");
	}
	
	else
	{
		printf("\nEnter Quanta number for each process: ");				//total quantum number
		scanf("%d",&quanta);
		printf("\nEnter f for faculty and s for student: \n");
		for(i=0; i<n; i++)
		{
			printf("\nJob Type(f/s): ");
			scanf("%s",&ch);
			
			if(ch=='f')
			{
				printf("Query ID: ");
				scanf("%d",&f[fc].pid);
				
				printf("Process Name: ");
				scanf("%s",&f[fc].pname);
				
				printf("Arrival Time: ");
				scanf("%d",&t);
				
				if(t<1000 || t>=1200)
				{
					printf("\nCome at another time between 10 am to 12pm");
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
				
				printf("Burst time: ");
				scanf("%d",&f[fc].bt);
				
				f[fc].rbt=f[fc].bt;
				fc++;
			} 
			
			else if(ch=='s')
			{
				printf("Query ID: ");
				scanf("%d",&s[sc].pid);
				
				printf("Process Name: ");
				scanf("%s",&s[sc].pname);
				
				printf("Arrival Time: ");
				scanf("%d",&t);
				
				if(t<1000 || t>=1200)
				{
					printf("\nCome at another time between 10 am to 12pm");
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
				
				printf("Burst time: ");
				scanf("%d",&s[sc].bt);
				
				s[sc].rbt=s[sc].bt;
				sc++;
			}
			else
			{
				printf("It is not a correct job type, please enter again...");
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
		printf("No jobs available...\n");
	}
}

void round_robin()					//whole work is done in this function by calling system call
{
	int time = m[0].at, mark=0, cc=0,i;
	
	while(cc!=mc)
	{
		for(i=0; i<=mark; i++)
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
		
		int start = mark+1,rc;
		
		for(rc = start; rc < mc; rc++)
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
	int total=0,i; 
	double avg,sum=0;
	
	printf("\n\n\t\t\t\t**********SUMMARY FOR THE EXECUTION**********\n");
	printf("\n\tQuery ID\tProcess Name\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
	printf("\t___________________________________________________________________________________________________________________________\n");
	
	for(i=0; i<mc; i++)
	{
		if(m[i].at>59 && m[i].at<120)
		{				
			if(m[i].cmpt>59 && m[i].cmpt<120)
			{
				printf("\n\t  %d\t\t%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d", m[i].pid, m[i].pname, (m[i].at+1040), m[i].bt, (m[i].cmpt+1040), (m[i].cmpt-m[i].at), ((m[i].cmpt-m[i].at)- m[i].bt));
			}
			
			else if(m[i].cmpt>=120)
			{
				printf("\n\t  %d\t\t%c\t\t%d\t\t%d\t\t%d	\t\t%d\t\t\t%d", m[i].pid, m[i].pname, (m[i].at+1040), m[i].bt, (m[i].cmpt+1080), (m[i].cmpt-m[i].at), ((m[i].cmpt-m[i].at)- m[i].bt));
			}
		}
		else if(m[i].at>=0 && m[i].at<60)
		{
			if(m[i].cmpt>=0 && m[i].cmpt<60)
			{
				printf("\n\t  %d\t\t%c\t\t%d\t\t%d\t\t%d	\t\t%d\t\t\t%d", m[i].pid, m[i].pname, (m[i].at+1000), m[i].bt, (m[i].cmpt+1000), (m[i].cmpt-m[i].at), ((m[i].cmpt-m[i].at)- m[i].bt));
			}
			
			else if(m[i].cmpt>59 && m[i].cmpt<120)
			{
				printf("\n\t  %d\t\t%c\t\t%d\t\t%d\t\t%d	\t\t%d\t\t\t%d", m[i].pid, m[i].pname, (m[i].at+1040), m[i].bt, (m[i].cmpt+1040), (m[i].cmpt-m[i].at), ((m[i].cmpt-m[i].at)- m[i].bt));
			}
			
			else if(m[i].cmpt>=120)
			{
				printf("\n\t  %d\t\t%c\t\t%d\t\t%d\t\t%d	\t\t%d\t\t\t%d", m[i].pid, m[i].pname, (m[i].at+1000), m[i].bt, (m[i].cmpt+1080), (m[i].cmpt-m[i].at), ((m[i].cmpt-m[i].at)- m[i].bt));
			}
		}
		if(total<m[i].cmpt)
		{
			total= m[i].cmpt;
		}
		sum+= ((m[i].cmpt-m[i].at)-m[i].bt);
	}
	
	printf("\n\t___________________________________________________________________________________________________________________________\n");
		
	avg = sum/mc;
	printf("\n\nTotal time Spent for all queries: %d",total);
	printf("\nAverage query time: %f",avg);
	printf("\n\n\t\t\t\t**********Process Execution Complete**********");
}


int main()
{
	instruction();
	input();
	ready();
	round_robin();
	printer();
}

