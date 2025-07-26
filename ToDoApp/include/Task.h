#pragma once
#include <string>

class Task
{
public:
	Task(const std::string& title, int id, bool done = false);

	std::string getTitle() const;
	bool isDone() const;
	void markDone();
	std::string serialize() const;
	static Task deserialize(const std::string& line);

private:
	std::string title;
	bool done;
	int id;
};