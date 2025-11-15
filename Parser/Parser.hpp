#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <cctype>
#include <direct.h>
#include <iterator>
#include <utility>
#include <format>
enum class TokenType {
	LEFT_UNIT,
	CONTENT,
	FIRST_ARROW,
	SECOND_ARROW,
	RIGHT_UNIT,
};
enum class UnitType {
	ARGS,
	MAIN_BODY,
	RETURN,
};
enum class BODY_EXPRESSIONS {
	LET,
	IDENT,
	INT,
	UNSIGNED,
	VARIABLE,
	ADD,
	DOUBLE_ADD,
	SUB,
	DOUBLE_SUB,
	MUL,
	DOUBLE_MUL,
	RETURN,
};
enum class BODY_PHASES {
	DECLARATION,
	ADD_PHASE,
	DOUBLE_ADD_PHASE,
	SUB_PHASE,
	DOUBLE_SUB_PHASE,
	MUL_PHASE,
	DOUBLE_MUL_PHASE,
};
std::ostream& operator<<(std::ostream& os, TokenType token_type)
{
	if (token_type == TokenType::LEFT_UNIT) {
		os << "LEFT_UNIT";
	}
	else if (token_type == TokenType::RIGHT_UNIT) {
		os << "RIGHT_UNIT";
	}
	else if (token_type == TokenType::CONTENT) {
		os << "CONTENT";
	}
	else if (token_type == TokenType::FIRST_ARROW) {
		os << "FIRST_ARROW";
	}
	else if (token_type == TokenType::SECOND_ARROW) {
		os << "SECOND_ARROW";
	}
	return os;
}
std::ostream& operator<<(std::ostream& os, UnitType unit_type) {
	if (unit_type == UnitType::ARGS) {
		os << "ARGS";
	}
	else if (unit_type == UnitType::MAIN_BODY) {
		os << "MAIN_BODY";
	}
	else if (unit_type == UnitType::RETURN) {
		os << "RETURN";
	}
	return os;
}
std::vector<std::string> split_string(std::string& content, char delimiter) {
	std::istringstream stream(content);
	std::vector<std::string> tokens;
	std::string token;
	while (getline(stream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}
std::tuple<std::string, std::string> remove_tailing_comma(std::string input) {
	std::istringstream stream(input);
	std::vector<std::string> tokens;
	std::string token;
	while (std::getline(stream, token, ',')) {
		tokens.push_back(token);
	}
	return std::make_tuple(tokens[0], tokens[1]);

}
std::tuple<std::string, std::string> remove_tailing_equal(std::string input) {
	std::istringstream stream(input);
	std::vector<std::string> tokens;
	std::string token;
	while (std::getline(stream, token, '=')) {
		tokens.push_back(token);
	}
	return std::make_tuple(tokens[0], tokens[1]);
}
std::vector<std::tuple<BODY_EXPRESSIONS, std::string, BODY_PHASES>> create_body(std::vector<std::string> body) {
	std::vector<std::tuple<BODY_EXPRESSIONS, std::string, BODY_PHASES>> expression_vec;
	for (std::string tokens : body) {
		if (tokens.find("let") != std::string::npos) {
			std::vector<std::string> content_string = split_string(tokens, ' ');
			std::tuple<std::string, std::string> expr = remove_tailing_equal(content_string[1]);
			std::string ident = std::get<0>(expr);
			std::string value = std::get<1>(expr);
			if (value.find("i") != std::string::npos) {
				value.pop_back();
				expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::LET, "LET", BODY_PHASES::DECLARATION));
				expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::IDENT, ident, BODY_PHASES::DECLARATION));
				expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::INT, value, BODY_PHASES::DECLARATION));

			}
			else if (value.find("u") != std::string::npos) {
				value.pop_back();
				expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::LET, "LET", BODY_PHASES::DECLARATION));
				expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::IDENT, ident, BODY_PHASES::DECLARATION));
				expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::UNSIGNED, value, BODY_PHASES::DECLARATION));
			}

		}
		else if (tokens.find("+=") != std::string::npos) {
			std::vector<std::string> content_string = split_string(tokens, '+');
			content_string[1].erase(0, 1);
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::IDENT, content_string[0], BODY_PHASES::ADD_PHASE));
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::ADD, content_string[1], BODY_PHASES::ADD_PHASE));

		}
		else if (tokens.find("++=") != std::string::npos) {
			std::vector<std::string> content_string = split_string(tokens, '+');
			content_string[1].erase(0, 1);
			content_string[1].erase(0, 1);
			std::tuple<std::string, std::string> corrected_strings = remove_tailing_comma(content_string[1]);
			content_string[1] = std::get<0>(corrected_strings);
			content_string[1] += " ";
			content_string[1] += std::get<1>(corrected_strings);
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::IDENT, content_string[0], BODY_PHASES::DOUBLE_ADD_PHASE));
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::DOUBLE_ADD, content_string[1], BODY_PHASES::DOUBLE_ADD_PHASE));
		}
		else if (tokens.find("-=") != std::string::npos) {
			std::vector<std::string> content_string = split_string(tokens, '-');
			content_string[1].erase(0, 1);
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::IDENT, content_string[0], BODY_PHASES::SUB_PHASE));
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::SUB, content_string[1], BODY_PHASES::SUB_PHASE));
		}
		else if (tokens.find("--= ") != std::string::npos) {
			std::vector<std::string> content_string = split_string(tokens, '-');
			content_string[1].erase(0, 1);
			content_string[1].erase(0, 1);
			std::tuple<std::string, std::string> corrected_strings = remove_tailing_comma(content_string[1]);
			content_string[1] = std::get<0>(corrected_strings);
			content_string[1] += " ";
			content_string[1] += std::get<1>(corrected_strings);
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::IDENT, content_string[0], BODY_PHASES::DOUBLE_SUB_PHASE));
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::DOUBLE_SUB, content_string[1], BODY_PHASES::DOUBLE_SUB_PHASE));
		}
		else if (tokens.find("*=") != std::string::npos) {
			std::vector<std::string> content_string = split_string(tokens, '*');
			content_string[1].erase(0, 1);
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::IDENT, content_string[0], BODY_PHASES::MUL_PHASE));
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::MUL, content_string[1], BODY_PHASES::MUL_PHASE));
		}
		else if (tokens.find("**=") != std::string::npos) {
			std::vector<std::string> content_string = split_string(tokens, '*');
			content_string[1].erase(0, 1);
			content_string[1].erase(0, 1);
			std::tuple<std::string, std::string> corrected_strings = remove_tailing_comma(content_string[1]);
			content_string[1] = std::get<0>(corrected_strings);
			content_string[1] += " ";
			content_string[1] += std::get<1>(corrected_strings);
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::IDENT, content_string[0], BODY_PHASES::DOUBLE_MUL_PHASE));
			expression_vec.push_back(std::make_tuple(BODY_EXPRESSIONS::DOUBLE_MUL, content_string[1], BODY_PHASES::DOUBLE_MUL_PHASE));
		}
	}
	return expression_vec;
}
std::string create_body_string(std::vector<std::tuple<BODY_EXPRESSIONS, std::string, BODY_PHASES>> body) {
	std::string body_string = " BODY: ";
	for (const auto token : body) {
		if (std::get<2>(token) == BODY_PHASES::DECLARATION) {
			body_string += std::get<1>(token);
			body_string += " ";
		}
		else if (std::get<2>(token) == BODY_PHASES::ADD_PHASE) {
			if (std::get<0>(token) == BODY_EXPRESSIONS::IDENT) {
				body_string += " ADD";
				body_string += " ";
				body_string += std::get<1>(token);
			}
			else if (std::get<0>(token) == BODY_EXPRESSIONS::ADD) {
				body_string += " ";
				body_string += std::get<1>(token);
			}
		}
		else if (std::get<2>(token) == BODY_PHASES::DOUBLE_ADD_PHASE) {
			if (std::get<0>(token) == BODY_EXPRESSIONS::IDENT) {
				body_string += " DOUBLE_ADD";
				body_string += " ";
				body_string += std::get<1>(token);
			}
			else if (std::get<0>(token) == BODY_EXPRESSIONS::DOUBLE_ADD) {
				body_string += " ";
				body_string += std::get<1>(token);
			}

		}
		else if (std::get<2>(token) == BODY_PHASES::SUB_PHASE) {
			if (std::get<0>(token) == BODY_EXPRESSIONS::IDENT) {
				body_string += " SUB";
				body_string += " ";
				body_string += std::get<1>(token);
			}
			else if (std::get<0>(token) == BODY_EXPRESSIONS::SUB) {
				body_string += " ";
				body_string += std::get<1>(token);
			}
		}
		else if (std::get<2>(token) == BODY_PHASES::DOUBLE_SUB_PHASE) {
			if (std::get<0>(token) == BODY_EXPRESSIONS::IDENT) {
				body_string += " DOUBLE_SUB";
				body_string += " ";
				body_string += std::get<1>(token);
			}
			else if (std::get<0>(token) == BODY_EXPRESSIONS::DOUBLE_SUB) {
				body_string += " ";
				body_string += std::get<1>(token);
			}
		}
		else if (std::get<2>(token) == BODY_PHASES::MUL_PHASE) {
			if (std::get<0>(token) == BODY_EXPRESSIONS::IDENT) {
				body_string += " MUL";
				body_string += " ";
				body_string += std::get<1>(token);
			}
			else if (std::get<0>(token) == BODY_EXPRESSIONS::MUL) {
				body_string += std::get<1>(token);
				body_string += " ";
			}
		}
		else if (std::get<2>(token) == BODY_PHASES::DOUBLE_MUL_PHASE) {
			if (std::get<0>(token) == BODY_EXPRESSIONS::IDENT) {
				body_string += " DOUBLE_MUL";
				body_string += " ";
				body_string += std::get<1>(token);
			}
			else if (std::get<0>(token) == BODY_EXPRESSIONS::DOUBLE_MUL) {
				body_string += " ";
				body_string += std::get<1>(token);
			}
		}
	}
	return body_string;
}
class ReadFile {
private:
	std::string file_content;
public:
	ReadFile(const std::string& file_name) {
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
	std::vector<std::tuple<TokenType, std::string, UnitType>> tokens;
public:
	Parser(const std::string& token_string) {
		this->token_string = token_string;
	}
	std::vector<std::tuple<TokenType, std::string, UnitType>> get_tokens() {
		return tokens;
	}
	void parse_tokens() {
		int unit_count = 0;
		std::vector<std::tuple<TokenType, std::string, UnitType>> token_tree;
		std::string content;
		for (const char c : token_string) {
			switch (c) {
			case '(': {
				std::string tmp_string = std::string(1, c);
				if (unit_count < 2) {
					unit_count++;
					tokens.push_back(std::make_tuple(TokenType::LEFT_UNIT, tmp_string, UnitType::ARGS));
					break;
				}
				else if (unit_count >= 2 && unit_count < 4) {
					unit_count++;
					tokens.push_back(std::make_tuple(TokenType::LEFT_UNIT, tmp_string, UnitType::MAIN_BODY));
					break;
				}
				else if (unit_count >= 4 && unit_count < 6) {
					unit_count++;
					tokens.push_back(std::make_tuple(TokenType::LEFT_UNIT, tmp_string, UnitType::RETURN));
					break;
				}
				break;
			}
			case '-': {
				std::string tmp_string = std::string(1, c);
				if (unit_count < 2) {
					tokens.push_back(std::make_tuple(TokenType::FIRST_ARROW, tmp_string, UnitType::ARGS));
					break;
				}
				else if (unit_count >= 2 && unit_count < 4) {
					tokens.push_back(std::make_tuple(TokenType::FIRST_ARROW, tmp_string, UnitType::MAIN_BODY));
					break;
				}
				else if (unit_count >= 4 && unit_count < 6) {
					tokens.push_back(std::make_tuple(TokenType::FIRST_ARROW, tmp_string, UnitType::RETURN));
					break;
				}
				break;
			}
			case '>': {
				std::string tmp_string = std::string(1, c);
				if (unit_count < 2) {
					tokens.push_back(std::make_tuple(TokenType::SECOND_ARROW, tmp_string, UnitType::ARGS));
					break;
				}
				else if (unit_count >= 2 && unit_count < 4) {
					tokens.push_back(std::make_tuple(TokenType::SECOND_ARROW, tmp_string, UnitType::MAIN_BODY));
					break;
				}
				else if (unit_count >= 4 && unit_count < 6) {
					tokens.push_back(std::make_tuple(TokenType::SECOND_ARROW, tmp_string, UnitType::RETURN));
					break;
				}
				break;
			}
			case ')': {
				std::string tmp_string = std::string(1, c);
				if (unit_count < 2) {
					unit_count++;
					tokens.push_back(std::make_tuple(TokenType::CONTENT, content, UnitType::ARGS));
					tokens.push_back(std::make_tuple(TokenType::RIGHT_UNIT, tmp_string, UnitType::ARGS));
					content.clear();
					break;
				}
				else if (unit_count >= 2 && unit_count < 4) {
					unit_count++;
					tokens.push_back(std::make_tuple(TokenType::CONTENT, content, UnitType::MAIN_BODY));
					tokens.push_back(std::make_tuple(TokenType::RIGHT_UNIT, tmp_string, UnitType::MAIN_BODY));
					content.clear();
					break;
				}
				else if (unit_count >= 4 && unit_count < 6) {
					unit_count++;
					tokens.push_back(std::make_tuple(TokenType::CONTENT, content, UnitType::RETURN));
					tokens.push_back(std::make_tuple(TokenType::RIGHT_UNIT, tmp_string, UnitType::RETURN));
					content.clear();
					break;
				}
				break;
			}
			default:{
			std::string tmp_string = std::string(1, c);
				content += tmp_string;
				break;
			}
			}
		}
	}
	void print_tokens() {
		for (const auto& token : tokens) {
			std::cout << "Token" << " Type: " << std::get<0>(token) << " Value: " << std::get<1>(token) << " Affilation: " << std::get<2>(token) << std::endl;
		}
	}
};


//PLACE FOR AST
class AST {
	std::vector<std::tuple<TokenType, std::string, UnitType>> tokens;
	std::string file_string;
public:
	AST(std::vector<std::tuple<TokenType, std::string, UnitType>> tokens) {
		this->file_string = "";
		this->tokens = tokens;
	}
	void convert_tokens_to_string() {
		for (const auto& token : tokens) {
			if (std::get<2>(token) == UnitType::ARGS) {
				if (std::get<0>(token) == TokenType::CONTENT) {
					//()
					// (int number)
					//(int number,int second)
					//()
					std::string delimiter = ",";
					std::string content_string = std::get<1>(token);
					auto pos = content_string.find(delimiter);
					std::cout << content_string << std::endl;
					if (content_string == "") {
						std::string formatted_string = "VALUES:NONE ";
						file_string += formatted_string;
					}
					else if (content_string.find("int") != std::string::npos) {
						std::vector<std::string> splitted_string = split_string(content_string, ' ');
						if (splitted_string.size() == 2) {
							std::string formatted_string = std::format("VALUES:int {} ", splitted_string[1]);
							file_string += formatted_string;
						}
						else if (splitted_string.size() == 3) {
							std::tuple <std::string, std::string> elements = remove_tailing_comma(splitted_string[1]);
							splitted_string.push_back(splitted_string[2]);
							splitted_string[1] = std::get<0>(elements);
							splitted_string[2] = std::get<1>(elements);
							std::string formatted_string = std::format("VALUES:int {} int {}", splitted_string[1], splitted_string[3]);
							file_string += formatted_string;
						}
						else {
							// throw error
						}
					}
					else if (content_string.find("unsigned") != std::string::npos) {
						std::vector<std::string> splitted_string = split_string(content_string, ' ');
						if (splitted_string.size() == 2) {
							std::string formatted_string = std::format("VALUES:unsigned {} ", splitted_string[1]);
							file_string += formatted_string;
						}
						else if (splitted_string.size() == 3) {
							std::tuple <std::string, std::string> elements = remove_tailing_comma(splitted_string[1]);
							splitted_string.push_back(splitted_string[2]);
							splitted_string[1] = std::get<0>(elements);
							splitted_string[2] = std::get<1>(elements);
							std::string formatted_string = std::format("VALUES:unsigned {} unsigned {}", splitted_string[1], splitted_string[3]);
							file_string += formatted_string;
						}
						else if (splitted_string.size() == 4) {
							//TODO!
						}
						else {
						}
					}
				}
			}
			//limit of expressions:4
			else if (std::get<2>(token) == UnitType::MAIN_BODY) {
				if (std::get<0>(token) == TokenType::CONTENT) {
					std::string content_string = std::get<1>(token);
					std::vector<std::string> splitted_string = split_string(content_string, ';');
					std::vector<std::tuple<BODY_EXPRESSIONS, std::string,BODY_PHASES>> body = create_body(splitted_string);
					std::string body_string = create_body_string(body);
					std::cout<<body_string<<std::endl;
					file_string += body_string;
				}
			}
			else if (std::get<2>(token) == UnitType::RETURN) {
				if (std::get<0>(token) == TokenType::CONTENT) {
					std::string content_string = std::get<1>(token);
					if (content_string == "void") {
						std::string formatted_string = "RETURN:VOID";
						file_string += formatted_string;
					}
					else if (content_string == "int") {
						std::string formatted_string = "RETURN:INT";
						file_string += formatted_string;
					}
					else if (content_string == "unsigned") {
						std::string formatted_string = "RETURN:UNSIGNED";
						file_string += formatted_string;
					}
				}
			}
		}
	}
	void save_to_file(){
		 std::ofstream mffd_file("format.mffd");
		 mffd_file << file_string;
 		 mffd_file.close();
	}
};