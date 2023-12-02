#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <chrono>

using namespace std;


void part1();
void part2();

int main(){

  part1();
  part2();

  return 0;
}

void part2 (){

  auto begin = std::chrono::high_resolution_clock::now();

  ifstream file("day02.txt");
  int result = 0;
  int game = 1;
  string line;
  while(getline(file, line)){

    regex reg("(\\d+ red)|(\\d+ blue)|(\\d+ green)");
    vector<string> parse = vector<string> {
      std::sregex_token_iterator{line.begin(), line.end(), reg},
      std::sregex_token_iterator{}
    };

    int red = 0;
    int blue = 0;
    int green = 0;

    for (string s : parse){

      int ammount = atoi(s.substr(0, s.find(' ')).c_str());
      string color = s.substr(s.find(' ')+1, s.length()-1); 
      // cout << ammount << " - " << color << endl;
      if (color == "red" && ammount > red) red = ammount;
      if (color == "green" && ammount > green) green = ammount;
      if (color == "blue" && ammount > blue) blue = ammount;

    }
    result += red*blue*green;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

  cout << "Part 2: " << result << endl;
  cout << duration / 1000000.0 << " milliseconds" << endl;

}

void part1(){

  auto begin = std::chrono::high_resolution_clock::now();

  ifstream file("day02.txt");
  int result = 0;
  int game = 1;
  string line;
  while(getline(file, line)){
    
    bool valid = true;

    regex reg("(\\d+ red)|(\\d+ blue)|(\\d+ green)");
    vector<string> parse = vector<string> {
      std::sregex_token_iterator{line.begin(), line.end(), reg},
      std::sregex_token_iterator{}
    };

    for (string s : parse){
      int ammount = atoi(s.substr(0, s.find(' ')).c_str());
      string color = s.substr(s.find(' ')+1, s.length()-1); 
      // cout << ammount << " - " << color << endl;
      if (color == "red") if (ammount > 12) valid = false;
      if (color == "green") if (ammount > 13) valid = false;
      if (color == "blue") if (ammount > 14) valid = false;
    }
   
    if(valid) result += game;
    game++;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();

  cout << "Part 2: " << result << endl;
  cout << duration / 1000000.0 << " milliseconds" << endl;

}
