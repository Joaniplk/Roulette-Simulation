#include <iostream>
#include <cstdlib>
#include <ctime>
using std::string;
using std::cout;
using std::cin;

const int numbers[38] = {0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
const char colors[38] = {'g','g','r','b','r','b','r','b','r','b','r','b','b','r','b','r','b','r','b','r','r','b','r','b','r','b','r','b','r','b','b','r','b','r','b','r','b','r'};
const char oddOrEvens[38] = {'n','n','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e','o','e'};
string betType;
string bet;
char cBet;
int straightBet;

void handleBet(string type){
  string question = "Where do you bet on?";
  if(type == "straight"){
    cout << question << '\n' << "(numbers 0 - 36): ";
    cin >> straightBet;
  }else if(type == "dozens"){
    cout << question << '\n' << "(1st, 2nd, 3rd): ";
    cin >> bet;
  }else if(type == "18Numbers"){
    cout << question << '\n' << "([1-18] , [19-36]): ";
    cin >> bet;
  }else if(type == "RedOrBlack"){
    cout << question << '\n' << "(r , b): ";
    cin >> cBet;
  }else if(type == "OddOrEven"){
    cout << question << '\n' << "(o , e): ";
    cin >> cBet;
  }
}

void start(){
  cout << "-- Roulette Simulation --\n";
  cout << "Standard American Table and Rules\n";
  cout << "Roulette Bets & Payouts\n\nSingle number bet pays 35 to 1. Type 'straight'.\nTwelve numbers or dozens (first, second, third dozen) pays 2 to 1. Type 'dozens'.\n18 numbers (1-18) pays even money. Type '18Numbers'.\n18 numbers (19-36) pays even money. Type '18Numbers'.\nRed or black pays even money. Type 'RedOrBlack'.\nOdd or even bets pay even money. Type 'OddOrEven'.\n\n";
  cout << "How would you like to bet? : ";
  cin >> betType;
  handleBet(betType);
}

void loop(){
  srand(time(NULL));
  int profit = 0;
  int iterations;
  cout << "\nHow many iterations: ";
  cin >> iterations;
  cout << "\nStarting...\n\n";
  for(int i=0;i<iterations;i++){
    int index = rand() % 38;
    int number = numbers[index];
    char color = colors[index];
    char OddEven = oddOrEvens[index];
    if(betType == "straight"){
      //cout << "Number: " << number << '\n';
      if(number == straightBet){
        profit += 36;
      }else {
        profit--;
      }
    }else if(betType == "RedOrBlack"){
      //cout << "Color: " << color << '\n';
      if(color == cBet){
        profit++;
      }else {
        profit--;
      }
    }else if(betType == "OddOrEven"){
      //cout << "Odd or Even: " << OddEven << '\n';
      if(OddEven == cBet){
        profit++;
      }else {
        profit--;
      }
    }else if(bet == "[1-18]"){
      //cout << "Number: " << number << '\n';
      if(number < 19 && number > 0){
        profit++;
      }else{
        profit--;
      }
    }else if(bet == "[19-36]"){
      //cout << "Number: " << number << '\n';
      if(number > 19){
        profit++;
      }else{
        profit--;
      }
    }else if(bet == "1st"){
      //cout << "Number: " << number << '\n';
      if(number < 13 && number > 0){
        profit+= 2;
      }else{
        profit--;
      }
    }else if(bet == "2nd"){
      //cout << "Number: " << number << '\n';
      if(number > 12 && number < 25){
        profit+= 2;
      }else{
        profit--;
      }
    }
    else if(bet == "3rd"){
      //cout << "Number: " << number << '\n';
      if(number > 24){
        profit+= 2;
      }else{
        profit--;
      }
    }
  }
  cout << "Your profit is: " << profit << '\n';
}

int main(){
  char delay;
  start();
  loop();
  cin >> delay;
  return 0;
}