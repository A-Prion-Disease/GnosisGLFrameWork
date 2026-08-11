#ifndef TEXTURE_SEER_HPP
#define TEXTURE_SEER_HPP
#include "Godhead.hpp" // Universal_Deps
		       
struct Image{

GLuint GL_ID;


GLint width, height;

Image(const std::string& TexturePath, bool alpha);

	    };

#endif
