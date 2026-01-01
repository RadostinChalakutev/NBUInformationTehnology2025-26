#include "priority_queue.h"

void PriorityQueue::push(const Route& r) {
    pq.push(r);
}

bool PriorityQueue::empty() const {
    return pq.empty();
}

Route PriorityQueue::pop() {
    Route r = pq.top();
    pq.pop();
    return r;
}
