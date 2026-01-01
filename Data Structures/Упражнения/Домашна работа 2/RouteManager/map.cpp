#include "map.h"

void Map::addRoute(const Route& r) {
    routes[r.name] = r;
}

void Map::removeRoute(const std::string& name) {
    routes.erase(name);
}

bool Map::exists(const std::string& name) const {
    return routes.find(name) != routes.end();
}

Route Map::getRoute(const std::string& name) const {
    return routes.at(name);
}

void Map::printRoutes() const {
    for (const auto& pair : routes) {
        const Route& r = pair.second;
        std::cout << "Route " << r.name << ": "
                  << r.start << " -> " << r.end
                  << ", length: " << r.length << " km\n";
    }
}
