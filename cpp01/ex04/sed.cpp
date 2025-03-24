
#include "sed.hpp"

void s_and_replace(const std::string& av1, const std::string& av2, const std::string& av3)
{
	if (av1.empty() || av2.empty() || av3.empty())
	{
		std::cerr << "Invalid arguments!!\n";
		return ;
	}
	std::ifstream file(av1.c_str());
	if (!file)
	{
		std::cerr << "file not found\n";
		return ;
	}
	std::string new_file = av1 + ".replace";
	std::ofstream outpfile(new_file.c_str());
	if (!outpfile)
	{
		std::cerr << "Problems with creating the file!\n";
		return ;
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::string new_line;
		size_t i = 0, end = 0;
		while ((i = line.find(av2, end)) != std::string::npos)
		{
			new_line.append(line, end, i - end);
			new_line.append(av3);
			end = i + std::string(av2).length();
		}
		new_line.append(line, end);
		outpfile << new_line << "\n";
	}
	//file.close();
	//outpfile.close();
}
