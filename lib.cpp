#include <iostream>
#include "lib.h"

void Container::$Sub$$Build(void)
{
	//Load Overlay
  std::cout << "$Sub$$Build" << std::endl;
	$Super$$Build();
	//Unload Overlay
}

void Container::Build(void)
{
  std::cout << "Build" << std::endl;
	// do something
}
