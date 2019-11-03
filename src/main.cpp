#include "Jam.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<Jam> jam = std::make_unique<Jam>();
	jam->run();
	return 0;
}
