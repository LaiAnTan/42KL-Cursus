#pragma once

#ifndef FUNCTIONS_HPP

#define FUNCTIONS_HPP

#include "Classes.hpp"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::exception;

Base	*generate(void);

void	identify(Base *p);

void	identify(Base &p);

#endif