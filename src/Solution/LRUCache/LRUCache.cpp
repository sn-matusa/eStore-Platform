#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity = capacity;
	size = 0;
	lru = vector<int>();
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	vector<int> vec_lru;
	unsigned int i, j, k;
	vec_lru.push_back(requestsNo[0]);
	size++;
	for (i = 0; i < requestsNo.size(); i++)    
	{
		if (size < capacity)
		{
			vec_lru.push_back(vec_lru[size-1]);
			for (j = size-1; j > 0; j--)
			{
				vec_lru[j] = vec_lru[j - 1];
			}
			vec_lru[0] = requestsNo[i];
			size++;
			for (j = 1; j < size; j++)
			{
				if (vec_lru[j] == vec_lru[0])
				{
					for (k = j; k < size-1; k++)
					{
						vec_lru[k] = vec_lru[k + 1];
					}
				size--;
				vec_lru.pop_back();
				}
			}
		}
		else
		{
			int index = -1;
			for (j = 0; j < size; j++)
			{
				if (vec_lru[j] == requestsNo[i])
					index = j;
				break;
			}
			if (index != -1)
			{
				for (j = index; j > 0; j--)
					vec_lru[j] = vec_lru[j - 1];
				vec_lru[0] = requestsNo[i];
			}
			else
			{
				for (j = size - 1; j > 0; j--)
					vec_lru[j] = vec_lru[j - 1];
				vec_lru[0] = requestsNo[i];
			}
		}
	}
	return vec_lru;
}

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
	return lru;
}

int LRUCache::getLRUCapacity()
{
	return lru.capacity();
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	lru = aux;
}
