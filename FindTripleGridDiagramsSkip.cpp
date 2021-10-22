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

void display_grid(int x[], int o[], int n){
    //cout<<"\n";
    for(int i = n-1; i >-1 ; i--){
        cout<<"|";
        for(int j = 0; j<n; j++){
            if(x[j]==i){
                cout<<"X";
            }else if(o[j]==i){
                cout<<"O";
            }else{
                cout<<".";
            }
        }
        cout<<"|"<<endl;
    }
    //cout<<"\n";
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
main (int argc, char* argv[])
{
  //int n;

  //cout << "Please enter grid size :" << "\n";
  //cin >> n;


  //cout << "The grid size (n) entered is:" << n << "\n";

  if (argc <= 1)
  {
    // On some operating systems, argv[0] can end up as an empty string instead of the program's name.
    // We'll conditionalize our response on whether argv[0] is empty or not.
    if (argv[0])
      std::cout << "Usage: " << argv[0] << " <number>" << '\n';
    else
      std::cout << "Usage: <program name> <number>" << '\n';

    return 1;
  }

  std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

  int n{};
  if (!(convert >> n)) // do the conversion
    n = 1; // if conversion fails, set myint to a default value

  //std::cout << "Got integer: " << n << '\n';
  std::stringstream convert1{ argv[2] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

  int skip{};
  if (!(convert1 >> skip)) // do the conversion
    skip = 1;

  int redblue_x[n];
  int redblue_o[n];

  for(int iskip = 0; iskip<skip; iskip++){
  	redblue_x[iskip] = -1;
  	redblue_o[iskip] = -1;
  }

  for (int ix = skip; ix < n; ix++)
    {
      redblue_x[ix] = ix - skip;
      redblue_o[ix] = ix - skip;
    }


  


  //long int factorial_n_ = factorial(n);
  //long int iter_Os = (factorial_n/2)+1;


  long int factorial_n_minus_skip = factorial(n-skip);
  long int iter_Xs = factorial_n_minus_skip;
  long int iter_Os = factorial_n_minus_skip;
  
  
  // Need to modify code so that skip and permutations are more efficiently permuted. 


  int count = 0;

  for (long int i = 0; i < iter_Xs; i++)
    {

      for (long int j = 0; j < iter_Os; j++)
	{

// 	  cout << "Permuation of RedBlue X:";
// 	  display (redblue_x, n);
// 	  cout << "Permuation of RedBlue O:";
// 	  display (redblue_o, n);
// 	  cout << "\n";

      bool redblue_gridcheck = grid_check(redblue_x,redblue_o,n);
    //   display_check("RedBlue Grid",redblue_gridcheck);
      
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
    //   display_check("RedGreen Grid",redgreen_gridcheck);

      if(!redgreen_gridcheck){
          next_permutation (redblue_o, redblue_o + n);
          continue;
      }
      
	  int greenblue_x[n] = { 0 };

  for (int i = 0; i < n; i++)
    {
      greenblue_x[i] = -1;
    }

  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (redgreen_x[j] == i)
	    {
	      greenblue_x[i] = (i + n - j) % n;
	    }
	}
    }

  int greenblue_o[n] = { 0 };
  for (int i = 0; i < n; i++)
    {
      greenblue_o[i] = -1;
    }

  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (redgreen_o[j] == i)
	    {
	      greenblue_o[i] = (i + n - j) % n;
	    }
	}
    }


	  

	  //cout<<"Now Checking if this is valid"<<"\n";

	  bool greenblue_gridcheck = grid_check(greenblue_x,greenblue_o,n);
    //   display_check("GreenBlue Grid",greenblue_gridcheck);
      
      bool triplegridcheck = redgreen_gridcheck && redblue_gridcheck && greenblue_gridcheck;
     // display_check("Triple Grid",triplegridcheck);
      
      if(triplegridcheck){
          cout << "\n";
          count = count + 1;
          cout<<"Count:"<<count<<endl;
          
        cout << "RedBlue X:";
	    display (redblue_x, n);
	    cout << "RedBlue O:";
	    display (redblue_o, n);
          
        display_grid(redblue_x,redblue_o,n);  
          
        cout << "RedGreen Xs:";
	    display (redgreen_x, n);

	    cout << "RedGreen Os:";
	    display (redgreen_o, n);
          
        display_grid(redgreen_x,redgreen_o,n);    
          
        cout << "GreenBlue Xs:";
	    display (greenblue_x, n);


	    cout << "GreenBlue Os:";
	    display (greenblue_o, n);
	    
	    display_grid(greenblue_x,greenblue_o,n);  
	    
      }
      
      
      
        
	  next_permutation (redblue_o, redblue_o + n);
	}

	for(int iskip = 0; iskip<skip; iskip++){
  		redblue_o[iskip] = -1;
  }

  for (int ix = skip; ix < n; ix++)
    {
      redblue_o[ix] = ix - skip;
    }
      next_permutation (redblue_x, redblue_x + n);
    }

    cout<<"\n"<<count<<"\n";

  return 0;
}
