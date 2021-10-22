#pragma once

class PolylineGateway;

class ConsoleApp {
private:
	PolylineGateway& _polylineGateway;
public:
	ConsoleApp(PolylineGateway& polylineGateway);
	int run(int argc, char* argv[]);
};