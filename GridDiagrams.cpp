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


int
main ()
{


  int n;

  cout << "Please enter grid size :" << "\n";
  cin >> n;
  //n = 3;

  cout << "The grid size (n) entered is:" << n << "\n";

  int redblue_x[n];
  int redblue_o[n];

  cout <<
    "Please enter the permutation for Xs (starting from 0 to n-1) (enter -1 for skipping a column) and press enter after each number:"
    << "\n";

  for (int ix = 0; ix < n; ix++)
    {
      cin >> redblue_x[ix];
    }

  bool redblue_x_check = check_repeat (redblue_x, n);

  display_check ("X Permutation", redblue_x_check);

  cout << "Confirm the permutation entered:";
  display (redblue_x, n);


  cout <<
    "Please enter the permutation for Os (starting from 0 to n-1) (enter -1 for skipping a column) and press enter after each number:"
    << "\n";

  for (int io = 0; io < n; io++)
    {
      cin >> redblue_o[io];
    }

  bool redblue_o_check = check_repeat (redblue_o, n);

  display_check ("O Permutation", redblue_o_check);

  cout << "Confirm the permutation entered:";

  display (redblue_o, n);

  int redgreen_x[n];
  int redgreen_o[n];

  for (int ix = 0; ix < n; ix++)
    {
      if (redblue_x[ix] != -1)
	{
	  int a = redblue_x[ix] + ix;
	  //cout<<"Iteration:"<<ix<<" a:"<<a<<"\n";
	  int b = (n + (a % n)) % n;
	  //cout<<"Iteration:"<<ix<<" b:"<<b<<"\n";
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
	  //cout<<"Iteration:"<<ix<<" a:"<<a<<"\n";
	  int b = (n + (a % n)) % n;
	  //cout<<"Iteration:"<<ix<<" b:"<<b<<"\n";
	  redgreen_o[io] = b;
	}
      else
	{
	  redgreen_o[io] = -1;
	}
    }


  cout << "RedGreen Xs:";
  display (redgreen_x, n);

  cout << "RedGreen Os:";
  display (redgreen_o, n);


  //cout << "Now Checking if this is valid" << "\n";

  bool redgreen_x_check = check_repeat (redgreen_x, n);
  display_check ("RedGreen X", redgreen_x_check);

  bool redgreen_o_check = check_repeat (redgreen_o, n);
  display_check ("RedGreen O", redgreen_o_check);

  bool redgreen_check_grid = check_overlap (redgreen_x, redgreen_o, n);
  display_check ("RedGreen Grid", redgreen_check_grid);

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


  cout << "GreenBlue Xs:";

  display (greenblue_x, n);

  cout << "GreenBlue Os:";

  display (greenblue_o, n);

  //cout << "Now Checking if this is valid" << "\n";

  bool greenblue_x_check = check_repeat (greenblue_x, n);
  display_check ("GreenBlue X", greenblue_x_check);

  bool greenblue_o_check = check_repeat (greenblue_o, n);
  display_check ("GreenBlue O", greenblue_o_check);


  bool greenblue_check_grid = check_overlap (greenblue_x, greenblue_o, n);
  display_check ("GreenBlue Grid", greenblue_check_grid);


  return 0;
}
