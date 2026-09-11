#ifndef FILE_ORACLE_HPP
#define FILE_ORACLE_HPP

#include <sstream>
#include <fstream>
#include <vector>

std::string FileRead(const std::string& filepath);

enum class MapQuality{
test
		       };

class MapFile{

public: 

std::vector<int> tiles;

int Width, Height;

MapQuality Quality;

void ReadMapFile(const std::string& filepath, MapQuality Qual);

	     };


#endif
