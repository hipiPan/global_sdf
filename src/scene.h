#pragma once

#include "ez_vulkan.h"
#include "sdf.h"
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <math/bounding_box.h>

struct Primitive
{
    SDF* sdf;
    BoundingBox bounds;
    uint32_t vertex_count;
    uint32_t index_count;
    VkIndexType index_type;
    VkPrimitiveTopology topology;
    EzBuffer index_buffer;
    EzBuffer vertex_buffer;
};

struct Mesh
{
    std::string name;
    std::vector<Primitive*> primitives;
};

struct Node
{
    std::string name;
    glm::mat4 transform;
    Mesh* mesh = nullptr;
};

class Scene
{
public:
    ~Scene();

    std::vector<Node*> nodes;
    std::vector<Mesh*> meshes;
    std::vector<Primitive*> primitives;
};