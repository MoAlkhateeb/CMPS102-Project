
#include "HelperFn.h"

bool IsValue(std::string input) {
    // checks if the input string is a double value
    // return true if it's double value, false otherwise
    
    std::regex validDoubleRegex(
        "[+-]?([0-9]+(.?)[0-9]*|[0-9]*(.?)[0-9]+)([eE][0-9]+)?");
    
    if (std::regex_match(input, validDoubleRegex)) return true;
    return false;
}

bool IsVariable(std::string input) {
    // checks if the input string is a variable name
    // return true if it can be a variable name, false otherwise
    std::regex validVariableNameRegex("[A-Za-z_][A-Za-z0-9_]*");

    if (std::regex_match(input, validVariableNameRegex)) return true;
    return false;
}

bool IsArithOperator(std::string input) {
    // checks if the input string is an arithmetic operator
    // return true if it's one of (+, -, *, /), false otherwise
    std::regex validArithOpRegex("[+\\-*\\/]");
    if (std::regex_match(input, validArithOpRegex)) return true;
    return false;
}

bool IsCompOperator(std::string input) {
    // checks if the input string is a comparision operator
    // return true if it's one of (==, !=, >, <, >=, <=)
    std::regex validCompOpRegex("(==|!=|>|<|>=|<=)");
    if (std::regex_match(input, validCompOpRegex)) return true;
    return false;
}

OpType ValueOrVariable (string input)
{
	// checks if the input string is a double value or a variable name
	// and returns enum "OpType" (the enum is declared in the .h)

    if (IsVariable(input)) return VARIABLE_OP;
    if (IsValue(input)) return VALUE_OP;

	return INVALID_OP;
}
