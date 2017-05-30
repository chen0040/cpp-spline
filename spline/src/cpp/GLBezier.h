#ifndef _H_GL_BEZIER_H
#define _H_GL_BEZIER_H

#include "GLCurve.h"

class GLBezier : public GLCurve
{
public:
	GLBezier();
	virtual ~GLBezier();

protected:
	virtual void OnNewControlPointAdded();

protected:
	GLVector GetPoint(double u, const GLVector& P0, const GLVector& P1, const GLVector& P2, const GLVector& P3);
};

#endif