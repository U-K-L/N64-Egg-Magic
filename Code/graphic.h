#ifndef N64_GRAPHIC_H
#define N64_GRAPHIC_H

#define SP 128 //Scale of the entire rendering engine, no floating point so 100 default value.


typedef struct 
{
    Vtx const *vertices;
    int size;
    Gfx const *settings;
}Mesh;
extern Mesh current_mesh;
extern Mesh current_mesh2;

//_END_MESHES_

// Gfx state:
typedef struct {
  Mtx     projection;
  Mtx     modeling;
  Mtx     rotate_z;
  Mtx     rotate_y;
  Mtx     rotate_x;
  Mtx     camera;
} Dynamic;
extern Dynamic gfx_dynamic;

typedef struct view {
	short   view_scale[4]; 
	short   view_transformation[4];
	long long int   force_structure_alignment;
};
#endif