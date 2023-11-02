/**
 * @file ScoreboardTest.cpp
 * @author Navya Singh
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Scoreboard.h>

TEST(ScoreboardTest, DefaultConstructor) {
    Scoreboard scoreboard;
    auto minutes = scoreboard.GetMinutes();
    auto seconds = scoreboard.GetSeconds();
    EXPECT_EQ(minutes, 0);
    EXPECT_EQ(seconds, 0);
}

TEST(ScoreboardTest, ResetTimer) {
    Scoreboard scoreboard;
    auto minutes = scoreboard.GetMinutes();
    auto seconds = scoreboard.GetSeconds();
    scoreboard.SetTime(2, 30);
    scoreboard.ResetTimer();
    EXPECT_EQ(minutes, 0);
    EXPECT_EQ(seconds, 0);
}

