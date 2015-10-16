
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cstdlib>


double solve(std::list<char> expression);
void parse_for_number(std::list<char>& expression, std::vector<double>& numbers, std::vector<char>& operands);
void parse_for_operand(std::list<char>& expression, std::vector<double>& numbers, std::vector<char>& operands);


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

	return 0;
}

double solve(std::list<char> input){

	std::vector<double> numbers;
	std::vector<char> operands;

	// Parse the input into numbers and operands
	if(input.size() > 0){
		parse_for_number(input, numbers, operands);
	}
	else{
		std::cout << "Please enter an expression" << std::endl;
	}

	/*
	// DEBUG: See what is in the two vectors:
	std::cout << "Numbers: ";
	for(unsigned int n = 0; n < numbers.size(); n++){
		std::cout << numbers[n] << " ";
	}
	std::cout << std::endl;

	std::cout << "Operands: ";
	for(unsigned int o = 0; o < operands.size(); o++){
		std::cout << operands[o] << " ";
	}
	std::cout << std::endl;
	*/

	// Do the math
	//TODO: PEMDAS
	if(numbers.size() != operands.size() + 1){
		std::cout << "Expression not properly formed" << std::endl;
		std::exit(0);
	}

	double answer = numbers[0];
	for(unsigned int o = 0; o < operands.size(); o++){
		if(operands[o] == '+'){
			answer += numbers[o+1];
		}
		else if(operands[o] == '-'){
			answer -= numbers[o+1];
		}
		else if(operands[o] == '*'){
			answer *= numbers[o+1];
		}
		else if(operands[o] == '/'){
			answer /= numbers[o+1];
		}
		//TODO: modulo
		else{
			std::cout << "Something went terribly wrong in parse_for_operand."  << std::endl;
			exit(0);
		}
	}
	return answer;
}

void parse_for_number(std::list<char>& expression, std::vector<double>& numbers, std::vector<char>& operands){

	// just for integers and no compound expressions
	std::list<char>::iterator first_char = expression.begin();

	// if character is a number
	if(*first_char >= 48 && *first_char <= 57){
		const char* to_add = &(*first_char);
		numbers.push_back(atoi(to_add));

		expression.erase(first_char);

		if(expression.size() > 0){
			parse_for_operand(expression, numbers, operands);
		}
	}
	else{
		std::cout << "This expression is not well formed." << std::endl;
	}
}
void parse_for_operand(std::list<char>& expression, std::vector<double>& numbers, std::vector<char>& operands){
	std::list<char>::iterator first_char = expression.begin();

	// If it is an operand, add it to the list
	if (*first_char == '+' ||
		*first_char == '-' ||
		*first_char == '*' ||
		*first_char == '/'){ //TODO: modulo

		operands.push_back(*first_char);

		expression.erase(first_char);

		if(expression.size() > 0){
			parse_for_number(expression, numbers, operands);
		}
	}

	else {
		std::cout << "There needs to be an operand between each expression." << std::endl;
		exit(0);
	}
}






