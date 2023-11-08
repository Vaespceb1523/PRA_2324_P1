#include "Shape.h"
#include <iostream>


Shape::Shape(){
	set_color ("red");
}

Shape::Shape(std::string color){
	set_color (color);
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	color = c;
}
