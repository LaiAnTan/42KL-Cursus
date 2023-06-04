#pragma once

#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP

#include "Data.hpp"

#include <stdint.h>

// in c++11: #include <cstdint>

#include <iostream>

using std::cout;
using std::endl;

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &serializer);
		Serializer &operator = (const Serializer &serializer);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif