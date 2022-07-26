//
// Created by wj on 22. 7. 21.
//

#ifndef KMEANSCLUSTERING_KMEANS_HPP
#define KMEANSCLUSTERING_KMEANS_HPP


#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

#include "Point3.hpp"
#include "Plane.hpp"

namespace camel
{
	class KMeans
	{
	public:
		KMeans();
		KMeans(std::vector<Point3> data, float k);

		std::vector<Point3> GetData() const;
		void SetData(const std::vector<Point3>& data);

		void FromPCD(const std::string& inputPath);
		void ToPCD(const std::vector<camel::Point3>& data, int num);
		void Run();
		void SaveResult();

	private:
		void setInitialCentroid();
		void assignCentroid();
		bool bUpdateCentroid();
		bool bFindNearRate();
		void generateCentroid();
		void clustering();

		std::vector<Point3> mData;

		std::vector<Point2> mCentroids;
		std::vector<Model::Plane> mModels;
	};
}

#endif //KMEANSCLUSTERING_KMEANS_HPP
