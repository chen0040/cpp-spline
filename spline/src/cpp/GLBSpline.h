#ifndef _H_GL_BSPLINE_H
#define _H_GL_BSPLINE_H

#include "GLCurve.h"

class GLBSpline : public GLCurve
{
public:
	GLBSpline();
	virtual ~GLBSpline();

protected:
	virtual void OnNewControlPointAdded();

protected:
	GLVector GetPoint(double u, const GLVector& P0, const GLVector& P1, const GLVector& P2, const GLVector& P3);
};

#endif