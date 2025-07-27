#pragma once
#include <unordered_set>
#include <queue>

class IdGenerator
{
public:
	int generateId();
	void releaseId(int id);

private:
	int nextAvailableId = 0;
	std::priority_queue<int, std::vector<int>, std::greater<>> freeIds;
	std::unordered_set<int> freeIds_set;
};