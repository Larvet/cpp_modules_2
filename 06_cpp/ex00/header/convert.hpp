#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

void	convertPseudoLitteral(const std::string& str);
void	convertChar(const std::string& str);
void	convertInt(const std::string& str);
void	convertFloat(const std::string& str);
void	convertDouble(const std::string& str);
void	handleNotConvertible(const std::string& str);