#ifndef TEXTURE_SEER_HPP
#define TEXTURE_SEER_HPP
#include "Godhead.hpp" // Universal_Deps
		       
struct Image{

GLuint GL_ID, TileSize;

GLint width, height;

Image(void){};
Image(const std::string& TexturePath, bool alpha, unsigned int TileSize);

	    };

#endif
