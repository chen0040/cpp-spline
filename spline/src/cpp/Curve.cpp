#include "Curve.h"

Curve::Curve()
: m_steps(100)
, m_bShowLineSegments(false)
{

}

Curve::~Curve()
{
}

void Curve::clear()
{
	m_nodes.clear();
	_way_points.clear();
	m_distances.clear();
}

void Curve::add_way_point(const Vector& point)
{
	_way_points.push_back(point);
	_on_way_point_added();
}



void Curve::add_node(const Vector& node)
{
	m_nodes.push_back(node);

	

	if(m_nodes.size()==1)
	{
		m_distances.push_back(0);
	}
	else
	{
		int new_node_index=m_nodes.size() - 1;

		double segment_distance=(m_nodes[new_node_index] - m_nodes[new_node_index-1]).length();
		m_distances.push_back(segment_distance + m_distances[new_node_index-1]);
	}
}
