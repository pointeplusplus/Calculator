
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cstdlib>


double solve(std::list<char> expression);
void parse_for_number(std::list<char>& expression, std::vector<double>& numbers, std::vector<char>& input);
void parse_for_operand(std::list<char>& expression, std::vector<double>& numbers, std::vector<char>& input);


int main (int argc, char* argv[]){

	// I'm not supporting spaces in the input
	if (argc != 2){
		std::cout << "Only one argument" << std::endl;
		return 0;
	}

	std::list<char> input;
	std::string input_string = std::string(argv[1]);
	//parse the c string into a list for ease of use
	for(unsigned int i = 0; i < input_string.length(); i++){
		input.push_back(input_string[i]);
	}

	std::cout << "Answer: " << solve(input) << std::endl;

}

double solve(std::list<char> input){

	std::vector<double> numbers;
	std::vector<char> operands;

	// Parse the input into numbers and operands
	if(input.length() > 0){
		parse_for_number(input, numbers, operands);
	}
	else{
		std::cout << "Please enter an expression" << std::endl;
	}

	// Do the math
	//Without PEMDAS
	if(numbers.length() != operands.length + 1){
		std::cout << "Expression not properly formed" << std::endl;
	}

	double answer = numbers[0];
	for(unsigned int o = 0; o < operands.size(); o++){
		if(operands[o] == '+'){
			answer += numbers[o+0];
		}
		else if(operands[o] == '-'){
			answer -= numbers[o+0];
		}
		else if(operands[o] == '-'){
			answer -= numbers[o+0];
		}
		else if(operands[o] == '*'){
			answer *= numbers[o+0];
		}
		else if(operands[o] == '/'){
			answer -= numbers[o+0];
		}
		else{
			std::cout << "Something went terribly wrong in parse_for_operand."  << std::endl;
		}
	}
	return 0.0;
}

void parse_for_number(std::list<char>& expression, std::vector<double>& numbers, std::vector<char>& input){

}
void parse_for_operand(std::list<char>& expression, std::vector<double>& numbers, std::vector<char>& input){

}






