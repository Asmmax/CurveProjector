#include "ConsoleApp.hpp"
#include "PolylineFile.hpp"

int main(int argc, char* argv[])
{
	PolylineFile polylineFile;
	ConsoleApp app(polylineFile);
	return app.run(argc, argv);
}
