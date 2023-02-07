#include "pch.h"
#include "Game.cpp"

std::pair<std::string, bool> InteractionOptions::interakt_with_obj(std::string obj, std::string inter)
{
	std::pair<std::string, bool> return_obj;
	return_obj.second = true;
	if (obj == "orange")
	{
		if (inter == "eat")
		{
			return_obj.first = "you become sick from eating the old orange";
		}
		else if (inter == "look")
		{
			return_obj.first = "you see a lot of mold on the orange";
		}
		else
		{
			return_obj.first = "invalid action";
			return_obj.second = false;
		}
	}
	else if (obj == "banana")
	{
		if (inter == "eat")
		{
			return_obj.first = "you eat the banana and feal invigorated";
		}
		else
		{
			return_obj.first = "invalid action";
			return_obj.second = false;
		}
	}
	else if (obj == "door")
	{
		if (inter == "open")
		{
			return_obj.first = "You enter the room";
		}
		else
		{
			return_obj.first = "invalid action";
			return_obj.second = false;
		}
	}
	else
	{
		return_obj.first = "invalid action";
		return_obj.second = false;
	}
	return return_obj;
}
