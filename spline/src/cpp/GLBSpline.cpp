#include "GLBSpline.h"
#include <iostream>

GLBSpline::GLBSpline()
: GLCurve()
{

}

GLBSpline::~GLBSpline()
{
}

void GLBSpline::OnNewControlPointAdded()
{
	if(m_points.size() < 4)
	{
		return;
	}

	int new_control_point_index=static_cast<int>(m_points.size()) - 1;

	int pt=new_control_point_index - 3;

	for(int i=0; i<=m_steps; i++)
	{
		double u=(double)i / (double)m_steps;

		AddNode(GetPoint(u, m_points[pt], m_points[pt+1], m_points[pt+2], m_points[pt+3]));
	}
}

GLVector GLBSpline::GetPoint(double u, const GLVector& P0, const GLVector& P1, const GLVector& P2, const GLVector& P3)
{
	GLVector point;
	point=u*u*u*((-1) * P0 + 3 * P1 - 3 * P2 + P3) / 6;
	point+=u*u*(3*P0 - 6 * P1+ 3 * P2) / 6;
	point+=u*((-3) * P0 + 3 * P2) / 6;
	point+=(P0+4*P1+P2) / 6;

	return point;
}

