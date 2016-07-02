#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;


double func(double a)      // FUNCTION TO BE MINIMIZED
{
	if(a<=1)
	return a*a;
	 
	   else return  ( (a-3) * (a-3) - 3 );
	   
}


int main()
{

int m=5;                                       //NUMBER OF ANTS
double x[m], f[m],ph[m],psi[m],d[m];
double xmin=20000;
double fmin= 20000;
int t = 400;                                  // NUMBER OF ITERATIONS

double alpha=0.5;                            // INITIAL STEP SIZE
double dx, xtemp, tempflag;


//INITIALIZATION

cout<<" x_ini_ANT\t"<<" f(x)_ini_ANT\t"<<endl;

for(int i=0;i<m;i++)                // FOR EACH ANT
{
	x[i]= rand()%21 - 10;           // GIVE X FROM -10 TO +10
	f[i]= func(x[i]) ;              // CALCULATE F(x)
	if (f[i]<fmin)
	
	{ fmin = f[i];
	  xmin = x[i];
		}
	    
	  	
		cout<<x[i]<<"\t\t"<<f[i]<<endl<<endl<<endl; 	
}


double psisum=0;                          
for(int j=0;j<m;j++)                   // FOR EACH ANT
{
	d[j]= f[j] - fmin;                 // DISTANCE FROM FMIN
	
	psi[j] = pow( 2.7, -100*d[j]*d[j] ) ;   // GAUSSIAN FUNCTION 
	
	psisum+= psi[j];
}

cout<<"ini_Ph\t";
for(int b=0;b<m;b++)
{
		cout<<"ant"<<b+1<<"\t";
}
cout<<endl;


for(int k=0;k<m;k++)          // FOR EACH ANT
{
	ph[k]= psi[k]/psisum;    // INITIALIZE PHENOMONE VALUE
	

	cout<< "\t"<<ph[k];
}

cout<<endl<<endl;




//TO CALCULATE GLOBAL MINIMUM

double mul=1;

for (int s=0;s<t;s++)          // FOR EACH ITERATION DO...

{
		xtemp = xmin + 0.001 * xmin;     // TO FIND SIGN OF dx i.e. + OR -
		
		if( func(xtemp)<func(xmin))
		   tempflag=1;
		  	     
				   else tempflag=0;
		  
	
	for(int r= 0;r<m;r++)                 // FOR EVERY ANT
	
	
	{
		dx= (rand()%2 - alpha ) * mul;      // RANDOMLY GENERATE dx from [-alpha, +alpha]
	
		if(tempflag)
		
		x[r] = xmin + dx;            // UPDATE ANT VALUE
		
		  else x[r]= xmin - dx;
		  
		  
	f[r]= func(x[r]);               // FIND NEW FMIN AND XMIN 
	if (f[r]<fmin)
	
	{ fmin = f[r];
	  xmin = x[r];
		}	
		  
	}
	
	
		
		
psisum=0;
for(int z=0;z<m;z++)          // FOR EACH ANT
{
	d[z]= f[z] - fmin;        // REDEFINE DISTANCE FROM FMIN
	
	psi[z] = pow( 2.7, -100*d[z]*d[z]) ;      // GAUSSIAN FUNCTION
	
	psisum+= psi[z];
}


cout<<"LOOP"<<1+s<<"\t";

for(int l=0;l<m;l++)              
	cout<< "ant"<<l+1<<"\t";
	cout<<endl;
	

for(int q=0;q<m;q++)           // FOR EACH ANT
{
	ph[q]= psi[q]/psisum;     // UPDATE PHENOMONE
	
	cout<< "\t"<< ph[q];
}

cout<<endl<<endl;
		
		
		
		alpha = 0.9* alpha;     // UPDATE ALPHA (JUMP STEP IN X-VALUE) AT THE END OF EVERY ITERATION
		 
		mul *= 0.9 ;
			
}


//RESULTS

cout<<" x_ANT\t"<<" f(x)_ANT\t"<<"Phenomone_Ant\t"<<"no. of ants with this soln"<<endl;
for(int ii=0;ii<m;ii++)
cout<<x[ii]<<"\t"<<f[ii]<<"\t\t"<<ph[ii]<<"\t\t\t"<<ph[ii]*m<<endl; 


cout<<endl<<endl;

cout<<"Global minimun is found at x =\t"<<xmin<<endl;
cout<<"Global minimum value =\t"<<fmin;


return 0;
}
