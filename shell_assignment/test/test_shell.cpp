#include <gtest/gtest.h>
#include "../shell.h"

// Test edge case
TEST(ShellTest, ExitCommand)
{
    Shell shell;

    EXPECT_FALSE(shell.run("exit"));
}
TEST(ShellTest, EmptyCommand)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("==========ACTION=========="),std::string::npos);
}
TEST(ShellTest, WhiteSpaceCommand)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run(" ");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("==========ACTION=========="),std::string::npos);
}
// Test action
TEST(ParserTest, ValidAction)
{
    Shell shell;

    EXPECT_TRUE(shell.check_action_valid("--set"));
}

TEST(ParserTest, InvalidAction)
{
    Shell shell;

    EXPECT_FALSE(shell.check_action_valid("set"));
}

TEST(ShellTest, HelpAction)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("--change");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("==========ACTION=========="), std::string::npos);
}

TEST(ShellTest, HelpTarget)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("--help");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("==========TARGET=========="), std::string::npos);
}

// Test target

TEST(ParserTest, ValidTarget)
{
    Shell shell;

    EXPECT_TRUE(shell.check_target_valid("--set tar=led"));
}

TEST(ParserTest, InvalidTarget)
{
    Shell shell;
    EXPECT_FALSE(shell.check_target_valid("--set tar=ledd"));
}

TEST(ShellTest, HelpParams)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("--help tar=led");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("==========LED=========="), std::string::npos);
}

// Test action in target

TEST(ShellTest, AuthHasAction)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("--get tar=auth");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Auth: Dinh Cuong"), std::string::npos);
}

TEST(ShellTest, LedHasAction)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("--set tar=led status=on");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("led :on"), std::string::npos);
}

TEST(ShellTest, AuthNotHasAction)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("--set tar=auth");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("==========AUTH=========="), std::string::npos);
}

TEST(ShellTest, AuthNotHasHelp)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("--help tar=auth");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("==========AUTH=========="), std::string::npos);
}

TEST(ShellTest, MissParam)
{
    Shell shell;
    testing::internal::CaptureStdout();
    shell.run("--set tar=led");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("==========LED=========="), std::string::npos);
}
