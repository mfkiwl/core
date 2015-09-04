#include <ma.h>
#include <apf.h>
#include <gmi_mesh.h>
#include <apfMDS.h>
#include <PCU.h>
#include <cassert>

int main(int argc, char** argv)
{
  assert(argc==4);
  MPI_Init(&argc,&argv);
  PCU_Comm_Init();
  gmi_register_mesh();
  ma::Mesh* m = apf::loadMdsMesh(argv[1],argv[2]);
  ma::Input* in = ma::configureUniformRefine(m, 1);
  if (in->shouldSnap) {
    in->shouldSnap = false;
    assert(in->shouldTransferParametric);
  }
  in->shouldFixShape = false;
  ma::adapt(in);
  m->writeNative(argv[3]);
  m->destroyNative();
  apf::destroyMesh(m);
  PCU_Comm_Free();
  MPI_Finalize();
}

