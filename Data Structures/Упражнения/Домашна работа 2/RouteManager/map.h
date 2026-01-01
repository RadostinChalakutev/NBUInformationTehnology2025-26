#ifndef MAP_H
#define MAP_H

#include <string>
#include <map>
#include <iostream>

struct Route {
    std::string name;
    std::string start;
    std::string end;
    int length;
};

class Map {
private:
    std::map<std::string, Route> routes;

public:
    void addRoute(const Route& r);
    void removeRoute(const std::string& name);
    bool exists(const std::string& name) const;
    Route getRoute(const std::string& name) const;
    void printRoutes() const;
};

#endif
