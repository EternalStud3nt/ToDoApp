#define	CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "Task.h"
#include <stdexcept>

TEST_CASE("Task constructor and getters")
{
	Task task("Test task", false);
	REQUIRE(task.getTitle() == "Test task");
	REQUIRE(task.isDone() == false);

	Task task1("Done task", true);
	REQUIRE(task1.getTitle() == "Done task");
	REQUIRE(task1.isDone() == true);
}

TEST_CASE("Task markDone")
{
	Task task("Incomplete task", false);
	REQUIRE(task.isDone() == false);
	task.markDone();
	REQUIRE(task.isDone() == true);
}

TEST_CASE("Task serializatioon task")
{
	Task task("Test task", false);
	REQUIRE(task.serialize() == "Test task,0");

	Task doneTask("Done task", true);
	REQUIRE(doneTask.serialize() == "Done task,1");
}

TEST_CASE("Task deserialization")
{
	Task task = Task::deserialize("Not done task, 0");
	REQUIRE(task.getTitle() == "Not done task");
	REQUIRE(task.isDone() == false);

	Task task2 = Task::deserialize("Done task,1");
	REQUIRE(task2.getTitle() == "Done task");
	REQUIRE(task2.isDone() == true);
}

TEST_CASE("Task deserialization invalid format")
{
	REQUIRE_THROWS_AS(Task::deserialize("NoCommaHere"), std::invalid_argument);
	REQUIRE_THROWS_AS(Task::deserialize("TitleOnly,"), std::invalid_argument);
	REQUIRE_THROWS_AS(Task::deserialize(","), std::invalid_argument);
}