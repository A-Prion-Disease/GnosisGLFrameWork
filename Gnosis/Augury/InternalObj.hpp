
#ifndef INTERNAL_OBJECT_HPP
#define INTERNAL_OBJECT_HPP

#include "Hermetica/OpenGospeL.hpp"


class TileGrid{

float TileSize;
float CenterX, CenterY; // Which row and col of the map is in the center of view (with some offset to maintain a less blocky quality)

int TileDensity; //(How many tiles in a row and col)
int VisBotRight;


MapFile& CurrentMap;

std::vector<int> VisibleTiles; // Tiles on screen // tiles will be numbered according to type
std::vector<int> AllTiles; // tiles comprising the map

	public:

TileGrid(MapFile& CurrentMap, float CenterX, float CenterY, float TileSize, int TileDensity);

void ShiftGrid(int X_Dif, int Y_Dif); 

void Render(void);

	      };

#endif
