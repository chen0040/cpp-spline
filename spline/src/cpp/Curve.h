#ifndef _H__CURVE_H
#define _H__CURVE_H

#include "Vector.h"
#include <vector>
#include <cassert>

class Curve
{
public:
	Curve();
	virtual ~Curve();

protected:
	std::vector<Vector> _way_points;
public:
	void add_way_point(const Vector& point);
	void clear();

protected:
	void add_node(const Vector& node);
	virtual void _on_way_point_added()=0;

protected:
	std::vector<Vector> m_nodes;
	std::vector<double> m_distances;
public:
	Vector GetNode(int i) const { return m_nodes[i]; }
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