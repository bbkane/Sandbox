#pragma once

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <string>

std::string trim_left(std::string expr)
{
	std::string::iterator i;
	i = std::find_if(std::begin(expr), std::end(expr), [](char c) {return c != ' '; });
	return expr.substr((i - expr.begin()));
}

std::string trim_right(std::string expr)
{
	return "";
}