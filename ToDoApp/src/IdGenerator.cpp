// The IdGenerator class provides a mechanism for generating unique integer IDs and reusing released IDs efficiently.
// It maintains a counter for the next available ID and a priority queue to store released IDs for reuse in ascending order.
// The class ensures that the smallest available ID is always reused first, and prevents duplicate reuse by tracking released IDs in an unordered_set.


#include "IDGenerator.h"
#include <stdexcept>

int IdGenerator::generateId()
{
	// If there are no released IDs, generate the next one
	if (freeIds.empty())
	{
		int id = nextAvailableId;
		nextAvailableId++;
		return id;
	}
	else
	{
		// Use the smallest released ID available
		int id = freeIds.top();
		freeIds.pop();
		freeIds_set.erase(id); // Remove from tracking set to allow future reuse
		return id;
	}
}

void IdGenerator::releaseId(int id)
{
	if (id < 0 || id >= nextAvailableId) 
	{
		throw std::invalid_argument("IdGenerator::releaseId: ID is out of valid range");
	}

	// Prevent duplicate reuse by checking if ID is already in the queue
	// We use a set because priority_queue has no way to search its contents
	bool idNotInSet = freeIds_set.find(id) == freeIds_set.end();
	if (id < nextAvailableId && idNotInSet)
	{
		freeIds.push(id);
		freeIds_set.insert(id);
	}
}
