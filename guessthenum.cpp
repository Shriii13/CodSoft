
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()

{ 

  srand((unsigned int) time(NULL));
  
 
 // Generate a random number between 1-100

  int number = (rand() % 50) + 1; 
  
  // Stores the guess the user enters
  
int guess = 0;
  
  // Counter to track the number of attempts
 
 int attempts = 0;
  
  do
 {
    
//  store it into guess
   
 cout << "\nEnter Guess (1-50) : ";
    cin >> guess;
    
 // Increment the attempts counter
   
 attempts++;
    
   // Tell the user to guess higher or lower or that they won based on 
    
   
 if (guess > number)
      cout << "\nGuess lower!!!!" << endl;
    

else if (guess < number)
      cout << "\nGuess higher!!!!" << endl;


else
   cout << "\nYou won! It took you\n " << attempts << " attempts." << endl;
      
    
// Keep the game going by having the user guess again so long as they did not guess correctly.


  } while (guess != number);
   
  return 0;
}
