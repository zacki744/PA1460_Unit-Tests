#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <map>

class InteractionOptions
{
public:
	std::pair<std::string, bool> interakt_with_obj(std::string obj, std::string inter);
};

class GameObject: public InteractionOptions
{
private:
	std::string Obj_name;
public:
	void set_obj(std::string name);
	std::string get_obj();
};


class Player
{
private:
	std::vector<GameObject> inventory;
public:
	std::vector<GameObject> Get_inv();
	void add_to_inv(std::string new_obj);
	std::string get_first();
	void remove_obj();
};

class Scene
{
private:
	std::vector<std::pair<std::string, std::string>> scene_list;
	int index;
public:
	Scene();
	std::pair<std::string, std::string> Gett_current_scene();
	void next_scene();
};

class Game
{
public:
	void Gameloop_start()
	{
		std::cout << "Hello World" << std::endl;
		Player charekter;
		Scene the_Scene;
		GameObject obj;
		std::string respons;
		int itorator = 0;
		std::pair<std::string, std::string> the_current_scene = the_Scene.Gett_current_scene();

		while (true)
		{
			// brek (there is only 3 seace) :(
			if (itorator == 3)
			{
				break;
			}
			// user prompt
			std::cout << std::endl << the_current_scene.first << std::endl;
			std::cin >> respons;
			if (respons == "q") // break if q
			{
				break;
			}
			// check prompt
			std::pair<std::string, bool> interaktion_res = obj.interakt_with_obj(the_current_scene.second, respons);
			std::cout << interaktion_res.first << std::endl;
			// if vallid uppdate options
			if (interaktion_res.second)
			{
				charekter.remove_obj();
				the_Scene.next_scene();
				itorator++;
				the_current_scene = the_Scene.Gett_current_scene();
				charekter.add_to_inv(the_current_scene.second);

			}
		}
	}
};

