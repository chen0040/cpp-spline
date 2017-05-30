#include "GLBezier.h"
#include <iostream>

GLBezier::GLBezier()
: GLCurve()
{

}

GLBezier::~GLBezier()
{
}

void GLBezier::OnNewControlPointAdded()
{
	if(m_points.size() < 4)
	{
		return;
	}

	int new_control_point_index=m_points.size() - 1;

	if(new_control_point_index == 3)
	{
		for(int i=0; i<=m_steps; i++)
		{
			double u=(double)i / (double)m_steps;

			AddNode(GetPoint(u, m_points[0], m_points[1], m_points[2], m_points[3]));
		}
	}
	else
	{
		if(new_control_point_index % 2 == 0)
		{
			return;
		}
		
		int pt=new_control_point_index - 2;
		for(int i=0; i<=m_steps; i++)
		{
			double u=(double)i / (double)m_steps;
			GLVector point4=2 * m_points[pt] - m_points[pt-1];

			AddNode(GetPoint(u, m_points[pt], point4, m_points[pt+1], m_points[pt+2]));
		}
	}
}

GLVector GLBezier::GetPoint(double u, const GLVector& P0, const GLVector& P1, const GLVector& P2, const GLVector& P3)
{
	GLVector point;
	point=u*u*u*((-1) * P0 + 3 * P1 - 3 * P2 + P3);
	point+=u*u*(3*P0 - 6 * P1+ 3 * P2);
	point+=u*((-3) * P0 + 3 * P1);
	point+=P0;

	return point;
}

