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

long int factorial(int n){
    long int ans = 1;
    for(int i=n; i>0; i--){
        ans = ans * i;
    }
    return ans;
}

int main(int argc, char* argv[]){

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

  int k{};
  if (!(convert1 >> k)) // do the conversion
    k = 1;
	
	int array[n];

	for (int i = 0; i<k; i++){
		array[i] = -1;
	}
	for(int i = k; i <n; i++){
		array[i] = i-k;
	}

	display(array,n);

	long int fact_n = factorial(n);
	long int fact_k= factorial(k);
	long int iter = fact_n/fact_k;


	for(long int j = 0; j < iter; j++){
		display(array,n);
		next_permutation (array, array + n);
	}



	return 0;
}


