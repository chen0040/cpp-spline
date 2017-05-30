#include <iostream>
#include "../../main/cpp/Bezier.h"
void demo_bezier();

int main(char** argv, int argc) {
	demo_bezier();
}

void demo_bezier() {
	Bezier* curve = new Bezier();
	curve->set_steps(100); // generate 100 interpolate points between the last 4 way points
	curve->add_way_point(Vector(1, 1, 0));
	curve->add_way_point(Vector(2, 3, 0));
	curve->add_way_point(Vector(3, 2, 0));
	curve->add_way_point(Vector(4, 6, 0));
	std::cout << "nodes: " << curve->node_count() << std::endl;
	std::cout << "total length: " << curve->total_length() << std::endl;
	for (int i = 0; i < curve->node_count(); ++i) {
		std::cout << "node #" << i << ": " << curve->node(i).toString() << " (length so far: " << curve->length_from_starting_point(i) << ")" << std::endl;
	}
	delete curve;
}