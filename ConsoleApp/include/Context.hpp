#pragma once
#include <memory>

class PolylineGateway;

class Context
{
private:
	std::unique_ptr<PolylineGateway> _polylineGateway;
public:
	Context();
	inline PolylineGateway* polylineGateway() { return _polylineGateway.get(); }
};
