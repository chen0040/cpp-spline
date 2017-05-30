#ifndef _H_GL_CURVE_H
#define _H_GL_CURVE_H

#include "GLVector.h"
#include <vector>
#include <cassert>

class GLCurve
{
public:
	GLCurve();
	virtual ~GLCurve();

protected:
	std::vector<GLVector> m_points;
public:
	void AddPoint(const GLVector& point);
	void AddNode(const GLVector& node);
	void Clear();

protected:
	virtual void OnNewControlPointAdded()=0;

protected:
	std::vector<GLVector> m_nodes;
	std::vector<double> m_distances;
public:
	GLVector GetNode(int i) const { return m_nodes[i]; }
	double GetDistance(int i) const { return m_distances[i]; }
	bool ReachEnd(int i) const { return static_cast<int>(m_nodes.size()) <= i; }
	int GetNodeCount() const {  return static_cast<int>(m_nodes.size()); }
	bool IsNull() { return m_nodes.empty(); }
	double GetTotalDistance() const
	{
		assert(!m_distances.empty());
		return m_distances[m_distances.size() - 1];
	}

protected:
	int m_steps;
public:
	void increment_steps(int steps) { m_steps+=steps; }

protected:
	bool m_bShowLineSegments;
public:
	void ShowLineSegment(bool bShow) { m_bShowLineSegments=bShow; }
};

#endif