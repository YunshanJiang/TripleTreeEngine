#include "TripleTreeEngine.h"

int main(int argc, char** argv)
{
	TripleTreeEngine engine;
	if(engine.Initialize())
		engine.Start();

	return 0;
}