#pragma once
#include "PolylineGateway.hpp"

class PolylineFile : public PolylineGateway {
public:
	std::shared_ptr<Polyline> getPolyline(const std::string& name) override;
};
