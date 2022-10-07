#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;
void printLine(){
for(int i = 0; i < 41; ++i){
  cout << "-";
}
cout << "\n";
}
int tryAgain(bool finished){
  bool correct_option = true;
  while(correct_option){
  cout << "Try again?\n1. [Yes] 2. [No]\n\n";
  int try_again_choice;
  cin >> try_again_choice;
  if (try_again_choice == 2){
    finished = false;
  } else if (try_again_choice != 1){
    printLine();
    cout << "Not a correct choice\n";
    printLine();
    continue;
  }
  return finished;
  }
}
void indent(){
  cout << "\n";
}
int main(int argc, char const *argv[]){
  vector <double> scores{};
  printLine();
  cout << "Enter the scores (type -1 when finished):\n";
  double score = 0;
  cin >> score;
  while (score != -1){
    scores.push_back(score);
    cin >> score;
  }
  double total_score = 0;
  for (const double& score : scores){
    total_score += score;
  }
  bool finished = true;
  while (finished){
  printLine();
  cout << "\nWhat would you like to do?\n1. [Avg] 2. [High] 3. [Low]\n\n";
  int average = 1;
  int high = 2;
  int low = 3;
  int choice = 0;
  cin >> choice;
  indent();
  if (choice == average){
    double score_average = total_score / double(scores.size()); 
    cout << "The average is: " << score_average << "\n\n";
    printLine();
    finished = tryAgain(finished);
  } else if (choice == high){
    double highest_score = scores.front();
    for (const double& score : scores){
      if (score > highest_score){
        highest_score = score;
      }
    }
    cout << "Highest score: " << highest_score << "\n\n";
    printLine();
    finished = tryAgain(finished);
  } else if (choice == low){
    double lowest_score = scores.front();
    for (const double& score : scores){
      if (score < lowest_score){
        lowest_score = score;
      }
    }
    cout << "Lowest score: " << lowest_score << "\n\n";
    printLine();
    finished = tryAgain(finished);
  } else{
    printLine();
    cout << "Not an option.\n";
    continue;
  }
  
  }
  
  //for(int s : scores){
  //  cout << s << " ";
  //}
  //cout << "\n";
  return 0;
}