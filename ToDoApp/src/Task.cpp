#include "Task.h"
#include <sstream>

Task::Task(const std::string& title, int id) : title(title), id(id)
{

}

std::string Task::getTitle() const 
{
	return title;
}

bool Task::isDone() const
{
	return done;
}

void Task::markDone() 
{
	done = true;
}

std::string Task::serialize() const 
{
	int doneInt = done ? 1 : 0;

	std::ostringstream oss;
	oss << title << "," << doneInt;
	return oss.str();
}

Task Task::deserialize(const std::string& line)
{
	std::istringstream iss(line);
	std::string title;
	std::string doneStr;
	if (std::getline(iss, title, ',') && std::getline(iss, doneStr))
	{
		bool done = (doneStr == "1");
		return Task(title, done);
	}
	throw std::invalid_argument("Invalid serialized task format");
}