#include <algorithm>
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void part1();
void part2();

int main(){
  part1();
  part2();
  return 0;
}

void part1(){
  ifstream file("day01.txt");
  string line;
  int result = 0;
  while(getline(file, line)){
    regex letters("[^0-9]");
    line = regex_replace(line, letters, "");
    line = string() + line[0] + line[line.length()-1];
    result += atoi(line.c_str()); 
  }
  cout << result << '\n';
}

void part2(){
  static vector<string> nums = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  static vector<string> reps = {"o1e", "t2o", "t3e", "f4r", "f5e", "s6x", "s7n", "e8t", "n9e"};
  ifstream file("day01.txt");
  string line;
  int result = 0;
  while(getline(file, line)){
    for(int i = 0; i<nums.size(); i++){
      regex reg(nums[i]);
      line = regex_replace(line, reg, reps[i]);
    }
    regex letters("[^0-9]");
    line = regex_replace(line, letters, "");
    line = string() + line[0] + line[line.length()-1];
    result += atoi(line.c_str()); 
  }
  cout << result << '\n';

}
