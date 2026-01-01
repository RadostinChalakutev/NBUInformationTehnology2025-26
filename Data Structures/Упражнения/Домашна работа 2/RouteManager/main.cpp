
#include <iostream>
#include "map.h"
#include "priority_queue.h"

int main() {
    Map map;
    PriorityQueue pq;

    int n;
    std::cout << "Number of routes: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Route r;
        std::cout << "Route name: ";
        std::cin >> r.name;
        std::cout << "Start point: ";
        std::cin >> r.start;
        std::cout << "End point: ";
        std::cin >> r.end;
        std::cout << "Length: ";
        std::cin >> r.length;

        if (r.length <= 0) {
            std::cout << "Invalid length!\n";
            i--;
            continue;
        }

        map.addRoute(r);
    }

    int m;
    std::cout << "Number of travel requests: ";
    std::cin >> m;

    for (int i = 0; i < m; i++) {
        std::string routeName;
        std::cout << "Request " << i + 1 << ": ";
        std::cin >> routeName;

        if (map.exists(routeName)) {
            pq.push(map.getRoute(routeName));
        }
    }

    std::cout << "\nProcessing travel requests:\n";
    int index = 1;
    while (!pq.empty()) {
        Route r = pq.pop();
        std::cout << index++ << ": Route "
                  << r.name << " from "
                  << r.start << " to "
                  << r.end << ", total length "
                  << r.length << " km\n";
    }

    return 0;
}
