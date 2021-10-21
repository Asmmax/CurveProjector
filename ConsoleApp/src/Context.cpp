#include "Context.hpp"
#include "PolylineFile.hpp"

//bindings
Context::Context():
	_polylineGateway(new PolylineFile())
{
}
