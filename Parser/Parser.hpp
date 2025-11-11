#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <tuple>
#include <cctype>
#include <direct.h>
#include <iterator>
#include <utility>
enum class TokenType {
LEFT_UNIT,
CONTENT,
FIRST_ARROW,
SECOND_ARROW,
RIGHT_UNIT,
};
enum class UnitType{
	ARGS,
	MAIN_BODY,
	RETURN,
};
std::ostream& operator<<(std::ostream& os, TokenType token_type)
{
    if (token_type == TokenType::LEFT_UNIT){
        os << "LEFT_UNIT";
	}
    else if (token_type == TokenType::RIGHT_UNIT){
		os<<"RIGHT_UNIT";
	}
	else if (token_type == TokenType::CONTENT){
		os << "CONTENT";
	}
	else if (token_type == TokenType::FIRST_ARROW){
		os << "FIRST_ARROW";
	}
	else if (token_type == TokenType::SECOND_ARROW){
		os << "SECOND_ARROW";
	}
    return os;
}
std::ostream& operator<<(std::ostream& os, UnitType unit_type){
    if (unit_type == UnitType::ARGS){
        os << "ARGS";
	}
    else if (unit_type == UnitType::MAIN_BODY){
		os<<"MAIN_BODY";
	}
	else if (unit_type == UnitType::RETURN){
		os<<"RETURN";
	}
    return os;
}
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
	std::vector<std::tuple<TokenType,std::string,UnitType>> tokens;
public:
	Parser(const std::string& token_string) {
		this->token_string = token_string;
	}
	std::vector<std::tuple<TokenType,std::string,UnitType>> get_tokens(){
		return tokens;
	}
	void parse_tokens() {
		int unit_count=0;
		std::vector<std::tuple<TokenType, std::string,UnitType>> token_tree;
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
				if (unit_count < 2){
				unit_count++;
				tokens.push_back(std::make_tuple(TokenType::LEFT_UNIT,tmp_string,UnitType::ARGS));
				break;
				}
				else if (unit_count >= 2 && unit_count < 4){
				unit_count++;
				tokens.push_back(std::make_tuple(TokenType::LEFT_UNIT,tmp_string,UnitType::MAIN_BODY));
				break;
				}
				else if (unit_count >= 4 && unit_count <6){
				unit_count++;
				tokens.push_back(std::make_tuple(TokenType::LEFT_UNIT,tmp_string,UnitType::RETURN));
				break;
				}
				break;
			}
			case '-': {
				std::string tmp_string = std::string(1, c);
				if (unit_count < 2){
				tokens.push_back(std::make_tuple(TokenType::FIRST_ARROW,tmp_string,UnitType::ARGS));
				break;
				}
				else if (unit_count >= 2 && unit_count < 4){
				tokens.push_back(std::make_tuple(TokenType::FIRST_ARROW,tmp_string,UnitType::MAIN_BODY));
				break;
				}
				else if (unit_count >= 4 && unit_count <6){
				tokens.push_back(std::make_tuple(TokenType::FIRST_ARROW,tmp_string,UnitType::RETURN));
				break;
				}
				break;
			}
			case '>': {
				std::string tmp_string = std::string(1, c);
				if (unit_count < 2){
				tokens.push_back(std::make_tuple(TokenType::SECOND_ARROW,tmp_string,UnitType::ARGS));
				break;
				}
				else if (unit_count >= 2 && unit_count < 4){
				tokens.push_back(std::make_tuple(TokenType::SECOND_ARROW,tmp_string,UnitType::MAIN_BODY));
				break;
				}
				else if (unit_count >= 4 && unit_count <6){
				tokens.push_back(std::make_tuple(TokenType::SECOND_ARROW,tmp_string,UnitType::RETURN));
				break;
				}
				break;
			}
			case ')': {
				std::string tmp_string = std::string(1, c);
				if (unit_count < 2){
				unit_count++;
				tokens.push_back(std::make_tuple(TokenType::CONTENT, content,UnitType::ARGS));
				tokens.push_back(std::make_tuple(TokenType::RIGHT_UNIT,tmp_string,UnitType::ARGS));
				content.clear();
				break;
				}
				else if (unit_count >= 2 && unit_count < 4){
				unit_count++;
				tokens.push_back(std::make_tuple(TokenType::CONTENT, content,UnitType::MAIN_BODY));
				tokens.push_back(std::make_tuple(TokenType::RIGHT_UNIT,tmp_string,UnitType::MAIN_BODY));
				content.clear();
				break;
				}
				else if (unit_count >= 4 && unit_count <6){
				unit_count++;
				tokens.push_back(std::make_tuple(TokenType::CONTENT, content,UnitType::RETURN));
				tokens.push_back(std::make_tuple(TokenType::RIGHT_UNIT,tmp_string,UnitType::RETURN));
				content.clear();
				break;
				}
				break;
			}
			}
		}
	}
	void print_tokens() {
		for (const auto& token : tokens) {
			std::cout << "Token" << " Type: " << std::get<0>(token) << " Value: " << std::get<1>(token) <<" Affilation: "<<std::get<2>(token) << std::endl;
		}
	}
};
//PLACE FOR AST
class AST{
 std::vector<std::tuple<TokenType,std::string>> tokens;
 std::string file_string;
 public:
	AST( std::vector<std::tuple<TokenType,std::string>> tokens){
		this->tokens=tokens;
	}
	void convert_tokens_to_string(){
		int arg_unit_count=0;
		int body_arg_count=0;
		int return_arg_count=0;
		int arrow_count;
		for (std::vector<std::tuple<TokenType,std::string>>::iterator it=tokens.begin(); it != tokens.end();++it){
			auto back=*it;
			auto forward=*it;
			if (std::get<0>(*it) == LEFT_UNIT && std::get<0>(*std::prev(forward,3)) == FIRST_ARROW){
			
			}

	}
	}
};