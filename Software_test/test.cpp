#include "pch.h"
#include "../Software_lib/Game.h"



TEST(GameTest, InteractionOptionsInteractWithObj)
{
    InteractionOptions inter;

    std::pair<std::string, bool> res_orange_eat = inter.interakt_with_obj("orange", "eat");
    std::pair<std::string, bool> res_orange_look = inter.interakt_with_obj("orange", "look");
    std::pair<std::string, bool> res_banana_eat = inter.interakt_with_obj("banana", "eat");
    std::pair<std::string, bool> res_door_open = inter.interakt_with_obj("door", "open");
    std::pair<std::string, bool> res_invalid = inter.interakt_with_obj("invalid", "invalid");

    EXPECT_EQ(res_orange_eat.first, "you become sick from eating the old orange");
    EXPECT_TRUE(res_orange_eat.second);
    EXPECT_EQ(res_orange_look.first, "you see a lot of mold on the orange");
    EXPECT_TRUE(res_orange_look.second);
    EXPECT_EQ(res_banana_eat.first, "you eat the banana and feal invigorated");
    EXPECT_TRUE(res_banana_eat.second);
    EXPECT_EQ(res_door_open.first, "You enter the room");
    EXPECT_TRUE(res_door_open.second);
    EXPECT_EQ(res_invalid.first, "invalid action");
    EXPECT_FALSE(res_invalid.second);
}

TEST(GameTest, PlayerInv)
{
    Player charekter;

    EXPECT_EQ(charekter.Get_inv().size(), 0);
    charekter.add_to_inv("banana");
    EXPECT_EQ(charekter.Get_inv().size(), 1);
    EXPECT_EQ(charekter.get_first(), "banana");
    charekter.remove_obj();
    EXPECT_EQ(charekter.Get_inv().size(), 0);
}

TEST(GameTest, SceneGetCurrentScene)
{
    Scene scene;

    std::pair<std::string, std::string> first = scene.Gett_current_scene();
    EXPECT_EQ(first.first, "You wake upp in a dimm room and you have a banana in your hand.");
    EXPECT_EQ(first.second, "banana");
    scene.next_scene();
    std::pair<std::string, std::string> second = scene.Gett_current_scene();
    EXPECT_EQ(second.first, "You notes that there is a door in front of you.");
    EXPECT_EQ(second.second, "door");
    scene.next_scene();
    std::pair<std::string, std::string> third = scene.Gett_current_scene();
    EXPECT_EQ(third.first, "In the room you find an orange.");
    EXPECT_EQ(third.second, "orange");
}

//int main(int argc, char** argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
