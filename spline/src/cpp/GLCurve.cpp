#include "GLCurve.h"

GLCurve::GLCurve()
: m_steps(100)
, m_bShowLineSegments(false)
{

}

GLCurve::~GLCurve()
{
}

void GLCurve::Clear()
{
	m_nodes.clear();
	m_points.clear();
	m_distances.clear();
}

void GLCurve::AddPoint(const GLVector& point)
{
	m_points.push_back(point);
	OnNewControlPointAdded();
}



void GLCurve::AddNode(const GLVector& node)
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
