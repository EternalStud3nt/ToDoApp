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
	oss << title << "," << id << "," << doneInt;
	return oss.str();
}

Task Task::deserialize(const std::string& line)
{
	std::istringstream iss(line);
	std::string title;
	std::string idInput;
	std::string doneInput;
	if (std::getline(iss, title, ',') && std::getline(iss, idInput, ',') && std::getline(iss, doneInput))
	{
		int id = std::stoi(idInput);
		int doneInt = std::stoi(doneInput);
		Task task(title, id);
		if( doneInt == 1)
		{
			task.markDone();
		}
		return task;
	}
	throw std::invalid_argument("Invalid serialized task format");
}