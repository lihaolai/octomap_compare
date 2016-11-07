#ifndef OCTOMAP_CONTAINER_H_
#define OCTOMAP_CONTAINER_H_

#include "container_base.h"

#include <unordered_map>

#include <octomap/OcTree.h>

class OctomapContainer : public ContainerBase {

  // Octomap.
  std::shared_ptr<octomap::OcTree> octree_;

  /// \brief Processes octree to enable comparison.
  void processTree();

public:
  /// \brief Read octomap from file.
  OctomapContainer(const std::string& file);

  /// \brief Use octree passed to constructor.
  OctomapContainer(const std::shared_ptr<octomap::OcTree>& octree);

  /// \brief Checks if voxel at point was observed. Also passes back pointer to node at point.
  bool isObserved(const Eigen::Vector3d& point, octomap::OcTreeNode** node) const;

  /// \brief Operator overload to allow access to underlying octree.
  std::shared_ptr<octomap::OcTree> operator->() const {
    return octree_;
  }

  /// \brief Used to check if OcTree is loaded.
  inline operator bool() const {
    return (bool)octree_;
  }

};

#endif // OCTOMAP_CONTAINER_H_