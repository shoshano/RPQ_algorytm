#pragma once
#include <vector>

#include "Dane.h"

class Result
{
	std::vector<std::vector<int>> algorithm_metods;
	std::vector<std::vector<int>> metods_times;

	Result(std::vector<std::vector<int>> am);
};

