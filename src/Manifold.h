#ifndef MANIFOLD2_MANIFOLD_H_
#define MANIFOLD2_MANIFOLD_H_

#include "types.h"

#include "Octree.h"

class Manifold {
public:
	Manifold();
	~Manifold();
	void ProcessManifold(const MatrixX& V, const MatrixXi& F, int resolution,
		MatrixX* out_V, MatrixXi* out_F);

protected:
	void BuildTree(int resolution);
	void CalcBoundingBox();
	void ConstructManifold();
	bool SplitGrid(const std::vector<Vector4i>& nface_indices,
		std::map<GridIndex,int>& vcolor,
		std::vector<Vector3>& nvertices,
		std::vector<std::set<int> >& v_faces,
		std::vector<Vector3i>& triangles);

private:	
	Octree* tree_;
	Vector3 min_corner_, max_corner_;
	MatrixX V_;
	MatrixXi F_;

	std::vector<Vector3> vertices_;
	std::vector<Vector3i> face_indices_;
	std::vector<GridIndex > v_info_;

};

#endif