#pragma once
#include <memory>

class PolylineGateway;
class PointParser;
class ProjectionParser;

class Context
{
private:
	std::unique_ptr<PolylineGateway> _polylineGateway;
	std::unique_ptr<PointParser> _pointParser;
	std::unique_ptr<ProjectionParser> _projectionParser;
public:
	Context();
	inline PolylineGateway* polylineGateway() { return _polylineGateway.get(); }
	inline PointParser* pointParser() { return _pointParser.get(); }
	inline ProjectionParser* projectionParser() { return _projectionParser.get(); }
};
