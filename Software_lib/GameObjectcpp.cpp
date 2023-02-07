#include "pch.h"
#include "Game.cpp"


void GameObject::set_obj(std::string name)
{
	this->Obj_name = name;
}

std::string GameObject::get_obj()
{
	return this->Obj_name;
}


