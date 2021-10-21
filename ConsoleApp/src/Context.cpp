#include "Context.hpp"
#include "PolylineFile.hpp"
#include "PointParser.hpp"
#include "ProjectionParser.hpp"

//bindings
Context::Context():
	_polylineGateway(new PolylineFile()),
	_pointParser(new PointParser()),
	_projectionParser(new ProjectionParser(_pointParser.get()))
{
}
