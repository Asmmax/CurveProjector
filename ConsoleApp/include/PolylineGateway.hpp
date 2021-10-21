#pragma once
#include <memory>
#include <string>

class Polyline;

class PolylineGateway {
public:
	virtual ~PolylineGateway() {};
	virtual std::shared_ptr<Polyline> getPolyline(const std::string& name) = 0;
};
