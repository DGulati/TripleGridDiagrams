/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void
display (int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

void
display_check (std::string input, bool check)
{
  if (check == true)
    {
      cout << input << " is valid" << "\n";
    }
  else
    {
      cout << input << " is not valid" << "\n";
    }
}

bool
check_overlap (int x[], int o[], int n)
{

  bool ans = true;
  for (int i = 0; i < n; i++)
    {
      int a = x[i];
      int b = o[i];

      if (a != -1 && b != -1)
	{
	  if (a == b)
	    {
	      ans = false;
	      //cout << "Break at x:" << a << "\n";
	      //cout << "Break at o:" << b << "\n";
	      break;
	    }
	}
      else if (a == -1 && b != -1 || a != -1 && b == -1)
	{
	  ans = false;
	  //cout << "Break at x:" << a << "\n";
	  //cout << "Break at o:" << b << "\n";
	  break;
	}


    }

  return ans;

}

bool
check_repeat (int x[], int n)
{
  int checkx[n] = { 0 };
  bool check = true;
  for (int i = 0; i < n && check == true; i++)
    {
      int a = x[i];
      //cout<<"A["<<i<<"]:"<<a<<"\n";
      if (a != -1)
	{
	  if (checkx[a] == 1)
	    {
	      check = false;
	      // cout<<"Break at :"<<i<<"\n";
	      break;
	    }
	  checkx[a] = 1;
	}
    }

  /*
     for(int j = 0; j < n; j++){
     if(checkx[j] != 1){
     check = false;
     }
     }
   */

  return check;
}

bool grid_check(int x[], int o[], int n){
    bool x_check = check_repeat (x, n);
	 

	  bool o_check = check_repeat (o, n);
	  

	  bool both_check = check_overlap (x, o, n);
	  
	  
	  bool grid_check = both_check && o_check && x_check;
	  
	 return grid_check;
}

long int factorial(int n){
    long int ans = 1;
    for(int i=n; i>0; i--){
        ans = ans * i;
    }
    return ans;
}


int
main ()
{
  int n;

  cout << "Please enter grid size :" << "\n";
  cin >> n;


  cout << "The grid size (n) entered is:" << n << "\n";

  int redblue_x[n];
  int redblue_o[n];


  for (int ix = 0; ix < n; ix++)
    {
      redblue_x[ix] = ix;
    }


  for (int io = 0; io < n; io++)
    {
      redblue_o[io] = io;
    }


  long int factorial_n = factorial(n);
  
  int count = 0;

  for (long int i = 0; i < factorial_n; i++)
    {

      for (long int j = 0; j < factorial_n; j++)
	{

	  cout << "Permuation of RedBlue X:";
	  display (redblue_x, n);
	  cout << "Permuation of RedBlue O:";
	  display (redblue_o, n);

      bool redblue_gridcheck = grid_check(redblue_x,redblue_o,n);
      display_check("RedBlue Grid",redblue_gridcheck);
      
      if(!redblue_gridcheck){
          next_permutation (redblue_o, redblue_o + n);
          continue;
      }
        
    
	  int redgreen_x[n];
	  int redgreen_o[n];

	  for (int ix = 0; ix < n; ix++)
	    {
	      if (redblue_x[ix] != -1)
		{
		  int a = redblue_x[ix] + ix;
		  int b = (n + (a % n)) % n;
		  redgreen_x[ix] = b;
		}
	      else
		{
		  redgreen_x[ix] = -1;
		}
	    }

	  for (int io = 0; io < n; io++)
	    {
	      if (redblue_o[io] != -1)
		{
		  int a = redblue_o[io] + io;
		  int b = (n + (a % n)) % n;
		  redgreen_o[io] = b;
		}
	      else
		{
		  redgreen_o[io] = -1;
		}
	    }


	  


	  //cout << "Now Checking if this is valid" << "\n";

	  bool redgreen_gridcheck = grid_check(redgreen_x,redgreen_o,n);
      display_check("RedGreen Grid",redgreen_gridcheck);

      if(!redgreen_gridcheck){
          next_permutation (redblue_o, redblue_o + n);
          continue;
      }
      
	  int greenblue_x[n] = { 0 };

	  for (int i = 0; i < n; i++)
	    {
	      for (int j = 0; j < n; j++)
		{
		  if (redgreen_x[j] == i)
		    {
		      greenblue_x[i] = j;
		    }
		}
	    }

	  int greenblue_o[n] = { 0 };

	  for (int i = 0; i < n; i++)
	    {
	      for (int j = 0; j < n; j++)
		{
		  if (redgreen_o[j] == i)
		    {
		      greenblue_o[i] = j;
		    }
		}
	    }


	  

	  //cout<<"Now Checking if this is valid"<<"\n";

	  bool greenblue_gridcheck = grid_check(greenblue_x,greenblue_o,n);
      display_check("GreenBlue Grid",greenblue_gridcheck);
      
      bool triplegridcheck = redgreen_gridcheck && redblue_gridcheck && greenblue_gridcheck;
      display_check("Triple Grid",triplegridcheck);
      
      if(triplegridcheck){
          cout << "\n";
          count = count + 1;
          cout<<"Count:"<<count<<endl;
          
        cout << "RedBlue X:";
	    display (redblue_x, n);
	    cout << "RedBlue O:";
	    display (redblue_o, n);
          
        cout << "RedGreen Xs:";
	    display (redgreen_x, n);

	    cout << "RedGreen Os:";
	    display (redgreen_o, n);
          
          
        cout << "GreenBlue Xs:";
	    display (greenblue_x, n);


	    cout << "GreenBlue Os:";
	    display (greenblue_o, n);
    cout << endl; 
          
      }
      
      
      
        
	  next_permutation (redblue_o, redblue_o + n);
	}
      next_permutation (redblue_x, redblue_x + n);
    }

    cout<<"\n"<<count<<"\n";

  return 0;
}
