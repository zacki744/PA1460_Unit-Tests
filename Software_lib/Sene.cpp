#include "pch.h"
#include "Game.cpp"

Scene::Scene()
{
	this->index = 0;
	//First scene
	std::pair<std::string, std::string> first;
	first.first = "You wake upp in a dimm room and you have a banana in your hand.";
	first.second = "banana";
	this->scene_list.push_back(first);
	//Second scene
	std::pair<std::string, std::string> Scecond;
	Scecond.first = "You notes that there is a door in front of you.";
	Scecond.second = "door";
	this->scene_list.push_back(Scecond);
	//thered scene
	std::pair<std::string, std::string> thre;
	thre.first = "In the room you find an orange.";
	thre.second = "orange";
	this->scene_list.push_back(thre);
}

std::pair<std::string, std::string> Scene::Gett_current_scene()
{
	std::pair<std::string, std::string> obj;
	if (this->index >= 3)
		obj = this->scene_list.at(2);
	else
		obj = this->scene_list.at(this->index);
	return obj;
}

void Scene::next_scene()
{
	this->index++;
}
