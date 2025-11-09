#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <tuple>
#include <cctype>
#include <direct.h>
enum TokenType {
LEFT_UNIT,
CONTENT,
FIRST_ARROW,
SECOND_ARROW,
RIGHT_UNIT,
};
class ReadFile {
private:
	std::string file_content;
public:
	ReadFile(const std::string& file_name){
		std::string line;
		std::ifstream myfile(file_name);
		if (myfile.is_open()) {
			while (std::getline(myfile, line)) {
		}
		myfile.close();
		this->file_content = line;
		}
	}
	std::string get_content() {
		return this->file_content;
	}	
};
//()->()->()
class Parser {
	std::string token_string;
	std::vector<std::tuple<TokenType,std::string>> tokens;
public:
	Parser(const std::string& token_string) {
		this->token_string = token_string;
	}
	std::vector<std::tuple<TokenType,std::string>> get_tokens(){
		return tokens;
	}
	void parse_tokens() {
		std::vector<std::tuple<TokenType, std::string>> token_tree;
		std::string content;
		for (const char c : token_string) {
			if (isalnum(c)) {
				std::string tmp_string = std::string(1, c);
				content += tmp_string;
			}
			else if (isspace(c)) {
				std::string tmp_string = std::string(1, c);
				content += tmp_string;
			}
			else if (c == ';') {
				std::string tmp_string = std::string(1, c);
				content += tmp_string;
			}
			else if (c == ',') {
				std::string tmp_string = std::string(1, c);
				content += tmp_string;
			}
			switch (c) {
			case '(': {
				std::string tmp_string = std::string(1,c);
				tokens.push_back(std::make_tuple(LEFT_UNIT,tmp_string));
				break;
			}
			case '-': {
				std::string tmp_string = std::string(1, c);
				tokens.push_back(std::make_tuple(FIRST_ARROW,tmp_string));
				break;
			}
			case '>': {
				std::string tmp_string = std::string(1, c);
				tokens.push_back(std::make_tuple(SECOND_ARROW, tmp_string));
				break;
			}
			case ')': {
				std::string tmp_string = std::string(1, c);
				tokens.push_back(std::make_tuple(CONTENT, content));
				tokens.push_back(std::make_tuple(RIGHT_UNIT,tmp_string));
				content.clear();
				break;
			}
			}
		}
	}
	void print_tokens() {
		for (const auto& token : tokens) {
			std::cout << "Token" << " Type: " << std::get<0>(token) << " Value: " << std::get<1>(token) << std::endl;
		}
	}
};
//PLACE FOR AST
class AST{
 std::vector<std::tuple<TokenType,std::string>> tokens;
 std::string file_string;
	AST( std::vector<std::tuple<TokenType,std::string>> tokens){
		this->tokens=tokens;
	}
};