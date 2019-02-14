#include<iostream>
#include<time.h>
#include<algorithm>
#include<ctime>
#include<typeinfo>
#include<cstdlib>
#include<limits>
#include<omp.h>
using namespace std;


void heat_map_100x100()
{
	clock_t start_t, end_t, total_t;
	const int size=101; 
	char ans,ans2;
	int htr,r,c,count,i,j,m,n,countuser;
	count=0;
	double H,tmp,tcon;
	double (*T)[size]=new double[size][size];
	double (*Told)[size]=new double[size][size];
	for (int k = 0; k < size; ++k)
				for (int l= 0; l < size; ++l)
				{T[k][l] = 0;
				   	}

	        cout<<"How many heaters are there ? ";
			cin>>htr;
			cout<<endl<<endl;
			cout<<"Please enter the thermal conductivity? ";
			cin>>tcon;
			cout<<endl<<endl;
			cout<<"Please enter the number of iteration you want to run ";
			cin>>countuser;
			cout<<endl<<endl;

			do
			{
				cout<<"Please enter the heater temperature (tmp),"<<endl;
				cout<<"row (r) and column (c) coordinates ( 1x1 is 1st element & matrix size:"<<size<<endl;
				cout<<" ) respectively seperated by space "<<endl;
				cin>>tmp>>r>>c;

				if ((r>size)||(c>size)||(tmp<0))
				{
					
					cout<< "You entered r or c value are out of border, please enter proper value !!!"<<endl<<endl;
					ans='y';
				}

				else {			
					
					cout<<" You entered for temparature, r and c..> "<<tmp<<" , "<<r<<" , "<<c<<endl<<endl;

					T[r][c]=tmp;

					cout<<" The T["<<r<<"]["<<c<<"]="<<T[r][c]<<endl;
					//cout<<" The A["<<10<<"]["<<10<<"]="<<tmp<<endl;
						
					cout<< "Do you want to continue (Y/N)?\n";
					cout<< "You must type a 'Y' or an 'N'.\n";
					cin >> ans;
					}
					
				} while (ans != 'N' && ans != 'n');
			
start_t = clock();
// keep the Told from T
#pragma omp parallel for private(n)
	for (m = 1; m < size-1; ++m) {
				   for (n= 1; n< size-1; ++n)
				          {   
						   Told[m][n]=T[m][n];
							  
				          } 
				}
// do-while iteration loop
			do {
				
#pragma omp parallel for private(j)
			for (i = 1; i < size-1; ++i) {
				   for (j= 1; j < size-1; ++j)
				          {   
						   T[i][j]= Told[i][j]+tcon*(Told[i-1][j]+Told[i+1][j]+Told[i][j-1]+Told[i][j+1]-4*Told[i][j]);
						  

						   cout<<"T["<<i<<"]["<<j<<"] = "<<T[i][j]<<endl;

				          } 
			}

				   count=count+1;
				   cout<< "Iteration number is :"<<count<<endl;
				  						  
				   } while (count <countuser);
	end_t = clock();
	total_t = (double)(end_t - start_t);
	cout<<"heat_map_100x100() takes "<<total_t<<" ms"<<endl; 
   
}



void heat_map_500x500()
{
	clock_t start_t, end_t, total_t;
	const int size=501; 
	char ans,ans2;
	int htr,r,c,count,i,j,countuser,m,n;
	double H,tmp,tcon;
	double (*T)[size]=new double[size][size];
	double (*Told)[size]=new double[size][size];

	for (int k = 0; k < size; ++k)
				for (int l= 0; l < size; ++l)
				{T[k][l] = 0;
				   	}
	

			cout<<"How many heaters are there ? ";
			cin>>htr;
			cout<<endl<<endl;
			cout<<"Please enter the thermal conductivity? ";
			cin>>tcon;
			cout<<endl<<endl;
			cout<<"Please enter the number of iteration you want to run ";
			cin>>countuser;
			cout<<endl<<endl;

			do
			{
				cout<<"Please enter the heater temperature (tmp),"<<endl;
				cout<<"row (r) and column (c) coordinates ( 1x1 is 1st element & matrix size:"<<size<<endl;
				cout<<" ) respectively seperated by space "<<endl;
				cin>>tmp>>r>>c;

				if ((r>size)||(c>size)||(tmp<0))
				{
					
					cout<< "You entered r or c value are out of border, please enter proper value !!!"<<endl<<endl;
					ans='y';
				}

				else {			
					
					cout<<" You entered for temparature, r and c..> "<<tmp<<" , "<<r<<" , "<<c<<endl<<endl;

					T[r][c]=tmp;

					cout<<" The T["<<r<<"]["<<c<<"]="<<T[r][c]<<endl;
					//cout<<" The A["<<10<<"]["<<10<<"]="<<tmp<<endl;
						
					cout<< "Do you want to continue (Y/N)?\n";
					cout<< "You must type a 'Y' or an 'N'.\n";
					cin >> ans;
					}
					
				} while (ans != 'N' && ans != 'n');

		start_t = clock();	
		count=0;
// keep the Told from T
#pragma omp parallel for private(n)
for (m = 1; m < size-1; ++m) {
				   for (n= 1; n < size-1; ++n)
				          {   
						   Told[m][n]=T[m][n];
							  
				          } 
				}

// iteration do-while loop
			do {
			
#pragma omp parallel for private(j)
			for (i = 1; i < size-1; ++i) {
				   for (j= 1; j < size-1; ++j)
				          {   
						   T[i][j]= Told[i][j]+tcon*(Told[i-1][j]+Told[i+1][j]+Told[i][j-1]+Told[i][j+1]-4*Told[i][j]);
							  
//#pragma omp critical		
						   //cout<<"From Thread#"<<omp_get_thread_num()<<endl;
//#pragma omp critical
						  // cout<<"T["<<i<<"]["<<j<<"] = "<<T[i][j]<<endl;

				          } 
			}

				   count=count+1;
				   cout<< "Iteration number is :"<<count<<endl;
				  						  
				   } while (count <countuser);
	end_t = clock();
	total_t = (double)(end_t - start_t);
	cout<<"heat_map_500x500() takes "<<total_t<<" ms"<<endl; 
		
   
}



void heat_map_1000x1000()
{
	clock_t start_t, end_t, total_t;
	const int size=1001; 
	char ans,ans2;
	int htr,r,c,count,i,j,countuser,m,n;
	double H,tmp,tcon;
	double (*T)[size]=new double[size][size];
	double (*Told)[size]=new double[size][size];
	for (int k = 0; k < size; ++k)
				for (int l= 0; l < size; ++l)
				{T[k][l] = 0;
				   	}
	

			cout<<"How many heaters are there ? ";
			cin>>htr;
			cout<<endl<<endl;
			cout<<"Please enter the thermal conductivity? ";
			cin>>tcon;
			cout<<endl<<endl;
			cout<<"Please enter the number of iteration you want to run ";
			cin>>countuser;
			cout<<endl<<endl;

			do
			{
				cout<<"Please enter the heater temperature (tmp),"<<endl;
				cout<<"row (r) and column (c) coordinates ( 1x1 is 1st element & matrix size:"<<size<<endl;
				cout<<" ) respectively seperated by space "<<endl;
				cin>>tmp>>r>>c;

				if ((r>size)||(c>size)||(tmp<0))
				{
					
					cout<< "You entered r or c value are out of border, please enter proper value !!!"<<endl<<endl;
					ans='y';
				}

				else {			
					
					cout<<" You entered for temparature, r and c..> "<<tmp<<" , "<<r<<" , "<<c<<endl<<endl;

					T[r][c]=tmp;

					cout<<" The T["<<r<<"]["<<c<<"]="<<T[r][c]<<endl;
					//cout<<" The A["<<10<<"]["<<10<<"]="<<tmp<<endl;
						
					cout<< "Do you want to continue (Y/N)?\n";
					cout<< "You must type a 'Y' or an 'N'.\n";
					cin >> ans;
					}
					
				} while (ans != 'N' && ans != 'n');

		start_t = clock();	
		count=0;
// keep the Told from T
#pragma omp parallel for private(n)
for (m = 1; m < size-1; ++m) {
				   for (n= 1; n < size-1; ++n)
				          {   
						   Told[m][n]=T[m][n];
							  
				          } 
				}
// iteration do-while loop
			do {
			
#pragma omp parallel for private(j)
			for (i = 1; i < size-1; ++i) {
				   for (j= 1; j < size-1; ++j)
				          {   
						   T[i][j]= Told[i][j]+tcon*(Told[i-1][j]+Told[i+1][j]+Told[i][j-1]+Told[i][j+1]-4*Told[i][j]);
							  
//#pragma omp critical		
						   //cout<<"From Thread#"<<omp_get_thread_num()<<endl;
//#pragma omp critical
						 //  cout<<"Z["<<i<<"]["<<j<<"] = "<<T[i][j]<<endl;

				          } 
			}
				 
			count=count+1;
			cout<< "Iteration number is :"<<count<<endl;
				   
						  
				   } while (count <countuser);
end_t = clock();
total_t = (double)(end_t - start_t);
cout<<"heat_map_1000x1000() takes "<<total_t<<" ms"<<endl; 
		
   
}



void heat_map_2000x2000()
{
	clock_t start_t, end_t, total_t;
	const int size=2001; 
	char ans,ans2;
	int htr,r,c,count,i,j,countuser,m,n;
	double H,tmp,tcon;
	double (*T)[size]=new double[size][size];
	double (*Told)[size]=new double[size][size];

	for (int k = 0; k < size; ++k)
				for (int l= 0; l < size; ++l)
				{T[k][l] = 0;
				   	}
	
			cout<<"How many heaters are there ? ";
			cin>>htr;
			cout<<endl<<endl;
			cout<<"Please enter the thermal conductivity? ";
			cin>>tcon;
			cout<<endl<<endl;
			cout<<"Please enter the number of iteration you want to run ";
			cin>>countuser;
			cout<<endl<<endl;

			do
			{
				cout<<"Please enter the heater temperature (tmp),"<<endl;
				cout<<"row (r) and column (c) coordinates ( 1x1 is 1st element & matrix size:"<<size<<endl;
				cout<<" ) respectively seperated by space "<<endl;
				cin>>tmp>>r>>c;

				if ((r>size)||(c>size)||(tmp<0))
				{
					
					cout<< "You entered r or c value are out of border, please enter proper value !!!"<<endl<<endl;
					ans='y';
				}

				else {			
					
					cout<<" You entered for temparature, r and c..> "<<tmp<<" , "<<r<<" , "<<c<<endl<<endl;

					T[r][c]=tmp;

					cout<<" The T["<<r<<"]["<<c<<"]="<<T[r][c]<<endl;
					//cout<<" The A["<<10<<"]["<<10<<"]="<<tmp<<endl;
						
					cout<< "Do you want to continue (Y/N)?\n";
					cout<< "You must type a 'Y' or an 'N'.\n";
					cin >> ans;
					}
					
				} while (ans != 'N' && ans != 'n');
		start_t = clock();
		count=0;

// keep the Told from T
#pragma omp parallel for private(n)
for (m = 1; m < size-1; ++m) {
				   for (n= 1; n < size-1; ++n)
				          {   
						   Told[m][n]=T[m][n];
							  
				          } 
				}
// iteration do-while loop
			do {
			
#pragma omp parallel for private(j)
			for (i = 1; i < size-1; ++i) {
				   for (j= 1; j < size-1; ++j)
				          {   
						   T[i][j]= Told[i][j]+tcon*(Told[i-1][j]+Told[i+1][j]+Told[i][j-1]+Told[i][j+1]-4*Told[i][j]);
							  
//#pragma omp critical		
						   //cout<<"From Thread#"<<omp_get_thread_num()<<endl;
//#pragma omp critical
						//   cout<<"Z["<<i<<"]["<<j<<"] = "<<T[i][j]<<endl;

				          } 
			}
			
			 count=count+1;
			 cout<< "Iteration number is :"<<count<<endl;
				   
						  
				   } while (count <countuser);
		
    end_t = clock();
	total_t = (double)(end_t - start_t);
	cout<<"heat_map_2000x2000(); takes "<<total_t<<" ms"<<endl<<endl;
}




int main ()
{
	
	omp_set_num_threads (4);
	//set OMP_NUM_THREADS=4;
	int x=omp_get_num_procs ();
	//double h;
	cout<<"Number of Processor in this computer: "<<x<<endl;
	//heat_map_100x100();
		
	cout<<"******************************************"<<endl;
	cout<<"FIRST CASE: 100x100                       "<<endl;
	cout<<"******************************************"<<endl;
	heat_map_100x100();
			
	// second case
	/*
	cout<<"******************************************"<<endl;
	cout<<"SECOND CASE:500x500                         "<<endl;
	cout<<"******************************************"<<endl;
	heat_map_500x500();
	*/

	// third case
	/*
	cout<<"******************************************"<<endl;
	cout<<"THIRD CASE: 1000x1000                               "<<endl;
	cout<<"******************************************"<<endl;
	heat_map_1000x1000();
	*/
	
	// fourth case
	/*
	cout<<"******************************************"<<endl;
	cout<<"FOURTH CASE: 2000x2000                               "<<endl;
	cout<<"******************************************"<<endl;
	heat_map_2000x2000();
	*/
	
	
	return 0;
}