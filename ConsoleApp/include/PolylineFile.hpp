#pragma once
#include "PolylineGateway.hpp"

class PointParser;

class PolylineFile : public PolylineGateway {
private:
	PointParser* _pointParser;
public:
	PolylineFile(PointParser* pointParser);
	std::shared_ptr<Polyline> getPolyline(const std::string& name) override;
};
