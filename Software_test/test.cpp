#include "pch.h"
#include "../Software_lib/Game.h"



TEST(InteractionOptionsTest, InteractWithObjTest)
{
    InteractionOptions interOpt;

    // Test with valid objects
    auto result = interOpt.interakt_with_obj("orange", "eat");
    EXPECT_EQ(result.first, "you become sick from eating the old orange");
    EXPECT_TRUE(result.second);

    result = interOpt.interakt_with_obj("banana", "eat");
    EXPECT_EQ(result.first, "you eat the banana and feal invigorated");
    EXPECT_TRUE(result.second);

    result = interOpt.interakt_with_obj("door", "open");
    EXPECT_EQ(result.first, "You enter the room");
    EXPECT_TRUE(result.second);

    // Test with invalid objects
    result = interOpt.interakt_with_obj("orange", "kick");
    EXPECT_EQ(result.first, "invalid action");
    EXPECT_FALSE(result.second);

    result = interOpt.interakt_with_obj("table", "open");
    EXPECT_EQ(result.first, "invalid action");
    EXPECT_FALSE(result.second);
}

TEST(GameObjectTest, SetGetObjectTest) {
    GameObject gameObj;
    gameObj.set_obj("banana");
    EXPECT_EQ(gameObj.get_obj(), "banana");
}

TEST(PlayerTest, AddGetObjectTest) {
    Player player;
    player.add_to_inv("banana");
    player.add_to_inv("orange");
    auto inv = player.Get_inv();
    EXPECT_EQ(inv[0].get_obj(), "banana");
    EXPECT_EQ(inv[1].get_obj(), "orange");
}

TEST(PlayerTest, GetFirstObjectTest) {
    Player player;
    player.add_to_inv("banana");
    player.add_to_inv("orange");
    EXPECT_EQ(player.get_first(), "banana");
}

TEST(PlayerTest, RemoveObjectTest) {
    Player player;
    player.add_to_inv("banana");
    player.add_to_inv("orange");
    player.remove_obj();

    auto inv = player.Get_inv();

    EXPECT_EQ(inv.size(), 1);
    EXPECT_EQ(inv[0].get_obj(), "banana");
}

TEST(SceneTest, GetCurrentSceneTest) {
    Scene scene;
    auto res = scene.Gett_current_scene();
    EXPECT_EQ(res.first, "You wake upp in a dimm room and you have a banana in your hand.");
    EXPECT_EQ(res.second, "banana");
}

TEST(SceneTest, NextSceneTest) {
    Scene scene;
    scene.next_scene();
    auto res = scene.Gett_current_scene();
    EXPECT_EQ(res.first, "You notes that there is a door in front of you.");
    EXPECT_EQ(res.second, "door");
}
