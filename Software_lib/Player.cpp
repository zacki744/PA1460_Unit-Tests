#include "pch.h"

#include "Game.cpp"

std::vector<GameObject> Player::Get_inv()
{
    return this->inventory;
}

void Player::add_to_inv(std::string new_obj)
{
    GameObject temp;
    temp.set_obj(new_obj);
    this->inventory.push_back(temp);
}

std::string Player::get_first()
{
    return this->inventory[0].get_obj();
}

void Player::remove_obj()
{
    if (this->inventory.size() != 0)
        this->inventory.pop_back();
}
