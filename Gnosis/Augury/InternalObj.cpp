#include "InternalObj.hpp"


TileGrid::TileGrid(MapFile& CurrentMap, float COS_X, float COS_Y, float TileSize, int TileDensity) 
:  CurrentMap(CurrentMap), COS_X(COS_X), COS_Y(COS_Y), TileSize(TileSize), TileDensity(TileDensity){


VTL = 0; //Initally : maybe i'll make a variation of this func which controls the position of the viewing upon init	
VTR = (TileDensity - 1);
VBL = ((TileDensity * TileDensity) - (TileDensity - 1));
VBR = ((TileDensity * TileDensity) - 1); //off one cause vector starts at 0
 // Unsure of how to use these 

this->Render();

this->AllTiles = CurrentMap.tiles;


for(int i = 0; i < VBR; i++){

this->VisibleTiles.at(i) = AllTiles.at(i);

				    } //Starts at the topright corner of the Current map

}//TileGrid Construct

void TileGrid::ShiftGrid( int X_Dif, int Y_Dif){
	
COS_X += X_Dif;
COS_Y += Y_Dif;


if(X_Dif != 0){

VTL += X_Dif; VBL += X_Dif;
VTR += X_Dif; VBR += X_Dif;

if(X_Dif > 0){

VisibleTiles.at(TileDensity) = 0; //PlaceHolder for a value in the vec: AllTiles

for(int i = 1; i < ((X_Dif * TileDensity ) - 1); i++){

VisibleTiles.at( (TileDensity * i) ) = 0; //PlaceHolder for a value in the vec: AllTiles	

			            } //Expands Right
	     } //If X_Dif is pos :: Expands Right
else{

VisibleTiles.at(0) = AllTiles.at(VTL);

for(int i = 1; i < X_Dif; i++){

VisibleTiles.at( (i + TileDensity) ) = AllTiles.at(VTL + (i * TileDensity)); //unsure if this is right 	
			      }
    }//If X_Dif is neg ::Expands left
     
	       }//If X_Dif != 0

if(Y_Dif != 0){

VTL += (TileDensity * Y_Dif); VBL += (TileDensity * Y_Dif);
VTR += (TileDensity * Y_Dif); VBR += (TileDensity * Y_Dif);

if(Y_Dif > 0){

for(int i = 0; i < (Y_Dif * TileDensity); i++){

VisibleTiles.at( (VBR - i) ) = 0; // 0 is a temp value :: replace with a value in the vec: AllTiles	
	
					      }//Expands Down
	     }//If Y_Dif is pos : i.e. expands downwards
else{

for(int i = 0; i < (Y_Dif * TileDensity); i++){

VisibleTiles.at(i) = 0; //placeholder value (Seems shockingly a little too simple)

					      }
    }//if Y_Dif is neg : i.e. expands upwards
	      }

if((X_Dif && Y_Dif) == 0){
	std::cout << "No shift happened despite being called: buggy code?" << std::endl;
			 }

					       }

void TileGrid::Render(void){

	int tx = 0;
	int ty = 0; //tx incremented each tile and ty incremented for each time tx > TileDensity and then tx = 0;
	int i = 0;

	Quad CurTile; //Current_Tile
	TextureRect CurTexRect; // Current TextureRect


	CurTile = Quad(tx * TileSize, ty * TileSize, 0.1f, TileSize, 0, CurTexRect);
	
	    while(i < VisibleTiles.size()){

	    if(!(i < VisibleTiles.size())){
		i++;
		tx++;
		if(tx > (TileDensity - 1)){//if_2
		ty++;
		tx = 0;
		 			  }//if_2

					  }//if_1

		switch(VisibleTiles.at(i)){
			case 1:{
			
				

			break;
			       }
		   	   
				  	   }//switch

				       }//While_Loop
			    }
