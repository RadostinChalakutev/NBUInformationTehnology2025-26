#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <queue>
#include <vector>
#include "map.h"

struct CompareRoute {
    bool operator()(const Route& a, const Route& b) {
        return a.length > b.length; // shorter route = higher priority
    }
};

class PriorityQueue {
private:
    std::priority_queue<Route, std::vector<Route>, CompareRoute> pq;

public:
    void push(const Route& r);
    bool empty() const;
    Route pop();
};

#endif
