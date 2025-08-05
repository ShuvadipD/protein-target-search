#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define pi 3.14
#define ENS 1000000000
#define Totalconfig 1



float ran2(long *idum);

int main()
{
	int i=0;
	int j=0;
  
	int L=503;

	int nbr[L][L];

	int degreesum[L];


	for(i = 0; i < L; i++)
	{
		for(j = 0; j < L; j++) 
		{
			nbr[i][j]=0;
		}


	}

	double gamma=put_value;

	

/*matrix*/
/*Use double , you have floating numbers not int*/

	
	int** path=malloc(L*sizeof(int*)); 
	for(i=0;i<L;++i)
	path[i]=malloc(L*sizeof(int));



	long idum =-time(NULL);
	
	FILE *file1;
	file1=fopen("raw_exit_times_power_law_semi_dynamic_500.dat", "w");
 
 
   
   
   
   	int counter=0;
   	
   	int count2=0;
   
    	int target1,target2; /*defines both side boundary*/
    	
    	int bin=1000;
   
   	for(target1=2; target1<3; target1=target1+1)
   	{
   	
   		for(target2=L-3; target2<L-2; target2=target2+1)
   		{
   
  			int config;
   
   
   		
  
   
   			for(config=0;config<Totalconfig;config++)
   			{
   



				/*first stage of putting contacts*/



   				for(i = 0; i < L; i++)
				{
			
					for(j = i; j < L; j++) 
					{
				
				
						if((j-i)==1) /*Neighbouring always connected*/
						{
	  			
							path[i][j]=1;
							path[j][i]=1;
	  			
	  					}
	  			
						else if((j-i)==0) /*self contact zero*/
						{
	  			
							path[i][j]=0;
							path[j][i]=0;
	  			
	  					}
	  			
	  					else /*non-neighbouring not connected*/
	  					{
	  						path[i][j]=-1;
	  						path[j][i]=-1;
	  			
	  			
	  					}


	      				}	
       
   				}
   			
		  	
		  	
		  	
		  	
   
				double r;
	   
				for(i = 0; i < L; i++)
				{
			
	      				for(j = i; j < L; j++) 
	      				{
	  
	  					if(i>=target1 && i<=target2 && j>=target1 && j<=target2)
	  					{			
							/*second stage of putting contacts*/
		
							r=ran2(&idum);
		  		
		  					if(path[i][j]==-1)  /*only non-neighbouring*/
		  					{



		  						if(r<(0.0214*pow((abs(i-j)),-gamma)))
		  						{

							
		  					
	  								path[i][j]=1;
	  								path[j][i]=1;
		  			
		
		  						}	
		  		
		  						else
		  						{
		  							path[i][j]=0;
		  							path[j][i]=0;
		  			
		  			
		  						}
	  		
	  						}
	  					}
	  				
	  					else
	  					{
	  				
		  					if(path[i][j]==-1)
		  					{
		  		
								path[i][j]=0;
		  						path[j][i]=0;
		  						
		  					}
	  				
	  					}
	  
	       					//printf("%d", path[i][j]);
	       				}
	       
					//printf("\n");
	   		
	   			}
	   		
	   		
	   
	   
	   			int degree[L];
	   
	   			int degreedist[L];
	   	
	   
	    			for(i = 0; i < L; i++)
	  			{
		     			degree[i]=0;
		      
		      			degreedist[i]=0;
		       
		   		}
		   
		    		for(i = 0; i < L; i++)
		 		{
		      			for(j = 0; j < L; j++) 
		      			{
		  				degree[i]=degree[i]+path[i][j];
		     			}
		      
		      			degreedist[degree[i]]++;
		       
				}
		   
		   
				
		   		
		   	
		   		
		   
		   
		   
		  		int step, origin, option;
		   
		   
		   
		    		/*neighbour listing*/



		  		for(i = 0;i < L; i++)
		  		{
		  
		    			int k=0;


		    			for(j = 0; j < L; j++)
		    			{
		    
		    				if(path[i][j]==1)
		    				{
		  					nbr[i][k]=j;
		  		
		  					k++;
		  				}
		  	
		  	
		   			}
		       
		   		}



		   
		   		/*neighbour list printing: bead_id-degree-neighbour_ids*/



		    		for(i = 0;i < L; i++)
		  		{
		  
		   			//printf("%d\t%d\t", i, degree[i]);
		    
		    
		    
		    			for(j = 0; j < degree[i]; j++)
		   			{
		    
		    				//printf("%d\t", nbr[i][j]);
		  	
		   			}
		    
		   			//printf("\n");
		       
		   		}
		   
		   
		   
		   
		   
		   
		   
		   	
		   
		   
		   		int e;
		   
		   		int totalsteps;


				int position, position_old;
		   
		   
		   		for(e=0; e<ENS; e++)  /*ENS loop*/
		   		{
		   			
		   			//origin=(int)((rand()%(target2- target1 + 1)) + target1);

					origin=L/2.0;
		   
		   			position=origin;

					step=0;

					//printf("%d\t%d\n", step, position);
		   
		   			
		   
		   
		  			 while(step<1000000000)
		  			 {
		   	
		   				position_old=position;

						option=(int)(ran2(&idum)*degree[position_old]);
						position=nbr[position_old][option];

		   				//int r;
		   	
		   				//printf("%d\t%d\n", step+1, position);
		   	
		   				//r=abs(position-position_old);
		   	
		   				if(position==target1-1 || position==target2+1)
		   	
		   				{
		   	
		   	  			
		   	 				//printf("%d\n", count2);
		   	  
		   	  				fprintf(file1,"%d\t%d\t%d\t%d\n", target2-target1+2, e, step+1, position);
							//printf("%d\t%d\t%d\t%d\n", target2-target1+2, e, step+1, position);
		   	  				
		   	  				//fprintf(file9,"%d\n", step+1);
		   	  
		   	  
		   	  				break;
		   				}
		   	
		   				//printf("%d\t%d\n", step+1,position);


						
		   				step++;


						if((step%1)==0)
						{

							/*first stage of putting contacts*/



			   				for(i = 0; i < L; i++)
							{
						
								for(j = i; j < L; j++) 
								{
							
							
									if((j-i)==1) /*Neighbouring always connected*/
									{
				  			
										path[i][j]=1;
										path[j][i]=1;
				  			
				  					}
				  			
									else if((j-i)==0) /*self contact zero*/
									{
				  			
										path[i][j]=0;
										path[j][i]=0;
				  			
				  					}
				  			
				  					else /*non-neighbouring not connected*/
				  					{
				  						path[i][j]=-1;
				  						path[j][i]=-1;
				  			
				  			
				  					}


				      				}	
			       
			   				}
			   			
					  	
					  	
					  	
					  	
			   
							double r;
				   
							for(i = 0; i < L; i++)
							{
						
				      				for(j = i; j < L; j++) 
				      				{
				  
				  					if(i>=target1 && i<=target2 && j>=target1 && j<=target2)
				  					{			
										/*second stage of putting contacts*/
					
										r=ran2(&idum);
					  		
					  					if(path[i][j]==-1)  /*only non-neighbouring*/
					  					{



					  						if(r<(0.0214*pow((abs(i-j)),-gamma)))
					  						{

									
					  		
				  								path[i][j]=1;
				  								path[j][i]=1;
					  			
					
					  						}	
					  		
					  						else
					  						{
					  							path[i][j]=0;
					  							path[j][i]=0;
					  			
					  			
					  						}
				  		
				  						}
				  					}
				  				
				  					else
				  					{
				  				
					  					if(path[i][j]==-1)
					  					{
					  		
											path[i][j]=0;
					  						path[j][i]=0;
					  						
					  					}
				  				
				  					}
				  
				       					//printf("%d", path[i][j]);
				       				}
				       
								//printf("\n");
				   		
				   			}
				   		
				   		
				   
			
				   
				    			for(i = 0; i < L; i++)
				  			{
					     			degree[i]=0;
					      
					      			degreedist[i]=0;
					       
					   		}
					   
					    		for(i = 0; i < L; i++)
					 		{
					      			for(j = 0; j < L; j++) 
					      			{
					  				degree[i]=degree[i]+path[i][j];
					     			}
					      
					      			degreedist[degree[i]]++;
					       
							}
					   
					   
							
					   		
					   	
					   		
					   
					   
					    		/*neighbour listing*/



					  		for(i = 0;i < L; i++)
					  		{
					  
					    			int k=0;


					    			for(j = 0; j < L; j++)
					    			{
					    
					    				if(path[i][j]==1)
					    				{
					  					nbr[i][k]=j;
					  		
					  					k++;
					  				}
					  	
					  	
					   			}
					       
					   		}



						}


		   	
		    			}
		    
		    
		    		} /*ENS loop done*/
		    
		    

		   
		   	}

		   	
	
		  
		}  /*target2 loop ends*/
		
	}  /*target1 loop ends*/
	
	






	
		  	
  	
  
   

}


#define IM1 2147483563
#define IM2 2147483399
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

float ran2(long *idum)
{
  int j;
  long k;
  static long idum2=123456789;
  static long iy=0;
  static long iv[NTAB];
  float temp;

  if (*idum <= 0) {
    if (-(*idum) < 1) *idum=1;
    else *idum = -(*idum);
    idum2 = (*idum);
    for (j=NTAB+7;j>=0;j--) {
      k=(*idum)/IQ1;
      *idum=IA1*(*idum-k*IQ1)-k*IR1;
      if (*idum < 0) *idum += IM1;
      if (j < NTAB) iv[j] = *idum;
    }
    iy=iv[0];
  }
  k=(*idum)/IQ1;
  *idum=IA1*(*idum-k*IQ1)-k*IR1;
  if (*idum < 0) *idum += IM1;
  k=idum2/IQ2;
  idum2=IA2*(idum2-k*IQ2)-k*IR2;
  if (idum2 < 0) idum2 += IM2;
  j=iy/NDIV;
  iy=iv[j]-idum2;
  iv[j] = *idum;
  if (iy < 1) iy+= IMM1;
  if ((temp=AM*iy) > RNMX) return RNMX;
  else return temp;
}
		   


