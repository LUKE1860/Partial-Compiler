#include <iostream>
#include "Parser/Parser.hpp"
#include <direct.h>
int main() {
ReadFile file_reader("function.txt");
Parser parser(file_reader.get_content());
parser.parse_tokens();
parser.print_tokens();
}