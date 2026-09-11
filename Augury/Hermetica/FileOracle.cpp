#include "FileOracle.hpp"

std::string FileRead(const std::string& filepath){

	std::ifstream CurrentFile(filepath);

	if(CurrentFile.is_open()){

	std::stringstream textBuffer;

	textBuffer << CurrentFile.rdbuf();

	const std::string F_Output = textBuffer.str();

	CurrentFile.close();

	return F_Output;

				 }
	return std::string();

						 }

void MapFile::ReadMapFile(const std::string& filepath, MapQuality Qual){

	this->Quality = Qual;

	std::ifstream stream(filepath);

	std::vector<int> FileData;

	std::string Line;

	MapFile NewMapFile;

	while(std::getline(stream, Line)){
	
	std::stringstream ss(Line);
	std::string Num;

	while(std::getline(ss, Num, ',')){
	
	if(!Num.empty()){
	FileData.push_back(std::stoi(Num));
			     }
					 }

					 }


	this->tiles = FileData;
					        }
